/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnoman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:21:43 by khnoman           #+#    #+#             */
/*   Updated: 2025/12/11 11:21:45 by khnoman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_stack
{
    int num;
    int index;
    struct s_stack  *next;
} t_stack;

char	**ft_split(char const *s, char c);
t_stack *ft_stack_new(int value);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int	ft_lstsize(t_stack *lst);
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *ptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void    swap_a(t_stack **a);
void    swap_b(t_stack **b);
void swap_a_and_b(t_stack **a, t_stack **b);
void push_a_to_b(t_stack **a, t_stack **b);
void push_b_to_a(t_stack **a, t_stack **b);
int check_valid_number(const char *str);
int check_duplicate(t_stack *stack, int number);
int check_in_range(int num);

/////////////////
void delete_first_node(t_stack **k);
void delete_last_node(t_stack **k);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
//////////////////////

void revers_rotate_a(t_stack **a);
void revers_rotate_b(t_stack **b);
void revers_rotate_a_and_b(t_stack **a, t_stack **b);
#endif
