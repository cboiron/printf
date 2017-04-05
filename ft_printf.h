/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 03:33:12 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:27:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_arg
{
	int				num_arg;
	int				flag[7];
	int				width;
	int				prec;
	int				modifier;
	char			conv;
	int				len;
	intmax_t		nb;
	char			*str;
	int				retour;
	struct s_arg	*next;
}					t_arg;

int					ft_printf(const char *str, ...);
t_arg				*ft_lst_arg(int num_arg);
void				ft_get_wide_char(t_arg **arg, wchar_t c, int *i);
void				ft_ismodifier(const char *str, int *i);
void				ft_move_minus(t_arg **arg);
void				ft_move_plus(t_arg **arg);
void				ft_move_prefix(t_arg **arg);
void				ft_move_prefix_p(t_arg **arg);
void				ft_add_prefix(t_arg **arg);
void				ft_add_arg(t_arg **liste, t_arg *new);
int					ft_is_conv(const char *str, int *i);
void				ft_flag(const char *str, int *i, t_arg **liste, int nb_prc);
int					ft_get_modifier(const char *str, int i);
int					ft_parser(const char *str, t_arg **liste);
void				ft_get_arg(t_arg **liste, int num_arg, va_list ap);
void				ft_invalid_conv(t_arg **arg);
void				ft_conv_p(t_arg **arg, va_list ap);
void				ft_conv_s(t_arg **arg, va_list ap);
void				ft_conv_c(t_arg **arg, va_list ap);
void				ft_conv_di(t_arg **arg, va_list ap);
void				ft_conv_uox(t_arg **arg, va_list ap);
void				ft_conv_b(t_arg **arg, va_list ap);
void				ft_conv_c_up(t_arg **arg, va_list ap);
void				ft_width_di(t_arg **arg);
void				ft_width_x(t_arg **arg);
void				ft_width_c(t_arg **arg);
int					ft_print_arg(t_arg *arg, int retour, const char *str,
		int i);
void				ft_apply_flags(t_arg **arg, int num_arg);
void				ft_space_flag(t_arg **arg);
void				ft_plus_flag(t_arg **arg);
char				*ft_itoa_base(long long nb, int base);
char				*ft_itoa_base_u(unsigned long long nb, int base);
void				ft_fill_with(t_arg **arg, int len, int width, int c);
void				ft_prec_di(t_arg **arg);
void				ft_prec_x(t_arg **arg);
void				ft_prec_s(t_arg **arg);
void				ft_str_capitalize(char *str);
void				ft_free_liste(t_arg **arg);
void				ft_strdel(char **as);
void				ft_memdel(void **as);
int					ft_go_to_conv(const char *str, int *i);
char				*ft_strnew(size_t size);
char				*ft_strsub(const char *str, unsigned int start, size_t len);
char				*ft_strdup(const char *src);
void				*ft_memset(void *s, int c, size_t len);
void				ft_print_list(t_arg *liste);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_len(const char *s1, const char *s2,
		int len1, int len2);
size_t				ft_strlen(const char *str);
size_t				ft_digitlen(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_putchar(int c);
void				ft_treat_perc(t_arg **arg);
#endif
