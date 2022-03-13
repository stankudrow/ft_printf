/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:57:18 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/08 22:57:19 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	release_fdb(t_fdb *fdb, t_fdb **fdblst)
{
	t_fdb	*curr;
	t_fdb	*prev;

	prev = NULL;
	curr = *fdblst;
	while (curr)
	{
		if (curr->fd == fdb->fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*fdblst = curr->next;
			free(curr->buf);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static char	*extract_line(t_fdb *fdb)
{
	t_line	*line;
	char	*str;
	char	chr;

	line = gnl_init_line();
	while (!line->error && !fdb->eof)
	{
		chr = gnl_pop_char(fdb);
		if (fdb->error)
			break ;
		gnl_push_char(line, chr);
		if (line->error)
			break ;
		if (line->endl)
		{
			str = gnl_remalloc(line->buf, line->lpos, line->lpos + 1);
			if (str)
				str[line->lpos] = '\0';
			gnl_free_line(line);
			return (str);
		}
	}
	gnl_free_line(line);
	return (NULL);
}

static t_fdb	*create_fdb(int fd)
{
	t_fdb	*new;

	new = malloc(sizeof(t_fdb));
	if (!new)
		return (NULL);
	new->buf = malloc(BUFFER_SIZE);
	if (new->buf)
	{
		new->fd = fd;
		new->nbytes = read(new->fd, new->buf, BUFFER_SIZE);
		if (new->nbytes > 0)
		{
			new->bpos = 0;
			new->next = NULL;
			new->error = false;
			new->eof = false;
			return (new);
		}
		free(new->buf);
	}
	free(new);
	return (NULL);
}

static t_fdb	*acquire_fdb(int fd, t_fdb **fdblst)
{
	t_fdb	*last;
	t_fdb	*new;

	last = *fdblst;
	while (last)
	{
		if (last->fd == fd)
			return (last);
		if (!last->next)
			break ;
		last = last->next;
	}
	new = create_fdb(fd);
	if (!new)
		return (NULL);
	if (last)
		last->next = new;
	else
		*fdblst = new;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_fdb	*fdblst = NULL;
	t_fdb			*fdb;
	char			*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1 || LBS < 1)
		return (NULL);
	fdb = acquire_fdb(fd, &fdblst);
	if (!fdb)
		return (NULL);
	line = extract_line(fdb);
	if (!line)
		release_fdb(fdb, &fdblst);
	return (line);
}
