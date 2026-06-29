#include <iostream>

#ifndef ENTREGADOR_H
#define ENTREGADOR_H

using namespace std;

#include "Pessoa.h"

class Entregador : public Pessoa {
protected:
    float salario;
    int numEntregas;
public:
    float getSalario();
    void setSalario(float s);

    int getNumEntregas();
    void setNumEntregas(int n);
};


#endif
