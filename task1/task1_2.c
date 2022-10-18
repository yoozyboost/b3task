#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <time.h>

#define ALPHA 1.0
#define T_0 10
#define T_MIN -50
#define T_MAX 50
#define T_INTERVAL 1
#define BIT_LENGTH 3


double h_calc(int);

int main(void){
    for(int j=0; j<8;j++){
        int input_num = j;
        int bit[3];
        
        double h_sum;
        char *sFile = malloc(sizeof(char) * 200);
        sprintf(sFile, "%.1f-%d.txt",ALPHA,input_num);
        FILE *fp = fopen(sFile, "w");

        for(int i=BIT_LENGTH-1; i>=0;i--){
            bit[i] = ((input_num % 2)-0.5) * 2;
            input_num /= 2; 
        }
        
        for(int time = T_MIN ; time<= T_MAX ; time += T_INTERVAL ){
            h_sum = bit[0] * h_calc(time + T_0) + bit[1] * h_calc(time) + bit[2] * h_calc(time - T_0);
            printf("%d:%f\n",time,h_sum);
            fprintf(fp, "%d %f\n" ,time , h_sum);
        }
    }
    return 0;

}


double h_calc(int time){
    double h;
     if(ALPHA == 0){
        if(time != 0){
            h = (pow(M_PI,2.0)/T_0) * sin(M_PI * time / T_0) / (M_PI * time / T_0) * (cos(ALPHA * M_PI * time * T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
        }
        else{
            h = (pow(M_PI,2.0)/T_0) * 1 * (cos(ALPHA * M_PI * time * T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
        }
        }else{
            int excp = T_0/(2*ALPHA); 

            if(time == excp || time == -excp)
            {
                h = ALPHA/(2*T_0) * sin(M_PI/(2*ALPHA));
            }
            else if(time != 0){
                h = (pow(M_PI,2.0)/T_0) * sin(M_PI * time / T_0) / (M_PI * time / T_0) * (cos(ALPHA * M_PI * time / T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
            }
            else{
                h = (pow(M_PI,2.0)/T_0) * 1 * (cos(ALPHA * M_PI * time / T_0)/(pow(M_PI , 2.0) - pow((2 * ALPHA * M_PI * time)/T_0,2.0)));
             }
        }
    return h;
}