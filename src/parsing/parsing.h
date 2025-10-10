/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:14:54 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/09 17:18:17 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

typedef struct s_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	floor;
	unsigned int	ceiling;
	char			**map;
	double			playersx;
	double			playersy;
	char			playero;
	int				*max_x;
} t_map;

// file_data_extraction //
int		is_map(char **info, t_map *map);
int		is_scene(char *line, t_map *map);
int		is_texture(char *line, t_map *map);
char	*extract_information(int fd);

// file_validation //
int		parse(int ac, char **av, t_map *map);
int		validate_input(char *file);
int		content_validation(char *file, t_map *map);

// gnl //
char	*gnl(int fd);

// map_extraction_utils //
int		is_map_char(int to_check);
int		fill_map(char **info, t_map *map);

// map_validation.c//
int		check_map(t_map *map);

// map_info_setters //
int		info_setter(char *info, t_map *map);

// parsing_cleanup //
void	ft_free_map(t_map *map);

// parsing_errors\2 //
void	invalid_rgb_val(char *value);
void	init_error(char *str);
void	nonexistant_file(void);
void	invalid_file_type(char *str);
void	invalid_arg_count(void);
void	missing_info(void);
void	map_error(void);

// parsing_utils //
void	max_x_setter(t_map *map);
int		is_spawn_point(char to_check);
void	ft_init_map(t_map *map);
int		ft_strcmp(char *s1, char *s2);

// scene_extraction_utils //
int		scene_setter(char *type, char *values, t_map *map);

// texture_extraction_utils //
int		texture_setter(char *type, char *line, t_map *map);

#endif
