#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

double p_stdnorm(double z)
{
return  exp(-z*z/2)/sqrt(2*M_PI);
}



int main(void)
{
    double z;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double La=1,Lb=1;
    double max_val, min_val;
    double a;
    double mu_a,mu_b,var_a,var_b;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
     printf("mu_a =");
     scanf("%lf",&mu_a);
     printf("var_a =");
     scanf("%lf",&var_a);
     printf("mu_b =");
     scanf("%lf",&mu_b);
     printf("var_b =");
     scanf("%lf",&var_b);
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        z=(val-mu_a)/ var_a;
        La=p_stdnorm(z)*La;
        z=(val-mu_b)/var_b;
        Lb=p_stdnorm(z)*Lb;

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",La);
    printf("L_B: %f\n",Lb);

    return 0;


}





