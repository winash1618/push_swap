/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:35:04 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/26 14:16:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		c;
	char	ch;

	ch = '\0';
	if (n == -2147483647 - 1)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
		ft_putstr_fd("-", fd);
	if (n < 0)
		n = n * -1;
	c = n % 10;
	if (n > 9)
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	ch = c + '0';
	ft_putstr_fd(&ch, fd);
}
