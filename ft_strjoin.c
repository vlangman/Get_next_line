/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 09:16:33 by vlangman          #+#    #+#             */
/*   Updated: 2017/06/08 10:30:28 by vlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (s2 == NULL)
		return ((char*)s1);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = ft_memalloc(i);
	if (str == NULL)
		return (NULL);
	str = ft_strcat((char*)s1, s2);
	return (str);
}
