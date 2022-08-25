#include <stdio.h>
#include <stdlib.h>
double fatorial(int numero){ //funçao recurssiva calculo fatorial
  double resultado;
  
  if ( numero <= 1 )
    return (1);
  else
  {
    resultado = numero * fatorial(numero - 1);
    return (resultado);
  }
}
int main(int argc, char *argv[]) {

	int numero;

	printf("===============================Calculo Fatorial=================================\n \n");
	
	printf(" Insira um numero:"); //recolha de dados
	scanf("%d",&numero);

	printf(" O fatorial de %d e:   %0.lf",numero, fatorial(numero)); // mostrar resultados
	
	return 0;
}

