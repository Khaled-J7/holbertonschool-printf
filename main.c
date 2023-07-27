#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's test _printf with custom test cases.\n");
    _printf("Length:[%d]\n", len);

    _printf("Character: [%c]\n", 'A');
    _printf("String: [%s]\n", "Hello, World!");
    _printf("Percentage: [%%]\n");

    return (0);
}

