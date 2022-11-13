//Preparing and printing final report logic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"

struct special {
    char fileName[100];
    int numOfStringUpdated;
};

struct special updatesPerFile[50];
int updateIdx = 0;

void insertReportData(char * file, int numOfStringReplaced) {
    strcpy(updatesPerFile[updateIdx].fileName, file);
    updatesPerFile[updateIdx].numOfStringUpdated = numOfStringReplaced;
    updateIdx++;
}

int QSortFunction (const void * a, const void * b) {
    struct special *special1 = (struct special *)a;
    struct special *special2 = (struct special *)b;
    if (special1->numOfStringUpdated < special2->numOfStringUpdated) {
        return 1;
    }
    else if (special1->numOfStringUpdated > special2->numOfStringUpdated) {
        return -1;
    }
    else {
        return 0;
    }
}

void generateReport() {
    printf("***********************************************************************\n");
    printf("                             Search Report\n");
    printf("***********************************************************************\n\n");

    if (updateIdx != 0) {
        qsort(updatesPerFile, updateIdx, sizeof(struct special), QSortFunction);
        for (int idx = 0; idx < updateIdx; idx++) {
            printf("File name: %s | Updates: %d\n", updatesPerFile[idx].fileName, updatesPerFile[idx].numOfStringUpdated);
        }
    }
    else {
        printf("The target string was not found in any files.\n");
    }

}