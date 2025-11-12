/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:53:11 by tamounir          #+#    #+#             */
/*   Updated: 2024/10/27 20:47:59 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	rzlt;

	i = 0;
	sign = 1;
	rzlt = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rzlt > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		rzlt = rzlt * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(rzlt * sign));
}
