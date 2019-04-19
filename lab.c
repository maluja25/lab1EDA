
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "funciones.h"
//definimos una constante para el arreglo dinamico
#define MAX_LIN 1000
int main()
{
	//declaramos variables a ocupar
	clock_t comienzo,final;
	//puntero doble de double donde se almacenaran todos los datos del archivo de entrada "matriz.in"
	double **Imatriz;
	//igualamos la matriz al llamado de la funcion leermatriz()
	Imatriz = leermatriz();
	//imprimirMatriz(Imatriz);
	//reservamos memoria para la matriz
	matriz = (double **)malloc(sizeof(double *)*tamano);
	for (int i = 0; i < tamano; ++i)
	{
		//reservamos memoria para cada uno de los espacios de la matriz
		matriz[i] = (double *)malloc(sizeof(double )*tamano);
	}
	//imprimimos el tamano para verificar que lo haya tomado correctamente
	printf("tamano es :%i\n",tamano);
	//declaramos variables para iterar
	int i,j;
	//copiamos los datos de la Imatriz a matriz para que queden correctamentes ordenados , ya que en Imatriz en la posicion 0,0 se encuentra el tamaño del arreglo
	for (int i = 1; i < tamano + 1 ; ++i)
	{
		for (int j = 0; j < tamano ; ++j)
		{
			matriz[i-1][j] = Imatriz[i][j];
		}
	}
	comienzo = clock();
	//llamamos a la funcion triangular matriz
	TriangularMatriz();
	final = clock();
	//printf("el tiempo de triangularMatriz es : %f\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC );
	comienzo = clock();
	//imprimirMatriz(matriz);
	final = clock();
	//printf("el tiempo de imprimir es : %f\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC );
	comienzo = clock();
	//llamaos a la funcion multiplicacion para obtener el resultado final
	multiplicacion();
	final = clock();
	//printf("el tiempo de multiplicacion es : %f\n",1000.00*(final-comienzo)/CLOCKS_PER_SEC );
	return 0;
}