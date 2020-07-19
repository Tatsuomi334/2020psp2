#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct DATA
{   int ID;
    double height;
    double gender;

}DATA;
int main(void)
{
    int ID,i;
    char fname1[FILENAME_MAX],fname2[FILENAME_MAX];
    char buf[256];
    double height,gender;
    FILE* fp1;
    FILE*fp2;
    DATA DATA[14];
    int iID;
    int nodata;

    printf("input the filename of sample height:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';
    printf("Input the filename of sample ID: %s\n",fname2);
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] ='\0';
    

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
      fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    i=0;

    while(fgets(buf,sizeof(buf),fp1) != NULL){
        sscanf(buf,"%lf,%lf",&height,&gender);
        DATA[i].height = height ;
        DATA[i].gender =gender;
        i++;
    }
    i=0;
    while(fgets(buf,sizeof(buf),fp2)!=NULL){
        scanf(buf,"%d",&ID);
        DATA[i].ID=ID;
        i++;
    }
     printf("Which ID's data do you want?:");
     scanf("%d",&ID);

     for(i=0;i<15;i++){
        if(iID==DATA[i].ID){
             printf("ID:%d\n",iID);
         if(DATA[i+1].gender==1){ 
             printf("gender:male\n");
         }
         else {
              printf("gender:female\n");
              }
            
             printf("height*%lf\n",DATA[i+1].height);
        }
     else{
        nodata++;
     }
        
     }

        if(nodata==14){
         printf("NO DATA");
         }
     
    return 0;

     }