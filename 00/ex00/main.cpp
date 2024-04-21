#include <iostream>
#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	bool	was_whitespace;

	if (argc == 1)
	{
		std::cout << "\033[31m" << NOISE << "033[0m" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		was_whitespace = false;
		while (argv[i][j])
		{
			if (!(was_whitespace && is_whitespace(argv[i][j])))
				std::cout << (char)toupper(argv[i][j]);
			was_whitespace = is_whitespace(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}