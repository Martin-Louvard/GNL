#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main(int	argc, char **argv)
{

	int	i;

	i = 0;
	if (!(argc == 2))
		return (0);
	int fd = open(argv[1], O_RDONLY);
	char *line;
	while (i++ < 100)
	{
	line = get_next_line(fd);
	printf("%s", line);
	}
	while(1)
		;
}
