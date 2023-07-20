/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:38:45 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 13:59:04 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft.h"

void	print_error(char c)
{
	if (c == '/')
		write(1, "Stop : division by zero\n", 24);
	if (c == '%')
		write(1, "Stop : modulo by zero\n", 22);
}

void	calc_and_print(char oper, int left, int right, int(*ptr[5])(int, int))
{	
	int	result;

	result = 0;
	if (oper == '+')
		result = ptr[0](left, right);
	if (oper == '-')
		result = ptr[1](left, right);
	if (oper == '/')
		result = ptr[2](left, right);
	if (oper == '*')
		result = ptr[3](left, right);
	if (oper == '%')
		result = ptr[4](left, right);
	ft_putnbr(result);
}

int	oper_check(char *str)
{
	if (str[0] != '+' && str[0] != '-' && str[0] != '*'
		&& str[0] != '/' && str[0] != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (str[1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	(*fptr[5])(int, int);
	int	right;
	int	left;

	fptr[0] = plus;
	fptr[1] = minus;
	fptr[2] = nanoogii;
	fptr[3] = gobhagi;
	fptr[4] = nameozi;
	if (argc != 4)
		return (0);
	if (oper_check(argv[2]) == 0)
		return (0);
	left = ft_atoi(argv[1]);
	right = ft_atoi(argv[3]);
	if (right == 0 && (argv[2][0] == '%' || argv[2][0] == '/'))
	{
		print_error(argv[2][0]);
		return (0);
	}
	calc_and_print(argv[2][0], left, right, fptr);
}
