#include <stdio.h>
#include "../headers/menus.h"

int menuPrincipal()
{
    int opcion1;
    printf("1) Ingresar producto\n");
    printf("2) Facturar Producto\n");
    printf("3) Imprimir Factura\n");
    printf("4) Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion1);
    return opcion1;
}

char menuFacturacion()
{
    char opcion2;
    printf("Escoja los productos que desea facturar:\n");
    printf("a) Llantas (Precio: $150) (Precio al por mayor, desde 6 unidades: $130)\n");
    printf("b) Kit Pastillas de freno (Precio: $55) (Precio al por mayor, desde12 unidades: $45)\n");
    printf("c) Kit de embrague (Precio: $180) (Precio al por mayor, desde 8 unidades: $165)\n");
    printf("d) Faros (Precio: $70) (Precio al por mayor, desde 10 unidades: $60)\n");
    printf("e) Radiador (Precio: $120)(Precio al por mayor, desde 6 unidades: $105)\n");
    fflush(stdin);
    scanf("%c", &opcion2);
    return opcion2;
}

int menuFacturacionDinamico(char nomProducto[10][50], float numxMProducto[10], float prcProducto[10], float prcxMProducto[10], int cont)
{
    int repetir = 0;
    int opcion2;
    int numItems = 0;
    while (repetir == 0)
    {
        /* code */

        system("cls");
        printf("Escoja los productos que desea facturar:\n");

        for (int i = 0; i < cont; i++)
        {
            printf("ID:%d | %s (Precio: $%.2f) (Precio al por mayor, desde %.0f unidades: $%.2f)\n", i + 1, nomProducto[i], prcProducto[i], numxMProducto[i], prcxMProducto[i]);
            numItems++;
        }

        printf("Escriba el ID del producto que desea facturar: ");
        scanf("%d", &opcion2);
        opcion2--;
        if (opcion2 > numItems)
        {
            printf("El ID de producto no existe, elija un ID existente: \n");
            repetir = 0;
        }
        else
        {
            repetir = 1;
        }
    }

    return opcion2;
}