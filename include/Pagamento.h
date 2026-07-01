#include <iostream>

#ifndef PAGAMENTO_H
#define PAGAMENTO_H

class Pagamento{

public:
    virtual void pagar(float valor) = 0;
};

#endif
