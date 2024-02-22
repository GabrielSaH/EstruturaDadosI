Funções da lista:

void addNo : Adiciona um novo nó no final da lista

void printLista : Percorre a lista mostrando os valores armazenados em ordem.

void retiraUlrimo : Retira o ultimo elemento da lista

void retiraValor : Retira a primeira ocorrencia do valor argumento

Void retiraTodosValor : Retira todas as ocorrencias do valor argumento
void addNoInicio : Adiciona um novo nó no inicio da lista


Overloading feitos:


int& operator[] : overloading do operador [] permitindo indexação da lista como por exemplo: minhaLista[10]. A indexação retornara apenas o valor armazenado no nó

void operator= (int) : overloading do operador = quando o valor atribuido é um int, permite trocar o valor de um index sem influenciar a list Ex: minhaLista[0] = 10


Obs:



O heading da lista NÂO é um ponteiro, porem, todos os outros nos seguintes são ponteiros.

é possivel fazer operaçoes com o index, como minhaLista[0] = minhaLista[2] + minhaLista[1]

a operação addNo é a unica feita com recursão.

