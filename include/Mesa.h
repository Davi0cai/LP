#include <iostream>
#include <vector>
#include "Pedido.h"
#include "Cliente.h"

#ifndef MESA_H
#define MESA_H

using namespace std;

class Mesa {
protected:
    bool ocupada;
    Cliente cliente;
    Pedido pedido;
public:
    Mesa();

    void trocarStatus();

    void setCliente(Cliente c);
    Cliente getCliente();

    void setPedido(Pedido p);
    Pedido getPedido();

    bool getStatus();

    friend ostream& operator<<(ostream& os, Mesa& mesa);

    friend istream& operator>>(istream& is, Mesa& mesa);
};

#endif
