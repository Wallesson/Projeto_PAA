#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h> //necessário p/ função time()
int main(){
	FILE *arquivo;
	arquivo = fopen("arquivo.txt", "w");
	
	int tamanho1;
	printf("informe o tamanho s1:\n");
	scanf("%d", &tamanho1);

	int v[tamanho1];
	char aux[tamanho1];
    srand(time(NULL));

	for(int i =0; i<tamanho1;i++){
		v[i]= rand() %4;
	}

	
	for(int i=0;i<tamanho1;i++){
		if(v[i]==0){aux[i]='a';}
		else if(v[i]==1){aux[i]='g';}
		else if(v[i]==2){aux[i]='t';}
		else if(v[i]==3){aux[i]='u';}
	}aux[tamanho1]= '\0';
	

	
	fprintf(arquivo,"%s" ,aux);
	printf("Blocos Gerados\n");
	fclose(arquivo);
	printf("Blocos Salvos");

	
	return 0;
}
