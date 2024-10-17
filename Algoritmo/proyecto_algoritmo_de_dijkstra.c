/*<-<-<-<-<- ALGORITMO DE DIJKSTRA PARA ENCONTRAR LA RUTA MAS CORTA >->->->->
Fecha de creación: 15/Septiembre/2024
Fecha de entrega: 19/Septiembre/2024

Creado por: Cruz Matias Allan Daniel

Descripción: El programa del algoritmo de Dijkstra su principal funcion es dado 
un nodo inicial encontrar la ruta más corta*/

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define INFINITY 9999
#define M 25

void impresion_matriz(float matriz[M][M], int nodo);
int mindistancia(float distancia[M], bool visitado[M], int nodo);
void impresion_solucion(float distancia[M], float vertice_vecino[M], int nodo_origen, int nodo_destino, int nodo, const char* nombres_nodos[]);
void imprimir_ruta(float vertice_vecino[M], int nodo_actual, const char* nombres_nodos[]);
void dijkstra(float matriz[M][M], int nodo_origen, int nodo_destino, int nodo, const char* nombres_nodos[]);
void margen(int c, int f);
void gotoxy(int x, int y);


int main() {
    int nodo = 24;  // Definir el número de nodos
    float matriz[M][M] = {  // Definir la matriz de adyacencia inicial
        {0, 217.78, 200.66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {217.78, 0, 51.74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {200.66, 51.74, 0, 370.68, 126.94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 370.68, 0, 239.91, 309.91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 126.94, 239.91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 309.91, 0, 0, 829.21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 829.21, 0, 136.17, 440.66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 136.17, 0, 0, 0, 300.13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 440.66, 0, 0, 398.36, 448.64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 398.36, 0, 0, 0, 0, 0, 0, 1053, 0, 0, 0, 0, 0, 2000, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 300.13, 448.64, 0, 0, 207.63, 0, 0, 0, 0, 0, 0, 0, 357.91, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207.63, 0, 278.68, 323.36, 0, 0, 0, 0, 0, 438.54, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 278.68, 0, 203.92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323.36, 203.92, 0, 267.14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 267.14, 0, 93.95, 0, 0, 261.57, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93.95, 0, 511.31, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1053, 0, 0, 0, 0, 0, 511.31, 0, 97.02, 0, 0, 0, 669.08, 473.66, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97.02, 0, 413.34, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261.57, 0, 0, 413.34, 0, 369.19, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 438.54, 0, 0, 0, 0, 0, 0, 369.19, 0, 108.26, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 357.91, 0, 0, 0, 0, 0, 0, 0, 0, 108.26, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 669.08, 0, 0, 0, 0, 264.89, 344.79},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0, 0, 0, 446.55, 0, 0, 0, 0, 344.79, 0, 217.17},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 473.66, 0, 0, 0, 0, 217.17, 0, 0}
        
        //V1: UMAR						//V7: CFMOTO PUERTO ESCONDIDO		//V13: BODEGA AURRERA		//V19: MODATELAS		
        //V2: SIX						//V8:  TERMINAL TURISTICA 			//V14: KORE´S PIZZA	 		//V20: COPPEL AVENIDA OAXACA			
        //V3: GASERA					//V9:  OXXO DE COSTA CHICA			//V15: PARISINA				//V21: CFE		
        //V4: COLONIA AEROPUERTO		//V10: BACOCHO						//V16: DHL					//V22: BANCO BBVA
        //V5: GASOLINERA PEMEX			//V11: CONALEP						//V17: CHEDRAUI				//V23: PLAYA PRINCIPAL
        //V6: GASOLINERA G500			//V12: MERCADO BENITO JUAREZ		//V18: MILANO	 			//V24: PLAYA MARINERO
    };
    
	int c = 13, f = 2;
    margen(c, f);

    const char* nombres_nodos[M] = {  
        "UMAR",	"SIX", "GASERA", "COLONIA AEROPUERTO", "GASOLINERA PEMEX", "GASOLINERA G500",
        "CFMOTO PUERTO", "TERMINAL TURISTICA", "OXXO DE COSTA CHICA", "BACOCHO", "CONALEP",
        "MERCADO BENITO JUAREZ", "BODEGA AURRERA", "KORE´S PIZZA", "PARISINA", "DHL",
        "CHEDRAUI", "MILANO", "MODATELAS", "COPPEL AVENIDA OAXACA", "CFE", "BANCO BBVA",
        "PLAYA PRINCIPAL", "PLAYA MARINERO"
    };

    int opcion, nodo_origen, nodo_destino;
    
    do {
    	system("cls");
    	margen(c, f);
        
        gotoxy(45,5); printf("ALGORITMO DE DIJKSTRA EN PUERTO ESCONDIDO");
    
    	gotoxy(58,8); printf("--|-- MENU --|--");
    	gotoxy(48,10); printf("Matriz de adyacencia..........[ 1 ]");
	    gotoxy(48,11); printf("Encontrar la ruta mas corta...[ 2 ]");
	    gotoxy(48,12); printf("Salir.........................[ 3 ]");
        gotoxy(48,14); printf("Seleccione una opcion.........[   ]");
    	gotoxy(80,14); scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                system("cls"); 
                impresion_matriz(matriz, nodo); 
                gotoxy(77, 22); system("pause"); 
                break;
            case 2:
                system("cls"); 
                margen(c, f);
                gotoxy(45,5); printf("ALGORITMO DE DIJKSTRA EN PUERTO ESCONDIDO");
                gotoxy(48,9); printf("Ingrese el nodo de origen (1 a %d): ", nodo);
                gotoxy(85,9); scanf("%d", &nodo_origen);
                nodo_origen = nodo_origen - 1;
                
                gotoxy(48,10); printf("Ingrese el nodo de destino (1 a %d): ", nodo);
                gotoxy(85,10); scanf("%d", &nodo_destino);
                nodo_destino = nodo_destino - 1;
                
                system("cls"); 
                dijkstra(matriz, nodo_origen, nodo_destino, nodo, nombres_nodos);
                gotoxy(77, 22); system("pause");
                break;
            case 3:
                break;
            default:
                printf("\nOpcion no valida.\n");
                gotoxy(77, 22); system("pause");
        }
    } while(opcion != 3);

    return 0;
}

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dijkstra(float matriz[M][M], int nodo_origen, int nodo_destino, int nodo, const char* nombres_nodos[]) 
{
    float distancia[M];           
    bool visitado[M];            
    float vertice_vecino[M];      
    int i, j;


    for (i = 0; i < nodo; i++) 
	{
        distancia[i] = INFINITY;
        visitado[i] = false;
        vertice_vecino[i] = -1;
    }
    distancia[nodo_origen] = 0;

    for (i = 0; i < nodo - 1; i++) 
	{
        int u = mindistancia(distancia, visitado, nodo);
        visitado[u] = true;

        for (j = 0; j < nodo; j++) 
		{
            if (!visitado[j] && matriz[u][j] && distancia[u] != INFINITY && distancia[u] + matriz[u][j] < distancia[j]) 
			{
                distancia[j] = distancia[u] + matriz[u][j];
                vertice_vecino[j] = u;
            }
        }
    }

    gotoxy(25,10); printf("Ruta mas corta de %s a %s:", nombres_nodos[nodo_origen], nombres_nodos[nodo_destino]);
    imprimir_ruta(vertice_vecino, nodo_destino, nombres_nodos);
    gotoxy(25,15); printf("Distancia total: %.2f", distancia[nodo_destino]);
}


int mindistancia(float distancia[M], bool visitado[M], int nodo) 
{
    float min = INFINITY;
    int min_indice;
    int v;
    
    for (v = 0; v < nodo; v++) 
	{
        if (!visitado[v] && distancia[v] <= min) 
		{
            min = distancia[v];
            min_indice = v;
        }
    }
    return min_indice;
}

void impresion_solucion(float distancia[M], float vertice_vecino[M], int nodo_origen, int nodo_destino, int nodo, const char* nombres_nodos[]) 
{
    int c = 13, f = 2;
	margen(c, f);
	gotoxy(45,5); printf("ALGORITMO DE DIJKSTRA EN PUERTO ESCONDIDO");
	gotoxy(50, 9); printf("Nodo de origen: %s\n", nombres_nodos[nodo_origen]);
    gotoxy(50,10); printf("Nodo de destino: %s\n", nombres_nodos[nodo_destino]);
    gotoxy(50,11);printf("Distancia minima: %.2f\n", distancia[nodo_destino]);
    gotoxy(50,12); printf("Ruta: ");
    imprimir_ruta(vertice_vecino, nodo_destino, nombres_nodos);
}

void imprimir_ruta(float vertice_vecino[M], int nodo_actual, const char* nombres_nodos[]) 
{
	int c = 13, f = 2;
	margen(c, f);
    if (vertice_vecino[nodo_actual] == -1) 
	{
        gotoxy(25,12);printf("%s ", nombres_nodos[nodo_actual]);
        return;
    }

    imprimir_ruta(vertice_vecino, (int)vertice_vecino[nodo_actual], nombres_nodos);
    printf(" -> %s ", nombres_nodos[nodo_actual]);
}

void impresion_matriz(float matriz[M][M], int nodo) 
{
	int i, j;
    for (i = 0; i < nodo; i++) 
	{
        for ( j = 0; j < nodo; j++) 
		{
            if (matriz[i][j] == 0) 
			{
                printf("0 ");
            } else {
                printf("%.2f ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void margen(int c, int f) 
{
    int i, p, q, j, m = 40, l = 4;

    gotoxy(c, f);
    printf("%c", 201);

    for (i = 0; i < 105; i++) 
	{
        gotoxy(c + i + 1, f);
        printf("%c", 205);
        for (j = 0; j < 20; j++) 
		{
            gotoxy(c, f + 1 + j);
            printf("%c", 186);

            gotoxy(c + 105, f + 1 + j);
            printf("%c", 186);
        }
        gotoxy(c + i + 1, f + 21);
        printf("%c", 205);
    }

    gotoxy(c, f + 21);
    printf("%c", 200);

    gotoxy(c + 105, f);
    printf("%c", 187);

    gotoxy(c + 105, f + 21);
    printf("%c", 188);

    gotoxy(m, l);
    printf("%c", 201);

    for (p = 0; p < 50; p++) 
	{
        gotoxy(m + p + 1, l);
        printf("%c", 205);
        for (q = 0; q < 2; q++) 
		{
            gotoxy(m, l + 1 + q);
            printf("%c", 186);

            gotoxy(m + 50, l + 1 + q);
            printf("%c", 186);
        }
        gotoxy(m + p + 1, l + 2);
        printf("%c", 205);
    }

    gotoxy(m, l + 2);
    printf("%c", 200);

    gotoxy(m + 50, f + 2);
    printf("%c", 187);

    gotoxy(m + 50, f + 4);
    printf("%c", 188);
}






