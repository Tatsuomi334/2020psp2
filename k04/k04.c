#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    char ID[14]
    char 
FILE* fp;

    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("Input the filename of sampl3 ID: %s\n",fname);
    fgets(fname,sizeof(fname),stdin);
    printf("Which ID's date do you what?:");
    fgets(fname,sizeof(fname),stdin);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }


