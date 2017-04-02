/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:04:19 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/15 17:20:44 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

typedef enum		e_inst
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}					t_inst;

typedef struct		s_stack
{
	int				*stack;
	int				nr;
}					t_stack;

typedef struct		s_in
{
	t_inst			i;
	struct s_in		*next;
}					t_in;

typedef struct		s_stix
{
	t_stack			*a;
	t_stack			*b;
}					t_stix;

void				swap_first2(t_stack *a);
void				push_front(t_stack **a, int nr);
int					pop(t_stack **a);
int					is_sorted(int *stack, int len);

t_stack				fill_stack(int ac, char **av, int debug);
t_stack				fill_stack_string(char *str);

void				sort(t_stack a);
void				sort2(t_stack *a, t_stack *b);
void				divide(t_stack *a, t_stack *b, int m);
int					get_min(t_stack *a);

t_inst				get_instr(char *s);
void				in_push_back(t_in **inst, t_inst i);
t_stack				execute_order66(t_stack a, int debug);
void				execute(t_stack *a, t_stack *b, t_inst i);
void				execute2(t_stack *a, t_stack *b, t_inst i);
void				execute3(t_stack *a, t_stack *b, t_inst i);
int					count_numbers(char *str);

int					err();
void				aff(t_stack a, t_stack b, t_inst i);
void				check_digits(char *str);
void				check_overflow(char *str);
void				duplicate(int *stack, int len);

#endif
