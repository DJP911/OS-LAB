//#include<stdio.h>
//#include<dirent.h>
//int main() {
//    char fn[10], pat[10], temp[200];
//    FILE *fp;
//    printf("\n Enter file name : ");
//    scanf("%s", fn);
//    printf("Enter the pattern: ");
//    scanf("%s", pat);
//    fp = fopen(fn, "r");
//    while (!feof(fp)) {
//        fgets(temp, sizeof(fp), fp);
//        if (strcmp(temp, pat))
//            printf("%s", temp);
//    }
//    fclose(fp);
//    return 1;
//}
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PATTERN_LENGTH 100
#define MAX_LINE_LENGTH 200

int main() {
    char filename[MAX_FILENAME_LENGTH], pattern[MAX_PATTERN_LENGTH], line[MAX_LINE_LENGTH];
    FILE *fp;
    
    printf("Enter file name: ");
    scanf("%s", filename);
    
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);
    
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }
    
    fclose(fp);
    return 0;
}

