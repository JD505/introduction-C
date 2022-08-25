#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int numero, i, resultado=1; //declaração de variaveis

	printf("===============Calculo Fatorial==============\n");
		
	printf(" Insira o numero inteiro: "); //recolha de dados
	scanf("%d", &numero);
	
	for(i=1; i<=numero; i++){ //ciclo para calculo do fatorial
		
		resultado= i*resultado;
	}
	
	printf(" Factorial de %d: %d", numero, resultado); //mostra o fatorial do numero pedido

	return 0;
}
