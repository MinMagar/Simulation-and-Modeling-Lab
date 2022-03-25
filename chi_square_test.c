#include<stdio.h>
int main(){
    //Step 1 : generate random numbers
    int a = 12,b = 34,m = 100;//initilizing parameter for generating random numbers
    float random_values[100];
    random_values[0] = 0.12;
    random_values[1] = 0.34;
    int temp;
    for (int i = 2; i < 100; i++){
        temp = (a + b) % 100;
        a = b;
        b = temp;
        random_values[i] = (float)temp / 100.0;
    }
    //Step 2 : display random numbers
    for (int i = 0; i<100; i++){
        printf("%f",random_values[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    //Step 3 : create class
    float lower_limit[10], upper_limit[10];
    float limit_difference = 1.0;
    lower_limit[0] = 0.0;
    lower_limit[1] = 1.0;
    for (int i = 1; i < 10; i++){
        lower_limit[i] = upper_limit[i-1];
        upper_limit[i] = lower_limit[i] + 1.0;
    }
    return 0;
}
