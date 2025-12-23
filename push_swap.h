/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:43 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/15 18:08:35 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_stack
{
	int				num;
	int				index;
	int				position;
	int				cost_b;
	int				move;
	struct s_stack	*next;
}	t_stack;

int		check_valid_number(const char *str);
int		check_duplicate(t_stack *stack, int number);
int		check_in_range(int num);
int		ft_lstsize(t_stack *lst);
int		ft_atoi(const char *ptr, int *error);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_a_and_b(t_stack **a, t_stack **b);
void	push_a_to_b(t_stack **a, t_stack **b);
void	push_b_to_a(t_stack **a, t_stack **b);
void	delete_first_node(t_stack **k);
void	delete_last_node(t_stack **k);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_a_and_b(t_stack **a, t_stack **b);
void	revers_rotate_a(t_stack **a);
void	revers_rotate_b(t_stack **b);
void	revers_rotate_a_and_b(t_stack **a, t_stack **b);
size_t	ft_strlen(const char *s);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_stack_new(int value);
//////////////
int *stack_to_array(t_stack *a,int size);
void sort_array(int *arr,int size);
int get_index(int *sort, int size, int value);
void add_index_to_node(t_stack **a);
/////////////////////
void sort2(t_stack *k);
void sort3(t_stack **k);
void sort4(t_stack **k, t_stack **l);
void sort5(t_stack **k, t_stack **l);

///////////////////////////
void fix_position(t_stack **a);
int find_best_cost(t_stack **b);
void calculate_cost_b(t_stack **b);
//////////////////////////
void check_and_push_to_b(t_stack **a,t_stack **b);
int find_target(t_stack **a, t_stack **b);
/////
void move_it_to_top(t_stack **b,t_stack **a);
#endif
