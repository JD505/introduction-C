#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int numEstudantes=0, idade, feminino=0, masculino=0, estudantesNao=0;
	char genero[15], curso[5];
	
	
	puts("##################### Questionario ########################### \n");
	//recolha de dados do utilizador
	puts(" Insira genero feminino ou masculino:\n - ver resultados stop- ");
	scanf("%s", genero);
	
	while(stricmp(genero,"stop")!=0){
	
		numEstudantes++; //numero de estudantes total
	
		puts(" Insira a sua idade: ");
		scanf("%d", &idade);
		
		puts(" Esta a gostar do seu curso, insira: \t sim ou nao ");
		scanf("%s", curso);
		
		if (stricmp(genero,"masculino")==0){
			masculino++; // numero de estudantes do genero masculino
			
			if(idade<23){
				if(stricmp(curso, "nao")==0){
				estudantesNao++; //numero de estudantes do genero masculino que nao gostam do curso
				}
			}
			
		}
		
		else if(stricmp(genero,"feminino")==0){
			feminino++;// numero de estudantes do genero masculino
		}
		
		puts(" Insira genero feminino ou masculino:\n -ver resultados insira stop- ");
		scanf("%s", genero);
	}
	
	//mostrar resultados
	printf(" O numero de estudantes intrevistados foram : %d", numEstudantes);
	printf(" \n Dos esudantes %d%% eram do genero feminino e %d%% do genero masculino", (feminino*100)/numEstudantes, (masculino*100)/numEstudantes);
	printf(" \n Os estudantes do genero masculino com menos de 23 anos que nao gostam do curso sao : %d ", estudantesNao);
	
	
	
	
	
	return 0;
}
