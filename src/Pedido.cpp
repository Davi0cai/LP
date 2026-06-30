#include "../include/Pedido.h"
#include "../include/Combo.h"
#include "../include/ItemPedido.h"
#include <string>
#include <vector>

using namespace std;

Pedido::Pedido(){
    this->id = Pedido::atual;
    Pedido::atual++;
}

int Pedido::getId(){
    return this->id;
}

ItemPedido Pedido::getProduto(int pos){
    return produtos[pos];
}
void Pedido::addProduto(ItemPedido prod){
    produtos.push_back(prod);
}
void Pedido::removeProduto(int pos){
    int qnt = produtos.size();
    ItemPedido aux = produtos[pos];

    produtos[pos] = produtos[qnt-1];
    produtos[qnt-1] = aux;

    produtos.pop_back();
}

Produto Pedido::getCombo(int pos){
    return combos[pos];
}
void Pedido::addCombo(Produto comb){
    combos.push_back(comb);
}
void Pedido::removeCombo(int pos){
    int qnt = combos.size();
    Produto aux = combos[pos];

    combos[pos] = combos[qnt-1];
    combos[qnt-1] = aux;

    combos.pop_back();
}


float Pedido::calcularTotal(){
    float total;
    for(ItemPedido i : produtos){
        total += (i.calcularSubtotal());
    }

    for(Produto j : combos){
        total += j.getPreco();
    }

    return total;
}
void Pedido::relatarPedido(){
    float total = calcularTotal();

    cout << "Individuais: \n";
    for(ItemPedido i : produtos){
        //cout << i.getProduto().getNome() << " | " << (i.getProduto().getPreco() * i.getQuantidade()) << " reais" << endl; // Código antigo, se a sobrecarga de << funcionar, não é necessário
        cout << i.getProduto() << "(x" << i.getQuantidade() << ")" << endl;
    }
    cout << "Combos: \n";
    for(Produto j : combos){
        //cout << j.getNome() << " | " << j.calcularSubtotal() << " reais" << endl; // Mesma coisa de cima
        cout << j << endl; // Supostamente já é o combo, então deve dar certo?
    }
    cout << "Dando total: " << total << "R$" << endl;
}
    
void Pedido::reiniciarIds(){
    Pedido::atual = 1;
}


void Pedido::operator+(Produto& prod){
    ItemPedido ip;
    int qnt;

    cout << "Quantidade a adicionar de " << prod.getNome() << "? ";
    try{
        cin >> qnt;
        if(qnt <= 0){
            throw invalid_argument("Quantidade deve ser maior que zero.");
        }
    } catch(exception& e){
        cout << e.what();
    }
    ip.setProduto(prod);
    ip.setQuantidade(qnt);

    produtos.push_back(ip);
    //addProduto(ip);
}

ostream& operator<<(ostream& os, Pedido& p){
    os << endl;

    p.relatarPedido();

    return os;
}

int Pedido::atual = 1;