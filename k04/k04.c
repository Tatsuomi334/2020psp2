#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 14

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
    double height;int gender;
    FILE* fp1;
    FILE*fp2;
    DATA DATA[14];
    int iID;
    int nodata=0;


    printf("input the filename of sample height:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';
    

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    
     i=0;
    
     fgets(buf,sizeof(buf),fp1);
    while(fgets(buf,sizeof(buf),fp1) != NULL){
        sscanf(buf,"%d,%lf",&gender,&height);
        DATA[i].gender = gender ;
        DATA[i].height=height;
        i++;
    }
      
    printf("Input the filename of sample ID: ");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] ='\0';

      fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    i=0;
    while(fgets(buf,sizeof(buf),fp2)!=NULL){
    
        sscanf(buf,"%d",&ID);
        DATA[i].ID=ID;
        i++;
    }
     printf("Which ID's data do you want?:");
     scanf("%d",&iID);

     for(i=0;i<N+1;i++){
        if(DATA[i].ID==iID){
             printf("ID:%d\n",iID);
         if(DATA[i].gender==1){ 
             printf("gender:male\n");
         }
         else {
              printf("gender:female\n");
              }
            
             printf("height*%lf\n",DATA[i].height);
        
    
        nodata=1;
     
        }     
     }

        if(nodata==0){
         printf("NO DATA");
         }

     if(fclose(fp1) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;

     }