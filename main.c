#include "main.h"

int main(void)
{
    int len;

    len = _printf("Char: %c\nString: %s\nPercent: %%\nInt: %d, %i\n", 'A', "Hello", 123, -456);
    _printf("Length: %d\n", len);

    return 0;
}
