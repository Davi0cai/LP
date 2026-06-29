#ifndef ITEMPEDIDO_H
#define ITEMPEDIDO_H

#include "Produto.h"

class ItemPedido {
protected:
    Produto produto;
    int quantidade;

public:
    ItemPedido();

    ItemPedido(Produto produto, int quantidade);

    
    Produto getProduto() const;
    void setProduto(Produto p);

    int getQuantidade() const;
    void setQuantidade(int quantidade);

    float calcularSubtotal() const;

    friend ostream& operator<<(ostream& os, const ItemPedido& ip);

    friend istream& operator>>(istream& is,ItemPedido& ip);

    void salvar(ofstream& out) const;

    void carregar(ifstream& in);
};

#endif
