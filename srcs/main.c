#include "minishell.h"

int main(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		printf("Give me just one parameter BOZO!\n");
		return (1);
	}
	i = -1;
	while (++i < atoi(av[1]))
		printf("¯\\_(ツ)_/¯\n");
	return (0);
}
