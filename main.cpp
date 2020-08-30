#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <thread>         // std::thread

using namespace std;

// Variáveis globais
int numeroInicial = 4930;
int aaa = 222;
int numerosEncontrados = 0;
int somaDosPrimos = 0;

// Função que testa se é primo
int TestaPrimo3(int n) {
    int EhPrimo,
        d=3;
    if (n <= 1 || (n != 2 && n % 2 == 0))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
        EhPrimo = 1;        /* o numero e' primo ate que se prove o contrario */

    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;        /* testar apenas Ã­mpares*/
    }
    return EhPrimo;
}

void percorreA(){			
  // Itera para não testar o próprio número inicial
  int numeroA = numeroInicial+2;
	while(numerosEncontrados < aaa-1){
		// Chama função para saber se é número primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA+=2;
	}
}

void percorreB(){	
	// Itera para não testar o próprio número inicial
  int numeroA = numeroInicial+1;	
	while(numerosEncontrados < aaa-1){
		// Chama função para saber se é número primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA+=2;
	}	
}

void percorreC(){			
  // Itera para não testar o próprio número inicial
  int numeroA = numeroInicial-2;
	while(numerosEncontrados < aaa-1){
		// Chama função para saber se é número primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA-=2;
	}
}

void percorreD(){	
	// Itera para não testar o próprio número inicial
  int numeroA = numeroInicial-1;	
	while(numerosEncontrados < aaa-1){
		// Chama função para saber se é número primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA-=2;
	}	
}

int main(int argc, char** argv) {
	// Decide lógica
	if (numeroInicial < 5000){
		// Criação das Threads
		std::thread first (percorreA);
    	std::thread second (percorreB);
    	first.join();                
    	second.join();           	
	}else{
	    // Criação das Threads
		std::thread first (percorreC);
	    std::thread second (percorreD);
	    first.join();                
	    second.join();
	}
	cout << "A soma dos numeros primos eh: " << somaDosPrimos << "\n";
		
	return 0;
}
