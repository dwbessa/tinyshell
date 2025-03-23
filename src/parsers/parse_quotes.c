#include "minishell.h"

int	parse_quotes(t_data *data)
{
	if (!quote_number(data))
	{
		quote_error();
		return (0);
	}
	return (1);
}
