#include <iostream>
#include <string>

using namespace std;

#include "../include/Pessoa.h"
#include "../include/Entregador.h"

Entregador::Entregador(){

}

float Entregador::getSalario(){
    return salario;
}
void Entregador::setSalario(float s){
    this->salario = s;
}

int Entregador::getNumEntregas(){
    return numEntregas;
}
void Entregador::setNumEntregas(int n){
    this->numEntregas = n;
}

ostream& operator<<(ostream& os, Entregador& ent){
    os << ent.nome << " (CPF: " << ent.cpf << ") | Salário: " << ent.salario << " | Entregas: " << ent.numEntregas;
    return os;
}

istream& operator>>(istream& is, Entregador& ent){
    string info;

    cout << "Nome do entregador? ";
    getline(is, info);
    ent.setNome(info);

    cout << "CPF do entregador? ";
    getline(is, info);
    ent.setCpf(info);

    cout << "Salário do entregador? ";
    getline(is, info);
    ent.setSalario(stof(info));

    cout << "Número de entregas do entregador? ";
    getline(is, info);
    ent.setNumEntregas(stoi(info));

    return is;
}