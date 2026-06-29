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

class Loader {
public:
    void cLoadSequence(Cardapio& c);
    void cSaveSequence(Cardapio& c);


};

#endif