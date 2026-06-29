#include <iostream>

#ifndef ENTREGA_H
#define ENTREGA_H

#include <string>
#include "Entregador.h"
#include "Cliente.h"
#include "Pedido.h"
using namespace std;

enum Status {
    RECEBIDO,
    PREPARANDO,
    A_CAMINHO,
    ENTREGUE
};

class Entrega {
protected:
    Entregador entregador;
    Cliente cliente;
    Pedido pedido;
    Status status;
public:
    Entrega(Entregador entregador, Cliente cliente, Pedido pedido, Status = RECEBIDO);

    void atualizarStatus();
};

#endif
