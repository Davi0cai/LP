#include <iostream>
#include <vector>
#include "../include/Pedido.h"
#include "../include/Cliente.h"
#include "../include/Mesa.h"

Mesa::Mesa(){

}

void Mesa::trocarStatus(){
    if(ocupada == false){
        ocupada = true;
    }else ocupada = false;
}

void Mesa::setCliente(Cliente c){
    this->cliente = c;
}
Cliente Mesa::getCliente(){
    return cliente;
}

void Mesa::setPedido(Pedido p){
    this->pedido = p;
}
Pedido Mesa::getPedido(){
    return pedido;
}

bool Mesa::getStatus(){
    return ocupada;
}

ostream& operator<<(ostream& os, Mesa& mesa){
    os << mesa.cliente << endl << mesa.pedido;

    return os;
}

istream& operator>>(istream& is, Mesa& mesa){
    cin >> mesa.cliente;
    //mesa.trocarStatus();
    //Inserção do pedido em mesa é feita por setPedido;

    return is;
}