#include "push_swap.h"

void error_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	check_args_with_only_spaces(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
		if (ft_strlen(ft_strtrim(argv[i++], " ")) == 0)
			return (1);
	return (0);
}

int check_args_for_non_digit_values(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int check_args(int argc, char **argv)
{
	if (check_args_with_only_spaces(argc, argv))
		error_exit();
	if (check_args_for_non_digit_values(argc, argv))
		error_exit();
	return (1);
}

int	main(int argc, char **argv)
{
	// int i;

	if (argc == 1)
		return (0);

	check_args(argc, argv);
	return (0);
}