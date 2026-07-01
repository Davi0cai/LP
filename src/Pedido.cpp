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

    cout << "Produtos: \n";
    for(ItemPedido i : produtos){
        //cout << i.getProduto().getNome() << " | " << (i.getProduto().getPreco() * i.getQuantidade()) << " reais" << endl; // Código antigo, se a sobrecarga de << funcionar, não é necessário
        cout << i.getProduto().getNome() << "(x" << i.getQuantidade() << ") | " << i.getProduto().getPreco() << "R$" << endl;
        cout << i.getProduto().getDesc() << endl;
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

    string relatorioTotal = "";
    float total = p.calcularTotal();

    for(ItemPedido& i : p.produtos){
        relatorioTotal += i.getProduto().getNome() + "(x" + to_string(i.getQuantidade()) + ") | " + to_string(i.getProduto().getPreco()) + "R$\n";
        relatorioTotal += i.getProduto().getDesc() + "\n";
    }

    relatorioTotal += "Dando total: " + to_string(total);
    
    os << relatorioTotal;


    //p.relatarPedido(); //Antigo

    return os;
}

int Pedido::atual = 1;