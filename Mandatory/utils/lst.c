/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:28:23 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/26 19:49:42 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*arrow;

	if (*lst == NULL)
		*lst = new;
	else
	{
		arrow = ft_lstlast(*lst);
		arrow -> next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstfree(void *stack)
{
	t_list	*arrow;

	arrow = stack;
	while (arrow)
	{		
		free(arrow);
		arrow = arrow -> next;
	}
}

void	ft_lstcreate_back(t_list **lst, void *content)
{
	t_list	*back;

	back = ft_lstnew(content);
	ft_lstadd_back(lst, back);
}

void	ft_lstcreate_front(t_list **lst, void *content)
{
	t_list	*front;

	front = ft_lstnew(content);
	ft_lstadd_front(lst, front);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*arrow;

	arrow = lst;
	if (arrow)
		while (arrow ->next != NULL)
			arrow = arrow -> next;
	return (arrow);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node->content = content;
	node->next = NULL;
	return (node);
}
