/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:27:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/26 14:18:44 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string s to the given file descriptor, followed by a newline.
 * 
 * @param s string to output
 * @param fd file descriptor on which to write
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (!write(fd, s, ft_strlen(s)))
		return ;
	if (write(fd, "\n", 1))
		return ;
}
