/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:28:59 by allallem          #+#    #+#             */
/*   Updated: 2018/02/14 17:13:37 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_my_key_event(int key, t_visu *p)
{
	if ((key == 49 && p->pause == 0) || key == 123 || key == 124)
		p->pause = 1;
	else if (key == 49 && p->pause == 1)
	{
		p->read = 0;
		p->pause = 0;
	}
	if (key == 123)
		p->read = -1;
	if (key == 124)
		p->read = 1;
	if (key == 53 || ft_game(p))
		exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_create_map(t_visu *p)
{
	int i;
	int j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			if (j % p->xmap == 0 || i % p->ymap == 0)
				ft_put_in_image(p, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

static int	ft_get_xy(t_visu *p)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(0, &str) && ft_strncmp("Plateau ", str, 7) != 0)
		free(str);
	while ((str[i] < 48 || str[i] > 57) && str[i])
		i++;
	if (str[i] >= 48 && str[i] <= 57)
		p->y = ft_atoi(str + i);
	else
		return (0);
	i += ft_sizeofint(p->y);
	while ((str[i] < 48 || str[i] > 57) && str[i])
		i++;
	if (str[i] >= 48 && str[i] <= 57)
		p->x = ft_atoi(str + i);
	else
		return (0);
	return (1);
}

int			main(void)
{
	t_visu	st;
	t_visu	*p;
	char	*str;

	p = &st;
	p->color = 0x000000;
	p->mlx = mlx_init();
	p->img = mlx_new_image(p->mlx, 1920, 1080);
	p->data = (unsigned char *)mlx_get_data_addr(p->img,
			&p->bpp, &p->size_line, &p->endian);
	p->window = mlx_new_window(p->mlx, 1920, 1080, "un boeuf");
	if (!ft_get_xy(p))
		exit(EXIT_SUCCESS);
	p->xmap = 1920 / p->x;
	p->ymap = 1080 / p->y;
	get_next_line(0, &str);
	ft_go_to_tab(str);
	ft_create_map(p);
	ft_complete_map(p, NULL);
	mlx_loop_hook(p->mlx, ft_game, p);
	mlx_key_hook(p->window, ft_my_key_event, p);
	mlx_loop(p->mlx);
	return (0);
}
