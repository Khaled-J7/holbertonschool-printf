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
    va_list args;
    int len = 0;
    int str_len = 0;

    if (format == NULL)
        return -1;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1); /* Print the character directly */
            len++;
        }
        else
        {
            format++; /* Move past the '%' */

            if (*format == 'c')
            {
                /* Print a character */
                char c = va_arg(args, int);
                write(1, &c, 1);
                len++;
            }
            else if (*format == 's')
            {
                /* Print a string */
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";

                
                while (str[str_len])
                    str_len++;

                write(1, str, str_len);
                len += str_len;
            }
            else if (*format == '%')
            {
                /* Print a '%' character */
                write(1, format, 1);
                len++;
            }
            else
            {
                /* Invalid conversion specifier, print '%' and the character */
                write(1, "%", 1);
                write(1, format, 1);
                len += 2;
            }
        }

        format++;
    }

    va_end(args);
    return len;
}

