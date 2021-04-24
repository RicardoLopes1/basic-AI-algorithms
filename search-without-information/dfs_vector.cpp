#include <bits/stdc++.h>
using namespace std;


#define pb push_back

typedef vector<int> vi;
typedef set<int> seti;
typedef stack<vi> stackvi;

// 
seti visited;
seti edgeCheck;
stackvi edge;
vi ghost;
vi neighbors[21];

void listAdj();
bool dfs(int root, int destiny);

int root = 1, destiny = 12;
int main(){
    listAdj();
    
    if(dfs(root, destiny)) cout << "\nFound: " << destiny << endl;
    else cout << "\nNot found.\n";

    cout << "Visited: ";
    for(auto v : visited){
        cout << v << " ";
    }
    cout << endl;
    cout << "Stack: ";
    for(auto s : edgeCheck){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

void listAdj(){
    // Arad 1
    neighbors[1].pb(1); // 1 Arad
    neighbors[1].pb(2); // 2 Zerind
    neighbors[1].pb(3); // 3 Timisuara
    neighbors[1].pb(4); // 4 Sibiu
    // Zerind 2         // 5 Oradea
    neighbors[2].pb(2); // 6 Lugogi
    neighbors[2].pb(1); // 7 R. Vilcea
    neighbors[2].pb(5); // 8 Fagaras
    // Timisuara 3      // 9 Mehadia
    neighbors[3].pb(3); // 10 Craiova
    neighbors[3].pb(1); // 11 Pitest
    neighbors[3].pb(6); // 12 Bucharest
    // Sibiu 4          // 13 Drobeta
    neighbors[4].pb(4); // 14 Giurgiu
    neighbors[4].pb(1); // 15 Urziceani
    neighbors[4].pb(5); // 16 Vaslui
    neighbors[4].pb(7); // 17 Iasi
    neighbors[4].pb(8); // 18 Neami
    // Oradea 5         // 19 Hirsova
    neighbors[5].pb(5); // 20 Eforie
    neighbors[5].pb(2);
    neighbors[5].pb(4);
    // Lugogi 6
    neighbors[6].pb(6);
    neighbors[6].pb(3);
    neighbors[6].pb(9); // Mehadia
    // R. Vilcea 7
    neighbors[7].pb(7);
    neighbors[7].pb(4);
    neighbors[7].pb(10); // Craiova 10
    neighbors[7].pb(11); // Pitest 11
    // Fagaras 8
    neighbors[8].pb(8);
    neighbors[8].pb(4);
    neighbors[8].pb(12); // Bucharest 12
    // Mehadia 9
    neighbors[9].pb(9);
    neighbors[9].pb(6);
    neighbors[9].pb(13); // Drobeta 13
    // Craiova 10
    neighbors[10].pb(10);
    neighbors[10].pb(7); // R. Vilcea
    neighbors[10].pb(13); // Drobeta
    neighbors[10].pb(11); // Pitest
    // Pitest 11
    neighbors[11].pb(11);
    neighbors[11].pb(7);
    neighbors[11].pb(12);
    // Bucharest 12
    neighbors[12].pb(12);
    neighbors[12].pb(11);
    neighbors[12].pb(8);
    neighbors[12].pb(14); // Giurgiu
    neighbors[12].pb(15); // Urziceani
    // Drobeta 13
    neighbors[13].pb(13);
    neighbors[13].pb(9);
    neighbors[13].pb(10);
    // Giurgiu 14
    neighbors[14].pb(14);
    neighbors[14].pb(12);
    // Urziceani 15
    neighbors[15].pb(15);
    neighbors[15].pb(12);
    neighbors[15].pb(16);
    neighbors[15].pb(19);
    // Vaslui 16
    neighbors[16].pb(16);
    neighbors[16].pb(15);
    neighbors[16].pb(17);
    // Iasi 17
    neighbors[17].pb(17);
    neighbors[17].pb(16);
    neighbors[17].pb(18);
    // Neami 18
    neighbors[18].pb(18);
    neighbors[18].pb(17);
    // Hirsova 19
    neighbors[19].pb(19);
    neighbors[19].pb(15);
    neighbors[19].pb(20);
    // Eforie 20
    neighbors[20].pb(20);
    neighbors[20].pb(19);
}

bool dfs(int root, int destiny){
    edge.push(neighbors[root]); // vi neigh | get top
    edgeCheck.insert(root);
    bool exit = false;
    
    while(!edge.empty() and !exit){
        ghost = edge.top(); // vi ghost
        edge.pop();
        edgeCheck.erase(edgeCheck.find(ghost.front()));
        visited.insert(ghost.front());
        
        // vi ghost
        for(auto i : ghost){
            if(!visited.count(i) and !edgeCheck.count(i)){
                if(i == destiny){
                    exit = true;
                    return exit;
                }
                edge.push(neighbors[i]); // add vi[i] in stack
                edgeCheck.insert(i);
            }
        }
        // repeat
    }
    return exit;

}