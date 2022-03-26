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

int* generate_random_4_digit(int a, int b, int m){
    static int random_var[1000];
    random_var[0] = a;
    random_var[1] = b;
    for (int i =2; i < 1000; i++){
		random_var[i] = (random_var[i-1] + random_var[i-2]) % m;
		while (random_var[i] < 1000){
			random_var[i + 1] = (random_var[i] + random_var[i-1]) % m;
			random_var[i] = random_var[i + 1];
		}
	}
    return random_var;
}