/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   ft_printf.c										:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: roperrin <roperrin@student.42.fr>	  +#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2022/11/28 23:16:34 by roperrin		#+#  #+#		  */
/*   Updated: 2022/11/29 21:10:13 by roperrin	   ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char input)
{
	char	*flag;

	flag = "csdiuxXp%";
	if (ft_strcmpchar(flag, input))
		return (1);
	return (0);
}

int	ft_print_arg(va_list *lst, const char *s, int *count)
{
	size_t	i;

	i = 1;
	if (s[i] == 'c')
		ft_putchar(va_arg(*lst, int), count);
	if (s[i] == 's')
		ft_putstr((va_arg(*lst, char *)), count);
	if (s[i] == 'i' || s[i] == 'd')
		ft_putnbr((va_arg(*lst, int)), count);
	if (s[i] == 'u')
		ft_putnbr_unsigned((va_arg(*lst, unsigned int)), count);
	if (s[i] == 'x')
		ft_putnbr_hexa(va_arg(*lst, int), 1, count);
	if (s[i] == 'X')
		ft_putnbr_hexa(va_arg(*lst, int), 2, count);
	if (s[i] == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_p(va_arg(*lst, unsigned long), count);
	}
	if (s[i] == '%')
		ft_putchar('%', count);
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	int		count;

	i = -1;
	count = 0;
	va_start(lst, str);
	while (str[++i])
	{
		if (str[i] == '%')
			if (!ft_check(str[i++]))
				return (0);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_print_arg(&lst, &str[i++], &count);
		}
		else
			ft_putchar(str[i], &count);
	}
	va_end(lst);
	return (count);
}
