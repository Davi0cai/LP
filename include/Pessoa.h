#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

class Pessoa {
protected:
   string nome;
   string cpf;

public:
    Pessoa(string nome, string cpf);

    string getNome() const;

    string getCpf() const;

};


#endif // PESSOA_H