/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:23:10 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:23:56 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	has_dups_in_lines(int *arr)
{
	int	line_idx;
	int	i;
	int	j;

	line_idx = 0;
	while (line_idx < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = i + 1;
			while (j < 4)
			{
				if (arr[line_idx * 4 + i] == arr[line_idx * 4 + j])
					return (1);
				j++;
			}
			i++;
		}
		line_idx++;
	}
	return (0);
}

int	has_dups_in_cols(int *arr)
{
	int	column_idx;
	int	i;
	int	j;

	column_idx = 0;
	while (column_idx < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = i + 1;
			while (j < 4)
			{
				if (arr[i * 4 + column_idx] == arr[j * 4 + column_idx])
					return (1);
				j++;
			}
			i++;
		}
		column_idx++;
	}
	return (0);
}

int	check_dups_numbers(int *arr)
{
	if (has_dups_in_cols(arr))
		return (0);
	if (has_dups_in_lines(arr))
		return (0);
	return (1);
}
