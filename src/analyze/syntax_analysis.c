#include "minishell.h"

int	quote_number(t_data *data)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (data->raw_cmd[i])
	{
		if (data->raw_cmd[i] == 39)
			single_quotes++;
		else if (data->raw_cmd[i] == 34)
			double_quotes++;
		i++;
	}
	if (double_quotes == 0 && single_quotes == 0)
		return (1);
	else if (double_quotes % 2 != 0 || single_quotes % 2 != 0)
		return (0);
	return (1);
}

void	quote_error(void)
{
	extern unsigned int	g_exit_status;

	printf("minishell: syntax error: even number of quotes\n");
	g_exit_status = 2;
}
