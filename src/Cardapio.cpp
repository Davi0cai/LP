#include "../include/Cardapio.h"
#include "../include/Produto.h"
#include "../include/ItemPedido.h"
#include <string>

using namespace std;

Cardapio::Cardapio(string n){
    this->nomeCardapio = n;
}

void Cardapio::setNome(string n){
    this->nomeCardapio = n;
}

void Cardapio::addProduto(Produto p){
    produtos.push_back(p);
}

void Cardapio::addCombo(Produto c){
    combos.push_back(c);
}

void Cardapio::removeProduto(int pos){
    try{
        if(pos == 0 && produtos.size() == 1){
            produtos.pop_back();
        }else if(pos >= 0 && pos < produtos.size()){
            for(int i = pos; i <= (produtos.size()-1); i++){
                produtos[i] = produtos[i+1];
            }
            produtos.pop_back();
            // 0123 - 0....0->1; 1->2; 2->3;
        }else {
            throw invalid_argument("Posição do elemento inválida.");
        }
    } catch(exception& e){
        cout << e.what();
    }
}

void Cardapio::removeCombo(int pos){
    try{
        if(pos == 0 && combos.size() == 1){
            combos.pop_back();
        }else if(pos >= 0 && pos < combos.size()){
            for(int i = pos; i <= (combos.size()-1); i++){
                combos[i] = combos[i+1];
            }
            combos.pop_back();
            // 0123 - 0....0->1; 1->2; 2->3;
        }else {
            throw invalid_argument("Posição do elemento inválida.");
        }
    } catch(exception& e){
        cout << e.what();
    }
}



Produto Cardapio::getProduto(int pos){
    try{
        if(pos < 0 || pos >= produtos.size()){
            throw invalid_argument("ID inválido.");
        }
    } catch(exception& e) {
        cout << e.what();
    }
    return produtos[pos];
}

Produto Cardapio::getCombo(int pos){
    try{
        if(pos < 0 || pos >= combos.size()){
            throw invalid_argument("ID inválido.");
        }
    } catch(exception& e) {
        cout << e.what();
    }
    return combos[pos];
}



void Cardapio::exporCardapio(){ //Substituir por <<
    cout << nomeCardapio;
    cout << "Produtos individuais: " << endl;
    for(Produto i : produtos){
        //cout << i.getNome() << " | " << i.getPreco() << " reais " << endl;
        cout << i << endl;
    }

    //Trocar de volta para Combo j caso não dê certo
    cout << "Combos: " << endl;
    for(Produto j : combos){
        cout << j << endl;
    }
}


void Cardapio::setProdutos(vector<Produto> produtos){
    this->produtos = produtos;
}

void Cardapio::setCombos(vector<Produto> combos){
    this->combos = combos;
}


vector<Produto> Cardapio::getProdutos(){
    return produtos;
}
vector<Produto> Cardapio::getCombos(){
    return combos;
}


//Adicionar ao cardápio com operador +;
void Cardapio::operator+(const Produto& p){
    produtos.push_back(p);
}

void Cardapio::operator+(Combo& c){
    Produto prod = c.criarProduto();
    combos.push_back(prod);
}

//Saída e entrada do cardápio
ostream& operator<<(ostream& os, Cardapio& c){
    os << endl;

    c.exporCardapio();

    return os;
}

//Cria tanto os produtos quanto combos!
istream& operator>>(istream& is, Cardapio& c){
    int escolha, qnt, id;
    Produto prod;
    ItemPedido ip;
    Combo comb;
    string nome;

    cout << "Produto (1) ou Combo (2)? ";
    cin >> escolha;

    try{
        if(escolha == 1){
            cin >> prod;
            c.addProduto(prod);
        }else if(escolha == 2){
            cout << "Qual será o nome do combo? ";
            cin >> nome;
            comb.setNome(nome);
            while(escolha != 0){
                cout << "Qual o ID do Produto (Começa em zero, depende da ordem dos produtos ao imprimir o Cardápio - Não considera outros combos)? ";
                try {
                    cin >> id;
                    if(id < 0 || id > c.produtos.size()) {
                        throw invalid_argument("ID inválido.");
                    }
                    ip.setProduto(c.produtos[id]);
                } catch (exception& e) {
                    cout << e.what();
                }
                cout << "Quantos do item adicionar ao combo? ";
                try {
                    cin >> qnt;
                    if(qnt <= 0) {
                        throw invalid_argument("Quantidade deve ser maior que zero.");
                    }
                    ip.setQuantidade(qnt);
                } catch (exception& e) {
                    cout << e.what();
                }
                comb.addProduto(ip);
                //c.addCombo(prod); //Pegar da sua própria lista de produtos, colocar quantidade, adicionar ao combo, e no final usar c.criarProduto();
                cout << "Adicionar mais produtos ao combo? (Digite 0 caso não) ";
                cin >> escolha;
            }
            c + comb;
            //prod = comb.criarProduto(); //Finaliza criação do combo
            //c.addCombo(prod); //Adiciona combo na sua forma de produto
        }else {
            throw invalid_argument("Escolha Inválida.");
        }
    }catch (exception& e){
        cout << e.what();
    }

    return is;
}

//Salvar e carregar PRODUTOS
void Cardapio::salvarP(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(this), sizeof(Cardapio));
}
void Cardapio::carregarP(ifstream& in) {
    in.read(reinterpret_cast<char*>(this), sizeof(Cardapio));
}

//Salvar