bool poker_test(int* random_var){
	float p[5];
	p[0] = 0.001;
	p[1] = 0.504;
	p[2] = 0.036;
	p[3] = 0.432;
	p[4] = 0.027;
	int O_count[5],digit[4],E_count[5],temp;
    //initiate counter for observed frequency
	for(int i = 0; i < 5; i++){
		O_count[i] = 0;
	}
    //calculate expected frequency
    for (int i=0; i<5; i++){
        E_count[i] = (int)(p[i] * 1000.0);
    }
	for (int i = 0; i < 1000; i++){
		temp = random_var[i];
        //store each digits of number in array of size four
		for (int j = 0;j < 4; j++){            
			digit[j] = temp % 10;
			temp = temp / 10;
		}
        //arrage digits in ascending order
		for (int j = 0;j < 4;j++){
			for (int k = 0; k < 4-j; k++){
				if(digit[k] > digit[k+1]){
					temp = digit[k];
					digit[k] = digit[k+1];
					digit[k+1] = temp;
				}
			}
		}
        //count obsered frequency
		if((digit[0] == digit[1]) && (digit[1] == digit[2]) && (digit[2] == digit[3])){
			O_count[0]++;
		}
		else if((digit[0]==digit[1] && digit[1]==digit[2])||(digit[1] == digit[2] && digit[2] == digit[3])){
			O_count[2]++;
		}
		else if((digit[0] == digit[1]) && (digit[2] == digit[3])){
			O_count[4]++;
		}
		else if((digit[0] != digit[1]) && (digit[1] != digit[2]) && (digit[2] != digit[3])){
			O_count[1]++;
		}
		else{
			O_count[3]++;
		}
	}
    //test within significance of 0.05
    float test_value;
    for (int i=0; i<5; i++){
        test_value += (float)((O_count[i]-E_count[i])*(O_count[i]-E_count[i]))/(float)E_count[i];
    }
    if (test_value <= 9.35) {
        return true;
    }
    else {
        return false;
    }
}