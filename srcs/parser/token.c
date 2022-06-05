#include "../../includes/parser.h"

t_token	*new_token(char *str)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		exit (1);
	new->str = str;
	new->next = NULL;
	return (new);
}

void	add_token(t_token **tokens, t_token *new)
{
	t_token	*tmp;

	if (new)
	{
		tmp = *tokens;
		if (!tmp)
			*tokens = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
