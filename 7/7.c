#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <stdlib.h>

int dirrecursive(char *path, int min, int max, int count, char *output);

int main(int argc[], char *argv[])
{
    int count = 0;
    FILE *fpout = fopen(argv[4], "w");
    fclose(fpout);
    count = dirrecursive(argv[1], atoi(argv[2]), atoi(argv[3]), count, argv[4]);
    printf("Checked %d files\n", count);
    return 0;
}

int dirrecursive(char *basePath, int min, int max, int count, char *output)
{
    char path[1000];
    struct dirent *dp;
    struct stat st;
    DIR *dir = opendir(basePath);
   
    if (!dir) {
        FILE *fp = fopen(basePath, "r");
        FILE *fpout = fopen(output, "a");
        if (fp) {
            stat(basePath, &st);
            count++;
            if (st.st_size > min && st.st_size < max) {
                fprintf(fpout, "%s - %ld\n", basePath, st.st_size);
            }

            fclose(fp);
            fclose(fpout);
            return count;
        } else {
            fclose(fp);
            fclose(fpout);
            return count;
        }
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            count = dirrecursive(path, min, max, count, output);
        }
    }

    closedir(dir);
    return count;
}