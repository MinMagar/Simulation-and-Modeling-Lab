#include<stdio.h>
#include<math.h>
float function(float x, float y){
    return (x * x + y * y);
}

void pi_value_using_monte_carlo(){
    float rand_x[200], rand_y[200];
    int x[200],y[200];
    int m,X[20],Y[20],count[10];
    int counter = 0,n = 3;
    float pi[10],pi_avg;
    printf("Enter modulous value : ");
    scanf("%d",&m);
    int index=0;
    for (int i = 0;i < n; i++){
        printf("Enter %d value of X[%d] and Y[%d]: ",i,(i%2)+1,(i%2)+1);
        scanf("%d%d",&X[index],&Y[index]);
        printf("Enter %d value of X[%d] and Y[%d]: ",i,(i%2)+2,(i%2)+2);
        scanf("%d%d",&X[index+1],&Y[index+1]);
        index += 2;
    }
    index = 0;
    for (int i = 0; i < n; i++){
        x[0] = (float)X[index];
        y[0] = (float)Y[index];
        x[1] = (float)X[index + 1];
        y[1] = (float)y[index + 1];
        for (int k=2;k<200;k++){
            y[k] = (y[k-1]+y[k-2])%m;
            x[k] = (x[k-1]+x[k-2])%m;
        }
        for (int k = 0;k < 200; k++){
            rand_x[k] = (float)x[k]/m;
            rand_y[k] = (float)y[k]/m;
        }
        for (int k = 0;k < 200;k++){
            if(function(rand_x[k],rand_y[k]) <= 1){
                counter++;
            }
        }
        count[i] = counter;
        pi[i] = (counter/200.0)*4.0;
        counter = 0;
        index += 2;
    }
    printf("\nrun\tx[0]\tx[1]\ty[0]\ty[1]\tn\tN\tpi");
    index = 0;
    for(int i=0; i<n; i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t200\t%f",i,X[index],X[index+1],Y[index],Y[index+1],count[i],pi[i]);
        index += 2;
    }
    pi_avg = 0;
    for (int i=0; i<n; i++){
        pi_avg += pi[i];
    }
    pi_avg = pi_avg / n;
    float err = 0;
    err = (fabs(pi_avg - 3.141)/3.141)*100.0;
    printf("\nCalculated pi value is %f",pi_avg);
    printf("\nError percentage is %f",err);
}