/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:55:40 by anporced          #+#    #+#             */
/*   Updated: 2023/12/13 18:46:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "textures.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <time.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define TILE_SIZE 64

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct	s_axes
{
	int			x;
	int			y;
}				t_axes;

typedef struct	s_player {
	t_axes				axes;
	int					stone;
	unsigned int		moves;

}						t_player;

typedef struct	s_enemies {
	t_axes				axes;
	int					stone;
	unsigned int		moves;

}						enemies;

typedef struct	s_wallsngrounds {
	t_axes	axes;
	int		stone;

}			t_wallsngrounds;

typedef struct s_img {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_assets {
	t_img	**player;
	t_img	**enemies;
	t_img	**wallsngrounds;
}			t_assets;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			img_width;
	int			img_height;
	t_img		img;
	t_axes		axes;
	t_assets	assets;
}			t_data;

int		hook_switch(int keycode, t_data *data);
// void	quit(t_data *data);
int		key_press(int keycode, t_data *data);
void	malloc_evolis(t_data *data);
char	**init_evolis_path(t_data *data);
void	init_evolis(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
char	*path_creator(char *pokemon, int i);

void	malloc_enemies(t_data *data);
char	**init_enemies_path(t_data *data);
void	init_enemies(t_data *data);

void	malloc_wallsngrounds(t_data *data);
char	**init_wallsngrounds_path(t_data *data);
void	init_wallsngrounds(t_data *data);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif

#endif
