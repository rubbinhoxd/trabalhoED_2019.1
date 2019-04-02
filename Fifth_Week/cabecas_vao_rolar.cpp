#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node * prev;
    Node(int value = 0, Node * next = nullptr, Node * prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

struct Lista{
    Node * head;
    Node * tail;

    Lista(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void show(){
        cout << "[ ";
        Node * node = head->next;
        while(node != tail){
            cout << node->value << " ";
            node = node->next;
        }
        cout << "]\n";
    }

    void push_back(int value){
        insert(tail, value);
    }

    void pop_back(){
        if(head->next == tail)
            return;
        remover(tail->prev);
    }

    void pop_front(){
        if(head->next == tail)
            return;
        remover(head->next);
    }

    void push_front(int value){
        insert(head->next, value);
    }

    void insert(Node * ref, int value){
        Node * node = new Node(value, ref, ref->prev);
        ref->prev = node;
        node->prev->next = node;
    }

    void remover(Node * ref){
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }
};


void mostrar(Lista lista, int esc){
    cout << "[ ";
    Node * node = lista.head->next;
    while(node != lista.tail){
        if(node->value == esc || node->value == esc*-1){
            if(node->value < 0)
                cout << "<" << node->value << " ";
            else
                cout << node->value << ">" << " ";
        }
        else
            cout << node->value << " ";
        node = node->next;
    }
    cout << "]\n";
}

int main(){
    Lista lista;
    
    int num = 0; 
    
    int esc = 0;
    
    int modulo = 0;
    
    int aux2 = 0;

    cin >> num >> esc >> modulo;

    for(int i = 1; i <= num; i++){
        lista.push_back(i*modulo);    //ler a lista
        modulo*=-1;
    }

    mostrar(lista,esc);

    Node * aux1 = lista.head->next;
    
    while(lista.head->next->next != lista.tail){
        if(aux1->value == esc || aux1->value == esc*-1) {
            if (aux1->value < 0) {
                if (aux1->prev == lista.head) {
                    aux1 = lista.tail;
                    lista.remover(aux1->prev);
                }
                else
                    lista.remover(aux1->prev);

                if(esc < 0)
                    aux2= esc*-1;
                else
                    aux2 = esc;

                for (int i = 0; i < aux2; i++) {
                    aux1 = aux1->prev;                    //procurando o proximo esc
                    if (aux1 == lista.head)
                        aux1 = lista.tail->prev;
                }
                
                esc = aux1->value;
                
                mostrar(lista, esc);
            }
            else{
                if (aux1->next == lista.tail) {
                    aux1 = lista.head;
                    lista.remover(aux1->next);
                }
                else
                    lista.remover(aux1->next);

                if(esc < 0)
                    aux2= esc*-1;
                else
                    aux2 = esc;

                for (int i = 0; i < aux2; i++) {
                    aux1 = aux1->next;
                    if (aux1 == lista.tail)                  //procurando o proximo escolhido
                        aux1 = lista.head->next;
                }
                
                esc = aux1->value;
                
                mostrar(lista, esc);
            }
        }
        else
            aux1 = aux1->next;
    }

}
