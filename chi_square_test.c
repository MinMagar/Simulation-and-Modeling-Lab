bool chi_square_test_on_float(float* random_variables){
    float lower_limit[10], upper_limit[10];
    float limit_difference = 1.0;
    lower_limit[0] = 0.0;
    lower_limit[1] = 1.0;
    for (int i = 1; i < 10; i++){
        lower_limit[i] = upper_limit[i-1];
        upper_limit[i] = lower_limit[i] + 1.0;
    }
    int expected_frequency = 10;
    int observed_frequency[10];
    for(int i=0; i<10; i++){
        observed_frequency[i] = 0;
    }
    for (int i=0; i<100; i++){
        if ((random_variables[i] >= 0.0) && (random_variables[i] < 0.1)){
            observed_frequency[0]++;
        }
        else if ((random_variables[i] >= 0.1) && (random_variables[i] < 0.2)){
            observed_frequency[1]++;
        }
        else if ((random_variables[i] >= 0.2) && (random_variables[i] < 0.3)){
            observed_frequency[2]++;
        }
        else if ((random_variables[i] >= 0.3) && (random_variables[i] < 0.4)){
            observed_frequency[3]++;
        }
        else if ((random_variables[i] >= 0.4) && (random_variables[i] < 0.5)){
            observed_frequency[4]++;
        }
        else if ((random_variables[i] >= 0.5) && (random_variables[i] < 0.6)){
            observed_frequency[5]++;
        }
        else if ((random_variables[i] >= 0.6) && (random_variables[i] < 0.7)){
            observed_frequency[6]++;
        }
        else if ((random_variables[i] >= 0.7) && (random_variables[i] < 0.8)){
            observed_frequency[7]++;
        }
        else if ((random_variables[i] >= 0.8) && (random_variables[i] < 0.9)){
            observed_frequency[8]++;
        }
        else {
            observed_frequency[9]++;
        }
    }
    float test_value = 0.0;
    for (int i=0; i<10; i++){
        test_value += (float)((observed_frequency[i] - expected_frequency) * (observed_frequency[i] - expected_frequency))/(float)expected_frequency;
    }
    if (test_value <= 9.35) {
        return true;
    }
    else {
        return false;
    }
}

