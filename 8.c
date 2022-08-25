#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fatorial(int numero) { //funçao calculo fatorial
	int i, resultado=1;

	for(i=1; i<=numero; i++) {
		resultado=resultado*i;
	}

	return resultado;
}
int main(int argc, char *argv[]) {

	int numero;

	printf("=========================Calculo Fatorial==================\n");

	printf("Insira um numero:"); //recolha de dados
	scanf("%d",&numero);

	printf("O fatorial de %d e:     %d",numero, fatorial(numero)); // mostrar resultados
	
	return 0;
}

