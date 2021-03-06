#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

int main(int argc, char* argv[])
{
	int fd;
// 	fd = open("p1", O_RDONLY);
	fd = open("p1", O_RDONLY | O_NONBLOCK);

	if (fd == -1)
		ERR_EXIT("open error");

	printf("open succ\n");

	return 0;
}
