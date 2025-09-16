/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:14:43 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:15 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *message)
{
	ft_putendl_fd((char *)message, 2);
	exit(1);
}

void	print_error(const char *message)
{
	ft_putendl_fd((char *)message, 2);
}
