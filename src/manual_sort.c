
#include "private.h"

void	print_stack_a(t_stack *stack)
{
	unsigned int	index;

	index = 0;
	ft_printf("\nstack a: ");
	while (index != stack->stack_a.size)
	{
		ft_printf("%d	", stack->stack_a.items[get_item(
				&stack->stack_a.begin, index, stack->total_size)]);
		index++;
	}
}

void	print_stack_b(t_stack *stack)
{
	unsigned int	index;

	index = 0;
	ft_printf("\nstack b: ");
	while (index != stack->stack_a.size)
	{
		ft_printf("%d	", stack->stack_b.items[get_item(
				&stack->stack_b.begin, index, stack->total_size)]);
		index++;
	}
}

void	sort(t_stack *stack)
{
	print_stack_a(stack);
	print_stack_b(stack);
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stack_a(stack);
	print_stack_b(stack);
	rotate(stack->stack_a.size, &stack->stack_a.begin, stack->total_size);
	print_stack_a(stack);
	print_stack_b(stack);
}
