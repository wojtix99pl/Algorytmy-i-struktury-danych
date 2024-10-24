/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    int suma = 8;
    int tablica[] = {0,6,5,1,-5,5,3,5,3,-2,0};
    int dlugosc_tablicy = 11;
    int maxDlugosc = 0;
    int maxStart =0;
    int maxStop = 0;
    bool pierwszyZnaleziony = false;
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
    cout<<"."<<endl<<"Najdluzszy podciag to: "<<"[";
    for(int x = maxStart; x <= maxStop; x++)
    {
        
                if(x==maxStop)cout<<tablica[x];
                else cout<<tablica[x]<<",";
            
    }
    cout<<"]";
    cout<<" o dlugosci "<<maxDlugosc<<".";
    return 0;
}