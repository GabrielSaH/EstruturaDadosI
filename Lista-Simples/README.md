Funções da lista:

void addno : Adiciona um novo nó no final da lista.  
void printLista : Percorre a lista mostrando os valores armazenados em ordem.  
void retiraUltimo : Retira o ultimo elemento da lista.  
void retiraValor : Retira a primeira ocorrencia do valor argumento.  
Void retiraTodosValor : Retira todas as ocorrencias do valor argumento.  
void addnoInicio : Adiciona um novo nó no inicio da lista.  
no* buscaValor : retorna um ponteiro para o primeiro nó com o valor argumento. (retorna nullptr em falha de busca)  
int buscaIndex : retorna o index do primeiro nó com o valor argumento. (retorna NULL em falha de busca)  
int getValor const : retorna o valor de um nó  
int setValor : altera o valor de um nó

Overloading feitos:


int& operator[] : overloading do operador [] permitindo indexação da lista como por exemplo: minhaLista[10]. A indexação retornara apenas o valor armazenado no nó  
void operator= (int) : overloading do operador = quando o valor atribuido é um int, permite trocar o valor de um index sem influenciar a list Ex: minhaLista[0] = 10  

Obs:

O heading da lista NÂO é um ponteiro, porem, todos os outros nós são ponteiros.  
é possivel fazer operaçoes com o index, como minhaLista[0] = minhaLista[2] + minhaLista[1]  
a operação addno e buscaValor são feitas usando recursão.  
buscaValor foi implementada puramente por que foi pedido em aula.  
as funçoes getValor e setValor foram feitas por que sem elas buscaValor nao teria nenhuma utilidade... isso porque os atributos da classe são privados.  
index negativo iniciara a contagem de tras para frente ex: minhaLista[-1] retorna o valor da ultima posição da lista.  

