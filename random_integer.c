int* generate_random_integer(int a, int b, int m){
    static int random_values[100];
    random_values[0] = a;
    random_values[1] = b;
    int temp;
    for (int i = 2; i < 100; i++){
        random_values[i] = (a + b) % m;
        a = b;
        b = random_values[i];   
    }
    return random_values;
}

float* generate_random_float(int a, int b, int m){
    static float random_values[100];
    random_values[0] = (float)a / (float)m;
    random_values[1] = (float)a / (float)m;
    int temp;
    for (int i = 2; i < 100; i++){
        temp = (a + b) % m;
        a = b;
        b = temp;
        random_values[i] = (float)temp / m;
    }
    return random_values;
}

