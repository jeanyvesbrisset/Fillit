/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/24 14:38:46 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fill the tetri variable of the 'index' structure passed in parameter with
** the parameter *buf.
*/

void	fill_tetri(char *buf, int index)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (i < 20)
	{
		if (buf[i] == '\n')
		{
			ft_strncpy(t_items[index].tetri[k], &buf[j], 4);
			t_items[index].tetri[k][4] = '\0';
			k++;
			i++;
			j = i;
		}
		i++;
	}
	upleft_tetri(&t_items[index].tetri);
	sharp_to_alpha(&t_items[index].tetri, index);
}

/*
** Fill the structure 'item' individually, according to the parameter 'index'
*/

void	fill_item(char *buf, int index)
{
	fill_tetri(buf, index);
	t_items[index].height = get_height(t_items[index].tetri);
	t_items[index].width = get_width(t_items[index].tetri);
}

/*
** Replace all the sharps by the letter corresponding to the given index
*/

void	sharp_to_alpha(char (*tetri)[5][5], int index)
{
	char	letter;
	int		i;
	int		j;

	letter = index + 65;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*tetri)[i][j] == '#')
			{
				(*tetri)[i][j] = letter;
			}
			j++;
		}
		i++;
	}
}
