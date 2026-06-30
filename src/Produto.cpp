#include "../include/Produto.h"

Produto::Produto(){
    
}

Produto::Produto(string nome, float preco, string descricao)
{
    this->nome = nome;
    this->preco = preco;
    this->descricao = descricao;
}

Produto::~Produto()
{
}

string Produto::getNome() const
{
    return nome;
}

void Produto::setNome(string nome)
{
    this->nome = nome;
}

float Produto::getPreco() const
{
    return preco;
}

void Produto::setPreco(float preco)
{
    this->preco = preco;
}

string Produto::getDesc() const{
    return descricao;
}

void Produto::setDesc(string d){
    this->descricao = d;
}

//Saída e entrada para produto
ostream& operator<<(ostream& os, const Produto& p){
    os << "Produto: " << p.nome << " | " << p.preco << "R$" << "\nDescrição: " << p.descricao;
    return os;
}

istream& operator>>(istream& is, Produto& p){
    string info;

    is.ignore();

    cout << "Nome do produto? ";
    getline(is, info);
    p.nome = info;

    cout << "Preço do produto? ";
    getline(is, info);
    p.preco = stof(info);

    cout << "Descrição do produto? ";
    getline(is, info);
    p.descricao = info;
    
    return is;
}

//Salvamento e carregar
void Produto::salvar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(this), sizeof(Produto));
}

void Produto::carregar(ifstream& in) {
    in.read(reinterpret_cast<char*>(this), sizeof(Produto));
}