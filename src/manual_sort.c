
#include "private.h"

void	print_stack_a(t_stack *stack)
{
	unsigned int	index;

	index = 0;
	ft_printf("stack a: ");
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
	ft_printf("stack b: ");
	while (index != stack->stack_b.size)
	{
		ft_printf("%d	", stack->stack_b.items[get_item(
				&stack->stack_b.begin, index, stack->total_size)]);
		index++;
	}
}

void	sort(t_stack *stack)
{
	ft_printf("CREATE STACKS\n");
	print_stack_a(stack);
	ft_printf("\n");
	print_stack_b(stack);
	ft_printf("\n");

	ft_printf("PUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stack_a(stack);
	ft_printf("\n");
	print_stack_b(stack);
	ft_printf("\n");

	ft_printf("PUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stack_a(stack);
	ft_printf("\n");
	print_stack_b(stack);
	ft_printf("\n");

	ft_printf("PUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stack_a(stack);
	ft_printf("\n");
	print_stack_b(stack);
	ft_printf("\n");
}
