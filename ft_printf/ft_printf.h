/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@42student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:13:48 by jihonkim          #+#    #+#             */
/*   Updated: 2022/08/27 15:15:59 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		print_chr(va_list ap);
int		print_str(va_list ap);
int		print_mem(va_list ap, const char c);
int		print_int(va_list ap, const char c);
int		print_uint(va_list ap, const char c);
int		print_hexa(va_list ap, const char c);
int		ft_strlen(char *str);
char	*get_base(const char c);
int		itoa_cnt(const char c, char *num_str, unsigned long long num, int base);
int		print_num(long long num, const char c, int base);
int		format_check(va_list ap, char c);
int		printing(va_list ap, const char *format);
int		ft_printf(const char *format, ...);

#endif
