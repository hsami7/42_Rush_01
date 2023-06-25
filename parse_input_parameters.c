/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_parameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordeev <agordeev@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:52 by agordeev          #+#    #+#             */
/*   Updated: 2023/02/05 22:57:27 by agordeev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_x_clues(int *clues_arr, int *x_clues)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		x_clues[i] = clues_arr[i / 2 + 8];
		x_clues[i + 1] = clues_arr[i / 2 + 12];
		i += 2;
	}
}

void	fill_y_clues(int *clues_arr, int *y_clues)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		y_clues[i] = clues_arr[i / 2];
		y_clues[i + 1] = clues_arr[i / 2 + 4];
		i += 2;
	}
}

int	parse_input_parameters(char *parameters, int *x_clues, int *y_clues)
{
	int		i;
	int		j;
	char	c;
	int		clues_arr[16];

	i = 0;
	j = 0;
	while (parameters[i] != '\0' && j < 16)
	{
		c = parameters[i];
		if (c >= '0' && c <= '9')
		{
			clues_arr[j] = c - 48;
			j++;
		}
		i++;
	}
	if (j != 16)
		return (0);
	fill_x_clues(clues_arr, x_clues);
	fill_y_clues(clues_arr, y_clues);
	return (1);
}
