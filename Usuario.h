#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    string nome, senha;

public:
    Usuario(string n, string s);
    bool autenticar(string n, string s) const;
    string getNome() const;
};

#endif