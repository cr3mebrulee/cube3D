/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:27:23 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/29 10:27:54 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(len * sizeof(char));
	if (joined_str != NULL)
	{
		ft_strlcpy(joined_str, s1, (ft_strlen(s1) + 1));
		ft_strlcat(joined_str, s2, len);
	}
	return (joined_str);
}
