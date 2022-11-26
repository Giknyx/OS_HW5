#include <stdio.h>
#include <stdlib.h>

int main(int argc[], char *argv[])
{
	FILE *fp;
	int ch;
    int line;
    fp = fopen(argv[1], "r");
 
	if (fp == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }

    line = 0;
    while (line < atoi(argv[2])) {
        if (getchar() == '\n') {
            while (1) {
                ch = fgetc(fp);

                if (feof(fp)) {
                    break;
                }
                if (ch == '\n') {
                    printf("%c", ch);
                    break;
                }

                printf("%c", ch);
            }
            line++;
        }
    }
	
    if (atoi(argv[2]) == 0) {
        while (1) {
            ch = fgetc(fp);

            if (feof(fp)) {
                break;
            }

            printf("%c", ch);
        }
    }

    printf("\n");
	return 0;
}