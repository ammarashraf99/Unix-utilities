#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


#define MAX_BUF_SIZE 1024 // files larger than MAX_BUF_SIZE won't be fully copied
#define ARG_SIZE 256
#define MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH

int main(int argc, char** argv)
{
	if (argc != 3)
		return -1;

	char src[ARG_SIZE];
	char dst[ARG_SIZE];
	char buf[MAX_BUF_SIZE];

	if (strlen(argv[1]) > ARG_SIZE ||
		strlen(argv[2]) > ARG_SIZE) // to prevent buffer overflow
	{ 
		printf("Too large arguments\n");
	}
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);

	int fd_read;
	int fd_write;

	if ((fd_read = openat(AT_FDCWD, src, O_RDONLY)) < 0) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		return -1;
	}
	if ((fd_write = openat(AT_FDCWD, dst, O_WRONLY | O_CREAT, MODE)) < 0) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		return -1;
	}
	if (read(fd_read, buf, MAX_BUF_SIZE) < 0) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		return -1;
	}
	if (write(fd_write, buf, strlen(buf)) < 0) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		return -1;
	}
}
