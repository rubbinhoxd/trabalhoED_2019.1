#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <sstream>

using namespace std;


struct Client{
    string id;
    int docs;
    int pac; 

    Client(string id, int docs, int pac){
    	this->id = id;
    	this->docs = docs;
    	this->pac = pac;
    }

    void show(){
    	cout << this->id << ":" << this->docs << ":" <<this->pac;
    }
};

struct Banco{
    int docs_adq = 0;
    int docs_perdidos = 0;
    vector<Client*> caixas;
    list<Client*> fila_entrada;
    list<Client*> fila_saida;



    void init(int size){
    	for(int i = 0; i < size; i++){
    		caixas.push_back(nullptr);
    	}
    }

    void in(string id, int docs, int pac){
    	Client *new_client = new Client(id, docs, pac);
    	fila_entrada.push_back(new_client);
    }

    void show(){
    	for(int i = 0; i < (int) caixas.size(); i++){
    		if(caixas[i] != nullptr){
    			cout << "[";
    			caixas[i]->show();
    			cout << "]";
    		}
    		else{
    			cout << "[" << "]";
    		}
    	}
    	cout << endl << "in: { ";
    	for(auto it = fila_entrada.begin(); it != fila_entrada.end(); it++){
    		Client *aux = *it;
    		aux->show();
    		cout << " ";
    	}
    	cout << " }";

    	cout << endl << "out : { ";
    	for(auto it = fila_saida.begin(); it != fila_saida.end(); it++){
    		Client *aux = *it;
    		aux->show();
    		cout << " ";
    	}
    	cout << " }" << endl;
    }
    void tic(){
    	fila_saida.erase(fila_saida.begin(), fila_saida.end());

    	for(int i = 0; i < (int) caixas.size(); i++){
    		if(caixas[i] != nullptr){
    			if(caixas[i]->docs > 0){
    				caixas[i]->docs --;
    				this->docs_adq ++;
    			}
    			else{
    				fila_saida.push_back(caixas[i]);
    				caixas[i] = nullptr;
    			}
    		}
    		else{
    			if(fila_entrada.size() > 0){
    				auto it = fila_entrada.front();
    				caixas[i] = it;
    				fila_entrada.pop_front();
    			}
    		}
    	}
    	for(auto it = fila_entrada.begin(); it != fila_entrada.end();){
    		Client *aux = *it;
    		if(aux->pac > 0){
    			aux->pac --;
    		}
    		else{
    			this->docs_perdidos += aux->docs;
    			fila_saida.push_back(aux);
    			auto it2 = it;
    			it++;
    			fila_entrada.erase(it2);
    			continue;
    		}
    		it++;
    	}
    }
};


int main(){
	
	Banco *aux = new Banco();

	string cmd, linha;

	while(true){
		getline(cin, linha);
		stringstream cut(linha);
		cut >> cmd;
		if(cmd == "init"){
			int size;
			cut >> size;
			aux->init(size);
		}
		else if(cmd == "in"){
			string id;
			int docs;
            int pac;
			cut >> id;
			cut >> docs;
			cut >> pac;
			aux->in(id, docs, pac);	
		}
		else if(cmd == "show"){
			aux->show();
		}
		else if(cmd == "tic"){
			aux->tic();
		}
		else if(cmd == "end"){
			break;
		}
		else if(cmd == "total"){
			cout << "Documentos recebidos até o momento: " << aux->docs_adq << endl;
			cout << "Documentos perdidos até o momento: " << aux->docs_perdidos << endl;
		}
	}

    //banco fechou
    
	while(true){
		bool ainda_tem = false;
		if(aux->fila_entrada.size() > 0){
			aux->tic();
			continue;
		}
		else{
			for(int i = 0; i < (int) aux->caixas.size(); i++){
				if(aux->caixas[i] != nullptr){
					ainda_tem = true;
				}
			}
		}
		if(ainda_tem){
			aux->tic();
		}
		else{
			break;
		}
	}

	if((int) aux->fila_saida.size() > 0){
		aux->fila_saida.erase(aux->fila_saida.begin(), aux->fila_saida.end());
	}

	cout << "Documentos recebidos: " << aux->docs_adq << endl;
	cout << "Documentos perdidos: " << aux->docs_perdidos;


	return 0;
}
