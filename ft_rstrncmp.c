/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:58 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/08/06 16:39:22 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// revisar si la funcion está bien.
int	ft_rstrncmp(const char *str1, const char *str2, size_t n)
{
	size_t	len_str1;
	size_t	len_str2;
	
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	
	while (n > 0)
	{
		char	s1;
		char	s2;
	
		if(len_str1 > n)
			s1 = str1[len_str1 - n];
		else
			s1 = '\0';
		if(len_str2 > n)
			s2 = str2[len_str2 - n];
		else
			s2 = '\0';
		if (s1 != s2)
			return ((unsigned char)s1 - (unsigned char)s2);
		n--;
	}
	return (0);
}
