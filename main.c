#include<stdio.h>
#include<stdbool.h>
#include "random_numbers.c"
#include "chi_square_test.c"
#include "monte_carlo.c"
#include "distributed_lag_model.c"
#include "kolmogorov_smirnov_test.c"
#include "poker_test.c"
int main(){
    int choice;
    int a,b,m;
    float* r_float_values;
    int* r_int_values;
    bool result;
    while(1){
        printf("\nChoose your option:");
        printf("\n0 > Quit Program");
        printf("\n1 > Chi-Square test");
        printf("\n2 > Kolmogorov-'smirnov test");
        printf("\n3 > Poker test");
        printf("\n4 > Calculate PI using Monte-Carlo simulation methot");
        printf("\n5 > Show distributive lag model");
        printf("\n\n>>> ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("\n\tEnter value of 'a' >>> ");
            scanf("%d",&a);
            printf("\n\tEnter value of 'b' >>> ");
            scanf("%d",&b);
            printf("\n\tEnter modulation 'm' >>> ");
            scanf("%d",&m);
            r_float_values = generate_random_float(a, b, m);
            result = chi_square_test_on_float(r_float_values);
            if (result){
                printf("\nRandom variables are Uniform\n");
            }
            else {
                printf("\nRandom variable are not Uniform\n");
            }
            break;
        case 2:
            printf("\n\tEnter value of 'a' >>> ");
            scanf("%d",&a);
            printf("\n\tEnter value of 'b' >>> ");
            scanf("%d",&b);
            printf("\n\tEnter modulation 'm' >>> ");
            scanf("%d",&m);
            r_float_values = generate_random_float(a, b, m);
            result = kolmogorov_smirnov_test_float(r_float_values);
            if (result){
                printf("\nRandom variables are Uniform\n");
            }
            else {
                printf("\nRandom variable are not Uniform\n");
            }
            break;
        case 3:
            printf("\n\tEnter value of 'a' >>> ");
            scanf("%d",&a);
            printf("\n\tEnter value of 'b' >>> ");
            scanf("%d",&b);
            printf("\n\tEnter modulation 'm' >>> ");
            scanf("%d",&m);
            r_int_values = generate_random_4_digit(a, b, m);
            result = poker_test(r_int_values);
            if (result){
                printf("\nRandom variables are Independent\n");
            }
            else {
                printf("\nRandom variable are not Dependent\n");
            }
            break;
        case 4:
            calculate_pi();
            break;
        case 5:
            distributed_lag_model();
            break;
        default:
            break;
        }
        if (choice == 0){
            break;
        }
    }
    printf("\n");
    return 0;
}