void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;
	int		size_b;
	int		size_a;

	size_b = lst_length(*stack_b);
	size_a = lst_length(*stack_a);
	cheapest_node = get_cheapest_node(*stack_a);
	while (*stack_a != cheapest_node || *stack_b != cheapest_node->target_node)
	{
		if (cheapest_node->position < size_a / 2 && \
			cheapest_node->target_node->position < size_b / 2)
			go_rr_ra_rb(stack_a, stack_b, cheapest_node);
		else if (cheapest_node->position >= size_a / 2 && \
			cheapest_node->target_node->position >= size_b / 2)
			go_rrr(stack_a, stack_b, cheapest_node);
		else if (cheapest_node->position < size_a / 2 && \
			cheapest_node->target_node->position >= size_b / 2)
			go_ra_rrb(stack_a, stack_b, cheapest_node);
		else
			go_rra_rb(stack_a, stack_b, cheapest_node);
	}
	pb(stack_a, stack_b);
}
void	go_ra_rrb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node)
		ra (stack_a);
	while (*stack_b != cheapest_node->target_node)
		rrb(stack_b);
}

void	go_rra_rb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node)
		rra (stack_a);
	while (*stack_b != cheapest_node->target_node)
		rb(stack_b);
}
void	go_rr_ra_rb(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rr(stack_a, stack_b);
	while (*stack_a != cheapest_node)
		ra(stack_a);
	while (*stack_b != cheapest_node->target_node)
		rb(stack_b);
}

void	go_rrr(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rrr(stack_a, stack_b);
	while (*stack_a != cheapest_node)
		rra(stack_a);
	while (*stack_b != cheapest_node->target_node)
		rrb(stack_b);
}

void	target_for_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*b_current;
	t_node	*target_node;
	long	close_smaller_index;

	while (stack_a)
	{
		close_smaller_index = LONG_MIN;
		b_current = stack_b;
		while (b_current)
		{
			if (b_current->index < stack_a->index && \
			b_current->index > close_smaller_index)
			{
				close_smaller_index = b_current->index;
				target_node = b_current;
			}
			b_current = b_current->next;
		}
		if (close_smaller_index == LONG_MIN)
			stack_a->target_node = find_max_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	initialize_positions_a(t_node *stack, int *position_a, int *position_b)
{
	*position_b = stack->target_node->position;
	*position_a = stack->position;
}

void	calculate_push_cost_a( t_node *stack_a, t_node *stack_b, \
					int *position_a, int *position_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_length(stack_a);
	len_b = lst_length(stack_b);
	if (*position_a >= len_a / 2)
	{
		if (*position_b >= len_b / 2)
		{
			if (stack_a->index < stack_b->index)
				stack_a->push_cost = len_a - *position_a;
			else
				stack_a->push_cost = len_b - *position_b;
		}
		else
			stack_a->push_cost = (len_b - *position_b) + *position_a;
	}
	else
		calc_push_cost_above_a(stack_a, stack_b, position_a, position_b);
}

void	calc_push_cost_above_a(t_node *stack_a, t_node *stack_b, int *position_a, int *position_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_length(stack_a);
	len_b = lst_length(stack_b);
	if (*position_a < len_a / 2)
	{
		if (*position_b < len_b / 2)
		{
			if (stack_a->index > stack_b->index)
				stack_a->push_cost = *position_a;
			else
				stack_a->push_cost = *position_b;
		}
		else
			stack_a->push_cost = *position_b + (len_a - *position_a);
	}
}

void	calculate_cost_a(t_node *stack_a, t_node *stack_b)
{
	int	position_a;
	int	position_b;

	while (stack_a)
	{
		initialize_positions_a(stack_a, &position_a, &position_b);
		calculate_push_cost_a(stack_a, stack_b, &position_a, &position_b);
		stack_a = stack_a->next;
	}
}
void	prepare_to_push_a(t_node *stack_a, t_node *stack_b)
{
	get_position(stack_a);
	get_position(stack_b);
	target_for_a(stack_a, stack_b);
	calculate_cost_a(stack_a, stack_b);
	find_cheapest(stack_a);
}
