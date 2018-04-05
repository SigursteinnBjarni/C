#include<stdio.h>
#include <stdlib.h>
int mypow(int base, int exp){
	int p = 1;
	if (exp == 0){
		return 1;
	}

	for (int i = 1; i <= exp; i++){
		p = base * p;
		
	}
	
	return p;

}


int main(int argc, char* argv[]){
	int base = atoi(argv[1]);
	int exp = atoi(argv[2]);
	printf("%d in the power of %d is %d\n",base,exp,mypow(base,exp));
	return 0;
}
