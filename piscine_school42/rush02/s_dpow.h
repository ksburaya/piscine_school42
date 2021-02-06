#ifndef RUSH02_S_DPOW_H
#define RUSH02_S_DPOW_H

typedef struct 	dpow
{
	int 			key;
	char 			*value;
	struct dpow		*next;
}					s_dpow;

s_dpow			*s_dpow_create_elem(int key, char *value)
{
	s_dpow	*element;

	element = malloc(sizeof(s_dpow));
	element->key = key;
	element->value = value;
	element->next = 0;
	return (element);
}

void	s_dpow_list_push_back(s_dpow **begin_list, int key, char *value)
{
	s_dpow	*new_element;
	s_dpow	*tmp;

	if (!*begin_list)
	{
		*begin_list = s_dpow_create_elem(key, value);
		return ;
	}
	new_element = s_dpow_create_elem(key, value);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_element;
}

#endif //RUSH02_S_DPOW_H
