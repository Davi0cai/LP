#include <iostream>
#include <string>

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"

using namespace std;

class Cliente : public Pessoa {
protected:
    string apelido;
public:
    Cliente();

    Cliente(string nome, string cpf, string a);

    string getApelido();
    void setApelido(string a);

    friend ostream& operator<<(ostream& os, Cliente& cli);

    friend istream& operator>>(istream& is, Cliente& cli);
};

#endif
