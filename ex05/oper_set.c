/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:13:40 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 13:36:45 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	plus(int left, int right)
{
	return (left + right);
}

int	minus(int left, int right)
{
	return (left - right);
}

int	nanoogii(int left, int right)
{
	return (left / right);
}

int	gobhagi(int left, int right)
{
	return (left * right);
}

int	nameozi(int left, int right)
{
	return (left % right);
}
