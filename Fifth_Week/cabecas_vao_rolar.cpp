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

    cin >> num >> esc >> modulo;

    for(int i = 1; i <= num; i++){
        lista.push_back(i*modulo);
        modulo*=-1;
    }

    mostrar(lista,esc);

    Node * aux = lista.head->next;
    
    int aux2 = 0;
    
    while(lista.head->next->next != lista.tail){
        if(aux->value == esc || aux->value == esc*-1) {
            if (aux->value > 0) {
                if (aux->next == lista.tail) {
                    aux = lista.head;
                    lista.remover(aux->next);
                }
                else
                    lista.remover(aux->next);

                if(esc < 0)
                    aux2= esc*-1;
                else
                    aux2 = esc;

                for (int i = 0; i < aux2; i++) {
                    aux = aux->next;
                    if (aux == lista.tail)
                        aux = lista.head->next;
                }
                
                esc = aux->value;
                
                mostrar(lista, esc);
            }
            else{
                if (aux->prev == lista.head) {
                    aux = lista.tail;
                    lista.remover(aux->prev);
                }
                else
                    lista.remover(aux->prev);

                if(esc < 0)
                    aux2= esc*-1;
                else
                    aux2 = esc;

                for (int i = 0; i < aux2; i++) {
                    aux = aux->prev;
                    if (aux == lista.head)
                        aux = lista.tail->prev;
                }
                
                esc = aux->value;
                
                mostrar(lista, esc);
            }
        }
        else
            aux = aux->next;
    }

}
