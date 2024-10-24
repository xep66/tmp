#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
/*
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
*/
#include <stdio.h>
#include "libft/libft.h"


typedef struct
{
	char	specifier;
	int	specifier_len;
	int	left_justify;
	int	zero_pad;
	int	width;
	int	precision;
	int	width_flag;
	int	precision_flag;
}	formatSpec;


# define SPECIFIERS	"cspiduxX%"

//			Bonus Functions
formatSpec	ft_init_formatspec(void);
int		ft_print_format(formatSpec f, va_list args);
int		ft_print_char_format(formatSpec f, va_list args);
int		ft_print_str_format(formatSpec f, va_list args);
int		ft_print_int_format(formatSpec f, va_list args);
int		ft_print_unsigned_format(formatSpec f, va_list args);
int		ft_print_hex_format(formatSpec f, va_list args);
int		ft_print_ptr_format(formatSpec f, va_list args);



//			Main functions & format specifiers
int 	ft_printf(const char *format, ...);
int 	ft_print_char(int c);
int 	ft_print_str(char *str);
int 	ft_print_int(int d);
int 	ft_print_unsigned(int n);
int 	ft_print_hex(unsigned int n, int is_upper);
int 	ft_print_ptr(unsigned long long p);
void 	ft_print_pct();




//			Helper Functions
char	*ft_strchr(const char *s, int c);
char 	*ft_utoa(unsigned int n);
//char	*ft_itoa(int n);
char 	*ft_xtoa(unsigned long n, int is_upper);
size_t	ft_utoa_len(unsigned int n);
size_t	ft_xtoa_len(unsigned int n);
// void 	ft_print_addr(unsigned long n);
// int 	ft_ptr_len(unsigned long n);
int 	ft_istype(int c);
int 	ft_isspec(int c);
int 	ft_isflag(int c);

#endif
