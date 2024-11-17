#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;
ifstream fileReader("tablica.txt");         //// PROSZE PODAC SCIEZKE DO PLIKU Z LICZBAMI
ofstream wynikFile("wynikZadania.txt");     //// PLIK TEKSTOWY Z WYNIKIEM ZADANIA


int algorytm(int tablica[], int suma, int dlugosc_tablicy) {
    int maxDlugosc = 0;
    int maxStart = 0;
    int maxStop = 0;
    bool pierwszyZnaleziony = false;
    auto start = std::chrono::high_resolution_clock::now(); /// kod mierzący czas programu

    for (int i = 0; i < dlugosc_tablicy; i++) {
        if (i == 0) {
            cout << "Podciagi o sumie " << suma << " to: ";
            wynikFile << "Podciagi o sumie " << suma << " to: ";
        }
        int sumaPomocnicza = 0;
        for (int j = i; j < dlugosc_tablicy; j++) {
            sumaPomocnicza += tablica[j];
            if (sumaPomocnicza == suma) {
                if (!pierwszyZnaleziony) {
                    pierwszyZnaleziony = true;
                    cout << "[";
                    wynikFile << "[";
                } else {
                    cout << ", [";
                    wynikFile << ", [";
                }
                for (int x = i; x <= j; x++) {
                    if (x == j) {
                        cout << tablica[x];
                        wynikFile << tablica[x];
                    }
                    else {
                        wynikFile << tablica[x] <<",";
                        cout << tablica[x] << ",";
                    }
                }
                wynikFile <<"]";
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
        wynikFile << "." << endl << "Najdluzszy podciag to: " << "[";
        for (int x = maxStart; x <= maxStop; x++) {
            if (x == maxStop) {
                cout << tablica[x];
                wynikFile << tablica[x];
            }
            else {
                cout << tablica[x] << ",";
                wynikFile << tablica[x] << ",";
            }
        }
        cout << "]";
        wynikFile <<"]";
        cout << " o dlugosci " << maxDlugosc << ".";
        wynikFile<<" o dlugosci "<<maxDlugosc<< ".";
    } else {
        cout << "brak podciagow.";
        wynikFile<<"brak podciagow.";
    }
    cout << endl;
    auto end = std::chrono::high_resolution_clock::now(); /// kod mierzący czas programu
    chrono::duration<double, milli> elapsed = end - start; /// kod mierzący czas programu
    cout << elapsed.count() << "ms" << endl; // czas programu w milisekundach
    return maxDlugosc;
}

int *generateArray(int dlugosc_tablicy) {                ///// FUNKCJA DO GENEROWANIA LOSOWYCH TABLIC
    int *tablica = new int[dlugosc_tablicy];
    srand(time(0));
    for (int i = 0; i < dlugosc_tablicy; i++) {
        tablica[i] = rand() % 11 - 5;
    }
    return tablica;
}

void test1() {
    int tablica[] = {0,6,5,1,-5,5,3,5,3,-2,0};
    int wynik = algorytm(tablica,8,11);
    if (wynik == 4) cout << "program dziala poprawnie"<<endl;
    else cout << "program nie dziala poprawnie"<<endl;
}
void test2() {
    int *tablica = new int[10];
    for (int i = 0; i < 10; i++) {
        tablica[i] = 0;
    }
    int wynik = algorytm(tablica,0,10);
    delete tablica;
    if (wynik == 10) cout << "program dziala poprawnie"<<endl;
    else cout << "program nie dziala poprawnie"<<endl;
}
int localSetData() {
    int dlugosc_tablicy = 0;
    cout << "podaj dlugosc tablicy" << endl;
    cin >> dlugosc_tablicy;

    return dlugosc_tablicy;
}
int localSetData2() {
    cout << "podaj sume" << endl;
    int suma = 0;
    cin >> suma;
    return suma;
}
int *fileArrayReader() {
    int i =0, number =0, y =0;
    while(fileReader >> number) {
        i++;
    }
    int* tablica = new int[i];
    fileReader.clear();
    fileReader.seekg(0);
    while (fileReader >> number) {
        tablica[y] = number;
        cout<<tablica[y]<<endl;
        y++;
    }
    fileReader.clear();
    fileReader.seekg(0);
    return tablica;
}
int fileLengthSeeker() {
    int number =0;
    int i = 0;
    while(fileReader >> number) i++;
    fileReader.clear();
    fileReader.seekg(0);
    return i;
}
int main() {
   // int *tablica = fileArrayReader();                       /////////GENEROWANIE TABLICY Z PLIKU
   // int dlugosc_tablicy = fileLengthSeeker();               /////////GENEROWANIE TABLICY Z PLIKU
   // int suma = localSetData2();                             /////////GENEROWANIE TABLICY Z PLIKU
    // algorytm(tablica, suma, dlugosc_tablicy);              /////////GENEROWANIE TABLICY Z PLIKU
    // delete tablica;                                        /////////GENEROWANIE TABLICY Z PLIKU


     int suma = localSetData2();                          /////////GENEROWANIE PSEUDOLOSOWEJ TABLICY W PROGRAMIE
     int dlugosc_tablicy = localSetData();                /////////GENEROWANIE PSEUDOLOSOWEJ TABLICY W PROGRAMIE
     int *tablica = generateArray(dlugosc_tablicy);       /////////GENEROWANIE PSEUDOLOSOWEJ TABLICY W PROGRAMIE
     algorytm(tablica, suma, dlugosc_tablicy);           /////////GENEROWANIE PSEUDOLOSOWEJ TABLICY W PROGRAMIE
     delete tablica;                                     /////////GENEROWANIE PSEUDOLOSOWEJ TABLICY W PROGRAMIE

   // test1();       /// TESTY
   //   test2();         /// TESTY

    fileReader.close();
    wynikFile.close();
    return 0;
}