#include <stdio.h>
#include <stdlib.h>

int main() {
    char caracter;
    printf("Digite um carácter: ");
    scanf("%c", &caracter);

    switch (caracter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
            printf("Você digitou uma vogal minúscula\n");
            break;
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
            printf("Você digitou uma vogal MAIÚSCULA\n");
            break;
    default:
            printf("Você não digitou uma vogal\n");
    }
}
