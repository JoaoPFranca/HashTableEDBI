#include <iostream>
#include <string>
#include "hashTable.h" 

int main() {
  //Criando a tabela de dispersao
  HashTable hashTable(100); // tamanho da tabela de dispersao e 100

  //Adicionando 20 palavras  tabela de dispersao
  hashTable.addWord("apple");
  hashTable.addWord("orange");
  hashTable.addWord("banana");
  hashTable.addWord("grape");
  hashTable.addWord("cherry"); 
  hashTable.addWord("peach"); 
  hashTable.addWord("mango"); 
  hashTable.addWord("apricot"); 
  hashTable.addWord("plum"); 
  hashTable.addWord("date");
  hashTable.addWord("fig"); 
  hashTable.addWord("kiwi"); 
  hashTable.addWord("lemon");
  hashTable.addWord("lime");
  hashTable.addWord("nectarine");
  hashTable.addWord("tangerine");
  hashTable.addWord("pear");
  hashTable.addWord("quince");
  hashTable.addWord("raspberry");
  hashTable.addWord("strawberry");

  //Contando a quantidade de ocorrencias das palavras
  std::cout << "Quantidade de 'apple': " << hashTable.countWord("apple") << std::endl;
  std::cout << "Quantidade de 'orange': " << hashTable.countWord("orange") << std::endl;
  std::cout << "Quantidade de 'banana': " << hashTable.countWord("banana") << std::endl;
  std::cout << "Quantidade de 'grape': " << hashTable.countWord("grape") << std::endl;
  std::cout << "Quantidade de 'cherry': " << hashTable.countWord("cherry") << std::endl;

  //Verificando se uma palavra esta na tabela
  if(hashTable.containsWord("peach")) {
    std::cout << "'peach' esta na tabela." << std::endl;
  } else {
    std::cout << "'peach' nao esta na tabela." << std::endl;
  }

  //Removendo uma palavra da tabela
  hashTable.removeWord("date");
  if(!hashTable.containsWord("date")) {
    std::cout << "'date' foi removida da tabela." << std::endl;
  }

  //Imprimindo todo o conteúdo da tabela
  hashTable.printTable();

  return 0;

}