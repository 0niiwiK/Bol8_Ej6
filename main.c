/* Realizar un programa que lea una cantidad de números a introducir.
 * Para cada uno de los números introducidos debe indicar si el número es o no perfecto
 * (un no es perfecto cuando es igual a la suma de sus divisores excepto el mismo).
Funciones que debe de contener:
PROTOTIPOS:
char leer_opcion ();
int leer_numero ();
int es_divisor (int, int);
int es_perfecto (int);
void mostrar_resultado (int); */

#include <stdio.h>

char leer_opcion ();
int leer_numero ();
int es_divisor (int num, int divisor);
int es_perfecto (int num);
void mostrar_resultado (int num);

int main() {
    /* Pide un numero y muestra en pantalla si el numero es perfecto o no
    luego pregunta si se quiere repetir el proceso, pidiendo la letra "s"
    sin distincion de mayusculas o minusculas para confirmar.
     */
    do {
        mostrar_resultado(leer_numero());
    } while (leer_opcion()==('s'|'S'));
    return 0;
}

char leer_opcion (){
    // Pide y lee la letra de entrada y la devuelve
    char opcion;
    printf("\nIntroduzca (s) o (S) para continuar: ");
    scanf("%c",&opcion);
    fflush(stdin);
    return opcion;
}

int leer_numero (){
    // Pide y lee un numero y comprueba si es valido, entonces lo retorna, si no, lo pide de nuevo
    int num;
    printf("Introduce un valor entero positivo: ");
    scanf("%d",&num);
    fflush(stdin);
    while (num<=0){
        printf("El numero debe ser positivo y no nulo");
        printf("\nIntroduce un valor entero positivo: ");
        scanf("%d",&num);
        fflush(stdin);
    }
    return num;
}

int es_divisor (int num, int divisor){
    // Comprueba si "divisor" es ciertamente divisor de "num" y retorna un "boolean"
    int resul;
    if (num%divisor==0)
        resul=1;
    else
        resul=0;
    return resul;
}

int es_perfecto (int num){
    // Comprueba si el numero de entrada es un numero perfecto y devuelve un "boolean"
    int resul, sumatorio=0;
    for (int i = 1; i <= num/2; i++) {
        if (es_divisor(num,i))
            sumatorio+=i;
    }
    if (sumatorio==num)
        resul=1;
    else
        resul=0;
    return resul;
}

void mostrar_resultado (int num){
    // Imprime el resultado de si "num" es un numero perfecto o no.
    (es_perfecto(num)) ? printf("El numero %d SI es un numero perfecto.\n",num):
    printf("El numero %d NO es un numero perfecto.\n",num);
}