/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 02:59:11 by fberger           #+#    #+#             */
/*   Updated: 2019/03/06 03:21:01 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../includes/t_options.h"
#include "../includes/t_functions_pointers.h"
#include "../includes/functions.h"

t_functions_pointers	fp[NB_ACCEPTED_OPTIONS] =
{
	{'c', &ft_printf_char}, // ok,
	//{'C', &print_char},
	{'s', &ft_printf_string}, // ok
	//{'S', &print_unicode_string},
	{'p', &ft_printf_base},
	//{'r', &print_string},
	{'d', &ft_printf_integer},
	//{'D', &print_integer},
	{'i', &ft_printf_integer},
	{'o', &ft_printf_base},
	//{'O', &print_base},
	{'u', &ft_printf_base},
	{'U', &ft_printf_base},
	{'x', &ft_printf_base},
	{'X', &ft_printf_base},
	{'b', &ft_printf_base},
	{'f', &ft_printf_floats},
	//{'F', &print_floats},
	{'%', &ft_printf_modulo},
};

// fonction qui renvoie vers la bonne fonction selon le type du %
int		root_options_printers(t_options *option, va_list *args)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < NB_ACCEPTED_OPTIONS)
	{
		if (fp[i].option == option->type)
		{
		//	printf("option is %c | g_func[%i].spec is %c\n", option->type, i, fp[i].option);
			if ((ret = fp[i].function(option, args)) == -1)
				return (-1);
//	printf("////// RET IN ROOTER FUNCTION %d ////////\n\n", ret);
			return (ret);
		}
		i++;
	}
	return (0);
}

/*
void print_t_options_list(t_options **options)
{
	int i = 0;
	t_options	*option;

	option = *options;
	while (option != NULL && ++i)
	{
		printf("\n******* option(f[%i]) *****\n", i);
		printf("1. o->type         = %c\n", option->type);
		printf("2. o->flags        = %s\n", option->flags);
		printf("3. o->flen         = %i\n", option->flen);
		printf("4. o->fpos         = %i\n", option->fpos);
		printf("5. o->left_justify = %i\n", option->left_justify);
		printf("6. o->sign         = %i\n", option->sign);
		printf("7. o->space        = %i\n", option->space);
		printf("8. o->hashtag      = %i\n", option->hashtag);
		printf("9. o->left_zeros   = %i\n", option->left_zeros);
		printf("10 o->pad_deux       = %i\n", option->pad_deux);
		printf("11 o->h            = %i\n", option->h);
		printf("12 o->hh           = %i\n", option->hh);
		printf("13 o->l            = %i\n", option->l);
		printf("14 o->ll           = %i\n", option->ll);
		printf("15 o->L            = %i\n", option->L);
		printf("**********  end ***********\n\n");
		option = option->next;
	}
}*/

void print_t_option(t_options **option)
{
	t_options	*o;

	o = *option;
	printf("\n******* option(f[%i]) *****\n", o->fpos);
	printf("1. type          = %c\n", o->type);
	printf("2. flags         = %s\n", o->flags);
	printf("3. flen          = %i\n", o->flen);
	printf("4. fpos          = %i\n", o->fpos);
	printf("5. left_justify  = %s\n", o->left_justify ? "1" : ".");
	printf("6. sign          = %s\n", o->sign ? "1" : ".");
	printf("7. space         = %s\n", o->space ? "1" : ".");
	printf("8. hashtag       = %s\n", o->hashtag ? "1" : ".");
	printf("9. left_zeros    = %s\n", o->left_zeros ? "1" : ".");
	printf("10 point         = %s\n", o->point ? "1" : ".");
	printf("11 neg           = %s\n", o->neg ? "1" : ".");
	printf("12 pad_un        = %i\n", o->pad_un);
	printf("13 pad_deux      = %i\n", o->pad_deux);
	printf("14 h             = %s\n", o->h ? "1" : ".");
	printf("15 hh            = %s\n", o->hh ? "1" : ".");
	printf("16 l             = %s\n", o->l ? "1" : ".");
	printf("17 ll            = %s\n", o->ll ? "1" : ".");
	printf("18 L             = %s\n", o->L ? "1" : ".");
	printf("19 j             = %s\n", o->j ? "1" : ".");
	printf("20 z             = %s\n", o->z ? "1" : ".");
	printf("21 sign_is_print = %s\n", o->sign_is_print ? "1" : ".");
	printf("**********  end  **********\n\n");
}
/*
 ** la petite -------------------------------------------------------------------
 */

int		no_opts_prntrs(t_options *options, const char *format, const int len)
{
	static int		idx = 0;
	int				ret;

	ret = options != NULL ? options->index - idx : len - idx;
	if (format + idx)
		write(1, format + idx, ret);
	idx += ret;
	if (options != NULL)
		idx += options->flen + 1;
	else
		idx = 0;
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_options	*options;
	t_options	*option;
	const int	formatlen = ft_strlen(format);
	int			ret;

	if (format == NULL)
	{
		ret = ft_printf_string(NULL, NULL);
		return (ret);
	}
	options = NULL;
//	printf("\n------- BUILDING LIST ---------\n");
	if (extract_options(format, &options) == -1)
	{
//		printf("RET -1 = LIST TO BE CLEAR\n");
		//options_lst_clear(spec);
		return (-1);
	}
//	printf("------- OK LIST ---------------\n");
	va_start(args, format);
	option = options;
	ret = 0;
//	printf("------- START FT_PRINTF -------\n\n");
	while (option != NULL)
	{
    // print_t_option(&option);
	  // if (option->type == 'd' || option->type == 'i' || option->type == 'x' || option->type == 'X')
	  // {
	  // 	printf("nb pad before      1.%d.%d.%d.%d\n", option->left_justify ? 1 : 2, option->pad_un ? 1 : 2, option->pad_deux ? 1 : 2, option->left_zeros ? 1 : 2);
	  // 	printf("nb pad after       2.%d.%d.%d.%d\n", option->left_justify ? 1 : 2, option->left_zeros ? 1 : 2, option->pad_un ? 1 : 2, option->pad_deux ? 1 : 2);
	  // 	printf("print ' ' pad bef  3.a faire\n");
	  // 	printf("print ' ' pad aft  4.a faire\n");
	  // 	printf("print '0' pad bef  5.%d.%d.%d\n", option->pad_deux ? 1 : 2, option->pad_un ? 1 : 2, option->left_zeros ? 1 : 2);
	  // 	printf("print '0' pad aft  6.%d.%d.%d\n\n", option->pad_deux ? 1 : 2, option->pad_un ? 1 : 2, option->left_zeros ? 1 : 2);
	  // }
	  // if (option->type == 's')
	  // {
		//  printf("nb pad before    1.%d.%d.%d.%s.%d\n", option->left_justify ? 1 : 2, option->point ? 1 : 2, option->pad_deux ? 1 : 2, "x", option->left_zeros ? 1 : 2);
		//  printf("nb pad after     2.%d.%d.%d.%s.%d\n\n", option->left_justify ? 1 : 2, option->point ? 1 : 2, option->pad_deux ? 1 : 2, "x", option->left_zeros ? 1 : 2);
	  // }
		ret += no_opts_prntrs(option, format, formatlen);
//	printf("////// RET IN MAIN_mid_while FUNCTION %d ////////\n\n", ret);
		ret += root_options_printers(option, &args);
//	printf("////// RET IN MAIN_end_while FUNCTION %d ////////\n\n", ret);
		option = option->next;
	}
	ret += no_opts_prntrs(NULL, format, formatlen);
//	printf("////// RET IN MAIN FUNCTION %d ////////\n\n", ret);
	va_end(args);
	return (ret);
}
