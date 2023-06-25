/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:08 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:27:12 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void);
int		parse_input_parameters(char *parameters, int *x_clues, int *y_clues);
int		recursion(int *arr, int digit_position, int *x_clues, int *y_clues);
void	print_arr(int *arr);

int	main(int args_count, char **args)
{
	int	arr[16];
	int	x_clues[8];
	int	y_clues[8];
	int	i;
	int	found;

	if (args_count != 2
		|| parse_input_parameters(args[1], x_clues, y_clues) < 1)
	{
		print_error();
		return (1);
	}
	i = 0;
	while (++i < 16)
		arr[i] = 0;
	found = recursion(arr, 0, x_clues, y_clues);
	if (found == 1)
		print_arr(arr);
	else
	{
		print_error();
		return (1);
	}
}
