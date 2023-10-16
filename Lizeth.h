#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int validarNumeros(char mensaje[], int ri, int rf);
int validarLetras(const char mensaje[], char nombre[], int tam);
int Buscar(int vect[], int n, int num);
int repetir();
int VectSinRep(int vec[], int n, int ri, int rf);
int random(int ri, int rf);
int imprimirVec(char msg[], int vec[], int n);
void matriz4x4(int matriz[4][4], int ri, int rf);
void imprimirMatriz(int matriz[][4], int m, int n, char mensaje[]);
void ordenarVec(int vec[], int n);

void buscarValor(int vec[], int n)
{
    int i, encontrado = 0, numero;
    numero = validarNumeros("INGRESE EL NUMERO: ", 0, 10000);
    for (i = 0; i < n; i++)
    {
        if (vec[i] == numero)
        {
            printf("El numero %d se encuentra el el lugar [%d]\n", numero, i);
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        printf("El numero no se encuentra en el vector\n");
    }
}

void ordenarVec(int vec[], int n)
{
    int i, j, temp;
    int ordenado = 0;

    for (i = 0; i < n - 1; i++)
    {
        ordenado = 1;
        for (j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                ordenado = 0;
            }
        }
    }
}

void imprimirMatriz(int matriz[][4], int m, int n, char mensaje[])
{
    int i, j;
    printf("%s:\n", mensaje);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%3d]  ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matriz4x4(int matriz[4][4], int ri, int rf)
{
    srand(time(NULL));
    int i, j, repe, vec[16];
    for (i = 0; i < 16; i++)
    {
        do
        {
            vec[i] = random(ri, rf);
            repe = 0;
            for (j = 0; j < i; j++)
            {
                if (vec[i] == vec[j])
                {
                    repe = 1;
                }
            }
        } while (repe == 1);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz[i][j] = vec[i * 4 + j];
        }
    }
}

int validarNumeros(char mensaje[], int ri, int rf)
{
    char entrada[100];
    int num;
    do
    {
        printf("%s", mensaje);
        fgets(entrada, sizeof(entrada), stdin);
        num = atoi(entrada);
        if (num < ri || num > rf)
        {
            printf("\nINGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}

int validarLetras(const char mensaje[], char nombre[], int tam)
{
    char entrada[1000];
    int i;
    int entradaValida;

    do
    {
        entradaValida = 1;
        printf("%s", mensaje);
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        for (i = 0; entrada[i] != '\0'; i++)
        {
            if (!isalpha(entrada[i]))
            {
                entradaValida = 0;
                printf("Cadena no válida. Deben ser solo letras.\n");
                break;
            }
            else
            {
                entrada[i] = toupper(entrada[i]);
            }
        }
    } while (!entradaValida);

    strncpy(nombre, entrada, tam - 1);
    nombre[tam - 1] = '\0';
}

int repetir()
{
    int repetir;
    repetir = validarNumeros("QUIERES HACER OTRA OPCION\nSI=1\nNO=2\n", 1, 2);
    if (repetir == 1)
    {
        return 1;
    }
    else
    {
        printf("FIN DEL PROGRAMA");
        return 0;
    }
}

int Buscar(int vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int VectSinRep(int vec[], int n, int ri, int rf)
{
    int i, num;
    for (i = 0; i < n; i++)
    {
        do
        {
            num = random(ri, rf);
        } while (Buscar(vec, i, num) != -1);
        vec[i] = num;
    }
}

int random(int ri, int rf)
{
    int r;
    r = (rf - ri) + 1;
    return (rand() % r) + ri;
}

int imprimirVec(char msg[], int vec[], int n)
{
    int i;
    printf("%s\n", msg);
    for (i = 0; i < n; i++)
    {
        printf("[%1d]\n", vec[i]);
    }
}
