#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc[], char *argv[])
{
	DIR *dr1;
    DIR *dr2;
    char cwd[256];
    struct dirent *d1;
    struct dirent *d2;
	
    printf("Current dir:\n");
    getcwd(cwd, sizeof(cwd));
    dr2 = opendir(cwd);
    d2 = readdir(dr2);
    while (d2 != NULL) {
        printf("%s\n", d2->d_name);
        d2 = readdir(dr2);
    }
    
    printf("\n");

    printf("Given dir:\n");
    dr1 = opendir(argv[1]);
    d1 = readdir(dr1);
    while (d1 != NULL) {
        printf("%s\n", d1->d_name);
        d1 = readdir(dr1);
    }

	return 0;
}