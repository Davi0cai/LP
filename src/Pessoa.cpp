#include "../include/Pessoa.h"
#include <string>

using namespace std;

Pessoa::Pessoa(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}

string Pessoa::getNome() const
{
    return nome;
}

string Pessoa::getCpf() const
{
    return cpf;
}
