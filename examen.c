#include <stdio.h>
#include <stdbool.h>


bool esPar(int numero) {
    return numero % 2 == 0;
}


bool esImpar(int numero) {
    return !esPar(numero);
}


void mostrarNumeros(int inicio, int fin, bool (*condicion)(int), const char* tipo) {
    int suma = 0;
    printf("Números %s en el rango [%d, %d]:\n", tipo, inicio, fin);
    for (int i = inicio; i <= fin; i++) {
        if (condicion(i)) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma de números %s: %d\n", tipo, suma);
}


void manejarOpciones(int inicio, int fin) {
    int opcion;
    do {
        printf("\nElige una opción:\n");
        printf("1. Mostrar todos los números pares y calcular su suma.\n");
        printf("2. Mostrar todos los números impares y calcular su suma.\n");
        printf("3. Mostrar tanto pares como impares con sus respectivas sumas.\n");
        printf("Tu elección: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarNumeros(inicio, fin, esPar, "pares");
                break;
            case 2:
                mostrarNumeros(inicio, fin, esImpar, "impares");
                break;
            case 3:
                mostrarNumeros(inicio, fin, esPar, "pares");
                mostrarNumeros(inicio, fin, esImpar, "impares");
                break;
            default:
                printf("Opción inválida. Por favor, elige una opción válida.\n");
        }
    } while (opcion < 1 || opcion > 3);
}


int main() {
    int inicio, fin;
    char repetir;

    do {
        
        do {
            printf("Ingresa el valor inicial del rango: ");
            scanf("%d", &inicio);
            printf("Ingresa el valor final del rango: ");
            scanf("%d", &fin);
            if (inicio > fin) {
                printf("El valor inicial debe ser menor o igual al valor final. Intenta nuevamente.\n");
            }
        } while (inicio > fin);

        
        manejarOpciones(inicio, fin);

       
        printf("\n¿Deseas realizar otra operación? (s/n): ");
        scanf(" %c", &repetir);
    } while (repetir == 's' || repetir == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
