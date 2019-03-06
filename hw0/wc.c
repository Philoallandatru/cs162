
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) exit(0);
    FILE * fp = fopen(argv[1], "r");
    if (fp == NULL) exit(0);
    size_t len = 0;
    ssize_t read;
    
    
    int nchar = 0;
    int nword = 0;
    int nline = 0;
    char * line = NULL;
    while ((read = getline(&line, &len, fp)) != -1) {
		nchar += strlen(line);
        char * word = strtok(line, " ");
        while (word) {
            nword += 1;
            word = strtok(NULL, " ");
        }
        nline++;
    }
    printf("%3d %3d %3d %s\n", nline, nword - 1, nchar, argv[1]);
    
    return 0;
}
