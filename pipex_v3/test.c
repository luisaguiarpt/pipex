#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **ep)
{
	(void)ac;
	(void)av;
	
	for (int i = 0; ep[i]; i++)
		printf("%d: %s\n", i, ep[i]);
}
