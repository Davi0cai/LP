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
    ENTREGUE,
    FINALIZADO
};

class Entrega {
protected:
    Entregador entregador;
    Cliente cliente;
    Pedido pedido;
    string endereco;
    Status status;
public:
    Entrega();

    Entrega(Entregador entregador, Cliente cliente, Pedido pedido, string endereco, Status stats = RECEBIDO);

    void atualizarStatus();

    void setCliente(Cliente c);
    Cliente getCliente();

    void setPedido(Pedido p);
    Pedido getPedido();

    void setEntregador(Entregador ent);

    string getEndereco();

    Status getStatus();

    friend ostream& operator<<(ostream& os, Entrega& e);

    friend istream& operator>>(istream& is, Entrega& e);

};

#endif
