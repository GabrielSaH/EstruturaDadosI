#include <iostream>

class no {
private:
    no* next;
    int valor;

public:
    no(int v) :valor(v), next(nullptr)
    {

    };

    void addNo(int v) {
        if (this->next == nullptr) {
            this->next = new no(v);
            return;
        }

        else {
            this->next->addNo(v);
        }
        return;
    };

    void printLista() {
        if (this == nullptr) return;

        std::cout << "Valor = " << this->valor << std::endl;

        if (this->next != nullptr) {
            this->next->printLista();
        }

        return;
    }

    void retiraUltimo() {
        if (this == nullptr) return;

        
        if (this->next == nullptr) {
            delete(this);
            return;
        };

        no* ant = this;
        no* next = this->next;

        while (next->next != nullptr) {
            ant = ant->next;
            next = next->next;
        };


        delete(next);
        ant->next = nullptr;


    }

    void retiraPrimeiro() {
        if (this == nullptr) return;

        
        if (this->next == nullptr) {
            delete(this);
            return;
        };

        no* prox = this->next;

        this->valor = prox->valor;
        
        this->next = prox->next;

        delete(prox);


        return;
    }

    void retiraValor(int v) {
        if (this == nullptr) return;



        if (this->valor == v) {
            this->retiraPrimeiro();
            return;
        };


        no* anterior = this;
        no* atual = this->next;

        while (atual != nullptr) {
            if (atual->valor == v) {
                anterior->next = atual->next;
                delete(atual);
                return;
            };

            anterior = anterior->next;
            atual = atual->next;
        };

        return;
    };

    void retiraTodosValor(int v) {
        if (this == nullptr) return;


        if (this->valor == v) {
            this->retiraPrimeiro();
        };


        no* anterior = this;
        no* atual = this->next;


        while (atual != nullptr) {
            if (atual->valor == v) {
                anterior->next = atual->next;
                no* temp = atual;
                atual = atual->next;
                delete(temp);
                continue;
            };

            anterior = anterior->next;
            atual = atual->next;
        };

        return;
    }

    void addNoInicio(int v) {
        no* temp = this->next;

        this->next = new no(this->valor);
        this->next->next = temp;
        this->valor = v;

    };

    no* buscaValor(int v) {
        if (this == nullptr) return nullptr;

        if (this->valor == v) {
            return this;
        }

        return this->next->buscaValor(v);
    }

    int buscaIndex(int v) {
        no* atual = this;
        int index = 0;

        while (atual != nullptr) {
            if (atual->valor == v) {
                return index;
            };

            atual = atual->next;
            index++;
        };
        return NULL;
    }

    void setValor(int v) {
        this->valor = v;
        return;
    };

    int getValor() const {
        return this->valor;
    }

    int& operator[](int index) {
        no* atual = this;

        if (index >= 0){
            for (int i(0); i < index; i++) {
                if (atual == nullptr) exit(1);

                atual = atual->next;
            };
        }
        
        if (index  < 0){
            no* pivo = this;
            no* atual = this;
            index = index * (-1);
            
            for (int i(1); i < index; i++){
                pivo = pivo->next;
                if (pivo == nullptr) exit(1);
            };

            while (pivo->next != nullptr){
                atual = atual->next;
                pivo = pivo->next;
            }

            return atual->valor;
        };

        return atual->valor;
    };

    
    void operator=(int v) {
        this->valor = v;
        return;
    };
};


int main() {

    // Lista Inicial: 1, 2, 3, 4, 5, 6, 6, 7, 8

    no lista = no(1);
    lista.addNo(2);
    lista.addNo(3);
    lista.addNo(4);
    lista.addNo(5);
    lista.addNo(6);
    lista.addNo(6);
    lista.addNo(7);
    lista.addNo(8);
    

    /* 
    ############## TESTE BUSCA DE VALOR ##############
    Retorna um ponteiro para o no de valor 2 e altera o valor para 50
    Lista Atual: 1, 2, 50, 4, 5, 6, 6, 7, 8
    */
    
    no* busca = lista.buscaValor(3);
    busca->setValor(50);

    /*
    ############## TESTE DE INDEX ##############
    Altera a lista na posicao 3 para 100 e a posicao 4 para 2 * lista[3] (200)
    Lista Atual: 1, 2, 50, 100, 200, 6, 6, 7, 8
    */
    
    lista[3] = 100;
    lista[4] = lista[3] * 2;

    /*
    ############## TESTE DE RETIRAR POSICAO ##############
    Retira a primeira posicao da lista e depois retira a ultima posicao
    Lista Atual: 2, 50, 100, 200, 6, 6, 7 
    */

    lista.retiraUltimo();
    lista.retiraPrimeiro();
    

    /*
    ############## TESTE DE ADICIONAR ##############
    Adiciona 9 no inicio da lista
    Lista Atual: 10, 11, 10, 9, 2, 50, 100, 200, 6, 6, 7
    */

    lista.addNoInicio(9);
    lista.addNoInicio(10);
    lista.addNoInicio(11);
    lista.addNoInicio(10);

    /*
    ############## TESTE DE RETIRAR VALOR ##############
    Retira a primeira ocorrencia do valor 10, e depois todas as ocorrencias do valor 6
    Lista Atual: 11, 10, 9, 2, 50, 100, 200, 7
    */

    lista.retiraValor(10);
    lista.retiraTodosValor(6);

    /*
    ############## TESTE DE BUSCA INDEX ##############
    Busca pelo index da primeira ocorrencia do valor desejado, simuntaneamente usa do index para alterar o valor
    Lista Atual: 20, 10, 9, 2, 50, 100, 200, 7
    */

    lista[lista.buscaIndex(11)] = 20;


    lista.printLista();

    std::cout << std::endl << std::endl << "Ponteiro: " << busca << std::endl << "valor: " << busca->getValor() << std::endl;

    std::cout << "lista[3] = " << lista[3] << std::endl;
    std::cout << "lista[-1] = " << lista[-1] << std::endl;


    return 0;
}