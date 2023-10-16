/* Lizeth Barrios Retana 372813
10-Oct-2023
REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.

        MENÚ
    1.- AGREGAR (AUTOM 10 REGISTROS)
    2.- AGREGAR MANUAL
    3.- ELIMINAR REGISTRO (lógico)
    4.- BUSCAR
    5.- ORDENAR
    6.- IMPRIMIR
    0.- SALIR

UTILIZAR UN ARREGLO DE 500 REGISTROS
SE DEBERÁ UTILIZAR ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN ALUMNO ( status, Matricula, ApPat,
ApMat, Nombre, Edad, Sexo )
Busqueda y Ordenacion por campo MATRICULA
BRL_Act10_01_932
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Lizeth.h"

struct InfoAlumno
{
    char Nombre[20];
    char ApMat[20];
    char ApPat[20];
    int matricula;
    char estado[20];
    int edad;
    char sexo[10];
};
char hombres[20][10] = {"JUAN", "PEDRO", "CARLOS", "LUIS", "JAVIER", "ANDRES", "ALEJANDRO", "MIGUEL", "JOSE", "ADAN", "JORGE", "GABRIEL", "ROBERTO", "DAVID", "FERNANDO", "RAUL", "EDUARDO", "SERGIO", "ANTONIO", "FRANCISCO"};

char mujeres[20][10] = {"DANIELA", "LAURA", "ANA", "CARMEN", "SOFIA", "ISABEL", "MARTA", "PAULA", "ELENA", "PATRICIA", "LUCIA", "CLARA", "ROSA", "BEATRIZ", "CAROLINA", "JULIA", "TERESA", "SARA", "IRENE", "ADRIANA"};

char ApMat[20][10] = {"PEREZ", "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "SANCHEZ", "RAMIREZ", "TORRES", "FLORES", "GARCIA", "DIAZ", "FERNANDEZ", "RUIZ", "CASTRO", "MORALES", "ORTIZ", "HERRERA", "BARRIOS", "JIMENEZ", "SILVA"};

char ApPat[20][10] = {"CRUZ", "LOZANO", "ROJAS", "REYES", "MENDOZA", "GUZMAN", "ROMERO", "VASQUEZ", "MUNOZ", "GOMEZ", "LUNA", "SANTOS", "CUEVAS", "CHAVEZ", "MEDINA", "DELGADO", "GALLEGOS", "MIRANDA", "RETANA", "RIOS"};

char stat[4][20] = {"DADO DE BAJA", "BAJA TEMPORAL", "MATRICULADO", "EGRESADO"};
char sexo[2][10] = {"HOMBRE", "MUJER"};
int genero, nombres;

void agregarAutom(struct InfoAlumno estudiantes[], int n);
void imprimir(struct InfoAlumno estudiantes[], int numEstudiantes);
void agregarManual(struct InfoAlumno estudiantes[], int *numEstudiantes);
void eliminarRegistro(struct InfoAlumno estudiantes[], int *numEstudiantes);
void buscar(struct InfoAlumno estudiantes[], int *numEstudiantes);
void ordenar(struct InfoAlumno estudiantes[], int numEstudiantes);

int main()
{
    srand(time(NULL));
    struct InfoAlumno estudiantes[500];
    int opcion, menu, i;
    int numEstudiantes = 0;
    do
    {
        menu = 0;

        opcion = validarNumeros("\n===MENU===\n1.- AGREGAR\n2.- AGREGAR MANUAL\n3.- ELIMINAR REGISTRO (logico)\n4.- BUSCAR\n5.- ORDENAR\n6.- IMPRIMIR\n0.- SALIR\n", 0, 6);
        switch (opcion)
        {
        case 1:
            for (i = numEstudiantes; i < numEstudiantes + 10; i++)
            {
                agregarAutom(estudiantes, i);
            }
            numEstudiantes += 10;
            menu = repetir();
            break;
        case 2:
            agregarManual(estudiantes, &numEstudiantes);
            menu = repetir();
            break;
        case 3:
            eliminarRegistro(estudiantes, &numEstudiantes);
            menu = repetir();
            break;
        case 4:
            buscar(estudiantes, &numEstudiantes);
            menu = repetir();
            break;
        case 5:
            ordenar(estudiantes, numEstudiantes);
            menu = repetir();
            break;
        case 6:
            imprimir(estudiantes, numEstudiantes);
            menu = repetir();
            break;
        case 0:
            printf("FIN DEL PROGRAMA!\n");
            return 0;
        }
    } while (menu == 1);

    return 0;
}
void agregarAutom(struct InfoAlumno estudiantes[], int n)
{

    strcpy(estudiantes[n].ApPat, ApPat[random(1, 20)]);
    strcpy(estudiantes[n].ApMat, ApMat[random(1, 20)]);
    estudiantes[n].matricula = random(100000, 500000);
    strcpy(estudiantes[n].estado, stat[random(0, 3)]);
    estudiantes[n].edad = random(18, 40);
    genero = random(0, 1);
    nombres = random(1, 2);

    if (nombres == 1)
    {
        if (genero == 0)
        {
            strcpy(estudiantes[n].sexo, "HOMBRE");
            strcpy(estudiantes[n].Nombre, hombres[random(0, 19)]);
        }
        else
        {
            strcpy(estudiantes[n].sexo, "MUJER");
            strcpy(estudiantes[n].Nombre, mujeres[random(0, 19)]);
        }
    }
    else
    {
        if (genero == 0)
        {
            strcpy(estudiantes[n].sexo, "HOMBRE");
            strcpy(estudiantes[n].Nombre, hombres[random(0, 19)]);
            strcat(estudiantes[n].Nombre, " ");
            strcat(estudiantes[n].Nombre, hombres[random(0, 19)]);
        }
        else
        {
            strcpy(estudiantes[n].sexo, "MUJER");
            strcpy(estudiantes[n].Nombre, mujeres[random(0, 19)]);
            strcat(estudiantes[n].Nombre, " ");
            strcat(estudiantes[n].Nombre, mujeres[random(0, 19)]);
        }
    }
}

void agregarManual(struct InfoAlumno estudiantes[], int *numEstudiantes)
{
    if (*numEstudiantes >= 500)
    {
        printf("EL LIMITE DEL REGISTRO HA SIDO ALCANZADO\n");
        return;
    }

    struct InfoAlumno *persona = &estudiantes[*numEstudiantes];
    int status, matricula, edad, genero;
    char ApPat[20], ApMat[20], segundoNombre[20];
    nombres = validarNumeros("TIENES 1 O 2 NOMBRES?\n", 1, 2);
    if (nombres == 2)
    {
        validarLetras("INGRESE EL PRIMER NOMBRE: ", persona->Nombre, sizeof(persona->Nombre));
        validarLetras("INGRESE EL SEGUNDO NOMBRE: ", segundoNombre, sizeof(segundoNombre));
        strcat(persona->Nombre, " ");
        strcat(persona->Nombre, segundoNombre);
    }
    else
    {
        validarLetras("INGRESE EL NOMBRE: ", persona->Nombre, sizeof(persona->Nombre));
    }
    validarLetras("INGRESE EL APELLIDO PATERNO: ", persona->ApPat, sizeof(persona->ApPat));
    validarLetras("INGRESE EL APELLIDO MATERNO: ", persona->ApMat, sizeof(persona->ApMat));
    matricula = validarNumeros("INGRESE LA MATRICULA: ", 100000, 500000);
    persona->matricula = matricula;
    edad = validarNumeros("INGRESE LA EDAD: ", 18, 30);
    persona->edad = edad;
    genero = validarNumeros("INGRESE EL NUMERO DEL GÉNERO:\n0.- HOMBRE\n1.- MUJER\n", 0, 1);
    strcpy(persona->sexo, sexo[genero]);
    status = validarNumeros("CUAL ES EL ESTADO ACADEMICO?\n0.- DADO DE BAJA\n1.- BAJA TEMPORAL\n2.- MATRICULADO\n3.- EGRESADO\n", 0, 3);
    strcpy(persona->estado, stat[status]);
    (*numEstudiantes)++;
}

void eliminarRegistro(struct InfoAlumno estudiantes[], int *numEstudiantes)
{
    int i, j, matricula, encontrado = 0;

    matricula = validarNumeros("INGRESE LA MATRICULA DEL ALUMNO PARA ELIMINAR SU REGISTRO: ", 100000, 500000);

    for (i = 0; i <= *numEstudiantes; i++)
    {
        if (estudiantes[i].matricula == matricula)
        {
            for (j = i; j < *numEstudiantes - 1; j++)
            {
                estudiantes[j] = estudiantes[j + 1];
            }
            (*numEstudiantes)--;
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
    else
    {
        printf("EL REGISTRO FUE ELIMINADO\n");
    }
}

void imprimir(struct InfoAlumno estudiantes[], int numEstudiantes)
{
    int i;
    if (numEstudiantes == 0)
    {
        printf("NO HAY REGISTROS PARA IMPRIMIR\n");
        return;
    }

    for (i = 0; i < numEstudiantes; i++)
    {
        printf("Estudiante #%d\n", i + 1);
        printf("Nombre: %s %s %s\n", estudiantes[i].Nombre, estudiantes[i].ApPat, estudiantes[i].ApMat);
        printf("Sexo: %s\n", estudiantes[i].sexo);
        printf("Matricula: %d\n", estudiantes[i].matricula);
        printf("Estado: %s\n", estudiantes[i].estado);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("\n");
    }
}

void buscar(struct InfoAlumno estudiantes[], int *numEstudiantes)
{
    int i, matricula, encontrado = 0;

    matricula = validarNumeros("INGRESE LA MATRICULA DEL ALUMNO PARA ENCONTRAR SU REGISTRO: ", 100000, 500000);

    for (i = 0; i <= *numEstudiantes; i++)
    {
        if (estudiantes[i].matricula == matricula)
        {
            printf("Estudiante #%d\n", i + 1);
            printf("Nombre: %s %s %s\n", estudiantes[i].Nombre, estudiantes[i].ApPat, estudiantes[i].ApMat);
            printf("Sexo: %s\n", estudiantes[i].sexo);
            printf("MatrIcula: %d\n", estudiantes[i].matricula);
            printf("Estado: %s\n", estudiantes[i].estado);
            printf("Edad: %d\n", estudiantes[i].edad);
            printf("\n");
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }
}

void ordenar(struct InfoAlumno estudiantes[], int numEstudiantes)
{
    int i, j;
    struct InfoAlumno temp;

    for (i = 0; i < numEstudiantes - 1; i++)
    {
        for (j = 0; j < numEstudiantes - i - 1; j++)
        {
            if (estudiantes[j].matricula > estudiantes[j + 1].matricula)
            {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}
