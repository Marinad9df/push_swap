#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
    int data;
    int s_index;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *head;
    int size;
} t_stack;

// parse_utils.c
void    free_2d(char **arr);
int     is_valid_char(char c);
int     is_in_int_range(const char *str);
int     check_range(char **s_numbers, int *numbers);

// parse_numbers.c
int     check_digits(int argc, char **argv);
int     *parse_numbers(int argc, char **argv, int count);

// parse_arguments.c
int     *arg_parse(int argc, char **argv, int count);

// stack_utils.c
int     push_stack(t_stack *stack, int index, int data);
int     pop_stack(t_stack *stack);
void    free_stack(t_stack *stack);
int     is_stack_empty(t_stack *stack);
int     get_stack_size(t_stack *stack);

// instructions.c
void    swap(t_stack *stack, char x, bool b);
void    push(t_stack *stack1, t_stack *stack2, char x, bool b);
void    rotate(t_stack *stack, char x, bool b);
void    reverse_rotate(t_stack *stack, char x, bool b);

// push_swap.c
void    init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c);

// sorting_algorithms.c
void    simple_sort(t_stack *stack, int length);
void    s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length);
void    k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void    k_sort2(t_stack *stack_a, t_stack *stack_b, int length);

// helper_functions.c
int     is_sorted(t_stack *stack);
int     get_min_index(t_stack *stack);
int     count_r(t_node *head, int index);
int     ft_sqrt(int nb);

// Additional functions
void    sort(t_stack *stack_a, t_stack *stack_b, int count);
int     check_duplicates_bf(int *numbers, int count);
int     index_of(int value, int *array, int size);
void    insertion_sort(int *arr, int n);

#endif
