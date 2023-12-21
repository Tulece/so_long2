/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:48:31 by anporced          #+#    #+#             */
/*   Updated: 2023/12/21 12:32:08 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_evolis(t_data *data)
{
	data->assets.player = (t_img **)malloc(sizeof(t_img *) * 8);
	data->assets.player[0] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[1] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[2] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[3] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[4] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[5] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[6] = (t_img *)malloc(sizeof(t_img) * 8);
	data->assets.player[7] = (t_img *)malloc(sizeof(t_img) * 8);
}

char	**init_evolis_path(t_data *data)
{
	char	**evopaths;

	evopaths = malloc(sizeof( char *) * 9);
	evopaths[0] = ft_strdup(evoli_);
	evopaths[1] = ft_strdup(pyroli_);
	evopaths[2] = ft_strdup(voltali_);
	evopaths[3] = ft_strdup(aquali_);
	evopaths[4] = ft_strdup(mentali_);
	evopaths[5] = ft_strdup(phyllali_);
	evopaths[6] = ft_strdup(givrali_);
	evopaths[7] = ft_strdup(noctali_);
	return (evopaths);
}

void	init_evolis(t_data *data)
{
	int		i;
	int		j;
	char 	*str;
	char	*evolition;
	int		w;
	int		h;
	char 	**evopaths;

	i = 0;
	evopaths = init_evolis_path(data);
	while (i < 8)
	{
		j = 0;
		evolition = evopaths[i];
		while (j < 8)
		{
			str = path_creator(evolition, j);
			data->assets.player[i][j].img = mlx_xpm_file_to_image(data->mlx, str, &w, &h);
			data->assets.player[i][j].path = str;
			j++;
		}
		i++;
	}
}

// void	render(t_data *data, , t_axes src_pos, t_axes dest_pos);

void	anime(t_data *data)
{
	if (data->clock != 15)
		data->clock++;
	else
	{
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
	}
//	print_img(data, data->assets.textures[0].img, data->src_pos);
	player_finder(data);
	printf("player.state = %d\n", data->player.state);
	overlay_img(data->assets.player[data->player.state][data->direction + data->frame], data->assets.textures[0], data, data->p_pos);
}

char	*path_creator(char *pokemon, int i)
{
	char 	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(pokemon, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}
