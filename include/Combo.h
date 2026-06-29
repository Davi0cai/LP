#include <iostream>

#ifndef COMBO_H
#define COMBO_H

using namespace std;
#include "ItemPedido.h"
#include "Produto.h"
#include <string>
#include <vector>

class Combo {
protected:
    string nome;
    vector<ItemPedido> produtos;
    float total;
public:
    Combo();
    //Inserir
    string getNome();
    void setNome(string n);

    ItemPedido getProduto(int pos);
    void addProduto(ItemPedido ip); 

    float calcularSubtotal();

    Produto criarProduto();
    Produto criarProduto(string nome, float valor, string desc); // Remover?

    friend ostream& operator<<(ostream& os, Combo& c);

    friend istream& operator>>(istream& is, Combo& c);

};

#endif