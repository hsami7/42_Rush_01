/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:24:40 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:24:59 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line_left_right(int *arr, int line_index, int clue)
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
		current_number_index = line_index * 4 + digit_index;
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

int	check_line_right_left(int *arr, int line_index, int clue)
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
		current_number_index = line_index * 4 + digit_index;
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

int	check_lines(int *arr, int *clues)
{
	int	i;
	int	a;
	int	b;
	int	clues_score;

	clues_score = 0;
	i = 3;
	while (i >= 0)
	{
		a = clues[i * 2 + 0];
		b = clues[i * 2 + 1];
		if (check_line_left_right(arr, i, a))
			clues_score++;
		if (check_line_right_left(arr, i, b))
			clues_score++;
		i--;
	}
	return (clues_score == 8);
}
