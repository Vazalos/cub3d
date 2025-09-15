/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:33:01 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/15 16:31:49 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_argb_to_hex(unsigned int a, unsigned int r,
	unsigned int g, unsigned int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

unsigned int	ft_hex_to_alpha(unsigned int hex)
{
	return ((hex >> 24) & 0xFF);
}

unsigned int	ft_hex_to_red(unsigned int hex)
{
	return ((hex >> 16) & 0xFF);
}

unsigned int	ft_hex_to_green(unsigned int hex)
{
	return ((hex >> 8) & 0xFF);
}

unsigned int	ft_hex_to_blue(unsigned int hex)
{
	return (hex & 0xFF);
}
