#include <iostream>
#include "Pagamento.h"

#ifndef PIX_H
#define PIX_H

class Pix : public Pagamento{

public:
    void pagar(float valor);
};

#endif
