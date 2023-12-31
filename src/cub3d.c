/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:18:15 by vchizhov          #+#    #+#             */
/*   Updated: 2023/07/31 17:19:38 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_name_file(char *av)
{
	size_t	len;
	char	*tmp;

	tmp = av;
	len = ft_strlen(tmp);
	if (ft_strncmp(&tmp[len - 4], ".cub", len))
		print_error("Format of file is not valid", 1);
}

int	main(int ac, char **av)
{
	t_game	info;

	if (ac != 2)
		print_error("Many arguments", 1);
	check_name_file(av[1]);
	init_info(&info);
	parsing_file(av[1], &info, 0, 0);
	init_window_with_map(&info);
}
