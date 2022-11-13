//Search and Replace logic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "text.h"

int searchAndReplace(char *filePath, char *find, char *replace){
    FILE *filePtr;
    filePtr = fopen(filePath, "r+");
    char read[100];
    int numOfStringReplaced = 0;
    
    if(filePtr == NULL){
        printf("Filepath is invalid\n");
        exit(0);
    }

    while (!feof(filePtr)) {
        fscanf(filePtr, "%s", read);

        if (strcmp(read, find) == 0) {
            fseek(filePtr, -(strlen(read)), SEEK_CUR);
            fputs(replace, filePtr);
            numOfStringReplaced++;
        }
        //This else if statement simply makes sure that a matching string ending with special characters like comma or period still gets capitalised.
        else if (strlen(read) == (strlen(find) + 1) && strstr(read, find) && !(((int)read[strlen(read)-1] > 64 && (int)read[strlen(read)-1] < 91) || ((int)read[strlen(read)-1] > 96 && (int)read[strlen(read)-1] < 123))) {
            fseek(filePtr, -(strlen(read)), SEEK_CUR);
            fputs(replace, filePtr);
            numOfStringReplaced++;
        }
    }

    fclose(filePtr);
    return numOfStringReplaced;
}