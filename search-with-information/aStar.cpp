#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

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
    string name;
    int id;
    int sld; // straight-line distance to Bucharest
    vii neig; // neighbors
    bool visited;

public:
    Grafo(){
    }
    // "constructor"
    void setup(string pName, int pId, int pSld){
        this->name = pName;
        this->id = pId;
        this->sld = pSld;
        this->visited = false;
    }
    
    // gets and sets
    string getName(){
        return this->name;
    }
    int getId(){
        return this->id;
    }
    int getSld(){
        return this->sld;
    }
    vii getNeig(){
        return this->neig;
    }
    bool getVisited(){
        return this->visited;
    }
    void setVisited(){
        this->visited = true;
    }
    void setEdge(int v, int d){
        neig.pb(mp(v, d));
    }
};

Grafo romenia_map[20];
// future correction: create separate heuristic function
void setupCity(){
    romenia_map[0].setup("Arad", Arad, 366);
    romenia_map[1].setup("Sibiu", Sibiu, 253);
    romenia_map[2].setup("Zerind", Zerind, 374);
    romenia_map[3].setup("Timisoara", Timisoara, 329); 
    romenia_map[4].setup("Lugoj", Lugoj, 244);
    romenia_map[5].setup("Mehadia", Mehadia, 241); 
    romenia_map[6].setup("Drobeta", Drobeta, 242);
    romenia_map[7].setup("Craiova", Craiova, 160);
    romenia_map[8].setup("RV", RV, 193); 
    romenia_map[9].setup("Pitest", Pitest, 100);
    romenia_map[10].setup("Oradea", Oradea, 380);
    romenia_map[11].setup("Fagaras", Fagaras, 176);
    romenia_map[12].setup("Bucharest", Bucharest, 0);
    romenia_map[13].setup("Giurgiu", Giurgiu, 77);
    romenia_map[14].setup("Urziceni", Urziceni, 80);
    romenia_map[15].setup("Hirsova", Hirsova, 151);
    romenia_map[16].setup("Eforie", Eforie, 161);
    romenia_map[17].setup("Vaslui", Vaslui, 199);
    romenia_map[18].setup("Iasi", Iasi, 226);
    romenia_map[19].setup("Neamt", Neamt, 234); 
}
void addPopulation(){
    //0 Arad
    romenia_map[0].setEdge(Sibiu, 140);
    romenia_map[0].setEdge(Zerind, 75);
    romenia_map[0].setEdge(Timisoara, 118);
    //1 Sibiu
    romenia_map[1].setEdge(Fagaras, 99);
    romenia_map[1].setEdge(RV, 80);
    romenia_map[1].setEdge(Oradea, 151);
    romenia_map[1].setEdge(Arad, 140);
    //2 Zerind
    romenia_map[2].setEdge(Arad, 75);
    romenia_map[2].setEdge(Oradea, 71);
    //3 Timisoara
    romenia_map[3].setEdge(Arad, 118);
    romenia_map[3].setEdge(Lugoj, 111);
    //4 Lugoj = 4;
    romenia_map[4].setEdge(Timisoara, 111);
    romenia_map[4].setEdge(Mehadia, 70);
    //Mehadia = 5;
    romenia_map[5].setEdge(Lugoj, 70);
    romenia_map[5].setEdge(Drobeta, 75);
    //Drobeta = 6;
    romenia_map[6].setEdge(Mehadia, 75);
    romenia_map[6].setEdge(Craiova, 120);
    //Craiova = 7;
    romenia_map[7].setEdge(Drobeta, 120);
    romenia_map[7].setEdge(RV, 146);
    romenia_map[7].setEdge(Pitest, 138);
    //RV = 8;
    romenia_map[8].setEdge(Sibiu, 80);
    romenia_map[8].setEdge(Craiova, 146);
    romenia_map[8].setEdge(Pitest, 97);
    //Pitest = 9;
    romenia_map[9].setEdge(Craiova, 138);
    romenia_map[9].setEdge(RV, 97);
    romenia_map[9].setEdge(Bucharest, 101);
    //Oradea = 10;
    romenia_map[10].setEdge(Zerind, 71);
    romenia_map[10].setEdge(Sibiu, 151);
    //Fagaras = 11;
    romenia_map[11].setEdge(Sibiu, 99);
    romenia_map[11].setEdge(Bucharest, 211);
    //Bucharest = 12;
    romenia_map[12].setEdge(Pitest, 101);
    romenia_map[12].setEdge(Fagaras, 211);
    romenia_map[12].setEdge(Giurgiu, 90);
    romenia_map[12].setEdge(Urziceni, 85);
    //Giurgiu = 13;
    romenia_map[13].setEdge(Bucharest, 90);
    //Urziceni = 14;
    romenia_map[14].setEdge(Bucharest, 85);
    romenia_map[14].setEdge(Hirsova, 98);
    romenia_map[14].setEdge(Vaslui, 142);
    //Hirsova = 15;
    romenia_map[15].setEdge(Urziceni, 98);
    romenia_map[15].setEdge(Eforie, 86); 
    //Eforie = 16;
    romenia_map[16].setEdge(Hirsova, 86);
    //Vaslui = 17;
    romenia_map[17].setEdge(Urziceni, 142);
    romenia_map[17].setEdge(Iasi, 92);
    //Iasi = 18;
    romenia_map[18].setEdge(Vaslui, 92);
    romenia_map[18].setEdge(Neamt, 87);
    //Neamt = 19;
    romenia_map[19].setEdge(Iasi, 87);
}

string aStar(int root, int destiny){
    stringstream ss;
    Grafo aux;
    int small, real = 0, realA;
    vi ids;
    bool ctrl = false; // control variable
    ids.pb(root);
    
    while(!ctrl){
        aux = romenia_map[root];
        small = 10000; // shortest path control
        // 'it' is a pair<int, int>
        for(auto it : aux.getNeig()){ 
            if(!romenia_map[it.F].getVisited()){
                if(min(small, romenia_map[it.F].getSld() + it.S) < small){
                    small = romenia_map[it.F].getSld() + it.S;
                    root = it.F;
                    realA = it.S;
                }
            }
        }// end for-each

        ids.pb(root);
        real += realA;  
        romenia_map[aux.getId()].setVisited();
        if(romenia_map[root].getId() == destiny) ctrl = true;
    } 
    
    ss <<"\nFound city." << endl;
    ss << "Path: ";
    for(auto e : ids){ 
        ss << romenia_map[e].getName() << " ";
    }
    ss << endl;
    auto tt = ids.back();
    ss << "Straight-line distance of " << romenia_map[ids.at(0)].getName() << 
    " to "<< romenia_map[tt].getName() << " is: " << romenia_map[ids.at(0)].getSld() << endl;
    ss << "Real distance: " << real << endl;
    return ss.str();
}

int main(){
    setupCity();
    addPopulation();
    
    cout << aStar(Neamt, Bucharest) << endl;
}
