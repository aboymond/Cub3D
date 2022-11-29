#include "../cub3D.h"

int	erreur_args(int argc, char **argv)
{
	if (argc != 2)
	{
		return (p_error("Error:\n\tInvalid arguments"));
		exit (0);
	}
	if (check_arg(argv[1]) != 1)
	{
		return (p_error("Error:\n\tInvalid arguments"));
		exit (0);
	}
	return (0);
}

int	check_arg(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[--i] == 'b')
	{
		if (c[--i] == 'u')
		{
			if (c[--i] == 'c')
			{
				return (1);
			}
		}
	}
	return (0);
}

int	p_error(char *error)
{
	printf("\033[1;31m%s\033[00m \n", error);
	exit (EXIT_FAILURE);
}