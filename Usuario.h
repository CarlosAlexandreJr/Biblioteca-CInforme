#ifndef USUARIO_H
#define USUARIO_H

#include <string>  // Inclui a biblioteca para manipulação de strings
using namespace std;

class Usuario {
private:
    string nome, senha;  // Armazenam o nome e a senha do usuário

public:
    // Construtor que inicializa o nome e a senha do usuário
    Usuario(string n, string s) : nome(n), senha(s) {}

    // Função que autentica o usuário comparando o nome e a senha fornecidos
    bool autenticar(string n, string s) const {
        // Retorna true se o nome e a senha coincidirem, caso contrário, false
        return nome == n && senha == s;
    }

    // Função que retorna o nome do usuário
    string getNome() const {
        return nome;  // Retorna o nome armazenado no objeto
    }
};

#endif
