/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 11:55:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2025-02-02 11:55:26 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	repetition(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*temp2;

	temp = a->top;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				error_program(a, b);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	is_int(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (temp->value > INT_MAX || temp->value < INT_MIN)
			error_program(a, b);
		temp = temp->next;
	}
}

int	to_int(char *arg, t_stack *a, t_stack *b)
{
	long	value;
	int		x;

	is_valid(arg, a, b);
	x = 0;
	if (arg[x] == '-' || arg[x] == '+')
		x++;
	while (arg[x] == '0' && arg[x + 1])
		x++;
	if (ft_strlen(arg + x) > 10)
		error_program(a, b);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		error_program(a, b);
	return ((int)value);
}

void	check_arguments(t_stack *a, t_stack *b)
{
	repetition(a, b);
	is_int(a, b);
}
