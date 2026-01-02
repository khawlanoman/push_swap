
#include "push_swap.h"

void	print_error_and_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_exit_on_error(t_stack **a, t_stack **b, char **split)
{
	free_split(split);
	print_error_and_exit(a, b);
}

int	is_valid_argument(char *str, t_stack *stack)
{
	int		error;
	long	num;

	num = ft_atoi(str, &error);
	if (error)
		return (0);
	if (!check_valid_number(str))
		return (0);
	if (!check_duplicate(stack, (int)num))
		return (0);
	return (1);
}

void	add_number_to_stack(t_stack **a, int value, int *position)
{
	t_stack	*new;

	new = ft_stack_new(value);
	if (!new)
		print_error_and_exit(a, NULL);
	new->position = (*position)++;
	ft_lstadd_back(a, new);
}
