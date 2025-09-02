#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define ARG_SIZE 256

int main(int argc, char **argv)
{
	if (argc != 3)
		exit(1);

	char src[ARG_SIZE];
	char dst[ARG_SIZE];

	if (strlen(argv[1]) > ARG_SIZE || strlen(argv[2]) > ARG_SIZE) {	// to prevent buffer overflow
		printf("Too large arguments\n");
	}
	strcpy(src, argv[1]);
	strcpy(dst, argv[2]);

	if (rename(src, dst) < 0) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		exit(1);
	}
	exit(0);
}
