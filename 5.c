#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	// declaração de variaveis e inicialização do contador
	int i, contador=0; 
	float peso;
	
	printf("######################## PESO ######################## \n ");
	
	// pedir o numero ao utilizador
	printf(" Insira o peso, para sair insira um numero negativo: ");
	scanf("%f", &peso); // guardar o numero na variavel peso

	for(i=0; peso>=0; i++){ // ciclo para pedir o peso ao utilizador, a condição de paragem é um numero negativo
		
		if(peso>=50 && peso<80){ // condição para selecionar os pesos entre 50 e 80
				
			contador++; // incrementação da variavel contador, para contar os pesos entre o intervalo pedido
		}
		
		printf("\n Insira o peso, para sair insira um numero negativo: "); 
		scanf("%f", &peso);
	}

	if(contador>0){
	// mostra quantos numeros foram intruduzidos entre o intervalo 50 a 80
	printf("\n Numeros de pesos: %d", contador);
	}
	
	else
	printf("\n Nao foram inseridos numeros dentro do intervalo");










	return 0;
}
