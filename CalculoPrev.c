#include <stdio.h>
int main(){
	float EB[] = {0.05,0.06, 0.17,0.361,1.406,4.67,16.87,66.12,248.447};
	float KMP[] = {0.0, 0.02, 0.05, 0.15,0.569, 1.889, 6.75,28.71,83.29};
	float prev = 0;
	
	printf("----------------EB-------------------\n");
	for(int i = 0; i<9;i++){
		if(prev > 0){
			printf("%.3f\n", EB[i]/prev);
		}
		prev = EB[i];
	}
	prev = 0;
	printf("----------------KMP-------------------\n");
	for(int i = 0; i<9;i++){
		if(prev > 0){
			printf("%.3f\n", KMP[i]/prev);
		}
		prev = KMP[i];
	}
	return 0;
}
