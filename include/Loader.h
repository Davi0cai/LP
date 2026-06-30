#include <iostream>

#ifndef LOADER_H
#define LOADER_H

using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "Produto.h"
#include "ItemPedido.h"
#include "Combo.h"
#include "Cardapio.h"
#include "Mesa.h"
#include "Entrega.h"
#include "Entregador.h"

class Loader {
public:
    void cLoadSequence(Cardapio& c);
    void cSaveSequence(Cardapio& c);

    void savePedidoLocal(Mesa& m);
    void saveEntrega(Entrega& m);

    void cLoadEntregadores(vector<Entregador>& ent);
    void cSaveEntregadores(vector<Entregador>& ent);

};

#endif