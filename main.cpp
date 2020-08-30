#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <thread>         // std::thread

using namespace std;

// Vari�veis globais
int numeroInicial = 4930;
int aaa = 222;
int numerosEncontrados = 0;
int somaDosPrimos = 0;

// Fun��o que testa se � primo
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
        d = d + 2;        /* testar apenas ímpares*/
    }
    return EhPrimo;
}

void percorreA(){			
  // Itera para n�o testar o pr�prio n�mero inicial
  int numeroA = numeroInicial+2;
	while(numerosEncontrados < aaa-1){
		// Chama fun��o para saber se � n�mero primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA+=2;
	}
}

void percorreB(){	
	// Itera para n�o testar o pr�prio n�mero inicial
  int numeroA = numeroInicial+1;	
	while(numerosEncontrados < aaa-1){
		// Chama fun��o para saber se � n�mero primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA+=2;
	}	
}

void percorreC(){			
  // Itera para n�o testar o pr�prio n�mero inicial
  int numeroA = numeroInicial-2;
	while(numerosEncontrados < aaa-1){
		// Chama fun��o para saber se � n�mero primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA-=2;
	}
}

void percorreD(){	
	// Itera para n�o testar o pr�prio n�mero inicial
  int numeroA = numeroInicial-1;	
	while(numerosEncontrados < aaa-1){
		// Chama fun��o para saber se � n�mero primo
		if (TestaPrimo3(numeroA)){
			numerosEncontrados++;
			somaDosPrimos+= numeroA;
			cout << numerosEncontrados << " numero primo: " << numeroA << "\n";
		}
		numeroA-=2;
	}	
}

int main(int argc, char** argv) {
	// Decide l�gica
	if (numeroInicial < 5000){
		// Cria��o das Threads
		std::thread first (percorreA);
    	std::thread second (percorreB);
    	first.join();                
    	second.join();           	
	}else{
	    // Cria��o das Threads
		std::thread first (percorreC);
	    std::thread second (percorreD);
	    first.join();                
	    second.join();
	}
	cout << "A soma dos numeros primos eh: " << somaDosPrimos << "\n";
		
	return 0;
}
