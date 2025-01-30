#include "Usuario.h"

Usuario::Usuario(string n, string s) : nome(n), senha(s) {}

bool Usuario::autenticar(string n, string s) const {
    return nome == n && senha == s;
}

string Usuario::getNome() const {
    return nome;
}
