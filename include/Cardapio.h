#include <iostream>
#include <fstream>

#ifndef CARDAPIO_H
#define CARDAPIO_H

using namespace std;
#include <vector>
#include <string>
#include "Produto.h"
#include "ItemPedido.h"
#include "Combo.h"

class Cardapio {
protected:
    string nomeCardapio;
    vector<Produto> produtos;
    vector<Combo> combosOG;
    vector<Produto> combos;
public:
    Cardapio(string n);

    //Talvez não precise de get para nome
    void setNome(string n);

    void addProduto(Produto p);
    void addCombo(Produto c);

    void removeProduto(int pos);
    void removeCombo(int pos);


    void exporCardapio();

    void setProdutos(vector<Produto> produtos);
    void setCombos(vector<Produto> combos);
    vector<Produto> getProdutos();
    vector<Produto> getCombos();

    void operator+(const Produto& p);
    void operator+(Combo& c);

    friend ostream& operator<<(ostream& os, Cardapio& c);

    friend istream& operator>>(istream& is, Cardapio& c);
    //Pensar em como isso será implementado...
    void salvarP(ofstream& out) const;
    void carregarP(ifstream& in);

    void salvarC(ofstream& out) const;
    void carregarC(ifstream& in);
};

#endif