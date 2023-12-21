/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:57:03 by anporced          #+#    #+#             */
/*   Updated: 2023/12/20 17:19:32 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	data_init(t_data *data)
{
	//data->win = NULL;
	//data->map = NULL;
	//data->map_dim.x = 0;
	//data->map_dim.y = 0;
	// data->nb_diamond = 0;
	// data->count = 0;
	data->p_pos.x = 0;
	data->p_pos.y = 0;
	//data->c_pos = NULL;
	//data->z_pos = NULL;
	data->clock = 0;
	data->frame = 0;
	data->direction = 0;
	data->src_pos.x = 0;
	data->src_pos.y = 0;
	data->player.state = 0;
}
