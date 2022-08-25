 #include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int primo(int num){ //funçao verifica se o numero é primo 
	int i, div = 0;

	for(i=1;i<=num;i++){
	
		if ((num % i)== 0){
			div++;
			
		}
	
		if(div>2){
			return 0;
		}
	}

/*	if(div==2){
		return 1;
	} 
	
	else
	return 0;
*/	
	
	return 1;
}
int main(int argc, char *argv[]) {
	
	int i,numPrimos=0, somaPrimos=0, numero, nPrimo;
	float media;


	printf("******************************Numeros Primos********************************************\n \n");
	srand(time(NULL));

	for (i=0; i< 100; i++){
		numero=rand()%1001; //gera os numeros
		
		nPrimo=primo(numero); //invoca a funçao
		
		if(nPrimo==1){
				
		printf("  E primo o numero:  %d \n", numero); //mostra os primos
		numPrimos++;
		somaPrimos=somaPrimos+numero;
	
		} 
		
	}
	// mostra a media e a soma dos primos			 					
	if(numPrimos>0){			
		media=somaPrimos/(float)numPrimos;
		printf(" \n \n A media dos primos gerados e: %.2f \n a soma dos primos e: %d",media, somaPrimos); 
	}

	else 
	printf(" Nao gerou numeros primos"); 
	
	return 0; 
}
