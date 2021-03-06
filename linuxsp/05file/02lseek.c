#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
// #include <errno.h>
// #include <string.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		ERR_EXIT("open error");

	char buf[1024] = {0};
	int ret = read(fd, buf, 5);
	if (ret == -1)
		ERR_EXIT("read error");
	printf("buf=%s\n", buf);
	
    ret = lseek(fd, 0, SEEK_CUR);
	if (ret == -1)
		ERR_EXIT("lseek");

	printf("current offset=%d\n", ret);
	return 0;
	
}
