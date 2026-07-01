#include "../include/ItemPedido.h"

ItemPedido::ItemPedido(){

}

ItemPedido::ItemPedido(Produto produto, int quantidade)
{
    this->produto = produto;
    this->quantidade = quantidade;
}



Produto ItemPedido::getProduto() const
{
    return produto;
}
void ItemPedido::setProduto(Produto p){
    this->produto = p;
}

int ItemPedido::getQuantidade() const
{
    return quantidade;
}



void ItemPedido::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

float ItemPedido::calcularSubtotal() const
{
    return produto.getPreco() * quantidade;
}

void ItemPedido::salvar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(this), sizeof(ItemPedido));
}

void ItemPedido::carregar(ifstream& in) {
    in.read(reinterpret_cast<char*>(this), sizeof(ItemPedido));
}


ostream& operator<<(ostream& os, const ItemPedido& ip){
    os << "Item do Pedido: " << ip.getProduto().getNome() << " | " << ip.calcularSubtotal() << "R$" << endl;
    return os;
}

//Necessário? O sistema só deve expor produtos e o cardápio!
istream& operator>>(istream& is, ItemPedido& ip){
    //Redefinição de quantidade??
    int qnt;

    cout << "Redefenir quantidade de " << ip.produto.getNome() << " para? ";
    try{
        cin >> qnt;
        if(qnt <= 0) throw invalid_argument("Quantidade deve ser inteiro positivo.");
    } catch (exception& e){
        cout << e.what() << endl;
    }
    ip.quantidade = qnt;

    return is;
}