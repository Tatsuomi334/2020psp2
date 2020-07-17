#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct DATA
{   int ID;
    double height;
    double gender;

};DATA[15];
int main(void)
{
    int ID,i;
    char fname1[FILENAME_MAX],fname2[FILENAME_MAX];
    char buf[256];
    double height,gender;
    FILE* fp1;
    FILE*fp2;

    printf("input the filename of sample height:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';
    printf("Input the filename of sampl3 ID: %s\n",fname2);
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] ='\0';
    

    fp1 = fopen(fname,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
      fp2 = fopen(fname,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp1) != NULL){
        sscanf(buf,"%lf,%lf",&height,&gender);
        DATE[i].height = height ;
        DATA[i].gender =gender;
    }
