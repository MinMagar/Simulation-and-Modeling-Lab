bool kolmogorov_smirnov_test_float(float* random_var){
    float d_plus[100];
    float d_minus[100];
    
    //arranging random values in ascending order
    for (int i=0; i<100; i++){
        for(int j=0; j<99; j++){
            if (random_var[j] > random_var[j+1]){
                float temp = random_var[j];
                random_var[j] = random_var[j+1];
                random_var[j+1] = temp;
            }
        }
    }
    //calculating d_plus and d_minus
    for(int i=0; i<100; i++){
        d_plus[i] = ((float)i/100.0) - random_var[i];
        d_minus[i] = random_var[i] - ((float)(i - 1))/100.0;
    }
    //for getting d_plus_max and d_minus_max
    float max_d_plus = 0, max_d_minus = 0;
    for(int i=0; i<100; i++){
        if (d_minus[i] > max_d_minus){
            max_d_minus = d_minus[i];
        }
        if (d_plus[i] > max_d_plus){
            max_d_plus = d_plus[i];
        }
    }
    //getting test value and test
    float test_value;
    if (max_d_minus > max_d_plus){
        test_value = max_d_minus;
    }
    else {
        test_value = max_d_plus;
    }
    if (test_value <= 9.14){
        return true;
    }
    else {
        return false;
    }
}