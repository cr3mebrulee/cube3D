/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:29 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/29 10:31:37 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	int_len(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	long long		num;
	char			*int_str;

	num = n;
	len = int_len(num);
	int_str = malloc((len + 1) * sizeof (char));
	if (int_str != NULL)
	{
		if (num < 0)
		{
			int_str[0] = '-';
			num = -num;
		}
		if (num == 0)
			int_str[0] = '0';
		int_str[len] = '\0';
		while (num != 0)
		{
			int_str[len - 1] = (num % 10) + '0';
			num = num / 10;
			len--;
		}
	}
	return (int_str);
}
