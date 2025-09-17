/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:14:54 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:54:44 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

// file_data_extraction //
int		is_texture(char *line, t_map *map);
char	*extract_information(int fd, t_map *map);

// file_validation //
int		parse(int ac, char **av, t_map *map);
int		validate_input(char *file);
int		content_validation(char *file, t_map *map);
int		extract_information(int fd, t_map *map);

// gnl //
char	*gnl(int fd);

// info_setters_utils //
int		is_texture(char *to_check);

// map_info_setters //
int		info_setter(char *info, t_map map);

// parsing_cleanup //
void	ft_free_map(t_map *map);

// parsing_errors //
void	init_error(char *str);
void	nonexistant_file(void);
void	invalid_file_type(char *str);
void	invalid_arg_count(void);

// parsing_utils //
void	ft_init_map(t_map *map);
int		ft_strcmp(char *s1, char *s2);

// texture_extraction_utils //
int		texture_setter(char *type, char *line, t_map *map);

#endif
