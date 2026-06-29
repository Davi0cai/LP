#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../include/Produto.h"
#include "../include/ItemPedido.h"
#include "../include/Combo.h"
#include "../include/Cardapio.h"
#include "../include/Loader.h"


using namespace std;

void opcoes();

int main()
{
    Cardapio cardapioGeral("Cardápio");
    Loader loadnsave;

    loadnsave.cLoadSequence(cardapioGeral);

    cin >> cardapioGeral;

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

    loadnsave.cSaveSequence(cardapioGeral);

    return 0;
}