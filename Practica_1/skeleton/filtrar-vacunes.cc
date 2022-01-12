#include <stdio.h>
 
int main() {
 
   int n1;
   char c1, c2;
   char filtre1 = 'P', filtre2 = 'f'; // Caràcters filtres, en el meu cas Biotech (Pfizer)
 
 
   scanf("%c", &c1); // Escanejo c1 per a llegir el text .csv
   scanf("%c", &c2); // Escanejo c2 per a llegir el text .csv
 
   while (c2 != '#') { // Mentre no es troba la marca de final ('#') segueix en el bucle.
      if (c1 == filtre1 && c2 == filtre2) {
         c1 = c2; // Igualo les variables per a no haver d'usar unes altres, i poder-les usar per a llegir les condicions.
         scanf("%c", &c2);
 
         while (c1 != ',') { // Escaneja a fins quan hi ha una coma (elimino fins a les comes)
            scanf("%c", &c1);
         }
 
         while (c1 != '"') { // Escaneja a fins quan hi ha unes cometes (elimino fins a les cometes)
            scanf("%c", &c1);
         }
         scanf("%i", &n1); // Escanejo el número desitjat de vacunes del fabricant
         printf(",%i", n1); // Printejo el número del número de vacunats
 
      } else {
         c1 = c2;
         scanf("%c", &c2); // Seguir llegint mentre no reconeixi els filtres
      }
   }
   printf("#"); // Printeja la marca de final del llistat de números desitjats
}