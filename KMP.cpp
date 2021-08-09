#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h> 
using namespace std;

void preKmp(char *x, int t, int kmpNext[]) {
   int i, j;
   i = 0;
   j = kmpNext[0] = -1;
   while (i < t) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      printf("i = %d, j = %d\n", i,j);
      if (x[i] == x[j])kmpNext[i] = kmpNext[j];
      else kmpNext[i] = j;
      for(int w = 0; w<t;w++){
		printf("%d", kmpNext[w]);
		}
		printf("\n");
   }
}

int KMP(char *x,  char *y) {  
   int t = strlen(x);
   int n = strlen(y);
   int i, j, kmpNext[t];

   preKmp(x, t, kmpNext);
   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= t) return j-i;
      if(n-j<t){
		return -1;
		 
	  }

      
   }
   return -1;
}


int main (){
	char str_1[20000];
	char str_2[20000];
	int sol;
	clock_t t;
	
	FILE *arq_1;
	arq_1 = fopen("arquivo.txt", "r");

	if(arq_1 == NULL){cout<<"Erro ao Ler o Arquivo!!!"<<endl;}

	fscanf(arq_1,"%s %s",str_1, str_2);
	t = clock();
	sol = KMP(str_1,str_2);
	t = clock() - t;
	if(sol>=0){
		cout<<"String Encontrada"<<endl;
	}
	else{
		cout<<"String NAO Encontrada"<<endl;
	}
	float r = (float)t/CLOCKS_PER_SEC;
	printf("Tempo KMP: %.8f", r);

	fclose(arq_1);
	return 0;
}
