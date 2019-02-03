#ifndef FUNCTIONS_H
# define FUNCTIONS_H


# include "../3.Libft/libft.h"
# include "t_functions_pointers.h"

t_options			*create_new_option(const char *format, int i);
void				push_back_new_option(t_options **latest_opt, t_options *n);
int					helper_print_nb_padding(t_options *o, int l, int a, int n);
int					helper_print_str_padding(t_options *opt, int ln, int aftr);
int					compute_new_option_len_in_format(const char *formt, int i);
int					ft_strchr_modified(const char *s, int c);
int					ft_strstr_modified(const char *m, const char *a);
int					get_base(t_options *option);
int					ft_printf_base(t_options *option, va_list *args);
int					ft_printf_char(t_options *option, va_list *args);
int					ft_printf_string(t_options *option, va_list *args);
int					ft_printf_floats(t_options *option, va_list *args);
int					ft_printf_integer(t_options *option, va_list *args);
int					ft_printf_modulo(t_options *option, va_list *args);
int					ft_print_str_ret(char *str);
int					ft_putchar_ret(char c);

int					extract_options(const char *format, t_options **options);

void 				print_t_options_list(t_options **options);
void 				print_t_option(t_options **option);

long long			get_type(t_options *option, va_list *args);
int					ft_printf(const char *format, ...);

#endif
