#include <bits/stdc++.h>
using namespace std;

const int Arad = 0;
const int Sibiu = 1;
const int Zerind = 2;
const int Timisoara = 3;
const int Lugoj = 4;
const int Mehadia = 5;
const int Drobeta = 6;
const int Craiova = 7;
const int RV = 8;
const int Pitest = 9;
const int Oradea = 10;
const int Fagaras = 11;
const int Bucharest = 12;
const int Giurgiu = 13;
const int Urziceni = 14;
const int Hirsova = 15; 
const int Eforie = 16;
const int Vaslui = 17;
const int Iasi = 18;
const int Neamt = 19;

class Grafo{
    int V; //número de vértices/nós no grafo
    list<int> *adj; //adjacencias

public:
    Grafo(int V){
        this->V = V;
        this->adj = new list<int>[V];
    }

    void setEdge(int v1, int v2){
        adj[v1].push_back(v2);
    }

    bool check(int v1, int v2){
        if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
		    return true;
	    return false;
    }
    
    list<int> getNeig(int v){
        return this->adj[v];
    }

    int get_v(){
        return this->V;
    }
};

void addPopulation(Grafo *G){
    //0 neighbors of Arad
    G->setEdge(Arad, Sibiu);
    G->setEdge(Arad, Zerind);
    G->setEdge(Arad, Timisoara);
    //1 neighbors of Sibiu
    G->setEdge(Sibiu, Fagaras);
    G->setEdge(Sibiu, RV);
    G->setEdge(Sibiu, Oradea);
    G->setEdge(Sibiu, Arad);
    //3 neighbors of Timisoara
    G->setEdge(Timisoara, Arad);
    G->setEdge(Timisoara, Lugoj);
    //2 neighbors of Zerind
    G->setEdge(Zerind, Arad);
    G->setEdge(Zerind, Oradea);
    //10 neighbors of Oradea 
    G->setEdge(Oradea, Zerind);
    G->setEdge(Oradea, Sibiu);
    //4 neighbors of Lugoj
    G->setEdge(Lugoj, Timisoara);
    G->setEdge(Lugoj, Mehadia);
    //5 neighbors of Mehadia
    G->setEdge(Mehadia, Lugoj);
    G->setEdge(Mehadia, Drobeta);
    //6 neighbors of Drobeta
    G->setEdge(Drobeta, Mehadia);
    G->setEdge(Drobeta, Craiova);
    //7 neighbors of Craiova
    G->setEdge(Craiova, Drobeta);
    G->setEdge(Craiova, RV);
    G->setEdge(Craiova, Pitest);
    //8 neighbors of RV
    G->setEdge(RV, Craiova);
    G->setEdge(RV, Pitest);
    G->setEdge(RV, Sibiu);
    //11 neighbors of Fagaras
    G->setEdge(Fagaras, Sibiu);
    G->setEdge(Fagaras, Bucharest);
    //9 neighbors of Pitest
    G->setEdge(Pitest, Craiova);
    G->setEdge(Pitest, RV);
    G->setEdge(Pitest, Bucharest);
    //12 neighbors of Bucharest
    G->setEdge(Bucharest, Pitest);
    G->setEdge(Bucharest, Fagaras);
    G->setEdge(Bucharest, Giurgiu);
    G->setEdge(Bucharest, Urziceni);
    //14 neighbors of Urziceni
    G->setEdge(Urziceni, Bucharest);
    G->setEdge(Urziceni, Hirsova);
    G->setEdge(Urziceni, Vaslui);
    //15 neighbors of Hirsova
    G->setEdge(Hirsova, Urziceni);
    G->setEdge(Hirsova, Eforie);
    //16 neighbors of Eforie
    G->setEdge(Eforie, Hirsova);
    //17 neighbors of Vaslui
    G->setEdge(Vaslui, Urziceni);
    G->setEdge(Vaslui, Iasi);
    //18 neighbors of Iasi
    G->setEdge(Iasi, Vaslui);
    G->setEdge(Iasi, Neamt);
    //19 neighbors of Neamt
    G->setEdge(Neamt, Iasi);

}

string dfs(Grafo *G, int root, int destiny){
    stringstream ss;
    int no;
    stack<int> cities;
    bool citiesB[G->get_v()]; // if at the stack, then true, else false
    bool visited[G->get_v()];
    bool ctrl = false; // control variable.

    //set false
    for(int i = 0;i<G->get_v();i++){
        citiesB[i] = false;
        visited[i] = false;
    }
    //Add root at stack
    cities.push(root);
    //add true at the auxiliar stack
    citiesB[root] = true;

    while(!ctrl){
        //
        if(cities.empty()){
            ss << "Fail. Element not found."<< endl;
            return ss.str();
        }    

        no = cities.top();
        cities.pop();
        citiesB[no] = false;
        visited[no] = true;
        
        for(auto it : G->getNeig(no)){
            if(!visited[it] and !citiesB[it]){
                if(it == destiny){
                    ctrl = true;
                    break;
                }
                cities.push(it);
                citiesB[it] = true;
            }
        } // end for       
    } 
    
    ss <<"\nElement " << destiny <<" found." << endl;
    ss << "visited: ";
    for(int i = 0; i < G->get_v(); i++){ 
        if(visited[i]) 
            ss << i << " ";
    }
    ss << endl;

    ss <<  "At stack: ";
    for(int j = 0; j < G->get_v(); j++){ 
        if(citiesB[j]) 
            ss << j << " ";
    }
    ss << endl;
    return ss.str();
}



int main(){
    Grafo romenia_map(20);
    addPopulation(&romenia_map);

    cout << dfs(&romenia_map, Hirsova, Bucharest) << endl;
        
}