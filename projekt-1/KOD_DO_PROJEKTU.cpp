
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;
int main()
{

    int suma = 1500;
    int dlugosc_tablicy = 0;
    int maxDlugosc = 0;
    int maxStart =0;
    int maxStop = 0;
    bool pierwszyZnaleziony = false;
    cout<<"podaj dlugosc tablicy"<<endl;
    cin>> dlugosc_tablicy;
    auto start = std::chrono::high_resolution_clock::now();
    int tablica[dlugosc_tablicy];
    srand(time(0));
    for(int i = 0; i < dlugosc_tablicy; i++) {

        tablica[i] = rand();
        cout<<tablica[i]<<" ";

    }
    for(int i =0; i  < dlugosc_tablicy; i++)
    {
    if(i==0) cout<<"Podciagi o sumie "<< suma<<" to: ";
    int sumaPomocnicza = 0;
     for(int j = i; j < dlugosc_tablicy; j++ )   
     {   sumaPomocnicza += tablica[j];
        if(sumaPomocnicza == suma)
        {
            if(!pierwszyZnaleziony)
            {
                pierwszyZnaleziony = true;
                cout<<"[";
            }
            else
            {
                cout<<", [";
            }
            for(int x = i; x <= j; x++)
            {
                if(x==j)cout<<tablica[x];
                else cout<<tablica[x]<<",";
            }
            
            cout<<"]";
            int dlugoscPodciagu = j + 1 - i;
            if( dlugoscPodciagu > maxDlugosc )
            {
                maxStart = i;
                maxStop = j;
                maxDlugosc = dlugoscPodciagu;
            }
        }
     }
    }
    if(maxDlugosc!=0) {
        cout<<"."<<endl<<"Najdluzszy podciag to: "<<"[";
        for(int x = maxStart; x <= maxStop; x++)
        {

            if(x==maxStop)cout<<tablica[x];
            else cout<<tablica[x]<<",";

        }
        cout<<"]";
        cout<<" o dlugosci "<<maxDlugosc<<".";
    }
    else cout<<"brak podciagow.";
    cout<<endl;
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed = end - start;
    cout<<elapsed.count();

    return 0;
}