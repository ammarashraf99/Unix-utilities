#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char** argv)
{
	char buf[SIZE];
	if (!getcwd(buf, SIZE)) {
		fprintf(stderr, "error: %s\n", strerror(errno));
		exit(1);
	}
	printf("pwd:%s\n", buf);
	exit(0);
}
