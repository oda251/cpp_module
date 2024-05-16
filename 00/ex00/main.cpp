#include <iostream>
#include <cstdlib>
#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc == 1)
	{
		std::cout << NOISE << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char) toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}