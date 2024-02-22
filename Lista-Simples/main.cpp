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

    int& operator[](int index) {
        no* atual = this;

        for (int i(0); i < index; i++) {
            if (atual == nullptr) exit(1);

            atual = atual->next;
        };

        return atual->valor;
    };


    
    void operator=(int v) {
        this->valor = v;
        return;
    };
};


int main() {

    no teste = no(1);

    teste.addNo(2);
    teste.addNo(3);
    teste.addNo(4);
    teste.addNo(5);
    teste.addNo(6);
    teste.addNo(6);
    teste.addNo(7);
    teste.addNo(8);
    
    
    teste[3] = 100;
    
    teste[4] = teste[3] * 2;

    teste.retiraUltimo();
    teste.retiraPrimeiro();
    
    teste.addNoInicio(9);

    teste.retiraValor(4);
    teste.retiraTodosValor(6);

    teste.printLista();


    std::cout << "teste[3] = " << teste[3] << std::endl;

    return 0;
}