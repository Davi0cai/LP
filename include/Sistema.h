#include <iostream>

#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Mesa.h"
#include "Entrega.h"
#include "Entregador.h"
#include "Cardapio.h"
using namespace std;

class Sistema {
protected:
    Mesa mesas[20];
    vector<Entrega> entregas;
    vector<Entregador> entregadores;
    int mesasAtuais = 0;
    int entregasAtuais = 0;
public:
    Sistema();

    void addPedidoMesa(int qual, Cardapio& c);

    void addPedidoEntrega(Cardapio& c);

    void addEntregadorSistema();
    void setEntregadores(vector<Entregador> ent);
    vector<Entregador> getEntregadores();

    int getMesasAtuais();
    int getEntregasAtuais();

    void mesaEntregue(int qual);
    void atualizarEntrega(int pos);

    friend ostream& operator<<(ostream& is, Sistema& sis);

    //friend istream& operator>>(istream& is, Sistema& sis);
};

#endif