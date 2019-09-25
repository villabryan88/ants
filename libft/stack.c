/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:29:28 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 19:58:45 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

struct s_stack *stack_init(void){
	t_stack *new = malloc(sizeof(t_stack));
	new->top = NULL;

	return (new);
}

void *stack_pop(struct s_stack *stack){
	t_node	*node;
	void	*content;

	if (stack_isempty(stack))
		return (NULL);
	node = stack->top;
	content = node->content;
	stack->top = node->next;
	free(node);
	return (content);
}

void stack_push(struct s_stack *stack, void *content) {
	t_node *new;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *stack_peek(struct s_stack *stack) {
	if (stack_isempty(stack))
		return (NULL);
	return (stack->top->content);
}

int stack_isempty(struct s_stack *stack) {
	return (!stack->top);
}