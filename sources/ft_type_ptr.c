#include "../includes/ft_printf.h"

static int	ft_output_ptr(char *ptr, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	count += ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_write_right_left(flags.dot, len, 1);
		count += ft_putstr(ptr, flags.dot);
	}
	else
		count += ft_putstr(ptr, len);
	return (count);
}

int			ft_type_ptr(unsigned long long nbr, t_flags flags)
{
	size_t	len;
	char	*ptr;
	int		count;

	count = 0;
	if (nbr == 0 && flags.dot == 0)
	{
		count += ft_write_right_left(flags.width, 2, 0);
		count += ft_putstr("0x", 2);
		return (count);
	}
	if (nbr == 0 && flags.dot >= 0)
		flags.width -= 1;
	ptr = ft_nbr_to_hex(nbr);
	ptr = ft_str_tolower(ptr);
	len = ft_strlen(ptr);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_output_ptr(ptr, flags, len);
	count += ft_write_right_left(flags.width, len + 2, 0);
	if (flags.minus == 0)
		count += ft_output_ptr(ptr, flags, len);
	free(ptr);
	return (count);
}
