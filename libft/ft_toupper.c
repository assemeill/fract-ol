/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:23:25 by aszhilki          #+#    #+#             */
/*   Updated: 2019/09/24 13:15:42 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int arg)
{
	if (arg != '\0')
	{
		if (arg > 96 && arg < 123)
			arg = arg - 32;
	}
	return (arg);
}
