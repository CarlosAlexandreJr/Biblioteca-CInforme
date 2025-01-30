#include "Usuario.h"  // Inclui o arquivo de cabeçalho para a classe Usuario

// Construtor da classe Usuario: inicializa o nome e a senha
Usuario::Usuario(string n, string s) : nome(n), senha(s) {}

// Função que autentica o usuário: compara o nome e a senha fornecidos com os armazenados no objeto
bool Usuario::autenticar(string n, string s) const {
    // Retorna true se o nome e a senha fornecidos forem iguais aos armazenados, caso contrário, false
    return nome == n && senha == s;
}

// Função que retorna o nome do usuário
string Usuario::getNome() const {
    return nome;  // Retorna o nome armazenado
}
