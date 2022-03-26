#include <stdio.h>

int distributed_lag_model() {

    float I[100], C[100], T[100], G[100], Y[50];
    int no_of_years, i;

    printf("\nEnter the National income for 2021: ");
    scanf("%f", &Y[0]);
    printf("Enter the Government Expenditure for 2021: ");
    scanf("%f", &G[0]);
    printf("Enter Number of Years to Simulate: ");
    scanf("%d", &no_of_years);

    printf("\n Income[2021]: %.2f \n Government_Expenditure[2021]: %.2f \n", Y[0], G[0]);
    printf("\n SN\t Years\t Investment(I)\t Tax(T)\t\t Expenditure(G)\t\t Consumption(C)\t\t Income(Y)\n");

    for (i=1; i <= no_of_years; i++) {
        I[i] = 2 + 0.1 * Y[i-1];
        T[i] = 0.2 * Y[i-1];
        G[i] = 0.15 * G[i-1] + G[i-1];
        C[i] = 45.45 + 2.27 * (I[i] + G[i]);
        Y[i] = C[i] + I[i] + G[i];
        printf(" %d\t %d\t %.2f\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t\t %.2f\t\n", i, 2021+i, I[i], T[i], G[i], C[i], Y[i]);
    }

}