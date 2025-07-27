#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Calculadora */

int main() {
    float num1=0, num2=0, resultado=0;
    char op1;
    int op;

    do{
        printf("\nDigite o primeiro numero: ");
        scanf("%f", &num1);
        printf("\nDigite o operador: ( + - * / ) :");
        scanf("%s", &op1);
        printf("\nDigite o segundo numero: ");
        scanf("%f", &num2);
        fflush(stdin);

        switch(op1){
            case '+':
                resultado = num1+num2;
                printf("\nResultado de %.2f %c %.2f = %.2f\n", num1, op1, num2, resultado);
                break;
            case '-':
                resultado = num1-num2;
                printf("\nResultado de %.2f %c %.2f = %.2f\n", num1, op1, num2, resultado);

                break;
            case '*':
                resultado = num1*num2;
                printf("\nResultado de %.2f %c %.2f = %.2f\n", num1, op1, num2, resultado);

                break;
            case '/':
                resultado = num1/num2;
                printf("\nResultado de %.2f %c %.2f = %.2f\n", num1, op1, num2, resultado);

                break;
            default:
                printf("\nCaracter errado, digite novamente!");
                break;
        }


        printf("\nDeseja continuar (1.Sim   2.Nao) : ");
        scanf("%d", &op);

    }while(op==1);


    return 0;
}
