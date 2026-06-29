#include <iostream>
#include "Pagamento.h"

#ifndef DINHEIRO_H
#define DINHEIRO_H

class Dinheiro : public Pagamento{

public:
    void pagar(float valor);
};

#endif
