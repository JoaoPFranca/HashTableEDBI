#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChaveValor {
public:
  string chave;
  int valor;
  ChaveValor *proximo;

  ChaveValor(string chaveNova) {
    chave = chaveNova;
    valor = 1;
    proximo = nullptr;
  }

  ~ChaveValor() {
    delete proximo;
  }
};

class ListaEncadeada {
public:
  ChaveValor *primeiro;
  int tamanho;

  ListaEncadeada() {
    primeiro = nullptr;
    tamanho = 0;
  }

  ~ListaEncadeada() {
    ChaveValor *atual = primeiro;
    for(int i = 0; i < tamanho - 1; i++) {
      ChaveValor *proximo = atual->proximo;
      delete atual;
      atual = proximo;
    }
  }

  bool remover(string chave) {
    ChaveValor *atual = primeiro;

    if (primeiro->chave == chave) {
      primeiro = primeiro->proximo;
      delete atual;
      tamanho--;
      return true;
    }

    ChaveValor *anterior = nullptr;
    for (int i = 0; i < tamanho - 1; i++) {
      anterior = atual;
      atual = atual->proximo;
      if (atual->chave == chave) {
        anterior->proximo = atual->proximo;
        delete atual;
        tamanho--;
        return true;
      }
    }

    return false;
  }
  bool verificar(string chave) {
    ChaveValor *atual = primeiro;

    for (int i = 0; i < tamanho; i++) {
      if (atual->chave == chave) {
        return true;
      }
      atual = atual->proximo;
    }

    return false;
  }
  int retornarValor(string chave) {
    ChaveValor *atual = primeiro;
    for (int i = 0; i < tamanho; i++) {
      if (atual->chave == chave) {
        return atual->valor;
      } else {
        atual = atual->proximo;
      }
    }
    return -1;
  }
  bool atualizarValor(string chave, int valorNovo) {
    ChaveValor *atual = primeiro;
    for (int i = 0; i < tamanho; i++) {
      if (atual->chave == chave) {
        atual->valor = valorNovo;
        return true;
      } else {
        atual = atual->proximo;
      }
    }

    return false;
  }
  bool inserir(string chave) {
    if (verificar(chave)) {
      atualizarValor(chave, retornarValor(chave) + 1);
      return true;
    }

    ChaveValor *novoChaveValor = new ChaveValor(chave);
    if (primeiro == nullptr) {
      primeiro = novoChaveValor;
      tamanho++;
      return true;
    }

    ChaveValor *atual = primeiro;
    for (int i = 0; i < (tamanho - 1); i++) {
      atual = atual->proximo;
    }
    atual->proximo = novoChaveValor;
    tamanho++;

    return true;
  }
  void imprimir(int indice) {
    ChaveValor *atual = primeiro;
    cout << "indice " << indice << ": ";
    for (int i = 0; i < tamanho; i++) {
      cout << "(" << "\"" << atual->chave << "\"" << ", " << atual->valor << ")";
      if (i != tamanho - 1) {
        cout << " -> ";
      } else {
        cout << " -> NULL";
      }
      atual = atual->proximo;
    }
    cout << endl;
  }
};

class HashTable {
public:
  ListaEncadeada *tabela;
  int TABLE_SIZE;

  HashTable(int tamanhoTabela) {
    TABLE_SIZE = tamanhoTabela;
    tabela = new ListaEncadeada[TABLE_SIZE];
  }

  int hashFunction(string word) {
    unsigned long hash = 5381;
    for (char c : word) {
      hash = ((hash << 5) + hash) + static_cast<unsigned long>(c);
    }

    return hash % TABLE_SIZE;
  }
  void addWord(string chave) {
    int indice = hashFunction(chave);
    if (tabela[indice].inserir(chave)) {
      cout << "Texto adicionado. Contagem de palavras atualizada" << endl;
    } else {
      cout << "Não foi possível adicionar o texto" << endl;
    }
  }
  void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      tabela[i].imprimir(i);
    }
  }
  void removeWord(string chave) {
    int indice = hashFunction(chave);
    if (!tabela[indice].remover(chave)) {
      cout << "Não foi possível remover o texto" << endl;
    } else {
      cout << "Palavra " << "\"" << chave << "\"" << " removida." << endl;
    }
  }
  bool containsWord(string chave) {
    int indice = hashFunction(chave);
    if(tabela[indice].verificar(chave)) {
      cout << "A palavra " << "\"" << chave << "\"" << " está presente." << endl;
    }
    return (tabela[indice].verificar(chave));
  }
  int countWord(string chave) {
    int indice = hashFunction(chave);
    int valor = tabela[indice].retornarValor(chave);

    cout << "A palavra " << "\"" << chave << "\"" << " ocorre " << valor << " vez(es) ";
    return valor;
  }
  void updateWord(string chave, int valorNovo) {
    int indice = hashFunction(chave);
    int valor = tabela[indice].atualizarValor(chave, valorNovo);

    cout << "Contagem da palavra " << "\"" << chave << "\"" << " atualizada para " << valor << "." << endl;
  }
};