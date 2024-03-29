/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:02:48 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/08 00:51:25 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*laststack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	creatinback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	last = laststack(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}

void	freeallstack(t_stack **a)
{
	t_stack	*f;

	if (!(*a))
		return ;
	while (*a)
	{
		f = (*a)->next;
		free(*a);
		*a = f;
	}
}

int	stacksize(t_stack *a)
{
	int		i;
	t_stack	*c;

	if (!a)
		return (0);
	i = 0;
	c = a;
	while (c)
	{
		i++;
		c = c->next;
	}
	return (i);
}
