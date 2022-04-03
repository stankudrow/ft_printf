/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:15:53 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 10:25:37 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "ft_stdlib.h"

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

void	ft_dlist_add_back(t_dlist **lst, t_dlist *node);
void	ft_dlist_add_front(t_dlist **lst, t_dlist *node);
void	ft_dlist_clear(t_dlist **lst, void (*del)(void *));
void	ft_dlist_delone(t_dlist *lst, void (*del)(void *));
void	ft_dlist_iter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlist_last(t_dlist *lst);
t_dlist	*ft_dlist_map(t_dlist *lst, void *(*f)(void *), void (*del)(void *));
t_dlist	*ft_dlist_new(void *content);
t_dlist	*ft_dlist_pop(t_dlist **lst);
t_dlist	*ft_dlist_popleft(t_dlist **lst);
void	ft_dlist_reverse(t_dlist **lst);
size_t	ft_dlist_size(t_dlist *lst);

#endif