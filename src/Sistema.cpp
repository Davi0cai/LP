#include <iostream>
#include <string>

using namespace std;

#include "../include/Dinheiro.h"
#include "../include/Sistema.h"
#include "../include/Mesa.h"
#include "../include/Entrega.h"
#include "../include/Pedido.h"
#include "../include/Produto.h"
#include "../include/Loader.h"
#include "../include/Pagamento.h"
#include "../include/Pix.h"
#include "../include/CartaoCredito.h"

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

    while(continuar != 0 && mesas[qual].getStatus() == false){
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

            pr = c.getCombo(escolha);

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

    mesas[qual].trocarStatus();
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
        cin.ignore();
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

            pr = c.getCombo(escolha);

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

    cout << "ID do Entregador responsável? ";
    cin >> escolha;
    e.atualizarStatus();
    e.setPedido(p);
    e.setEntregador(entregadores[escolha]);
    entregadores[escolha].setNumEntregas(entregadores[escolha].getNumEntregas() + 1);
    entregas.push_back(e);
    entregasAtuais++;
}

void Sistema::addEntregadorSistema(){
    Entregador ent;

    cin >> ent;

    entregadores.push_back(ent);
}
void Sistema::removerEntregadorSistema(){
    int id;
    
    cout << "ID do entregador a remover? ";
    cin >> id;

    try{
        if(id == 0 && entregadores.size() == 1){
            entregadores.pop_back();
        }else if(id >= 0 && id < entregadores.size()){
            for(int i = id; i < (entregadores.size()-1); i++){
                entregadores[i] = entregadores[i+1];
            }
            entregadores.pop_back();
            // 0123 - 0....0->1; 1->2; 2->3;
        }else {
            throw invalid_argument("Posição do elemento inválida.");
        }
    } catch(exception& e){
        cout << e.what();
    }
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
    int escolha = 0;

    if(mesas[pos].getStatus() == true && pos < 19 && pos >= 0){
        load.savePedidoLocal(mesas[pos]);
        mesas[pos].trocarStatus();

        cout << "Dinheiro (1), Pix (2), ou Cartão? (3) ";
        while(escolha <= 0 || escolha >= 4){
            cin >> escolha;
            if(escolha <= 0 || escolha >= 4){
                cout << "Escolha inválida, tente novamente. ";
            }
        }
        switch(escolha){
            case 1: {
                Dinheiro din;

                din.pagar(mesas[pos].getPedido().calcularTotal());
            }
            break;
            case 2: {
                Pix pix;

                pix.pagar(mesas[pos].getPedido().calcularTotal());
            }
            break;
            case 3: {
                CartaoCredito cartao;

                cartao.pagar(mesas[pos].getPedido().calcularTotal());
            }
            break;
        }

        mesasAtuais--;
    }else if(mesas[pos].getStatus() == false && pos < 19 && pos >= 0){
        cout << "Mesa não ocupada.\n";
    }else cout << "Mesa inválida.\n";
    
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