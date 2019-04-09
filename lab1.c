#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LIN 1000

void imprimirMatriz(float **Matriz);
//m y n nos daran el tamaño que posee nuestra matriz que viene en el archivo ,esta matriz viene con el tamaño incluido en la posicion 0.0
int m = 0 , n = 0;
int tamano;
float **leermatriz(){
   //fp es un dato tipo FILE y usando fopen para abrir el archivo de entrada .txt en modo lectura 
   FILE* fp1=fopen("matriz-6071.in","r");
   fscanf(fp1, "%i",&tamano);
   fclose(fp1);
   FILE* fp=fopen("matriz-6071.in","r");
   // linea[MAX_LIN] es un arreglo estatico de tamaño 1000 (MAX_LINE = 1000) donde en el se almacenar cada una de las lineas en el archivo de entrada .txt
   // *p es un puntero que utilizando la funcion strtok va a separar los datos según la separacion que deseamos dar.
   char linea[MAX_LIN], *p;
   // val es la variable que almacenara cada dato de la linea en dato entero para posteriormente guardarla en la matriz
   int val;
   // aqui reservamos memoria para la matriz con la funcion calloc
   float **matriz= (float **) calloc(1000, sizeof(float*)) ;
   //inicializamos m con valor -1
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL) {
     m=m+1;
     //aqui reservamos memoria para cada uno de los espacios de la matriz
     printf("La linea es : %s\n", linea);
     matriz[m] = (float *) calloc(MAX_LIN, sizeof(float));
     p = strtok(linea," ");
     n=-1;
     while(p != NULL) {
       n=n+1;
       //con sscanf le damos le asignamos a val el valor que contiene p para posteriormente asigarle val a matriz en la posicion m,n
       sscanf(p,"%d",&val);
       printf("%d\n",val);
       matriz[m][n] = val;
       p=strtok(NULL," ");
     }
   }
   imprimirMatriz(matriz);
   //retornamos la matriz con los datos del archivo de entrada.in en ella
   return matriz;
   fclose(fp);
}
float **matriz;
void imprimirMatriz(float **Matriz){
	for (int i = 0; i < tamano; ++i)
	{
		for (int j = 0; j < tamano; ++j)
		{
			printf("%f.",Matriz[i][j]);
		}
		printf("\n");
	}
}
void RestarALaFila(int f1,int f2,float m){
	for (int i = 0; i < tamano; ++i)
	{
		matriz[f2][i] = matriz[f2][i] + (matriz[f1][i] * m) ;
	}
}
void HacerCerosColum(int Ncol){
	int i = Ncol + 1;
	float n;
	while(i < tamano){
		n = -(matriz[i][Ncol] / matriz[Ncol][Ncol]);
		printf("n es %f\n",n);
		RestarALaFila(Ncol,i,n);
		i++;
	}
}
void Triangularla(){
	int i;
	for (int i = 0; i < tamano; ++i)
	{
		HacerCerosColum(i);
	}
}
void multiplicacion(){
	float resultado = 1;
	for (int i = 0; i < tamano; ++i)
	{
		resultado = resultado * matriz[i][i];
	}
	printf("el resultado es :%f\n",resultado);
}
int main()
{
	float **Imatriz;
	printf("aqui es la imatriz XD\n");
	Imatriz = leermatriz();
	imprimirMatriz(Imatriz);
	matriz = (float **)malloc(sizeof(float *)*tamano);
	for (int i = 0; i < tamano; ++i)
	{
		matriz[i] = (float *)malloc(sizeof(float )*tamano);
	}
	printf("tamano es :%i\n",tamano);
	int i,j;
	for (int i = 1; i < tamano + 1 ; ++i)
	{
		for (int j = 0; j < tamano ; ++j)
		{
			matriz[i-1][j] = Imatriz[i][j];
		}
	}
	imprimirMatriz(matriz);
	Triangularla();
	imprimirMatriz(matriz);
	multiplicacion();
	return 0;
}