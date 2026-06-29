#include <iostream>
#include <string>

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"

using namespace std;

class Cliente : public Pessoa
{
public:
    Cliente(string nome, string cpf);
};

#endif
