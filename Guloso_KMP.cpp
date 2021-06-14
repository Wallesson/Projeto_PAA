#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h> 
using namespace std;

bool Testar(int teste[], int tam){
	for(int m =0; m<tam;m++){
		if(teste[m]==0){return false;}	
	}
	return true;
}

struct Bloco{
	int tamanho;
	int ini_str_1;
	int fin_str_1;
	int ini_str_2;
	int fin_str_2;
	char bloco[4000];
};

void preKmp(char *x, int t, int kmpNext[]) {
   int i, j;
   i = 0;
   j = kmpNext[0] = -1;
   while (i < t) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])kmpNext[i] = kmpNext[j];
      else kmpNext[i] = j;
   }
}

int KMP(char *x, int t, char *y, int n, int maior_teste[2]) {  
   int i, j, kmpNext[t];
   preKmp(x, t, kmpNext);
   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      maior_teste[0] = j-i;
      maior_teste[1] = (j-i) + (t-1);
      if (i >= t) return j-i;
   }
   return -1;
}

//Função MCSP, basicamente é a responsavel por controlar todo a aplicação
int Guloso(char str_1[], char str_2[]){
	int maior_teste[2];
	int v=0;
	int t = strlen(str_1);
	int x = 1;
	int a = t;
	int i = 0;
	int f = t;
	int ini = i;
	struct Bloco *blc = (struct Bloco*)malloc(sizeof(struct Bloco)*x);
	bool teste = true;
	while(teste){
		int tam = f;
		char aux[tam];
		int k =0;
		
		for(ini=i; ini<f; ini++){
			aux[k] = str_1[ini];
			k++;
		}aux[k]='\0';

		if(KMP(aux,strlen(aux),str_2,strlen(str_2),maior_teste)>=0){
			blc[v].ini_str_1 = i;
			blc[v].fin_str_1 = f-1;
			blc[v].ini_str_2 = maior_teste[0];
			blc[v].fin_str_2 = maior_teste[1];
			x++;
			blc[v].tamanho = strlen(aux);
			strcpy(blc[v].bloco,aux);
			v++;
			for(int u= i; u<=ini-1; u++){str_1[u]='-';}
			for(int u= maior_teste[0]; u<=maior_teste[1]; u++){	str_2[u]='+';}

			struct Bloco *blc2;
			blc2 = (struct Bloco*) realloc(blc,sizeof(struct Bloco)*x);
			if(blc2 != NULL){blc = blc2;}
		}

		if(f+1 <= t){
			i++;
			f++;
		}
		else{
			if(a-1 > 0){
				a = a-1;
				f = a;
				i = 0;
			}
			else{
				teste = false;
			}
		}
	}

	free(blc);
	return x-1;
}

int main (){
	char str_1[4000];
	char str_2[4000];
	int sol;
	clock_t t;
	
	FILE *arq_1;
	arq_1 = fopen("arquivo.txt", "r");

	if(arq_1 == NULL){cout<<"Erro ao Ler o Arquivo!!!"<<endl;}

	fscanf(arq_1,"%s %s",str_1, str_2);
	t = clock();
	sol = Guloso(str_1,str_2);
	t = clock() - t;
	cout<<"SOLUCAO GULOSO_KMP ENCONTRADA: "<<sol<< " PARTICOES"<<endl;
	cout<<"TEMPO GULOSO_KMP : "<<(double)t/CLOCKS_PER_SEC;

	fclose(arq_1);
	return 0;
}
