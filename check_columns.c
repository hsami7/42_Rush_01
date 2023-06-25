/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_columns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:21:50 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:22:13 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_columns_from_top(int *arr, int column_index, int clue)
{
	int	digit_index;
	int	score;
	int	max;
	int	current_number_index;
	int	current_number;

	digit_index = 0;
	score = 0;
	max = 0;
	while (digit_index < 4)
	{
		current_number_index = digit_index * 4 + column_index;
		current_number = arr[current_number_index];
		if (current_number > max)
		{
			max = current_number;
			score++;
		}
		digit_index++;
	}
	return (score == clue);
}

int	check_columns_from_bottom(int *arr, int column_index, int clue)
{
	int	digit_index;
	int	score;
	int	max;
	int	current_number_index;
	int	current_number;

	digit_index = 3;
	score = 0;
	max = 0;
	while (digit_index >= 0)
	{
		current_number_index = digit_index * 4 + column_index;
		current_number = arr[current_number_index];
		if (current_number > max)
		{
			max = current_number;
			score++;
		}
		digit_index--;
	}
	return (score == clue);
}

int	check_columns(int *arr, int *clues)
{
	int	i;
	int	a;
	int	b;
	int	clues_score;

	i = 3;
	clues_score = 0;
	while (i >= 0)
	{
		a = clues[i * 2 + 0];
		b = clues[i * 2 + 1];
		if (check_columns_from_top(arr, i, a))
			clues_score++;
		if (check_columns_from_bottom(arr, i, b))
			clues_score++;
		i--;
	}
	return (clues_score == 8);
}
