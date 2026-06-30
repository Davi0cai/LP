#include "../include/Pagamento.h"
#include "../include/Dinheiro.h"
#include <string>

using namespace std;

void Dinheiro::pagar(float valor){
    float pago = 0;
    float outraTentativa;
    
    cout << "Valor a pagar: " << valor << endl;
    cout << "Valor dado? ";
    cin >> pago;
    try {
        while(pago < valor){
            if(pago < 0) {
                throw invalid_argument("Não é possível pagar em valores negativos. Tente novamente.");
                pago = 0;
            } else {
                cout << "Faltam " << (valor-pago) << " reais." << endl;
                cin >> outraTentativa;
            }
            if(outraTentativa < 0) { 
                 invalid_argument("Não é possível pagar em valores negativos. Tente novamente.");
            } else pago += outraTentativa;
        }

        cout << "Troco: " << (pago-valor);
    } catch (exception& e) {
            // Espaço vazio, só foi para capturar a exceção
    }
}