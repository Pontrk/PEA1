#include "brute_force.h"

Brute_Force::Brute_Force(){

};

void Brute_Force::getFromMatrix(Adjacency_Matrix& adjacencyMatrix){
    data = adjacencyMatrix.getMatrix();
}

vector<int> Brute_Force::findBestPath(int startNode) {
    vector<int> nodes(data.size());
    nodes[0]=startNode;
    int j=0;
    for (int i = 1; i < data.size(); i++) {
        if(j!=startNode)
            nodes[i] = j;
        else {
            j++;
            nodes[i]=j;
        }
        j++;
    }
    vector<int> best_path;
    int best_cost = INT_MAX;
    do {
        int current_cost = calculatePathCost(nodes); // Oblicz koszt bieżącej ścieżki
        if (current_cost < best_cost) {
            best_path = nodes; // Aktualizuj najlepszą ścieżkę
            best_cost = current_cost;
        }
    } while (next_permutation(nodes.begin() +1, nodes.end())); // Generuj permutacje węzłów
    cout<<"Najszybsza sciezka to: ";
    for (int i = 0; i < best_path.size(); i++)
            cout << best_path[i] << "->";
    cout<<best_path[0]<<endl;
    cout<<"jej koszt to: "<<best_cost<<endl;
    best_cost=0;
    return best_path;
}
vector<int> Brute_Force::findBestPathAll() {
    time_t futur = time(NULL) + 120;
    vector<int> best_path;
    int best_cost = INT_MAX;
    vector<int> nodes(data.size());
    for (int i = 0; i < data.size(); i++)
        nodes[i] = i; // Inicjalizacja węzłów od 0 do n-1
    do {
        int current_cost = calculatePathCost(nodes); // Oblicz koszt bieżącej ścieżki
        if (current_cost < best_cost) {
            best_path = nodes; // Aktualizuj najlepszą ścieżkę
            best_cost = current_cost;
        }
        if(time(NULL)>futur){
            cout<<"przekroczono limit czasu"<<endl;
            return best_path;
        }
    } while (next_permutation(nodes.begin(), nodes.end())); // Generuj permutacje węzłów
    cout<<"Najszybsza sciezka to: ";
    for (int i = 0; i < best_path.size(); i++)
        cout << best_path[i] << "->";
    cout<<best_path[0];
    cout<<"jej koszt to: "<<best_cost<<endl;
    return best_path;
}
int Brute_Force::calculatePathCost(const vector<int>& path) {
    int cost = 0;
    for (int i = 0; i < data.size() - 1; ++i) {
        cost += data[path[i]][path[i + 1]];
    }
    cost += data[path[data.size() - 1]][path[0]]; // Wracamy do pierwszego węzła
    return cost;
}