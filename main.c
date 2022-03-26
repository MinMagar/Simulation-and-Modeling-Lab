#include<stdio.h>
#include<stdbool.h>
#include "random_integer.c"
#include "chi_square_test.c"
#include "monte_carlo.c"
#include "distributed_lag_model.c"
int main(){
    float* r;
    r = generate_random_float(2,4,100);
    for (int i = 0; i<100; i++){
        printf("%f   ",r[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    bool result;
    result = chi_square_test_on_float(r);
    if (result){
        printf("random varibles are uniform\n");
    }
    else{
        printf("random variables are non uniform\n");
    }
    calculate_pi();
    distributed_lag_model();
    return 0;
}