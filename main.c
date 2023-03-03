#include <stdio.h>
#include <string.h>
#include "headers/menus.h"
#include "headers/modulos.h"


int main(int argc, char *argv[])
{
    // Definición variables
    char nomProducto[10][50];
    float numProducto[10];
    float numxMProducto[10];
    float prcProducto[10];
    float prcxMProducto[10];
    int opcion1 = 0, continuar1 = 0, continuar2 = 0, idProducto=0;
    int cont = 0;
    // Inicio
    printf("*********BIENVENIDO AL SISTEMA DE FACTURACIÓN***********\n");
    // Menu Principal
    do
    {
        opcion1 = menuPrincipal();
        switch (opcion1)
        {
        case 1:

            do
            {
                if (cont < 10)
                {
                    printf("Ingrese el nombre del Producto: ");
                    scanf("%s", &nomProducto[cont]);
                    printf("Ingrese el precio normal del Producto: ");
                    scanf("%f", &prcProducto[cont]);
                    printf("Ingrese el precio al por mayor del Producto: ");
                    scanf("%f", &prcxMProducto[cont]);
                    printf("Ingrese el número de unidades desde el cual se aplicará el precio al por mayor del Producto: ");
                    scanf("%f", &numxMProducto[cont]);
                    cont++;
                }
                else
                {
                    printf("No se puede ingresar más productos");
                }
                printf("Desea ingresar otro producto  1) Si   2) No: ");
                scanf("%d", &continuar2);
            } while (continuar2 == 1 && cont <= 10);

            break;
        case 2:
            // Opción a
            do
            {
                idProducto=menuFacturacionDinamico(nomProducto, numxMProducto, prcProducto, prcxMProducto, cont);
                numProducto[idProducto]=leerCantidadProducto(nomProducto[idProducto]);
                printf("Desea facturar otro producto  1) Si   2) No: ");
                scanf("%d", &continuar1);
            } while (continuar1 == 1);
            break;
        case 3:
            opcion1 = imprimirFacturaDinamico(numProducto, nomProducto, numxMProducto, prcProducto, prcxMProducto, cont);
            break;
        case 4:
            printf("Adios");
            opcion1 = 4;
            break;

        default:
            printf("Elija una opción correcta");
            break;
        }
    } while (opcion1 != 4);
    //

    return 0;
}
