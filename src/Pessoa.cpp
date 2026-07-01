#include "../include/Pessoa.h"
#include <string>

using namespace std;

Pessoa::Pessoa(){

}

Pessoa::Pessoa(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}


void Pessoa::setNome(string n){
    this->nome = n;
}
string Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setCpf(string c){
    this->cpf = c;
}
string Pessoa::getCpf() const
{
    return cpf;
}
