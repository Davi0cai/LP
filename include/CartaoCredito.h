#include <iostream>
#include "Pagamento.h"

#ifndef CARTAOCREDITO_H
#define CARTAOCREDITO_H

class CartaoCredito : public Pagamento{

public:
    void pagar(float valor);
};

#endif
