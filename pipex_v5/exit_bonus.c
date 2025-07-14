#include "pipex_bonus.h"

void	ft_exit(int err)
{
	if (err == 1)
		perror("Usage: ./pipex <here_doc LIMITER/file1> cmd1 cmd2 file2");
	if (err == 2)
		perror("Pipe");
	if (err == 3)
		perror("Fork");
	if (err == 4)
		perror("here_doc");
	if (err == 5)
		perror("Input file");
	if (err == 6)
		perror("Output file");
	if (err == 7)
		perror("Couldn't execute command");
	if (err == 8)
		perror("Couldn't find command");
	if (err == 8)
		exit(127);
	exit(1);
}
