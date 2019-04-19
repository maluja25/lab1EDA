#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//definimos una constante para el arreglo dinamico
#define MAX_LIN 1000
void imprimirMatriz(double **Matriz);
//m y n nos daran el tamaño que posee nuestra matriz que viene en el archivo ,esta matriz viene con el tamaño incluido en la posicion 0.0
int m = 0 , n = 0;
int tamano;
double **leermatriz(){
   //fp es un dato tipo FILE y usando fopen para abrir el archivo de entrada .txt en modo lectura 
   FILE* fp1=fopen("matriz3.in","r");
   fscanf(fp1, "%i",&tamano);
   fclose(fp1);
   FILE* fp=fopen("matriz3.in","r");
   // linea[MAX_LIN] es un arreglo estatico de tamaño 1000 (MAX_LINE = 1000) donde en el se almacenar cada una de las lineas en el archivo de entrada .txt
   // *p es un puntero que utilizando la funcion strtok va a separar los datos según la separacion que deseamos dar.
   char linea[MAX_LIN], *p;
   // val es la variable que almacenara cada dato de la linea en dato entero para posteriormente guardarla en la matriz
   int val;
   // aqui reservamos memoria para la matriz con la funcion calloc
   double **matriz= (double **) calloc(1000, sizeof(double*)) ;
   //inicializamos m con valor -1
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL) {
     m=m+1;
     //aqui reservamos memoria para cada uno de los espacios de la matriz
     //printf("La linea es : %s\n", linea);
     matriz[m] = (double *) calloc(MAX_LIN, sizeof(double));
     p = strtok(linea," ");
     n=-1;
     while(p != NULL) {
       n=n+1;
       //con sscanf le damos le asignamos a val el valor que contiene p para posteriormente asigarle val a matriz en la posicion m,n
       sscanf(p,"%d",&val);
       //printf("%d\n",val);
       matriz[m][n] = val;
       p=strtok(NULL," ");
     }
   }
   //imprimirMatriz(matriz);
   //retornamos la matriz con los datos del archivo de entrada.in en ella
   return matriz;
   fclose(fp);
}
//puntero double de dos dimensiones para almacenar las filas y columnas del archivo de entrada.
double **matriz;
/*
void imprimir(matriz)
entradas: matriz 
salidas: nada
funcion que imprime por pantalla la matriz que ingresa.
*/
void imprimirMatriz(double **Matriz){
	//iniciamos un for hasta el tamaño de la matriz para las columnas
	for (int i = 0; i < tamano; ++i)
	{
		//iniciamos un for hasta el tamaño de la matriz para las filas
		for (int j = 0; j < tamano; ++j)
		{
			//funcion printf para imprimir por pantalla el tipo de dato que queremos , en este caso el %f nos permite imprimir un double.
			printf(" %f ",Matriz[i][j]);
			//sleep(1);
		}
		//salto de linea
		printf(" \n ");
	}
}
/*
void RestarALaFila(fila 1 , fila 2 , m)
entradas:
numero de la fila 1
numero de la fila 2 
m = numero con el cual se anula el termino siguiente para triangular la diagonal hacia abajo con ceros
salida : nada.
funcion que resta la fila 1 con la fila 2 , modificando la fila 2 para que esta se haga 0.
*/
void RestarALaFila(int f1,int f2,double anulador){
	//iniciamos un for hasta el tamano.
	for (int i = 0; i < tamano; ++i)
	{
		//sumamos el numero de la fila 2 con el numero de la fila 1 por M.
		
		/*if(m == 0){
			matriz[f2][i] = matriz[f2][i];
		}else{
			matriz[f2][i] = matriz[f2][i] + (matriz[f1][i] * m) ;
		}
		*/
		matriz[f2][i] = matriz[f2][i] + (matriz[f1][i] * anulador) ;
		//sleep(1); 
		
	}
}
/*
void HacerCerosColumna(numero de columna)
entradas:
Ncol = es el numero de la columa a la que se quiere hacer cero.
salidas:nada
*/
void HacerCerosColumna(int Ncol){
	int i = Ncol + 1;
	double n;
	while(i < tamano){
		//printf("pos1 %i,%i\n",i,Ncol);
		//printf("pos2 %i,%i\n",Ncol,Ncol);
		//printf("n1 es %f,n2 es %f \n",matriz[i][Ncol],matriz[Ncol][Ncol]);
		if(matriz[i][Ncol] != 0){
			n = -(matriz[i][Ncol] / matriz[Ncol][Ncol]);
			RestarALaFila(Ncol,i,n);
				//sleep(1);
		}else{
			RestarALaFila(Ncol,i,0);
	    }
		//printf("n es %f\n",n);
		//printf("\n\n\n\n\n\n\n\n\n");
		
		i++;
	}
}
/*
TriangularMatriz()
funcion que triangula la matriz tomando la diagonal central como punto de referencia para que todo lo que estaba bajo la diagonal central se haga cero
llamando a la funcion HacerCerosColumna() indicandole el numero de la columna.
entradas: nada
salidas: nada
*/
void TriangularMatriz(){
	//variable entera i para iterar
	int i;
	//iniciamos un for desde i=0 hasta el tamano del arreglo.
	for (int i = 0; i < tamano; ++i)
	{
		//llamamos a la funcion HacerCerosColumna() con i como parametro de entrada para ir haciendo 0 las columnas respectivas
		HacerCerosColumna(i);
		//imprimirMatriz(matriz);
		//sleep(1);

	}
}
/*
multiplicacion()
funcion que realiza la multiplicacion de todos los numeros de la diagonal central una vez hecho la triangulacion de esta para obtener el determinante de la matriz
entrada:nada
salida:nada
*/
void multiplicacion(){
	double resultado = 1;
	for (int i = 0; i < tamano; ++i)
	{
		resultado = resultado * matriz[i][i];
	}
	printf("el determinante es : %f \n",resultado);
}