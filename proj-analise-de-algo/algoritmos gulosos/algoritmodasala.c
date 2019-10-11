#include <stdio.h>

int main() {

    int Ini[12] = {1,3,0,5,3,5,6,8,8,2,12};

    int Fim[12] = {4,5,6,7,8,9,10,11,12,13,14};

    int Selecao[22];

    for (int i =0; i<=22; i++) {

        Selecao[i] = 0;
    }

    Selecao[0] = Ini[0];
    Selecao[1] = Fim[0];

    int x = 1;

    for (int i = 1; i <= 10; i++) {
        if (Ini[i] >= Selecao[x]) {

            Selecao[x+1] = Ini[i];
            Selecao[x+2] = Fim[i];
            x += 2;
        }
    }
    
    for (int i =0; i<(sizeof(Selecao)/sizeof(int)/2)-3; i++) {
        if (Selecao>0)
          printf("%d ", Selecao[i]);

        if (i % 2 == 0)
            printf("- ");

        if (i % 2 != 0)
            printf("\n");
    }



    return 0;
}