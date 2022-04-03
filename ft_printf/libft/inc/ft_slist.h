/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:15:43 by stanislav         #+#    #+#             */
/*   Updated: 2022/03/25 00:15:43 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLIST_H
# define FT_SLIST_H

# include "ft_stdlib.h"

typedef struct s_slist
{
	void			*content;
	struct s_slist	*next;
}	t_slist;

void	ft_slist_add_back(t_slist **lst, t_slist *node);
void	ft_slist_add_front(t_slist **lst, t_slist *node);
void	ft_slist_clear(t_slist **lst, void (*del)(void *));
void	ft_slist_delone(t_slist *lst, void (*del)(void *));
void	ft_slist_iter(t_slist *lst, void (*f)(void *));
t_slist	*ft_slist_last(t_slist *lst);
t_slist	*ft_slist_map(t_slist *lst, void *(*f)(void *), void (*del)(void *));
t_slist	*ft_slist_new(void *content);
t_slist	*ft_slist_pop(t_slist **lst);
t_slist	*ft_slist_popleft(t_slist **lst);
void	ft_slist_reverse(t_slist **lst);
size_t	ft_slist_size(t_slist *lst);

#endif