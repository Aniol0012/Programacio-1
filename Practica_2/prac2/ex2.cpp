// Aniol Serrano Exercici 2

#include <stdio.h>
#define M 9

// Defineixo les funcions


void imprimir_sudoku(int sudoku[M][M]);
void llegir_sudoku(int sudoku[M][M]);
int comprovar_sudoku(int revisar_row[M], int revisar_col[M], int sudoku[M][M]);
bool verificar_row(int sudoku[M][M], int row, int col, int pos);
bool verificar_col(int sudoku[M][M], int row, int col, int pos);
bool verificar_regio(int sudoku[M][M], int row, int col, int pos);
int trobar_regio(int value);

// Funció main

int main() {

	int revisar_col[M];
	int revisar_row[M];
	int sudoku [M][M] = {};

	llegir_sudoku(sudoku); // Llegeix el sudoku
	imprimir_sudoku(sudoku); // Imprimeix el sudoku
	comprovar_sudoku(revisar_row,revisar_col,sudoku); // Comprova si la solució és correcta
}

// Funcions extra

// Imprimir la graella del SUDOKU

void imprimir_sudoku(int sudoku[M][M]){
	int a, b;
	for(b = 0; b < M; b++){
		printf("│───│───│───│───│───│───│───│───│───│\n"); // Imprimeixo vertical
		for(a = 0; a < M; a++){
			printf("│ %i ", sudoku[a][b]); // Primera
		}
		printf("│\n"); // Ultima
	}
	printf("│───│───│───│───│───│───│───│───│───│\n");
}

// LLegir el sudoku i guardarlo en una taula

void llegir_sudoku(int sudoku[M][M]){
	int a, b;
	printf("Introdueix un sudoku 9x9 per a comprovar si és correcte o no:\n");
	for(b = 0; b < M; b++){
		for(a = 0; a < M; a++){
			scanf("%i", &sudoku[a][b]);
		}
	}
	printf("\n");
}

// Comprova si la solució és correcta

int comprovar_sudoku(int revisar_row[M], int revisar_col[M],int sudoku[M][M]){
	for(int c = 0; c < M ; c++) {
		for (int d = 0; d < M ; d++) {
			int pos = sudoku[c][d];
			if (verificar_row(sudoku, c,d, pos)) {
				printf("\n");
				printf("El sudoku introduït té un error en la fila %i.\nLa solució al Sudoku és INCORRECTA!\n",d+1);
				printf("\n");
				return -1;
			}
			if (verificar_col(sudoku, c,d, pos)) {
				printf("\n");
				printf("El sudoku introduït té un error en la columna %i.\nLa solució al Sudoku és INCORRECTA!\n",c+1);
				printf("\n");
				return -1;
			}
			if (verificar_regio(sudoku, c, d, pos)) {
				printf("\n");
				printf("El sudoku introduït té un error en la regió %i,%i.\nLa solució al Sudoku és INCORRECTA!\n",trobar_regio(c),trobar_regio(d));
				printf("\n");
				return -1;
			}
		}
	}
	printf("La solució al Sudoku és CORRECTA!\n");
	printf("\n");
	return 0;
}

// Verificar el SUDOKU

bool verificar_row(int sudoku[M][M], int row, int col, int pos){
	row++;
	while(M>row) {
		if (sudoku[row][col] == pos)
			return true;
		row++;
	}
	return false;
}

bool verificar_col(int sudoku[M][M], int row, int col, int pos){
	col++;
	while(M>col) {
		if (sudoku[row][col] == pos)
			return true;
		col++;
	}
	return false;
}
bool verificar_regio(int sudoku[M][M], int row, int col, int pos){
	for(int c = row ; c%3 > 0 ; c++) // Graella de 3 x 3 (linea)
		for(int d = col; d%3 > 0 ; d++) // Graella de 3 x 3 (columna)
			if(sudoku[c][d] == pos && !(c == row && col == d))
				return true;
	return false;
}

// Trobar en quina regió està per a identificar l'error

int trobar_regio(int value) {
	if (value > 0 and value <= 2) // De la 1a a la 3a (0-2)
		return 1;
	else if( value > 2 and value<=5) // De la 3a a la 6a (2-5)
		return 2;
	else if(value> 5 and value <=8) // De la 6a a la 9a (5-8)
		return 3;
	else
		return -1;
}
