#include <iostream>
#include <fstream>

#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

using namespace std;

class Produto {
protected:
    string nome;
    float preco;
    string descricao;
public:
    Produto();

    Produto(string nome, float preco, string descricao = "Sem Detalhes");
    virtual ~Produto(); //Destrutor caso precise

    string getNome() const;
    void setNome(string nome);

    float getPreco() const;
    void setPreco(float preco);

    string getDesc() const;
    void setDesc(string d);

    friend ostream& operator<<(ostream& os, const Produto& p);

    friend istream& operator>>(istream& is, Produto& p);

    void salvar(ofstream& out) const;
    void carregar(ifstream& in);
};

#endif
