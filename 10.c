#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// funçao para contar o numero de pesos dentro do intervalo
int numeroPesos(float min, float max){ 
	//declaração de variaveis
	int contador=0;
	float peso,aux;
	
	//condição para verificação de maior e menor na correta posiçao
	if(min>max){
		aux=max;
		max=min;
		min=aux;
	}
	
	printf("Insira o peso, para ver resultados insira peso negativo:");
	scanf("%f",&peso);
	
	//recolha de pesos	
	while (peso>0) {

		if (peso>=min && peso<max) {
			contador++;
		}

	printf("Insira o peso, para ver os resultados insira peso negativo:");
	scanf("%f",&peso);
	}	
	
	//retorna o numero de pesos no intervalo
	return contador;
	}
int main(int argc, char *argv[]) {

	float minimo,maximo,peso;
	int numPesos;
	
	printf("############################ Pesos ########################## \n");	
	
	//recolha de dados
	printf("Insira o peso minimo do intervalo:");
	scanf("%f",&minimo);
	
	printf("Insira o peso maximo do intervalo:");
	scanf("%f",&maximo);
	

	
	// ver resultados
	numPesos=numeroPesos(minimo,maximo);
	printf("Foram inseridos %d pesos",numPesos);
	
	return 0;
}
