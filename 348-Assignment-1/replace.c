// Main function
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "traversal.h"
#include "report.h"

//Folder names with "." will not be read
//Target string must not have any space. If it does, anything after the space will not be considered.

int main()
{
    char find[50];
    char replace[50];
    printf("\n***********************************************************************\n");
    printf("                     WELCOME TO STRING CAPITALISER\n");
    printf("***********************************************************************\n\n");
    printf("Target string: ");

    scanf("%s", find);

    strcpy(replace, find);

    for (int i = 0; replace[i] != '\0'; i++)
    {
        if (replace[i] >= 97 && replace[i] <= 122)
        {
            replace[i] = replace[i] - 32;
        }
    }

    char cwd[100];
    getcwd(cwd, sizeof(cwd));
    printf("\nSearch begins in current folder: %s\n\n", cwd);

    int filesFound = 0;
    filesFound = getDirectory(".");

    if (filesFound != 0) {
        startFNRProcedure(find, replace);
    }
    else {
        printf("No text files found in current dirrectory\n");
    }

    generateReport();

    printf("\n");

    return 0;
}