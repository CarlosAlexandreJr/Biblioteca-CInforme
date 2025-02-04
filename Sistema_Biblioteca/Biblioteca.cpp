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
    vector<Livro> meusLivros; // Vetor de livros alugados pelo usuário

public:
    // Função que adiciona livros ao catálogo da biblioteca
    void Adicionar_Livro() {
        cout << "" << endl;
        Livro novoLivro; // Criando um novo livro
        // Lendo o título do livro
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Titulo do livro: ";
        cin.ignore(); // Limpa o buffer para garantir leitura correta
        getline(cin, novoLivro.titulo); // Lê o título do livro
        // Lendo o autor do livro
        cout << "Autor do livro: ";
        getline(cin, novoLivro.autor); // Lê o autor do livro
        // Lendo a editora do livro
        cout << "Editora do livro: ";
        getline(cin, novoLivro.editora); // Lê a editora do livro
        // Lendo o ano do livro
        cout << "Ano do livro: ";
        cin >> novoLivro.ano; // Lê o ano de publicação
        // Lendo o ISBN do livro
        cout << "ISBN do livro: ";
        cin >> novoLivro.isbn; // Lê o ISBN do livro
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        // Adicionando o livro à biblioteca
        biblioteca.push_back(novoLivro); 
        // Imprime a confirmação
        cout << "O livro " << novoLivro.titulo << " foi adicionado ao estoque." << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;
    }

    // Função para listar os livros disponíveis na biblioteca
    void Listar_Livros() const {
        cout << "" << endl;
        // Imprime o cabeçalho para a lista de livros
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Livros disponiveis no momento:" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        if (biblioteca.size() == 0) {
            // Se não houver livros, imprime a mensagem correspondente
            cout << "Nosso catalogo de livros esta vazio." << endl;
            cout << "" << endl;
        } else {
            // Se houver livros, imprime a lista com as informações
            for (size_t i = 0; i < biblioteca.size(); ++i) {
                cout << i + 1 << ". Titulo: " << biblioteca[i].titulo << " | Autor: " << biblioteca[i].autor << endl;
                cout << "Editora: " << biblioteca[i].editora << " | Ano: " << biblioteca[i].ano << endl;
                cout << "ISBN: " << biblioteca[i].isbn << endl;
            }
        }
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "" << endl;
    }

    // Função para alugar um livro da biblioteca
    void Alugar_Livro() {
        int numLivro;
        // Se há livros disponíveis, solicita o número do livro para alugar
        if (biblioteca.size() > 0) {
            cout << "Numero do livro que deseja alugar (1 a " << biblioteca.size() << "): ";
            cin >> numLivro;
            // Verifica se o número do livro é válido
            if (numLivro <= biblioteca.size() && numLivro > 0) {
                cout << "O livro \"" << biblioteca[numLivro - 1].titulo << "\" foi alugado!" << endl;
                meusLivros.push_back(biblioteca[numLivro - 1]);  // Adiciona o livro aos livros do usuário
                biblioteca.erase(biblioteca.begin() + numLivro - 1); // Remove o livro da biblioteca
            }
            else {
                cout << "O livro de numero " << numLivro << " nao foi encontrado!" << endl; // Mensagem de erro
            }
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << "" << endl;            
        }     
    }

    // Função para listar os livros alugados pelo usuário
    void Listar_Livros_Alugados() const {
        cout << "" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Livros alugados por você:" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

        if (meusLivros.empty()) {
            cout << "Você ainda nao alugou nenhum livro." << endl; // Se não houver livros alugados
        } else {
            // Imprime a lista de livros alugados
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

    // Função para editar um livro existente na biblioteca
    void Editar_Livro() {
        // Verifica se há livros disponíveis para editar
        if (biblioteca.empty()) {
            cout << "Nao ha livros disponiveis para editar." << endl;
            return;
        }

        Listar_Livros(); // Exibe a lista de livros disponíveis
        int numLivro;
        cout << "Digite o numero do livro que deseja editar (1 a " << biblioteca.size() << "): ";
        cin >> numLivro;

        // Verifica se o número do livro é válido
        if (numLivro < 1 || numLivro > biblioteca.size()) {
            cout << "Numero invalido! Nenhuma edicao realizada." << endl;
            return;
        }

        Livro& livro = biblioteca[numLivro - 1]; // Obtém uma referência ao livro selecionado

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "Editando o livro: " << livro.titulo << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

        cin.ignore(); // Limpa o buffer do cin para permitir a leitura de strings corretamente
        cout << "Novo titulo: ";
        getline(cin, livro.titulo);  // Lê o novo título
        cout << "Novo autor: ";
        getline(cin, livro.autor);  // Lê o novo autor
        cout << "Nova editora: ";
        getline(cin, livro.editora);  // Lê a nova editora
        cout << "Novo ano: ";
        cin >> livro.ano;  // Lê o novo ano
        cout << "Novo ISBN: ";
        cin >> livro.isbn;  // Lê o novo ISBN

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "O livro foi atualizado com sucesso!" << endl;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    }

    // Função para remover um livro do catálogo da biblioteca
    void Remover_Livro() {
        // Verifica se há livros para remover
        if (biblioteca.empty()) {
            cout << "Nao ha livros disponiveis para remover." << endl;
            return;
        }

        Listar_Livros(); // Exibe a lista de livros disponíveis
        int numLivro;
        cout << "Digite o numero do livro que deseja remover (1 a " << biblioteca.size() << "): ";
        cin >> numLivro;

        // Verifica se o número do livro é válido
        if (numLivro < 1 || numLivro > biblioteca.size()) {
            cout << "Numero invalido! Nenhuma remocao realizada." << endl;
            return;
        }

        // Remove o livro do catálogo da biblioteca
        cout << "O livro \"" << biblioteca[numLivro - 1].titulo << "\" foi removido do catalogo." << endl;
        biblioteca.erase(biblioteca.begin() + (numLivro - 1));

        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    }
};
