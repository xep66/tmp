#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char    *ptr;

    ptr = s;
    if (!ptr || n == 0)
        return ;
    while (n--)
        *ptr++ = '\0';
}
