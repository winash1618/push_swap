#include "push_swap.h"

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
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
							&& argv[i][j] != '+' && argv[i][j] != '-')
			{
				return (1);
			}
			j++;
		}
	}
	return (0);
}

int check_args_for_sign_error(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j + 1])
		{
			if (argv[i][j] == '+')
			{
				if (argv[i][j + 1] == '-' || argv[i][j + 1] == '+' || argv[i][j + 1] == ' ')
					return (1);
			}
			else if (argv[i][j] == '-')
			{
				if (argv[i][j + 1] == '-' || argv[i][j + 1] == '+' || argv[i][j + 1] == ' ')
					return (1);
			}
			j++;
		}
		if ((argv[i][j] == '+' || argv[i][j] == '-') && !argv[i][j + 1])
			return (1);
	}
	return (0);
}

int check_args(int argc, char **argv)
{
	if (check_args_with_only_spaces(argc, argv))
		error_exit();
	if (check_args_for_non_digit_values(argc, argv))
		error_exit();
	if (check_args_for_sign_error(argc, argv))
		error_exit();
	return (1);
}