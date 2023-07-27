#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int len = 0;
    va_list args;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            write(1, format, 1); /* Print the character directly */
            len++;
        }
        else
        {
            format++; /* Move past the '%' */
            /* Handle the conversion specifier */
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                len++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    int str_len = 0;
                    while (str[str_len])
                        str_len++;

                    write(1, str, str_len);
                    len += str_len;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                len++;
            }
        }

        format++;
    }

    va_end(args);
    return len;
}

