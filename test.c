#include "ft_printf.h"

/*
Variadic function only work with a function with ellipsis comment.
The library allows va_list, va_start, va_arg, var_copy, and va_end to be used.

*/

void test_put_char(int c, ...)
{
	va_list ptr;
	char    a;

	va_start(ptr, c);
	/*
	if there's no va_start --> result segmentation fault
	since the program tries to access a thing that doesn not exist
	*/
	a = va_arg(ptr, int); // no need to expressively convert the type, but it's a good practice
	// no need to expressively convert the type, but it's a good practice
	// a = va_arg(ptr, int); // move through the list by using va_arg again.
	write(1, &a, 1);
	write(1, "\n", 1);
	va_end(ptr); // va_end is used before returing the fuction so that it the result won't be undefined
}

void	test_put_str(int c, ...)
{
	va_list	ptr;
	int	i;
	char	a;

	va_start(ptr, c);
	i = 0;
	while (i < c)
	{
		a = va_arg(ptr, int); // when this line is called again. It's similar to index++ in loop;
		write(1, &a, 1);
		i++;
	}
	va_end(ptr);
}

// int main(void)
// {
// 	test_put_char(1, 'a');
// 	// test_put_char(1, 'a', 'b');
// 	test_put_str(2, 'h', 'e');
// 	printf("\n%lu", 123ul);
// }
