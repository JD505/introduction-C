 #include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j,div,numPrimos=0, somaPrimos=0, numero;
	float media;


	printf("******************************Numeros Primos********************************************\n \n");
	srand(time(NULL));// semente para gerar numeros


	for (i=0; i< 100; i++){ 
		numero=rand()%1001;  //gera os numeros aleatoriamente
		div = 0;
		
		for(j=1;j<=numero;j++){ 
			if ((numero % j)== 0){ //verifica a divisao
			div++;
			}
		}
			
		if(div==2){ // verifica se tem apenas dois divisores
				
		printf("  E primo o numero:  %d \n", numero);
		numPrimos++;
		somaPrimos=somaPrimos+numero;
	
		} 
	}
						 	
		//se foram gerados primos calcula a media destes		
	if(numPrimos>0){			
		media=somaPrimos/(float)numPrimos; 
		printf(" \n \n A media dos primos gerados e: %.2f \n a soma dos primos e: %d",media, somaPrimos);
	}

	else 
	printf(" Nao gerou numeros primos");
	
	return 0; 
}
