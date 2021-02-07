#ifndef RUSH02_S_DITEM_H
#define RUSH02_S_DITEM_H

#include <stdio.h>

typedef struct 			ditem
{
	char 				*key;
	char 				*value;
	struct ditem		*next;
}						s_ditem;

s_ditem			*s_ditem_create_elem(char *key, char *value)
{
	s_ditem	*element;

	element = malloc(sizeof(s_ditem));
	element->key = key;
	element->value = value;
	element->next = 0;
	return (element);
}

void	s_ditem_list_push_back(s_ditem **begin_list, char *key, char *value)
{
	s_ditem	*new_element;
	s_ditem	*tmp;

	if (!*begin_list)
	{
		*begin_list = s_ditem_create_elem(key, value);
		return ;
	}
	new_element = s_ditem_create_elem(key, value);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_element;
}

void    s_ditem_print_list(s_ditem **begin_list)
{
    s_ditem *pointer;

    pointer = *begin_list;
    while (pointer)
    {
        printf("address: %p, key: %s, value: %s, next: %p\n",
               pointer, (char *)pointer->key, (char *)pointer->value, pointer->next);
        pointer = pointer->next;
    }
}

char    *s_ditem_find_value(s_ditem **begin_list, char *key)
{
    s_ditem *pointer;

    pointer = *begin_list;
    while (pointer)
    {
        if (ft_strcmp((char *)pointer->key, key) == 0)
            return ((char *)pointer->value);
        pointer = pointer->next;
    }
    return 0;
}

#endif //RUSH02_S_DITEM_H
