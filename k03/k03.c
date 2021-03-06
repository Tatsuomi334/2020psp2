#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifdef CONST_SEED
#define RAND_SEED 2020
#else
#include <time.h>
#define RAND_SEED ((unsigned) time(NULL))
#endif


double r_unif(void)
{
    return (double)(rand()+1)/(RAND_MAX+2);
}

double r_stdnorm(void)
{
    return sqrt( -2.0*log(r_unif()) ) * sin( 2.0*M_PI*r_unif() );
}




int main(int argc, char* argv[])
{
    int num_dummy;
    double mu;
    double sigma;
    int i;
    double dummy;
    double a,b;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
     



    sscanf(argv[argc-3],"%lf",&mu);
    sscanf(argv[argc-2],"%lf",&sigma);
    sscanf(argv[argc-1],"%d",&num_dummy);

    printf("============================================\n");
    printf("template mean: %3.2lf\n",mu);
    printf("template standard deviation: %3.2lf\n",sigma);
    printf("Num of dummy data: %d\n",num_dummy);
    printf("============================================\n");

    srand(RAND_SEED);
   
    
      for(i=1;i<=num_dummy;i++){
        /* r_stdnormを使って，1人のデータを捏造 */
        

        dummy = sigma*r_stdnorm()+mu  ;
        printf("%5.2lf\n",dummy);
    
      }
    return EXIT_SUCCESS;
}

