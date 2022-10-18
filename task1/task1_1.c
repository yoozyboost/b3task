#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <time.h>

#define ALPHA 0.0
#define T_0 10
#define T_MIN -50
#define T_MAX 50
#define T_INTERVAL 1



int main(void){
    int time;
    double h;


    char *sFile = malloc(sizeof(char) * 200);
    sprintf(sFile, "%.1f.txt",ALPHA);

    FILE *fp = fopen(sFile, "w");
    
    
    for( time = T_MIN ; time<= T_MAX ; time += T_INTERVAL ){
        if(ALPHA == 0){
        if(time != 0){
            h = (pow(M_PI,2.0)/T_0) * sin(M_PI * time / T_0) / (M_PI * time / T_0) * (cos(ALPHA * M_PI * time * T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
            printf("%d:%f\n",time,h);
            fprintf(fp, "%d %f\n" ,time , h);
        }
        else{
            h = (pow(M_PI,2.0)/T_0) * 1 * (cos(ALPHA * M_PI * time * T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
            printf("%d:%f\n",time,h);
            fprintf(fp, "%d %f\n" ,time , h);
        }
        }else{
            int excp = T_0/(2*ALPHA); 

            if(time == excp || time == -excp)
            {
                h = ALPHA/(2*T_0) * sin(M_PI/(2*ALPHA));
                printf("%d:%f\n",time,h);
                fprintf(fp, "%d %f\n" ,time , h);
            }
            else if(time != 0){
                h = (pow(M_PI,2.0)/T_0) * sin(M_PI * time / T_0) / (M_PI * time / T_0) * (cos(ALPHA * M_PI * time / T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
                printf("%d:%f\n",time,h);
                fprintf(fp, "%d %f\n" ,time , h);
            }
            else{
                h = (pow(M_PI,2.0)/T_0) * 1 * (cos(ALPHA * M_PI * time / T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
                printf("%d:%f\n",time,h);
                fprintf(fp, "%d %f\n" ,time , h);
             }
        }
    }

    return 0;
}