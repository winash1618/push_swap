#include "push_swap.h"

char *ft_strjoin_with_spaces(char const *s1, char const *s2)
{
	char	*str;
	int		count1;
	int		count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	str = (char *) ft_calloc((count1 + count2 + 2), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, count1);
	ft_memcpy(str + count1, " ", 1);
	ft_memcpy(str + count1 + 1, s2, count2);
	return (str);
}

char *merge_args_with_spaces(int argc, char **argv)
{
	int i;
	char *merged_arg;

	i = 0;
	merged_arg = "";
	while(++i < argc)
	{
		merged_arg = ft_strjoin_with_spaces(merged_arg, argv[i]);
	}
	printf("merged string: %s\n", merged_arg);
	return (merged_arg);
}

int	main(int argc, char **argv)
{
	int i;
	char **str;

	if (argc == 1)
		return (0);
	i = -1;
	check_args(argc, argv);
	str = ft_split(merge_args_with_spaces(argc, argv), ' ');
	while (str[++i])
		printf("str[%d]: %s\n", i, str[i]);
	// init_list(argc, argv);
	return (0);
}