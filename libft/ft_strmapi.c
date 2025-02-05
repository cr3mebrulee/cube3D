/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:30:32 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/29 10:30:38 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	index;
	char			*mod_str;

	len = ft_strlen(s);
	mod_str = malloc((len + 1) * sizeof (char));
	if (mod_str == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		mod_str[index] = f(index, s[index]);
		index++;
	}
	mod_str[len] = '\0';
	return (mod_str);
}
