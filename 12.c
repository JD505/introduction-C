#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float maior_menor_temperatura(float *tempOriginal, float *tempConvertida,int tamanho){ //procedimento maior/menor
	int i;
	float tempMaiorO, tempMaiorC, tempMenorO=tempOriginal[0], tempMenorC=tempConvertida[0];

	
	for(i=0; i <= tamanho;i++){
		
		// temperaturas mais altas
		if(tempOriginal[i]>tempMaiorO && tempConvertida[i]>tempMaiorC){
	
		tempMaiorO=tempOriginal[i];
		tempMaiorC=tempConvertida[i];
		}
		
		// temperaturas mais baixas
		if(tempOriginal[i]<tempMenorO&& tempConvertida[i]<tempMenorC){
		
	//	tempMenorC=tempConvertida[998];
		
		tempMenorO=tempOriginal[i];
		tempMenorC=tempConvertida[i];
		}
	}
	
	//mostra temperaturas mais altas e mais baixas
	printf("|__________________________________________________|\n");
	printf("| Maior | %-7.2f      |      %-7.2f              |\n", tempMaiorO, tempMaiorC);
	printf("| Menor | %-7.2f      |      %-7.2f              |\n", tempMenorO, tempMenorC);
	printf("|______________________|___________________________|\n");	
}
void conversor(float *tempOriginal,float *tempConvertida, char *unidade, int tamanho){
	int i, contador=0;
	float media, soma,aux;
	
	printf(" __________________________________________________\n");
	printf("|     celsius          |       kelvin              |\n");
	printf("|______________________|___________________________|\n");
	
	for(i=0;i<=tamanho;i++){
	
		if(unidade[i]=='c'){
			tempConvertida[i] = tempOriginal[i] - 273;
			
			contador++;
			contador++;
			
			printf("|    %-10.3f        |      %-10.3f           |\n", tempConvertida[i], tempOriginal[i]);
			printf("|______________________|___________________________|\n");
			
			aux=tempConvertida[i];
			tempConvertida[i]=tempOriginal[i];
			tempOriginal[i]=aux;
				
		}
		
		
		else if(unidade[i]=='k'){
			tempConvertida[i] = tempOriginal[i] + 273;
			
			contador++;
			contador++;
			
			printf("|    %-10.3f        |      %-10.3f           |\n",tempOriginal[i],tempConvertida[i]);
			printf("|______________________|___________________________|\n");
			
		} 				
		
		soma=soma+tempConvertida[i]+tempOriginal[i];
	}
		media=soma/contador;
		printf("|  media das temperaturas e: %-10.2f 	   |\n",media);
		
		maior_menor_temperatura(tempOriginal,tempConvertida, tamanho);
}
int main(int argc, char *argv[]) {
	int n=0, i;
	float tempInseridas[50], tempConvertidas[50];
	char escala[50];
	
	printf("===========================Conversor: kelvin <-> Celsius =======================================\n");	
	printf("ver tabela insira temperatura: 999 \n inserir k para converter para kelvin \n inserir c para converter para celsius\n \n");
	
	printf("Insira a temperatura: ");
	scanf("%f", &tempInseridas[n]);
	
	while(tempInseridas[n]!= 999){
		
		fflush(stdin);
		printf("insira a unidade k ou c: ");
		scanf("%c", &escala[n]);
	
		n++;
		
		fflush(stdin);
		printf("\n Insira a temperatura: ");
		scanf("%f", &tempInseridas[n]);
		
	}
	conversor(tempInseridas, tempConvertidas, escala, n);
	return 0;
}
