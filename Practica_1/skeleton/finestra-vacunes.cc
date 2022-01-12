#include <stdio.h>
 
int main() {
	int n, max, min;
	float tot, cont;
	char c;
	 
	tot 	= 0; // Inicalitzo el comptador de totals a 0
	cont 	= 0;  // Inicialitzo el comptador per a fer la mitja a 0
	min 	= 10000; // Inicialitzo el mínim, es suposa que no hi ha més de 10000 casos
	max 	= 0; // Inicialitzo el màxim a 0
 
	scanf("%c", &c);
	scanf("%i", &n);
 
	while (c != '#') { // Mentre no es trobi la marca de final ('#') es fa el tractament
		tot = tot + n; // Comptador per al total de vacunats
		cont++; // Contador per a fer la mitja
		scanf("%c", &c);
		scanf("%i", &n);
 
		if (n < min) { // Si el nombre és menor a l'inicialitzat, llavors aquest és el mínim.
			min = n;
		}
 
		if (n > max) { // Si el nombre és major a l'inicialitzat, llavors aquest és el màxim.
			max = n;
		}
	}
  
	printf("Màxim = %i\n", max); // Printejo el màxim de la sèrie de números.
	printf("Mínim = %i\n", min); // Printejo el mínim de la sèrie de números.
	printf("Mitja = %.2f\n", tot/cont); // Printejo la mitjana de la sèrie de números.
}