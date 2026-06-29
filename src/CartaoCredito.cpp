#include "../include/Pagamento.h"
#include "../include/CartaoCredito.h"
#include <string>

using namespace std;

void CartaoCredito::pagar(float valor){
    string senha = "N/A";
    cout << "Valor a pagar: " << valor << endl;

    cout << "Insira o cartão.";
    getchar();
    cout << "Insira a senha.\n";
    while(senha.length() != 4){
        try { cin >> senha;
            if(senha.length() != 4) throw invalid_argument("Senha deve possuir 4 digitos.");
        } catch(exception& e){
            cout << e.what() << endl;
            cout << "Tente novamente: ";
        }
    }
   
}