#include "../include/Combo.h"
#include "../include/ItemPedido.h"
#include "../include/Produto.h"
#include "../include/Cardapio.h"
#include <string>
#include <vector>

using namespace std;

Combo::Combo(){
    
}

string Combo::getNome(){
    return nome;
}
void Combo::setNome(string n){
    this->nome = n;
}

ItemPedido Combo::getProduto(int pos){
    return produtos[pos];
}
void Combo::addProduto(ItemPedido ip){
    produtos.push_back(ip);
}

float Combo::calcularSubtotal(){
    total = 0;

    for(ItemPedido i : produtos){
        total += i.calcularSubtotal();
    }
    
    return (total - total/10);
}

Produto Combo::criarProduto(){
    Produto prod;
    string desc = "";
        
    prod.setNome(nome);
    prod.setPreco(Combo::calcularSubtotal());
    for(ItemPedido& ip : produtos){
        desc = desc + ip.getProduto().getNome() + "(x" + to_string(ip.getQuantidade()) + "); ";
    }
    prod.setDesc(desc);

    return prod;
}


/*Produto criarProduto(string nome, float valor, string desc){

}*/

ostream& operator<<(ostream& os, Combo& c){
    os << "Combo: " << c.getNome() << " | " << c.calcularSubtotal() << "R$";
    return os;
}

//Necessário? Sistema só deve expor produtos e o cardápio!
istream& operator>>(istream& is, Combo& c){
    //Criação de combo personalizado?
    string nome;
    string preco;
    string desc;

    cout << "Nome do Combo Personalizado? ";
    getline(is, nome);
    c.nome = nome;

    cout << "Preço dos Itens do Combo no Total? ";
    getline(is, preco);
    c.total = stof(preco);

    cout << "Descrição do Combo Personalizado? ";
    getline(is, desc);


    return is;
}