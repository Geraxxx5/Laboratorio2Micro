#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int menu = 1;
    char opc;

    //Calculo de Numero decimal a binario
    int numero;
    int nNumero;
    int arrBinario[] = {0,0,0,0};
    div_t division;

    //Calculo del IVA
    float Monto;
    float IVA;

    //Realizar regla de 3
    float calcular;
    float n; 
    float cienPorciento;

    printf("Bienvenido a la parte 1 del laboratorio 2");

    printf("Seleccione la accion que desea\n1) Transformar 1 numero decimal a binario\n2) Realizar el calculo del IVA de una factura\n3) Realizar una regla de 3\n4) salir\nSeleccione la opcion: ");
    while (menu == 1)
    {
        scanf("%c",&opc);
        getchar();
        switch (opc)
        {
        case '1':
            
            printf("Ingrese el numero que quiere pasar a binario: ");
            scanf("%d",&numero);
            getchar();

            if(numero > 15){
                printf("El numero no puede ser mayor a 15");
            }else{
                nNumero = numero;
                for (int i = 0; i < 4; i++)
                {
                    division = div(nNumero,2);
                    arrBinario[i] = division.rem;
                    nNumero = division.quot;
                }

                printf("El numero binario es: ");
                for (int i = 3;  i > -1; i--)
                {
                    printf("%d",arrBinario[i]);
                }
                
            }
            break;
        case '2':
            printf("Ingrese el monto al que le quiera sacar el IVA: ");
            scanf("%f",&Monto);
            getchar();
            IVA = (Monto/1.12)*0.12;
            printf("El IVA para el monto %f es de %f",Monto,IVA);
            break;
        case '3':
            printf("Ingrese el n%% del 100%% que desea calcular: ");
            scanf("%f",&n);
            getchar();
            printf("Ingrese el 100%%: ");
            scanf("%f",&cienPorciento);
            getchar();
            calcular = cienPorciento * n / 100;
            printf("El %f%% de %f es de: %f",n,cienPorciento,calcular);
            break;
        case '4':
            menu = 0;
            break;
        }
        printf("\n");
        printf("Seleccione la accion que desea\n1) Transformar 1 numero decimal a binario\n2) Realizar el calculo del IVA de una factura\n3) Realizar una regla de 3\n4) salir\nSeleccione la opcion: ");
        printf("\n");
    }
    
    return 0;
}
