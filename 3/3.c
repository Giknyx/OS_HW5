#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    printf("\n");
    exit(0);
}

int main(int argc[], char *argv[])
{
	signal(SIGINT, sigintHandler);

	FILE *fp;
	int ch;
    fp = fopen(argv[1], "w");
 
	if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }

    while (1) {
    	ch = getc(stdin);
    	fputc(ch, fp);
    }

	return 0;
}