#include <iostream>
#include <string>
#include <chrono>
#include "adjacency_matrix.h"
#include "brute_force.h"

using namespace std;

int main() {
    Adjacency_Matrix graf;
    Brute_Force bruteForce;
    string dane = "dane.txt";
    int wierzcholki,wierzcholekStartowy;
    int opcja;
    do {
        cout << "Wybierz opcje:" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj Graf losowo" << endl;
        cout << "3. Wyswietl ostatni graf" << endl;
        cout << "4. Brute Force wszystkie permutacje" << endl;
        cout << "5. Brute Force z wyborem wierzcholka poczatkowego" << endl;
        cout << "0. Zakoncz program" << endl;
        cin >> opcja;
        switch (opcja) {
            case 1: {
                graf.loadFromFile(dane);
                break;
            }
            case 2: {
                cout<<"Podaj liczbe wierzcholkow"<<endl;
                cin>>wierzcholki;
                graf.generate(wierzcholki);
                break;
            }
            case 3: {
                graf.printMatrix();
                break;
            }
            case 4: {
                bruteForce.getFromMatrix(graf);
                auto start = std::chrono::high_resolution_clock::now();
                bruteForce.findBestPathAll();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                cout<<"Czas wykonania algorytmu: " << duration.count()<<" Milisekund"<<endl;
                break;
            }
            case 5: {
                cout<<"podaj wierzcholek startowy" << endl;
                cin>>wierzcholekStartowy;
                bruteForce.getFromMatrix(graf);
                auto start = std::chrono::high_resolution_clock::now();
                bruteForce.findBestPath(wierzcholekStartowy);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
                cout<<"Czas wykonania algorytmu: " << duration.count()<<" Milisekund"<<endl;
                break;
            }
        }
    } while (opcja != 0);
}




