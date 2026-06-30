#include "../include/Cliente.h"

using namespace std;

Cliente::Cliente(){

}

Cliente::Cliente(string nome, string cpf, string a) : Pessoa(nome, cpf) {
    this->apelido = a;
}

string Cliente::getApelido(){
    return apelido;
}
void Cliente::setApelido(string a){
    this->apelido = a;
}

ostream& operator<<(ostream& os, Cliente& cli){
    os << cli.nome << " (" << cli.cpf << ") | Apelido: " << cli.apelido;
    return os;
}

istream& operator>>(istream& is, Cliente& cli){
    string info;

    cout << "Nome do cliente? ";
    getline(is, info);
    cli.setNome(info);

    cout << "CPF do cliente? ";
    getline(is, info);
    cli.setCpf(info);

    cout << "Apelido a se Referir? ";
    getline(is, info);
    cli.setApelido(info);

    return is;
}