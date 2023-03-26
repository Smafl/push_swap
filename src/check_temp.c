
#include "private.h"

static void	print_stacks(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	ft_printf("stack a:	");
	while (i != stack->total_size)
	{
		ft_printf("%d, %u	", stack->stack_a.items[i], stack->stack_a.begin);
		i++;
	}
	ft_printf("size a: %u", stack->stack_a.size);
	ft_printf("\nstack b:	");
	i = 0;
	while (i != stack->total_size)
	{
		ft_printf("%d, %u	", stack->stack_b.items[i], stack->stack_b.begin);
		i++;
	}
	ft_printf("size b: %u", stack->stack_b.size);
}

static void	check_swap(t_stack *stack)
{
	ft_printf("\n\nSWAP a\n");
	swap(stack->stack_a.items, stack->stack_a.size,
		stack->stack_a.begin, stack->total_size);
	print_stacks(stack);
}

static void	check_swap_both(t_stack *stack)
{
	ft_printf("\n\nSWAP BOTH\n");
	swap_both(stack);
	print_stacks(stack);
}

static void	check_push_b(t_stack *stack)
{
	ft_printf("\n\nPUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
	ft_printf("\n\nPUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
	// ft_printf("\n\nPUSH b\n");
	// push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	// print_stacks(stack);
}

static void	check_push_a(t_stack *stack)
{
	ft_printf("\n\nPUSH a\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
}

static void	check_push_both(t_stack *stack)
{
	ft_printf("\n\nPUSH BOTH\n");
	push_both(stack);
	print_stacks(stack);
}

static void	check_rotate(t_stack *stack)
{
	ft_printf("\n\nROTATE b\n");
	rotate(stack->stack_b.size, &stack->stack_b.begin, stack->total_size);
	print_stacks(stack);
	// ft_printf("\n\nROTATE b\n");
	// rotate(stack->stack_b.size, &stack->stack_b.begin, stack->total_size);
	// print_stacks(stack);
	// ft_printf("\n\nROTATE BOTH\n");
	// rotate_both(stack);
	// print_stacks(stack);
}

static void	check_rev_rotate(t_stack *stack)
{
	ft_printf("\n\nreverse ROTATE b\n");
	rev_rotate(stack->stack_b.size, &stack->stack_b.begin, stack->total_size);
	print_stacks(stack);
	ft_printf("\n\nreverse ROTATE b\n");
	rev_rotate(stack->stack_b.size, &stack->stack_b.begin, stack->total_size);
	print_stacks(stack);
	ft_printf("\n\nreverse ROTATE BOTH\n");
	rev_rotate_both(stack);
	print_stacks(stack);
}

void	check_all_temp(t_stack *stack)
{
	print_stacks(stack);
	check_swap(stack);
	check_push_b(stack);
	check_swap_both(stack);
	check_push_a(stack);
	check_push_both(stack);
	check_rotate(stack);
	check_rev_rotate(stack);
	check_rotate(stack);
	check_rev_rotate(stack);
}
