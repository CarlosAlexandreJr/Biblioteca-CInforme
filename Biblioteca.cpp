#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Livro {
    string titulo, autor, editora;
    int isbn, ano;
};

class Sistema_da_Biblioteca {
private:
    vector<Livro> biblioteca; // Vetor de livros da biblioteca
    vector<Livro> meusLivros; // Vetor de livros do usuário

public:
    // Função que adiciona livros
    void Adicionar_Livro() {
        cout << "" << endl;
        Livro novoLivro; // Criando um novo livro
        // Lendo o titulo do livro
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Titulo do livro: ";
        cin.ignore(); // Limpando
        getline(cin, novoLivro.titulo);
        // Lendo o autor do livro
        cout << "Autor do livro: ";
        getline(cin, novoLivro.autor);
        // Lendo a editora do livro
        cout << "Editora do livro: ";
        getline(cin, novoLivro.editora);
        // Lendo o ano do livro
        cout << "Ano do livro: ";
        cin >> novoLivro.ano;
        // Lendo o isbn do livro
        cout << "ISBN do livro: ";
        cin >> novoLivro.isbn;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        // Adicionando o livro à biblioteca
        biblioteca.push_back(novoLivro);
        // Imprimindo a mensagem
        cout << "O livro " << novoLivro.titulo << " foi adicionado ao estoque." << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;
    }

    // Função para listar livros disponiveis
    void Listar_Livros() const {
        cout << "" << endl;
        // Imprimindo um titulo
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Livros disponiveis no momento:" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        if (biblioteca.size() == 0) {
            // Imprimindo a mensagem
            cout << "Nosso catalogo de livros esta vazio." << endl;
            cout << "" << endl;
        } else {
            // Imprimindo o catálogo de livros
            for (size_t i = 0; i < biblioteca.size(); ++i) {
                cout << i + 1 << ". Titulo: " << biblioteca[i].titulo << " | Autor: " << biblioteca[i].autor << endl;
                cout << "Editora: " << biblioteca[i].editora << " | Ano: " << biblioteca[i].ano << endl;
                cout << "ISBN: " << biblioteca[i].isbn << endl;
            }
        }
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;
    }

    // Função para remover um livro do catálogo
    void Alugar_Livro() {

        int numLivro;
        // Imprimindo a mensagem
        if (biblioteca.size() > 0) {
            cout << "Numero do livro que deseja alugar (1 a " << biblioteca.size() << "): ";
        cin >> numLivro;
        // Verificando se o numLivro é válido e imprimindo a mensagem de confirmação
        if (numLivro <= biblioteca.size() && numLivro > 0){
            cout << "O livro \"" << biblioteca[numLivro - 1].titulo << "\" foi alugado!" << endl;
            meusLivros.push_back(biblioteca[numLivro - 1]);
            biblioteca.erase(biblioteca.begin() + numLivro - 1);

        }
        else{
            cout << "O livro de numero " << numLivro << " nao foi encontrado!" << endl;
        }
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;            
        }     
    }

    void Listar_Livros_Alugados() const {
        cout << "" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Livros alugados por você:" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

        if (meusLivros.empty()) {
            cout << "Você ainda nao alugou nenhum livro." << endl;
        } else {
            for (size_t i = 0; i < meusLivros.size(); ++i) {
                cout << i + 1 << ". Titulo: " << meusLivros[i].titulo << " | Autor: " << meusLivros[i].autor << endl;
                cout << "Editora: " << meusLivros[i].editora << " | Ano: " << meusLivros[i].ano << endl;
                cout << "ISBN: " << meusLivros[i].isbn << endl;
                cout << "-------------------------------" << endl;
            }
        }

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;
    }

    // Editar um livro existente
    void Editar_Livro() {
        if (biblioteca.empty()) {
            cout << "Nao ha livros disponiveis para editar." << endl;
            return;
        }

        Listar_Livros(); // Mostra a lista de livros
        int numLivro;
        cout << "Digite o numero do livro que deseja editar (1 a " << biblioteca.size() << "): ";
        cin >> numLivro;

        if (numLivro < 1 || numLivro > biblioteca.size()) {
            cout << "Numero invalido! Nenhuma edicao realizada." << endl;
            return;
        }

        Livro& livro = biblioteca[numLivro - 1]; // Obtém referência ao livro selecionado

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Editando o livro: " << livro.titulo << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

        cin.ignore(); // Limpa o buffer do cin
        cout << "Novo titulo: ";
        getline(cin, livro.titulo);
        cout << "Novo autor: ";
        getline(cin, livro.autor);
        cout << "Nova editora: ";
        getline(cin, livro.editora);
        cout << "Novo ano: ";
        cin >> livro.ano;
        cout << "Novo ISBN: ";
        cin >> livro.isbn;

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "O livro foi atualizado com sucesso!" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    }

    void Remover_Livro() {
        if (biblioteca.empty()) {
            cout << "Nao ha livros disponiveis para remover." << endl;
            return;
        }

        Listar_Livros(); // Exibe os livros disponiveis
        int numLivro;
        cout << "Digite o numero do livro que deseja remover (1 a " << biblioteca.size() << "): ";
        cin >> numLivro;

        if (numLivro < 1 || numLivro > biblioteca.size()) {
            cout << "Numero invalido! Nenhuma remocao realizada." << endl;
            return;
        }

        cout << "O livro \"" << biblioteca[numLivro - 1].titulo << "\" foi removido do catalogo." << endl;
        biblioteca.erase(biblioteca.begin() + (numLivro - 1));

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    }
};