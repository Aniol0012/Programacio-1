// Aniol Serrano Exercici 1

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define P 20
#define C 30

/// Definim les funcions

void llegir_text(char paraules_spam[P+1][C+1], int cont[P+1]);
void llegir_nomes_text(char &c);
void buscar_spam(char paraules_spam[P+1][C+1], int cont[P+1], char paraules[P+1]);
void imprimir_resultat(float contador_paraules_repetides, float rati, int taxa_permissivitat);

// Funció Main

int main(){

	// Inicializacions
	char paraules_spam[P+1][C+1];
	int cont[P+1];
	float rati = 0;
	float contador_paraules_repetides = 0;
	int m = 0, b, n;
	char c = '\0';

	// Configurable

	int taxa_permissivitat = 50; // Taxa en % per a determinar si un text és spam o no.

	printf("Introdueix les paraules a identificar:\n");

	while(c != '.' and m < P) { // Mentres el contador no sigui major a la m
		b = 0;
		scanf("%c",&c);
		llegir_nomes_text(c);

		while(c != '.' and b < C and c != ' ' and c != '\n') {
			c = tolower(c);
			paraules_spam[m][b] = c;
			scanf("%c",&c);
			b++;

			if(c == '.' or c == ' ' or c == '\n') {
				rati = rati + 1;
			}
		}
		paraules_spam[m][b] = '\0';
		cont[m] = 0;
		m++;
	}
	paraules_spam[m][0] = '\0';

	llegir_text(paraules_spam, cont);

	printf("Relació de les paraules buscades:\n");

	for(n = 0; paraules_spam[n][0] != '\0'; n++){
		if(cont[n] >= 2){
			contador_paraules_repetides++;
		}

		printf("La paraula \"%s\" apareix %i vegada/es.\n", paraules_spam[n], cont[n]);
	}
	imprimir_resultat(contador_paraules_repetides, rati, taxa_permissivitat);
}

// Funcions extra

void llegir_text(char paraules_spam[P+1][C+1], int cont[P+1]){

	int p;
	char paraules[C+1];
	char final = '\0';

	printf("Introdueix el text acabat en doble punt:\n");
	printf("\n");

	while(final != '.') {
		while(final != '.') {
			p=0;
			llegir_nomes_text(final);

			while(final != ' ' && p < C && final != '.' && final != '\n' && final != ',') {
				final = tolower(final);
				paraules[p] = final;
				p++;
				scanf("%c",&final);
			}
			paraules[p] = '\0';
			buscar_spam(paraules_spam, cont, paraules);
		}
		scanf("%c",&final);
		llegir_nomes_text(final);
	}
}

// Funció per evitar que llegeixi del text els canvis de línea, els espais i les comes.

void llegir_nomes_text(char &c) {

	while(c == '\n' or c == ' ' or c == ',')	{
		scanf("%c",&c);
	}

}

void buscar_spam(char paraules_spam[P+1][C+1], int cont[P+1], char paraules[P+1]) {

	int n = 0, p = 0;

	while(n < P and paraules[p] != '\0') {
		p = 0;

		if(strlen(paraules_spam[n]) == strlen(paraules)) {
			while(paraules_spam[n][p] == paraules[p] and paraules[p] != '\0') {
				p++;
			}

			if(paraules[p] == '\0') {
				cont[n]++;
			}
		}
		n++;
	}
}

// Imprimimeixo el resultat de les paraules repetides i determino si les paraules repetides se troben mes del 50% o el que es determini en la "taxa_permissivitat" són o no missatges SPAM

void imprimir_resultat(float contador_paraules_repetides, float rati, int taxa_permissivitat) {
	printf("Rati: paraules amb 2 o més aparicions / total de paraules = %.0f / %.0f = %.3f \n", contador_paraules_repetides, rati, contador_paraules_repetides/rati);

	if (((contador_paraules_repetides/rati)*100) >= taxa_permissivitat) {
		printf("El missatge és SPAM.\n");
	} else {
		printf("El missatge no és SPAM.\n");
	}
	printf("\n");
}
