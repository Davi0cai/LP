#include <iostream>
#include <string>

using namespace std;

#include "../include/Sistema.h"
#include "../include/Mesa.h"
#include "../include/Entrega.h"
#include "../include/Pedido.h"
#include "../include/Produto.h"
#include "../include/Loader.h"

Sistema::Sistema(){
    this->mesasAtuais = 0;
    this->entregasAtuais = 0;

    for(int i = 0; i <= 19; i++){
        if(mesas[i].getStatus() == true){
            mesas[i].trocarStatus();
        }
    }
}

void Sistema::addPedidoMesa(int qual, Cardapio& c){
    int continuar = 1;
    int escolha = 0;
    Pedido p;
    Produto pr;

    cin >> mesas[qual];

    while(continuar != 0 && mesas[qual].getStatus() == true){
        cout << "Adicionar produto (1) ou combo (2) ao pedido? ";
        cin >> escolha;

        if(escolha == 1){
            cout << "Adicionar que produto? (Por ID na ordem do Cardápio) ";
            cin >> escolha;

            pr = c.getProduto(escolha);

            p + pr;
        }else if(escolha == 2){
            cout << "Adicionar que combo? (Por ID na ordem do Cardápio) ";
            cin >> escolha;

            pr = c.getProduto(escolha);

            p + pr;
        }else{
            cout << "Escolha inválida.\n";
        }

        cout << "Adicionar mais itens a mesa? (0 cancela) ";
        cin >> continuar;
        if(continuar == 0){
            break;
        }
    }

    mesas[qual].setPedido(p);
    mesasAtuais++;
}

void Sistema::addPedidoEntrega(Cardapio& c){
    //int qual = (entregas.size() - 1);
    int continuar = 1;
    int escolha = 0;
    Pedido p;
    Produto pr;
    Entrega e;

    cin.ignore();

    cin >> e;

    while(continuar != 0 && e.getStatus() == RECEBIDO){
        cout << "Adicionar produto (1) ou combo (2) ao pedido? ";
        cin >> escolha;

        if(escolha == 1){
            cout << "Adicionar que produto? (Por ID na ordem do Cardápio) ";
            cin >> escolha;

            pr = c.getProduto(escolha);

            p + pr;
        }else if(escolha == 2){
            cout << "Adicionar que combo? (Por ID na ordem do Cardápio) ";
            cin >> escolha;

            pr = c.getProduto(escolha);

            p + pr;
        }else{
            cout << "Escolha inválida.\n";
        }

        cout << "Adicionar mais itens a mesa? (0 cancela) ";
        cin >> continuar;
        if(escolha == 0){
            break;
        }
    }

    cout << "ID do Entregador responsável? ";
    cin >> escolha;
    e.atualizarStatus();
    e.setEntregador(entregadores[escolha]);
    entregas.push_back(e);
    entregasAtuais++;
}

void Sistema::addEntregadorSistema(){
    Entregador ent;

    cin >> ent;

    entregadores.push_back(ent);
}

int Sistema::getMesasAtuais(){
    return mesasAtuais;
}
int Sistema::getEntregasAtuais(){
    return entregasAtuais;
}
void Sistema::setEntregadores(vector<Entregador> ent){
    this->entregadores = ent;
}
vector<Entregador> Sistema::getEntregadores(){
    return entregadores;
}


void Sistema::mesaEntregue(int pos){
    Loader load;

    if(mesas[pos].getStatus() == true){
        mesasAtuais--;

        load.savePedidoLocal(mesas[pos]);
    }
    
}
void Sistema::atualizarEntrega(int pos){
    Loader load;

    if(entregas[pos].getStatus() != FINALIZADO){
        entregas[pos].atualizarStatus();

        if(entregas[pos].getStatus() == FINALIZADO){
            entregasAtuais--;

            load.saveEntrega(entregas[pos]);
        }
    }
}

ostream& operator<<(ostream& os, Sistema& sis){

    cout << "Entregadores:\n";
    for(Entregador& e : sis.entregadores){
        cout << e << endl;
    }

    cout << "Pedidos locais:\n";
    for(int i = 0; i <= 19; i++){
        if(sis.mesas[i].getStatus() == true){
            cout << "Mesa " << i+1 << ":\n" << sis.mesas[i];
        }
    }

    cout << "Entregas:\n";
    for(Entrega& e : sis.entregas){
        cout << e << endl;
    }
    
    return os;
}

/*istream& operator>>(istream& is, Sistema& sis){
    //Nada??
    return is;
}*/