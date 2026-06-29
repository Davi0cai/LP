#include <iostream>

using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "../include/Loader.h"
#include "../include/Produto.h"
#include "../include/ItemPedido.h"
#include "../include/Combo.h"
#include "../include/Cardapio.h"

//Carrega dados do cardápio de dois txt diferentes.
void Loader::cLoadSequence(Cardapio& c){
    //Inserção dos produtos individuais
    ifstream entrada("data/produtos.txt");

    int atual = 1;
    Produto transfer;
    string leitura;

    while(getline(entrada, leitura)){
        if(atual == 1){
                transfer.setNome(leitura);
                atual++;
        }else if(atual == 2){
                transfer.setPreco(stof(leitura));
                atual++;
        }else if(atual == 3){
            transfer.setDesc(leitura);
            c + transfer;
            atual = 1;
        }
    }

    entrada.close();

    //Inserção dos combos
    ifstream entrada1("data/combos.txt");

    atual = 1;

    while(getline(entrada1, leitura)){
        if(atual == 1){
                transfer.setNome(leitura);
                atual++;
        }else if(atual == 2){
                transfer.setPreco(stof(leitura));
                atual++;
        }else if(atual == 3){
            transfer.setDesc(leitura);
            c.addCombo(transfer);
            atual = 1;
        }
    }

    entrada1.close();
}

//Salva dados em arquivo txt osdados do cardápio
void Loader::cSaveSequence(Cardapio& c){
    //Salvamento dos produtos individuais em txt
    ofstream saida("data/produtos.txt");

    //if(saida.is_open()) cout << "Aberto.";

    for(Produto i : c.getProdutos()){
        saida << i.getNome() << endl;
        saida << i.getPreco() << endl;
        saida << i.getDesc() << endl;
    }

    saida.close();

    //Salvamento dos combos em txt
    ofstream saida1("data/combos.txt");

    //if(saida.is_open()) cout << "Aberto.";

    for(Produto i : c.getCombos()){
        saida1 << i.getNome() << endl;
        saida1 << i.getPreco() << endl;
        saida1 << i.getDesc() << endl;
    }

    saida1.close();
}