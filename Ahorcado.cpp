#include <stdio.h>
#include <stdlib.h>

void llenarGuiones(char b[], int cant);
void visualizarPalabra(char b[], int cant);
int jugar(char a[], char b[], int cant, char letra, int &intentos);
char busqueda(char a[], char letra, int cant, int &intentos);

main(){
	int n, intentos = 0, j=0;
	bool N=false;
	char x;
	char munieco[50][50]={"cabeza","tronco","brazo izquierdo","brazo derecho","pierna izquierda","pierna derecha",
	"mano izquierda", "mano derecha","pie izquierdo","pie derecho"};
	char letrasInc[50];
		
	printf("ingrese cuantas letras tiene la palabra\n");
	scanf("%d", &n);
	int faltan = n;
	char palabra[n];
	char guiones[n];
	
	for(int i=0; i<n; i++){
		_flushall();
		printf("ingrese la letra %d: \n", i+1);
		scanf("%c", &palabra[i]);
		if (palabra[i] >= 'a' && palabra[i]<='z') 
		{
			palabra[i] = palabra[i] - 32;
		}
	}
	
	llenarGuiones(guiones, n);	
	
	while (intentos < 10){
			
		system("cls");
		
		printf("\n\t\t\t\t\t\t\tAHORCADO");
		printf("\n\t\t\t\t\t\t\t---------");	
		
		printf("\n\nPalabra a adivinar: ");	
		visualizarPalabra(guiones, n);
		_flushall();
		
		printf("\n\ningrese una letra para adivinar la palabra: (intento n: %d)\n", intentos+1);
		scanf("%c", &x);
		
		if (x >= 'a' && x<='z' || x >= 'A' && x<='Z') 
		{
			bool correct = true; 
			
			if (x >= 'a' && x<='z')
			x = x - 32;
		
			if(intentos > 0)
			{
				busqueda(letrasInc, x, j, intentos);	
			}
			
			for(int i=0; i<n; i++)
			{
				if(palabra[i] == x)
				{
					correct = false;
					break;
				}	
			}
			
			if(correct == true)
			{
				letrasInc[j] = x;
				
				printf("\nLetras incorrectas ya ingresadas: ");
				for(int i=0; i<=j; i++)
				{
					printf("%c,", letrasInc[i]);
				}
		
				j++;
			}
			
			else
			{
				printf("\n\nLetras incorrectas ya ingresadas: ");
				
				for(int i=0; i<j; i++)
				{
					printf("%c,", letrasInc[i]);
				}
			}
			
			faltan = jugar(palabra, guiones, n, x, intentos);
			if (faltan == 0){
				printf("Usted a ganado!!!!");
				break;
			}
		
			printf("\n\nEstado del munieco: ");
			for(int i=0;i<intentos;i++){
				printf("%s |  ",munieco[i]);
			}
			
		}

		printf("\n\n");
		
		if (x<'A' || x > 'Z'){
		  printf("caracter no valido. Intentelo de nuevo!!\n");
		} 
		
		printf("\n\n");
		system("pause");
	}
	
	if (intentos == 10) printf("usted perdio: 0 puntos\n");
	else printf("%d puntos", 50-(2*intentos));
	
	printf("\n\n");
	system("pause");
}


void llenarGuiones(char b[], int cant){
	for (int i=0; i<cant; i++){
		b[i] = '_';
	}
}

void visualizarPalabra(char b[], int cant){
	for (int i=0; i<cant; i++){
		printf("%c ", b[i]);
	}
}

int jugar(char a[], char b[], int cant, char letra, int &intentos){
	
	int restan = 0;
	bool acerto = false;
	for(int i=0; i< cant; i++){
		if (a[i] == letra){
			b[i] = letra;	
			acerto = true;
		}
		if (b[i] == '_') restan++;
	}
	if (!acerto) intentos++;
	return restan;

}

char busqueda(char a[], char letra, int cant, int &intentos)
{
	bool N = false;
	
	for(int i=0; i<cant; i++)
	{
		if(letra == a[i])
		{
			N = true;	
		}
	}
	
	if(N == true)
	{
		intentos = intentos - 1;
		printf("\n\nEsta letra ya fue ingresada. Intentelo de nuevo!!");
	}
	
}







