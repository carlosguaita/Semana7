#include <stdio.h>
#include "../headers/modulos.h"

float leerCantidadProducto(char producto[])
{
    float cantProducto = 0;
    printf("Ingrese la cantidad de %s que desea facturar: ", producto);
    scanf("%f", &cantProducto);
    return cantProducto;
}

int imprimirFactura(float numa, float numb, float numc, float numd, float nume)
{
    float prca = 150, prcb = 55, prcc = 180, prcd = 70, prce = 120;
    float prcaxM = 130, prcbxM = 45, prccxM = 165, prcdxM = 60, prcexM = 105;
    float numaxM = 6, numbxM = 12, numcxM = 8, numdxM = 10, numexM = 6;
    float tota = 0, totb = 0, totc = 0, totd = 0, tote = 0;
    float subtotal = 0, total = 0;

    tota = calculoTotalProducto(numa, numaxM, prca, prcaxM);
    totb = calculoTotalProducto(numb, numbxM, prcb, prcbxM);
    totc = calculoTotalProducto(numc, numcxM, prcc, prccxM);
    totd = calculoTotalProducto(numd, numdxM, prcd, prcdxM);
    tote = calculoTotalProducto(nume, numexM, prce, prcexM);

    printf("*********   FACTURA ************\n");
    ingresarCliente();
    printf("Producto               Número              valor           total\n");
    imprimirProductos("Llantas               ", numa, numaxM, prca, prcaxM, tota);
    imprimirProductos("Kit Pastillas de freno", numb, numbxM, prcb, prcbxM, totb);
    imprimirProductos("Kit de embrague       ", numc, numcxM, prcc, prccxM, totc);
    imprimirProductos("Faros                 ", numd, numdxM, prcd, prcdxM, totd);
    imprimirProductos("Radiador              ", nume, numexM, prce, prcexM, tote);

    subtotal = tota + totb + totc + totd + tote;
    printf("El subtotal sin descuento es: %.2f\n", subtotal);
    if (subtotal > 100 && subtotal <= 500)
    {
        printf("Se aplica un descuento del 5 porciento\n");
        subtotal = subtotal * 0.95;
    }
    else if (subtotal > 500 && subtotal <= 1000)
    {
        printf("Se aplica un descuento del 7 porciento\n");
        subtotal = subtotal * 0.93;
    }
    else if (subtotal > 1000)
    {
        printf("Se aplica un descuento del 10 porciento\n");
        subtotal = subtotal * 0.90;
    }
    else
    {
        printf("No se aplica descuento dado que el mónto no alcanzo el mínimo necesario\n");
    }

    total = subtotal * 1.12;

    printf("El subtotal es: %.2f\n", subtotal);
    printf("El total es: %.2f\n", total);
    return 4;
}

int imprimirFacturaDinamico(float numProducto[10], char nomProducto[10][50], float numxMProducto[10], float prcProducto[10], float prcxMProducto[10], int cont)
{

    float tot[10];
    float subtotal = 0, total = 0;

    printf("*********   FACTURA ************\n");
    ingresarCliente();

    for (int i = 0; i < cont; i++)
    {
        if (numProducto[i] > 0)
        {
            tot[i] = calculoTotalProducto(numProducto[i], numxMProducto[i], prcProducto[i], prcxMProducto[i]);
            imprimirProductos(nomProducto[i], numProducto[i], numxMProducto[i], prcProducto[i], prcxMProducto[i], tot[i]);
            subtotal = subtotal + tot[i];
        }
    }

    printf("El subtotal sin descuento es: %.2f\n", subtotal);
    if (subtotal > 100 && subtotal <= 500)
    {
        printf("Se aplica un descuento del 5 porciento\n");
        subtotal = subtotal * 0.95;
    }
    else if (subtotal > 500 && subtotal <= 1000)
    {
        printf("Se aplica un descuento del 7 porciento\n");
        subtotal = subtotal * 0.93;
    }
    else if (subtotal > 1000)
    {
        printf("Se aplica un descuento del 10 porciento\n");
        subtotal = subtotal * 0.90;
    }
    else
    {
        printf("No se aplica descuento dado que el mónto no alcanzo el mínimo necesario\n");
    }

    total = subtotal * 1.12;

    printf("El subtotal es: %.2f\n", subtotal);
    printf("El total es: %.2f\n", total);
    return 4;
}

void imprimirProductos(char nomProdcuto[], float num, float numxM, float prc, float prcxM, float tot)
{
    if (num > 0)
    {
        if (num < numxM)
        {
            printf("Producto: %s | Número: %.0f | Precio: %.2f | Total: %.2f\n", nomProdcuto, num, prc, tot);
        }
        else
        {
            printf("Producto: %s | Número: %.0f | Precio: %.2f | Total: %.2f\n", nomProdcuto, num, prcxM, tot);
        }
    }
}

float calculoTotalProducto(float cantidad, float numPorMayor, float precioNormal, float precioPorMayor)
{
    float totalProducto = 0;
    if (cantidad < numPorMayor)
    {
        totalProducto = cantidad * precioNormal;
    }
    else
    {
        totalProducto = cantidad * precioPorMayor;
    }
    return totalProducto;
}

void ingresarCliente()
{
    char nombre[50];
    char cedula[50];
    printf("Ingrese su nombre: ");
    scanf("%s", &nombre);
    printf("Ingrese su número de cédula: ");
    fflush(stdin);
    scanf("%s", &cedula);
    printf("Nombre: %s\n", nombre);
    printf("Nro. cédula: %s\n", cedula);
}
