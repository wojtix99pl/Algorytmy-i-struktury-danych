#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;

void algorytm(int dlugosc_tablicy, int suma) {
    int maxDlugosc = 0;
    int maxStart = 0;
    int maxStop = 0;
    bool pierwszyZnaleziony = false;
    auto start = std::chrono::high_resolution_clock::now(); /// kod mierzący czas programu
    int tablica[dlugosc_tablicy];
    srand(time(0));
    for (int i = 0; i < dlugosc_tablicy; i++) {        /// Generowanie tablicy losowych liczb
        tablica[i] = rand() %11 -5;
    }
    for (int i = 0; i < dlugosc_tablicy; i++) {
        if (i == 0) cout << "Podciagi o sumie " << suma << " to: ";
        int sumaPomocnicza = 0;
        for (int j = i; j < dlugosc_tablicy; j++) {
            sumaPomocnicza += tablica[j];
            if (sumaPomocnicza == suma) {
                if (!pierwszyZnaleziony) {
                    pierwszyZnaleziony = true;
                    cout << "[";
                } else {
                    cout << ", [";
                }
                for (int x = i; x <= j; x++) {
                    if (x == j)cout << tablica[x];
                    else cout << tablica[x] << ",";
                }

                cout << "]";
                int dlugoscPodciagu = j + 1 - i;
                if (dlugoscPodciagu > maxDlugosc) {
                    maxStart = i;
                    maxStop = j;
                    maxDlugosc = dlugoscPodciagu;
                }
            }
        }
    }
    if (maxDlugosc != 0) {
        cout << "." << endl << "Najdluzszy podciag to: " << "[";
        for (int x = maxStart; x <= maxStop; x++) {
            if (x == maxStop)cout << tablica[x];
            else cout << tablica[x] << ",";
        }
        cout << "]";
        cout << " o dlugosci " << maxDlugosc << ".";
    } else cout << "brak podciagow.";
    cout << endl;
    auto end = std::chrono::high_resolution_clock::now(); /// kod mierzący czas programu
    chrono::duration<double, milli> elapsed = end - start; /// kod mierzący czas programu
    cout << elapsed.count() << "ms"; // czas programu w milisekundach
}

int main() {
    cout<<"podaj sume"<<endl;
    int suma = 0;
    cin>>suma;
    int dlugosc_tablicy = 0;
    cout << "podaj dlugosc tablicy" << endl;
    cin >> dlugosc_tablicy;
    algorytm(dlugosc_tablicy, suma);


    return 0;
}
