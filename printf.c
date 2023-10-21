#include "main.h"

/**
 * _printf - function to print different data types
 * @format: char array
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i;
	int d;
	int char_len;
	char c;
	va_list arg;

	va_start(arg, *format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			char_len++;
		}

		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i += 1;
			char_len++;
		}

		else if (format[i + 1] == 'c')
		{
			c = va_arg(arg, int);
			_putchar(c);
			i += 1;
			char_len++;
		}

		else if (format[i + 1] == 'd')
		{
			d = va_arg(arg, int);

			if (d < 0)
			{
				_putchar('-');
				d = (-1) * d;
			}
			_putchar(d + '0');
			i += 1;
			char_len++;
		}

		else if (format[i + 1] == 's')
		{
			print_string(va_arg(arg, char *));
			i += 1;
			char_len++;
		}
	}

	va_end(arg);

	return (char_len);
}
