/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:50 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 18:32:53 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putnstr(char const *s, size_t n)
{
	if (!s)
		return ;
	write(1, s, n);
}

int		print_error(t_arg *arg_lst, char *new, int type)
{
	if (type)
	{
		if (type == 1)
		{
			ft_putstr("error: invalid format string'");
			ft_putstr("'\n");
		}
		free(arg_lst);
		if (type == 2)
			free(new);
	}
	return (-1);
}

int		ft_printf(char *s, ...)
{
	int		ac;
	t_arg	*arg_lst;
	int		ret;
	char	*new;
	va_list	ap;

	ac = count_args(s);
	if (!(arg_lst = (t_arg*)ft_memalloc(sizeof(t_arg) * ac)))
		return (print_error(arg_lst, NULL, 0));
	va_start(ap, s);
	ret = parse_args(s, arg_lst, ap);
	if (ret == -1)
		return (print_error(arg_lst, NULL, 1));
	if (!(new = (char*)malloc(sizeof(char) * (ret + 1))))
		return (print_error(arg_lst, new, 2));
	pop_args(s, new, arg_lst);
	ft_putnstr(new, ret);
	va_end(ap);
	free(arg_lst);
	free(new);
	return (ret);
}
