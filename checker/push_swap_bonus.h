/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:43:29 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/26 18:44:08 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

void				pa_bonus(t_list **stack_a, t_list **stack_b);
void				pb_bonus(t_list **stack_b, t_list **stack_a);
void				rra_bonus(t_list **stack_a);
void				rrb_bonus(t_list **stack_b);
void				rrr_bonus(t_list **stack_a, t_list **stack_b);
void				ra_bonus(t_list **stack_a);
void				rb_bonus(t_list **stack_b);
void				rr_bonus(t_list **stack_a, t_list **stack_b);
void				sa_bonus(t_list **stack_a);
void				sb_bonus(t_list **stack_b);
void				ss_bonus(t_list **stack_a, t_list **stack_b);

void				ft_putstr_fd_bonus(char *s, int fd);
int					ft_full_bonus(t_list **stack, char **argv, int argc);

t_list				*ft_lstnew_bonus(int content);
void				ft_lstadd_back_bonus(t_list **lst, t_list *new);
void				ft_lstadd_front_bonus(t_list **lst, t_list *new);
t_list				*ft_lstlast_bonus(t_list *lst);
int					ft_lstsize_bonus(t_list *lst);
void				ft_lstadd_front_bonus(t_list **lst, t_list *new);
int					check_error_bonus(char **argv, int argc);
int					check_double_bonus(t_list *stack);
size_t				ft_strlen_bonus(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *s, int c);
char				*get_next_line(int fd);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
long double			ft_atoi_bonus(char *str);
void				displaylist_list(t_list *current);
void				free_list(t_list *head);
void				full_split(t_list **stack_a, char **argv);
char				**ft_free(char **s, int j);
int					count_words(char const *s, char c);
char				**ft_split(char const *s, char c);
int					check_non_number(char **argv, int argc);
int					valide_args_bonus(char **argv, int argc);
int					ft_push(t_list **stack_a, t_list **stack_b);
int					ft_strcmp(char *s1, char *name_moves);
#endif
