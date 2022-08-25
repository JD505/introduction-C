#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i, j, i1,j1; //declarção das variaveis como numeros inteiros
	int multiplicacao,resultado=0;//inicialização das variaveis a 0
	int invertido=0, numero=0;

	printf("===================Capicua=======================\n");
	
	for (i=100; i<=999 ; i++){ //ciclo que percorre um nos numeros da multiplicação
	
		for(j=100; j<=999 ; j++){ // ciclo que percorre o outro numero da multiplicação
			multiplicacao= (i*j);
		
			numero=multiplicacao;
   
 			do{
      		invertido=invertido*10+(numero%10);
	  		numero=numero/10;
    
			} while(numero>0);
		
			if(invertido==multiplicacao){ //condição que verifica se o numero invertido e igual ao numero por inverter
		
		 	if (multiplicacao>resultado){
				resultado=multiplicacao;
				i1=i;
				j1=j;
			}
		}
		
		invertido = 0;
			
		}
	}

	printf("\t O maior numero capicua e: \n \t %d = %d x %d", resultado, i1,j1); // mostra o maior capicua e os numeros multiplicados

	return 0;
}




