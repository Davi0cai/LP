#include <iostream>

#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "ItemPedido.h"
#include "Combo.h"
using namespace std;

class Pedido {
protected:
    static int atual;
    int id;
    vector<ItemPedido> produtos;
    vector<Produto> combos;
    //Fazer a mesma mudança de tornar combos uma espécie de produto
public:
    Pedido();

    int getId();

    
    ItemPedido getProduto(int pos);
    void addProduto(ItemPedido prod);
    void removeProduto(int pos);

    Produto getCombo(int pos);
    void addCombo(Produto comb);
    void removeCombo(int pos);


    float calcularTotal();
    void relatarPedido();
    

    void reiniciarIds();

    void operator+(Produto& prod);

    friend ostream& operator<<(ostream& os, Pedido& p);

    //Como seria a porcaria do >> ????
};

#endif
