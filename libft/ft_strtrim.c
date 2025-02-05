/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:35:27 by dbisko            #+#    #+#             */
/*   Updated: 2023/11/29 10:35:32 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*trimmed_str;
	int			trim_start;
	int			trim_end;

	trim_start = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[trim_start] != '\0' && char_in_set(s1[trim_start], set) == 1)
		trim_start++;
	trim_end = ft_strlen(s1) - 1;
	while (trim_end > trim_start && char_in_set(s1[trim_end], set) == 1)
		trim_end--;
	if (trim_start > trim_end)
		return (ft_strdup(""));
	trimmed_str = malloc((trim_end - trim_start + 2) * sizeof(char));
	if (trimmed_str != NULL)
		ft_strlcpy(trimmed_str, s1 + trim_start, (trim_end - trim_start + 2));
	return (trimmed_str);
}
