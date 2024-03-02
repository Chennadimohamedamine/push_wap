/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:13:22 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/02 05:31:48 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack    *laststack(stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}
void	creatinback(stack **lst,stack *new)
{
	stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	last = laststack(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}
void    freeallstack(stack **a)
{
    stack *f;
    while (*a)
    {
      f = (*a)->next;
      free(*a);
      *a = f;
    }
}
int	stacksize(stack *a)
{
	int		i;
	stack	*c;

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