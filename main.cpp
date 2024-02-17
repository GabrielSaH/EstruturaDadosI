#include <iostream>

class no{
private:
    no* next;
    int valor;

public:
    no(int v):valor(v), next(nullptr)
    {
        
    };

    void addNo(int v){
        if (this->next == nullptr){
            this->next = new no(v);
            return;
        }

        else{
            this->next->addNo(v);
        }
        return;
    };

    void printLista(){
        std::cout << "Valor = " <<this->valor << std::endl;
        
        if (this->next != nullptr){
            this->next->printLista();
        }

        return;
    }

    void retiraUltimo(){
        if (this->next == nullptr){
            delete(this);
            return;
        };
        
        no* ant = this;
        no* next = this->next;

        while (next->next != nullptr){
            ant = ant->next;
            next = next->next;
        };


        delete(next);
        ant->next = nullptr;

    }

};


int main(){

    no teste = no(10);
    
    teste.addNo(12);
    teste.addNo(13);
    
    teste.retiraUltimo();

    teste.printLista();

    return 0;
}

