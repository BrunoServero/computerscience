#include <stdio.h>

int troco(int n){
	int posicao =0;
	int moedas = 0;
	int centavos [6] = {100,50,25,10,5,1};
	while (posicao<6){
		while (n >= centavos[posicao])
		{
			n = n - centavos[posicao];
			moedas++;
			
		};
		printf("%d moeda de %d\n", moedas, centavos[posicao]);
		moedas = 0;
		posicao++;
}
}

int main(){
	troco(100);
};


