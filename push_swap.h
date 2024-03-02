/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:46:37 by zel-harb          #+#    #+#             */
/*   Updated: 2024/02/27 16:37:39 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				moves;
	struct s_list	*next;

}					t_list;
typedef struct s_para
{
	int				offset;
	int				start;
	int				the_end;
	int				mid;
}					t_para;
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				swap(t_list *stack_a);
void				sb(t_list **stack_b);
void				sa(t_list **stack_a);
void				ss(t_list **stack_a, t_list **stack_b);
void				rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				reverseRotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				push(t_list **stack_1, t_list **stack_2);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
int					is_sorted(t_list *stack);
void				ft_sort_int_tab(int *tab, int size);
int					is_sorted(t_list *stack);
int					get_max(t_list *stack);
void				mini_sort(t_list **stack, t_list **stack_b);
void				algo_sort(t_list **stack_a, t_list **stack_b,
						int size_stack);
void				full_moves(t_list **stack_a);
int					get_min(t_list *stack);
int					is_be(t_list *stack_a, int integer);
long double			ft_atoi(char *str);
void				full_array(int *table, int size, t_list *stack_a);
void				push_a_to_b(t_list **stack_a, t_list **stack_b, int *table,
						int size_stack);
void				push_b_to_a(t_list **stack_a, t_list **stack_b, int *table,
						int size_stack);
int					check_error(char **argv, int argc);
char				**ft_split(char const *s, char c);
int					ft_full(t_list **stack, char **argv, int argc);
void				full_split(t_list **stack_a, char **argv);
int					count_words(char const *s, char c);
int					check_double(t_list *stack);
size_t				ft_strlen(char *str);
int					find_max(t_list *stack, int max);
void				free_list(t_list *head);
int					ft_check_max(t_list *stack, int max);
void				ra_move(t_list **stack_a, int *table, int the_end,
						int start);
int					find_near(t_list *stack_a, int *table, int the_end,
						int start);
void				first_last(t_list **stack_a, t_list **stack_b, int max);
void				moves(t_list **stack_b, int max);
void				rest(t_list **stack_a, int *max, int *k);
void				on_stack_a(t_list **stack_a, t_list **stack_b, int *k);
char				**ft_free(char **s, int j);
int					count_words(char const *s, char c);
char				**ft_split(char const *s, char c);
void				free_t_para(t_para *ptr);
int					valide_args(char **argv, int argc);
#endif