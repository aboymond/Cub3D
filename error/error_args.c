#include "../cube3d.h"

int	erreur_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("\033[1;31m Error:\n\tErreur d'arguments \033[00m \n", 1);
		exit (0);
	}
	if (check_arg(argv[1]) != 1)
	{
		ft_printf("\033[1;31m Error:\n\t'.cub' Non valide\033[00m \n", 1);
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
	
}