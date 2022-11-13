//Directory traversal logic
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversal.h"
#include "text.h"
#include "report.h"

char dirArray[50][100];
int arrIdx = 0;

int validateTxtFile(char *FileName) { //Makes sure that only text files are modified
    if (FileName[strlen(FileName) - 1] == 't' &&
        FileName[strlen(FileName) - 2] == 'x' &&
        FileName[strlen(FileName) - 3] == 't' &&
        FileName[strlen(FileName) - 4] == '.') {
            return 1;
    }

    return 0;
}

int getDirectory (char *path) {
    DIR *directory;
    struct dirent *dir;
    directory = opendir(path);

    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (strstr((dir->d_name), ".") != NULL) { //Any folders with dots in them are invalid and will not be red by this function.
                if (validateTxtFile((dir->d_name))) {
                    if (strcmp(path, ".") == 0) {
                        strcpy(dirArray[arrIdx], (dir->d_name));
                    }
                    else {
                        char filePath[strlen(path)];
                        strcpy(filePath, path);
                        strcat(filePath, "/");
                        strcat(filePath, (dir->d_name));
                        strcpy(dirArray[arrIdx], filePath);
                    }
                    arrIdx++;
                }
            }
            else {
                if (strcmp(path, ".") == 0) {
                    getDirectory((dir->d_name));
                }
                else {
                    char nextPath[strlen((path))];
                    strcpy(nextPath, path);
                    strcat(nextPath, "/");
                    strcat(nextPath, (dir->d_name));
                    getDirectory(nextPath);
                }
            }
        }

    }
    else {
            printf("Base directory could not be read");
            exit(0);
        }
        
    closedir(directory);
    return arrIdx;
}

void startFNRProcedure(char *find, char *replace){
    int tempInt = 0;
    for (int idx = 0; idx < arrIdx; idx++) {
        tempInt = searchAndReplace(dirArray[idx], find, replace);
        if (tempInt != 0) {
            insertReportData(dirArray[idx], tempInt);
        }
    }
}