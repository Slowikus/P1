#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

#include "Quicksort.h"
#include "Mergesort.h"
#include "Introsort.h"

//*********************************************************************//
//*********************************************************************//
//Driver jest w kodzie źródłowym, należy poprostu uruchomić program.
//Pętla służące do wykoanania eksperymentów została wykomentowana
//wilkość tablicy wynosi 20 a zakres liczb losowanych zmniejszony do 10.
//********************************************************************//
//*********************************************************************//

int main() {

    //***************************************
    //wielkość tablicy
    int n= 20;
    //promil posortowania (podaj w promilach)
    int p = 0;
    //zakres liczb losowanych
    int a = 10;
    //***************************************

        //pętla do przeproawdzania testów dla różnych procentów posortownych wart pocz
    // int procent[]= {0, 250, 500, 750, 950, 990, 997, 1000};
    // for (int k =0; k < 8; k++) {

        //wypełnienie 100 tablic liczbami i posortowanie odpowiedniego
        //procentu pocztątkowych liczb przy uzyciu quicksort

        //za każdym razem inne liczby losowe o
        srand (time(NULL));
        //std::cout << p << std::endl;
        int **tab = new int *[100];

        for (int i = 0; i < 100; i++) {
            tab[i] = new int[n];
        }


        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                //liczby z zakresu 0-a
                tab[i][j] = rand() % (a + 1);
            }
            Quicksort(tab[i], 0, ((n * p / 1000) - 1));
        }



        //posortowane ale w odwrotnej kolejności - wykona sie tylko
        //gdy tablica jest posortowana w 100%
        if (p == 1000) {
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < n; j++) {
                    tab[i][j] = a - tab[i][j];
                }
            }
        }
////////////////////////////////////////DRIVER//////////////////////////////////////////////////////////////////////
        std::cout<< "Jedna ze 100 tablic wygenerowanych na potrzeby eksperymentow" << std::endl;
        std::cout<< "Zawiera ona 20 losowych elementow z zakresu od 0 do 10:    " << std::endl;
         for (int j = 0; j < n; j++) {
        std::cout << tab[5][j] << " ";
        }
         std::cout << "" << std::endl;
////////////////////////////////////////DRIVER///////////////////////////////////////////////////////////////////////

        //**********************************************************************************//
        //Quciksort
        int **tabQ;

        tabQ = new int *[100];

        for (int i = 0; i < 100; ++i) {
            tabQ[i] = new int[n];
        }

        //wpisanie liczb do tablicy na ktorj bede testował algorytm quicksort
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                tabQ[i][j] = tab[i][j];
            }
        }

        // pomiar czasu wykonania algorytmu na 100 tablicach i obliczenie czasu jego wykonania
        clock_t start_Q = clock();
        for (int i = 0; i < 100; ++i) {
            Quicksort(tabQ[i], 0, n - 1);
        }
        clock_t stop_Q = clock();

        double timeQ = (double) (stop_Q - start_Q) / CLOCKS_PER_SEC;
//        std::cout << "Czas wyknania algorytmu Quicksort: " << timeQ << std::endl;

////////////////////////////////////////DRIVER//////////////////////////////////////////////////////////////////////
    std::cout<< "Elemety tablicy posortowanej przez algorytm Quicksort: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << tabQ[5][j] << " ";
    }
    std::cout << "" << std::endl;
////////////////////////////////////////DRIVER///////////////////////////////////////////////////////////////////////


        //zwalnianie pamieci

        for (int i = 0; i < 100; ++i) {
            delete[] tabQ[i];
        }
        delete[] tabQ;


        //**********************************************************************************//
        //Mergesort

        int **tabM;
        int **q;

        q = new int *[100];

        tabM = new int *[100];

        for (int i = 0; i < 100; ++i) {
            q[i] = new int[n];
            tabM[i] = new int[n];
        }

        //wpisanie liczb do tablicy na ktorj bede testował algorytm mergesort
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                q[i][j] = 0;
                tabM[i][j] = tab[i][j];
            }
        }

        // pomiar czasu wykonania algorytmu na 100 tablicach i obliczenie czasu jego wykonania
        clock_t start_M = clock();
        for (int i = 0; i < 100; ++i) {
            Mergesort(tabM[i], q[i], 0, n - 1);
        }
        clock_t stop_M = clock();

        double timeM = (double) (stop_M - start_M) / CLOCKS_PER_SEC;
//        std::cout << "Czas wyknania algorytmu Mergesort: " << timeM << std::endl;

////////////////////////////////////////DRIVER//////////////////////////////////////////////////////////////////////
    std::cout<< "Elemety tablicy posortowanej przez algorytm sortowania przez scalanie: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << tabM[5][j] << " ";
    }
    std::cout << "" << std::endl;
////////////////////////////////////////DRIVER///////////////////////////////////////////////////////////////////////


        //zwalnianie pamięci
        for (int i = 0; i < 100; ++i) {
            delete[] tabM[i];
            delete[] q[i];
        }
        delete[] tabM;
        delete[] q;

        //**********************************************************************************//
        //HeapSort

        int **tabI;

        tabI = new int *[100];

        for (int i = 0; i < 100; ++i) {
            tabI[i] = new int[n];
        }

        //wpisanie liczb do tablicy na ktorj bede testował algorytm sortowania Heapsort
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < n; j++) {
                tabI[i][j] = tab[i][j];
            }
        }

        // pomiar czasu wykonania algorytmu na 100 tablicach i obliczenie czasu jego wykonania
        clock_t start_I = clock();
        for (int i = 0; i < 100; ++i) {
            //Introsort(tabI[i], 0, n - 1, 2 * log(n));
            Heapsort(tabI[i], n-1);
        }
        clock_t stop_I = clock();

        double timeI = (double) (stop_I - start_I) / CLOCKS_PER_SEC;
//        std::cout << "Czas wyknania algorytmu sortowania Heapsort: " << timeI << std::endl;

////////////////////////////////////////DRIVER//////////////////////////////////////////////////////////////////////
    std::cout<< "Elemety tablicy posortowanej przez algorytm sortowania przez kopcowanie: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << tabI[5][j] << " ";
    }
    std::cout << "" << std::endl;
////////////////////////////////////////DRIVER///////////////////////////////////////////////////////////////////////

        //zwalnianie pamieci

        for (int i = 0; i < 100; ++i) {
            delete[] tabI[i];
        }
        delete[] tabI;

        //zwalnianie pamieci

        for (int i = 0; i < 100; ++i) {
            delete[] tab[i];
        }
        delete[] tab;
    //}


    return 0;
}
