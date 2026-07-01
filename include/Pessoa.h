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
    Pessoa();

    Pessoa(string nome, string cpf);

    void setNome(string n);
    string getNome() const;

    void setCpf(string c);
    string getCpf() const;

};


#endif // PESSOA_H