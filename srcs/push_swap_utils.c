#include "../includes/push_swap.h"

int check_duplicates_bf(int *numbers, int count)
{
    int i;
    int j;

    i = 0;
    while (i < count - 1)
    {
        j = i + 1;
        while (j < count)
        {
            if (numbers[i] == numbers[j])
                return (1);  // Found a duplicate
            j++;
        }
        i++;
    }
    return (0);  // No duplicates found
}

int index_of(int value, int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (array[i] == value)
            return (i);
        i++;
    }
    return (-1);  // Value not found
}

void insertion_sort(int *arr, int n)
{
    int i;
    int key;
    int j;

    i = 1;
    while (i < n)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        i++;
    }
}

int ft_sqrt(int nb)
{
    int i;

    if (nb <= 0)
        return (0);
    i = 1;
    while (i * i <= nb && i <= 46340)
    {
        if (i * i == nb)
            return (i);
        i++;
    }
    return (0);
}
