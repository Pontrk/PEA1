#include "adjacency_matrix.h"

#include <iostream>

using namespace std;

Adjacency_Matrix::Adjacency_Matrix() {
}

void Adjacency_Matrix::printMatrix() //wyświetlenie macierzy
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void Adjacency_Matrix::loadFromFile(const string& filename){
    matrix.clear();
    ifstream plik(filename);
    int wagi, liczbaWierzcholkow;
    if (plik.is_open()) {
        // Plik został otwarty pomyślnie,
        plik >> liczbaWierzcholkow;
        vector<int> wiersz;
        for (int j = 0; j < liczbaWierzcholkow; j++){
            for (int i = 0; i < liczbaWierzcholkow; i++){//tworzenie wektora wierszy
                plik >> wagi;
                wiersz.push_back(wagi);
            }
            matrix.push_back(wiersz);//umieszczenie wektora wierszy w macierzy
            wiersz.clear(); //czyszczenie wektora wierszy przed nastepnym wierszem
        }
    } else {
        cout << "Nie udało się otworzyć pliku.";
    }
}
void Adjacency_Matrix::generate(int numberOfNodes){
    matrix.clear();
    srand(time(NULL));
    vector<int> wiersz;
    for (int j = 0; j < numberOfNodes; j++){//kod dziala w bardzo podobny sposob co kod wczytujacy z pliku + uwzglednienie przekatnej macierzy
        for (int i = 0; i < numberOfNodes; i++) {
            if(i==j)
                wiersz.push_back(-1);
            else wiersz.push_back((rand() % 101) + 1);
        }
        matrix.push_back(wiersz);
        wiersz.clear();
    }

}
vector<vector<int>> Adjacency_Matrix::getMatrix() {
    return matrix;
}