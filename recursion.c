/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:30:16 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:30:36 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_dups_numbers(int *arr);
int		check_columns(int *arr, int *clues);
int		check_lines(int *arr, int *clues);

int	recursion(int *arr, int digit_position, int *x_clues, int *y_clues)
{
	int	digit;

	digit = 1;
	if (digit_position == 16)
		return (0);
	while (digit <= 4)
	{
		if (!(digit_position > 0 && digit_position % 4 != 0
				&& arr[digit_position - 1] == digit))
		{
			arr[digit_position] = digit;
			if (check_dups_numbers(arr)
				&& check_columns(arr, y_clues)
				&& check_lines(arr, x_clues))
			{
				return (1);
			}
			if (recursion(arr, digit_position + 1, x_clues, y_clues) == 1)
				return (1);
		}
		digit++;
	}
	return (0);
}
