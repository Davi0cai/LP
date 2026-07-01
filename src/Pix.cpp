#include "../include/Pagamento.h"
#include "../include/Pix.h"
#include <string>

using namespace std;

void Pix::pagar(float valor){
    cout << "Valor a pagar: " << valor << endl;

    cout << "Código: XXXXXXXXXXXXX" << endl;
    getchar();
}