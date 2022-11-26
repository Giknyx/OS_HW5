#include <stdio.h>
#include <stdlib.h>

int main(int argc[], char *argv[])
{
	FILE *fp1;
    FILE *fp2;
	int ch;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
 
	if (fp1 == NULL || fp2 == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }
	
    while (1) {
        ch = fgetc(fp1);

        if (feof(fp1)) {
            break;
        }

        fputc(ch, fp2);
    }

	return 0;
}