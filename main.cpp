#include <iostream>
#include <vector>
#include "Biblioteca.cpp"
#include "Usuario.h"
using namespace std;

int main() {
    Sistema_da_Biblioteca sistema; // Criando o sistema da biblioteca
    Usuario* usuario = nullptr;  // Ponteiro para armazenar o usuário cadastrado (inicia como nullptr)

    int escolha, escolha2;
    string nome, senha, nomeLogin, senhaLogin;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Seja bem-vindo a Biblioteca CInForme!" << endl;

    while (true) {
        cout << "\n1. Cadastrar Usuario\n";
        cout << "2. Fazer Login\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        if (escolha == 1) {
            if (usuario != nullptr) {
                cout << "Usuario ja cadastrado!\n";
            } else {
                cout << "Digite seu usuario: ";
                cin >> nome;
                cout << "Digite sua senha: ";
                cin >> senha;
                usuario = new Usuario(nome, senha);
                cout << "Usuario cadastrado com sucesso!\n";
            }
        } 
        else if (escolha == 2) {
            if (usuario == nullptr) {
                cout << "Nenhum usuario cadastrado! Por favor, cadastre-se primeiro.\n";
            } else {
                cout << "\n--- Login ---\n";
                cout << "Nome: ";
                cin >> nomeLogin;
                cout << "Senha: ";
                cin >> senhaLogin;

                if (usuario->autenticar(nomeLogin, senhaLogin)) {
                    cout << "Login bem-sucedido! Bem-vindo, " << nomeLogin << ".\n";
                    break;  // Sai do loop e segue com o sistema após login
                } else {
                    cout << "Credenciais invalidas. Tente novamente.\n";
                }
            }
        } 
        else if (escolha == 3) {
            cout << "Obrigado por nos visitar! Volte sempre..." << endl;
            delete usuario;  // Libera a memória antes de sair
            return 0;
        } 
        else {
            cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    do {
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "MENU PRINCIPAL DA BIBLIOTECA: " << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "1. Adicionar um livro" << endl;
        cout << "2. Catalogo de livros" << endl;
        cout << "3. Alugar um livro" << endl;
        cout << "4. Ver meus livros alugados" << endl;
        cout << "5. Editar um livro" << endl;
        cout << "6. Remover um livro" << endl;
        cout << "7. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha2;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

        switch(escolha2) {
            case 1:
                sistema.Adicionar_Livro();
                break;
            case 2:
                sistema.Listar_Livros();
                break;
            case 3:
                sistema.Listar_Livros();
                cout << "";
                sistema.Alugar_Livro();
                break;
            case 4:
                sistema.Listar_Livros_Alugados();
                break;
            case 5:
                sistema.Editar_Livro();
                break;
            case 6:
                sistema.Remover_Livro();
                break;
            case 7:
                cout << "Obrigado por nos visitar! Volte sempre..." << endl;    
                break;
            default:
                cout << "Escolha uma das opcoes do menu!!!" << endl;
        }

    } while (escolha2 != 7);

    return 0;
}