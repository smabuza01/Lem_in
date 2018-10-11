/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabuza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 08:13:20 by smabuza           #+#    #+#             */
/*   Updated: 2018/08/24 08:13:45 by smabuza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	void	*i;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	i = mem;
	ft_memset(mem, 0, size);
	return (mem);
}
