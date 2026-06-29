#include <iostream>
#include <vector>
#include "Pedido.h"
#include "Cliente.h"

#ifndef DINHEIRO_H
#define DINHEIRO_H

using namespace std;

class Mesa {
protected:
    Cliente cliente;
    Pedido pedido;
public:
    Mesa();

    void setCliente(Cliente c);
    Cliente getCliente();

    void setPedido(Pedido p);
    Pedido getPedido();
};

#endif
