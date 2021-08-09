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
//Função que verifica se as partições de uma string aparecem na outra
bool Encontra_blocos(char str_1[], char str_2[]){
	int i = 0;
	int teste[strlen(str_1)];
	int aux;
	int tam_1 = strlen(str_1);
	int tam_2 = strlen(str_2);

	for(i = 0; i <= tam_2; i++){
		if(str_2[i] == str_1[0]){
			printf("-\n");
			for(int k = 0; k<tam_1; k++){teste[k]=0;}
			aux = i;
			for(int j = 0; j<tam_1; j++){
				printf("-\n");
				if(str_1[j]==str_2[aux]){
					teste[j]=1;
					aux++;
				}
			}
			if(Testar(teste, tam_1)){
				return true;
			}
		}
	}
	return false;
}



int main (){
	char str_1[20000];
	char str_2[20000];
	bool sol;
	clock_t t;
	
	FILE *arq_1;
	arq_1 = fopen("arquivo.txt", "r");

	if(arq_1 == NULL){cout<<"Erro ao Ler o Arquivo!!!"<<endl;}

	fscanf(arq_1,"%s %s",str_1, str_2);
	printf("%s\n", str_1);
	t = clock();
	sol = Encontra_blocos(str_1,str_2);
	t = clock() - t;
	if(sol){
		cout<<"String Encontrada"<<endl;
	}
	else{
		cout<<"String NAO Encontrada"<<endl;
	}
	float r = (float)t/CLOCKS_PER_SEC;
	printf("Tempo EB: %.8f", r);

	fclose(arq_1);
	return 0;
}
