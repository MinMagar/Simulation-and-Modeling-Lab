#include<stdio.h>
#include "random_integer.c"
int main(){
    float* r;
    r = generate_random_float(2,4,100);
    for (int i = 0; i<100; i++){
        printf("%f",r[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    return 0;
}