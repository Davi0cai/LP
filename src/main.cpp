#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../include/Produto.h"
#include "../include/ItemPedido.h"
#include "../include/Combo.h"
#include "../include/Cardapio.h"
#include "../include/Loader.h"
#include "../include/Pedido.h"
#include "../include/Sistema.h"


using namespace std;

void opcoes();

int main()
{
    Sistema sis;
    vector<Entregador> salvar;
    Cardapio cardapioGeral("Cardápio");
    Loader loadnsave;
    Pedido p;

    vector<Entregador> temp;

    //Tudo deve ficar entre as linhas de load e save
    loadnsave.cLoadSequence(cardapioGeral);
    loadnsave.cLoadEntregadores(temp);
    sis.setEntregadores(temp);

    //sis.addEntregadorSistema();

    sis.addPedidoMesa(10, cardapioGeral);
    //sis.addPedidoEntrega(cardapioGeral);

    cout << sis;

    
    

    //Produto what = cardapioGeral.getProduto(0);

    //cout << what;
    //int qnt = 1;
    //ItemPedido hohoh(what, qnt);
    //p + what;
    //what = cardapioGeral.getCombo(1);
    //p + what;
    //p.addProduto(hohoh);

    //cout << p;

    //cin >> cardapioGeral;

    //cout << cardapioGeral;

    //cardapioGeral.exporCardapio();
    
    //Produto p3("Taco", 10);

    //cardapioGeral + p3;

    //ItemPedido ip1(p3, 2);
    //Combo c1;
    //c1.setNome("Combo 1");
    //c1.addProduto(ip1);

    //cardapioGeral + c1;

    //cout << endl << endl;
    //cardapioGeral.exporCardapio();

    salvar = sis.getEntregadores();
    loadnsave.cSaveEntregadores(salvar);
    loadnsave.cSaveSequence(cardapioGeral);

    return 0;
}