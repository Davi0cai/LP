#include <iostream>
#include <vector>
#include "../include/Pedido.h"
#include "../include/Entregador.h"
#include "../include/Cliente.h"
#include "../include/Mesa.h"
#include "../include/Entrega.h"

Entrega::Entrega(){

}

Entrega::Entrega(Entregador entregador, Cliente cliente, Pedido pedido, string endereco, Status stats){
    this->entregador = entregador;
    this->cliente = cliente;
    this->pedido = pedido;
    this->endereco = endereco;
    this->status = stats;
}

void Entrega::atualizarStatus(){
    if(status == RECEBIDO){
        status = PREPARANDO;
    }else if(status == PREPARANDO){
        status = A_CAMINHO;
    }else if(status == A_CAMINHO){
        status = ENTREGUE;
    }else if(status == ENTREGUE){
        status = FINALIZADO;
    }
}

void Entrega::setCliente(Cliente c){
    this->cliente = c;
}
Cliente Entrega::getCliente(){
    return cliente;
}

void Entrega::setPedido(Pedido p){
    this->pedido = p;
}
Pedido Entrega::getPedido(){
    return pedido;
}

void Entrega::setEntregador(Entregador ent){
    this->entregador = ent;
}

string Entrega::getEndereco(){
    return endereco;
}

Status Entrega::getStatus(){
    return status;
}

Entregador Entrega::getEntregador(){
    return entregador;
}

ostream& operator<<(ostream& os, Entrega& e){
    os << e.status << "\nCliente: " << e.cliente << "\nLocal: " << e.endereco << "\nEntregador: " << e.entregador << "\nPedido: " << e.pedido << endl;
    return os;
}

istream& operator>>(istream& is, Entrega& e){
    e.status = RECEBIDO;

    cin >> e.cliente;

    cout << "Endereço de entrega? ";
    getline(is, e.endereco);

    return is;
}