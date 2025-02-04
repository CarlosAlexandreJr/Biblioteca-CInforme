#include <iostream>
#include <vector>
#include "Biblioteca.cpp"  // Inclusão do arquivo que contém a lógica do sistema da biblioteca
#include "Usuario.h"       // Inclusão do arquivo que define a classe Usuario
using namespace std;

int main() {
    // Criação do objeto sistema que gerencia a biblioteca
    Sistema_da_Biblioteca sistema; 

    // Ponteiro para armazenar o usuário cadastrado, inicialmente nulo (não existe nenhum usuário)
    Usuario* usuario = nullptr;  

    int escolha, escolha2;
    string nome, senha, nomeLogin, senhaLogin;

    // Exibição de boas-vindas
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Seja bem-vindo a Biblioteca CInForme!" << endl;

    while (true) {
        // Apresentação das opções do menu inicial
        cout << "\n1. Cadastrar Usuario\n";
        cout << "2. Fazer Login\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        // Se o usuário escolher a opção de cadastro
        if (escolha == 1) {
            // Verifica se já existe um usuário cadastrado
            if (usuario != nullptr) {
                cout << "Usuario ja cadastrado!\n";  // Se já existir, informa que o cadastro não pode ser feito
            } else {
                // Se não existir, solicita o nome e a senha para criar o usuário
                cout << "Digite seu usuario: ";
                cin >> nome;
                cout << "Digite sua senha: ";
                cin >> senha;
                usuario = new Usuario(nome, senha);  // Cria o usuário e armazena no ponteiro
                cout << "Usuario cadastrado com sucesso!\n";
            }
        } 
        // Se o usuário escolher a opção de login
        else if (escolha == 2) {
            // Se não houver usuário cadastrado, informa o erro
            if (usuario == nullptr) {
                cout << "Nenhum usuario cadastrado! Por favor, cadastre-se primeiro.\n";
            } else {
                // Solicita as credenciais de login
                cout << "\n--- Login ---\n";
                cout << "Nome: ";
                cin >> nomeLogin;
                cout << "Senha: ";
                cin >> senhaLogin;

                // Verifica se as credenciais são válidas
                if (usuario->autenticar(nomeLogin, senhaLogin)) {
                    cout << "Login bem-sucedido! Bem-vindo, " << nomeLogin << ".\n";
                    break;  // Sai do loop principal após login bem-sucedido
                } else {
                    cout << "Credenciais invalidas. Tente novamente.\n";  // Se as credenciais estiverem erradas
                }
            }
        } 
        // Se o usuário escolher a opção de sair
        else if (escolha == 3) {
            cout << "Obrigado por nos visitar! Volte sempre..." << endl;
            delete usuario;  // Libera a memória alocada para o objeto usuario antes de sair
            return 0;  // Encerra o programa
        } 
        // Se a opção digitada for inválida
        else {
            cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    // Menu principal do sistema da biblioteca
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

        // Com base na opção escolhida, o sistema executa a ação correspondente
        switch(escolha2) {
            case 1:
                sistema.Adicionar_Livro();  // Chama a função para adicionar um livro
                break;
            case 2:
                sistema.Listar_Livros();  // Chama a função para listar os livros disponíveis
                break;
            case 3:
                sistema.Listar_Livros();  // Exibe os livros disponíveis
                cout << "";
                sistema.Alugar_Livro();  // Chama a função para alugar um livro
                break;
            case 4:
                sistema.Listar_Livros_Alugados();  // Exibe os livros alugados
                break;
            case 5:
                sistema.Editar_Livro();  // Chama a função para editar os detalhes de um livro
                break;
            case 6:
                sistema.Remover_Livro();  // Chama a função para remover um livro do sistema
                break;
            case 7:
                cout << "Obrigado por nos visitar! Volte sempre..." << endl;  // Mensagem de despedida
                break;
            default:
                cout << "Escolha uma das opcoes do menu!!!" << endl;  // Caso a opção seja inválida
        }

    } while (escolha2 != 7);  // O loop continua até que a opção 7 (sair) seja escolhida

    return 0;  // Finaliza o programa
}
