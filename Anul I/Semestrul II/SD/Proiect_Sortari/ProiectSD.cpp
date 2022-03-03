#include <iostream>
#include <queue>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

ifstream fin ("intrare.txt");
ofstream fout ("rezultate.txt");

int aux[100000000];

void BubbleSort(int v[], int n)
{
    int i,j,aux;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }
}

void CountSort(int v[], int n)
{
    int i, j, max=v[0];
    for (i = 0; i < n; i++) 
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    int* fr;
    fr = new int [max+4];
    for (i = 0; i <= max; i++)
    {
        fr[i] = 0;
    }
    for (i = 0; i < n; i++) 
    {
        fr[v[i]]++;
    }
    int k = 0;
    for (i = 0; i <= max; i++)
    {
        for (j = 0; j < fr[i]; j++)
        {
            v[k++] = i;
        }
    }

    delete[]fr;
}

//LSD Baza 2:
void RadixSort(int v[], int n)
{
    int i;
    queue <int> q0;
    queue <int> q1;

    int* vnou;
    vnou = new int[n+4];

    int max = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    int ordin = 0;

    while(max != 0)
    {
    
        for (i = 0; i < n; i++)
        {
            vnou[i] = v[i];
            int index = ordin;
            while (index != 0)
            {
                vnou[i]= vnou[i] >> 1;
                index--;
            }
        }
       
        for (i = 0; i < n; i++)
        {
            if ((vnou[i] & 1) == 0)
            {
                q0.push(v[i]);
            }
            else
            {
                q1.push(v[i]);
            }
        }
        int j = 0;
       
        while (!q0.empty())
        {
            v[j++] = q0.front();
            q0.pop();
        }

        while (!q1.empty())
        {
            v[j++] = q1.front();
            q1.pop();
        }

        max = max >> 1;
        ordin++;
    }
    delete[]vnou;
}

//LSD Baza 8:
void RadixSort1(int v[], int n)
{
    int i;
    queue <int> q0;
    queue <int> q1;
    queue <int> q2;
    queue <int> q3;
    queue <int> q4;
    queue <int> q5;
    queue <int> q6;
    queue <int> q7;

    int* vnou;
    vnou = new int[n];
    int lastDigit;

    int max = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    int ordin = 0;

    while (max != 0)
    {

        for (i = 0; i < n; i++)
        {
            vnou[i] = v[i];
            int index = ordin;
            while (index != 0)
            {
                vnou[i] = vnou[i] >> 3;
                index--;
            }
        }

        for (i = 0; i < n; i++)
        {
            lastDigit = ((vnou[i] & 4) + (vnou[i] & 2) + (vnou[i] & 1));

            if (lastDigit == 0)
            {
                q0.push(v[i]);
            }
            else if (lastDigit == 1)
            {
                q1.push(v[i]);
            }
            else if (lastDigit == 2)
            {
                q2.push(v[i]);
            }
            else if (lastDigit == 3)
            {
                q3.push(v[i]);
            }
            else if (lastDigit == 4)
            {
                q4.push(v[i]);
            }
            else if (lastDigit == 5)
            {
                q5.push(v[i]);
            }
            else if (lastDigit == 6)
            {
                q6.push(v[i]);
            }
            else
            {
                q7.push(v[i]);
            }

        }
        int j = 0;

        while (!q0.empty())
        {
            v[j++] = q0.front();
            q0.pop();
        }

        while (!q1.empty())
        {
            v[j++] = q1.front();
            q1.pop();
        }

        while (!q2.empty())
        {
            v[j++] = q2.front();
            q2.pop();
        }
        while (!q3.empty())
        {
            v[j++] = q3.front();
            q3.pop();
        }
        while (!q4.empty())
        {
            v[j++] = q4.front();
            q4.pop();
        }
        while (!q5.empty())
        {
            v[j++] = q5.front();
            q5.pop();
        }
        while (!q6.empty())
        {
            v[j++] = q6.front();
            q6.pop();
        }
        while (!q7.empty())
        {
            v[j++] = q7.front();
            q7.pop();
        }
        max = max >> 3;
        ordin++;
    }
    delete[]vnou;
}

void MergeSort(int v[], int st, int dr)
{
    //cout << st << ' ' << dr << "\n";

    if (st < dr) 
    {
        int mij = (st + dr) / 2;

        MergeSort(v, st, mij);
        MergeSort(v, mij + 1, dr);

        int i = st, j = mij + 1, k = 0;
        while (i <= mij && j <= dr)
        {
            if (v[i] < v[j])
            {
                aux[k++] = v[i++];
            }
            else
            {
                aux[k++] = v[j++];
            }
        }
        while (i <= mij)
        {
            aux[k++] = v[i++];
        }
        while (j <= dr)
        {
            aux[k++] = v[j++];
        }
        for (i = st, j = 0; i <= dr; i++, j++)
        {
            v[i] = aux[j];
        }
    }
}

void QuickSort(int v[],int n)
{
        int a[3], i=0;

        for (i = 0; i < 3; i++)
        {
            a[i] = v[rand() % n];
        }

        BubbleSort(a, 3);

        int pivot = a[1];

        
        
        int i1 = 0, i2 = 0, i3 = 0;

        int* l;
        l = new int[n];

        int* r;
        r = new int[n];

        int* e;
        e = new int[n];

        for (i = 0; i < n; i++)
        {
            if (v[i] < pivot)
            {
                l[i1++] = v[i];
            }
            else if (v[i] > pivot)
            {
                r[i2++] = v[i];
            }
            else
            {
                e[i3++] = v[i];
            }
        }

      
        
        if (i1 > 1)
        {
            QuickSort(l, i1);
        }
        
        if (i2 > 1)
        {
            QuickSort(r, i2);
        }
       
        int k = 0;
        for (i = 0; i < i1; i++)
        {
            v[k++] = l[i];
        }
        
        for (i = 0; i < i3; i++)
        {
            v[k++] = e[i];
        }
       
        for (i = 0; i < i2; i++)
        {
            v[k++] = r[i];
        }
       
    
        delete[]l;
        delete[]r;
        delete[]e;
}

int TipTest(char test[100])
{
    int a=0;
    if (strcmp(test, "Sortat") == 0)
    {
         a=1;
    }
    else if (strcmp(test, "Sortat_Invers") == 0)
    {
        a=2;
    }
    else if (strcmp(test, "Constant") == 0)
    {
        a=3;
    }
    else if (strcmp(test, "Random") == 0)
    {
        a=4;
    }
    return a;
}

void Sortat(int v[],int n)
{
    bool ok = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            ok = false;
         
        }
    }
    if (ok)
    {
        fout << "Vectorul este bine sortat";
    }
    else
    {
        fout << "Vectorul nu este bine sortat";
    }
}

int main()
{

    int T, N, Max, tipTest,x,i;
    int* v, * vect_princ, * aux;
    char TT[100];

    random_device device;
    mt19937 generator(device());

    fin >> T;

    for (int index = 0; index < T; index++)
    {

        fin >> TT;     

        tipTest = TipTest(TT);

        fin >> N >> Max;
        uniform_int_distribution<int> distribution(0, Max);

        v = new int[N+1];
        vect_princ = new int[N+1];
        
        

        if (tipTest == 4)
        {
            for (i = 0; i < N; i++)
            {
                vect_princ[i] = distribution(generator);
            }
        }
        else if (tipTest == 1)
        {
            for (i = 0; i < N; i++)
            {
                vect_princ[i] = distribution(generator);
            }
            CountSort(vect_princ, N);
        }
        else if (tipTest == 2)
        {
            for (i = 0; i < N; i++)
            {
                vect_princ[i] = distribution(generator);
            }
            CountSort(vect_princ, N);
            aux = new int[N + 1];
            int k = 0;
            for (i = N - 1; i >= 0; i--)
            {
                aux[k++] = vect_princ[i];
            }
            vect_princ = aux;
        }
        else if (tipTest == 3)
        {
            x = distribution(generator);
            for (i = 1; i < N; i++)
            {
                vect_princ[i] = x;
            }
        }
            
        for (i = 0; i < N; i++)
        {
            v[i] = vect_princ[i];
        }
            
        if (N <= 10000000 || tipTest == 3)
        {
                auto startTime7 = chrono::high_resolution_clock::now();
                sort(v, v + N);
                auto stopTime7 = chrono::high_resolution_clock::now();
                fout << "Sortare nativa c++" << endl;
                Sortat(v, N);
                chrono::duration<float> duration7 = stopTime7 - startTime7;
                fout << endl << "Durata:" << duration7.count() << " secunde" << endl;
                fout << endl;


                for (i = 0; i < N; i++)
                {
                    v[i] = vect_princ[i];
                }
        }
        else
        {
            fout << "Numar prea mare pentru sortarea nativa \n";
        }

        if (N <= 100000) 
        {
                auto startTime1 = chrono::high_resolution_clock::now();
                BubbleSort(v, N);
                auto stopTime1 = chrono::high_resolution_clock::now();
                fout << "BubleSort:" << endl;
                Sortat(v, N);
                chrono::duration<float> duration1 = stopTime1 - startTime1;
                fout << endl << "Durata:" << duration1.count() << " secunde" << endl;
                fout << endl;

                for (i = 0; i < N; i++)
                {
                    v[i] = vect_princ[i];
                }
        }
        else
        {
                fout << "Numar prea mare pentru BubbleSort"<<endl;
        }

            
        if (N <= 100000000 && tipTest != 3) 
        {
            auto startTime2 = chrono::high_resolution_clock::now();
            CountSort(v, N);
            auto stopTime2 = chrono::high_resolution_clock::now();
            fout << "CountSort:" << endl;
            Sortat(v, N);
            chrono::duration<float> duration2 = stopTime2 - startTime2;
            fout << endl << "Durata:" << duration2.count() << " secunde" << endl;
            fout << endl;
            for (i = 0; i < N; i++)
            {
                v[i] = vect_princ[i];
            }
        }

        else if(tipTest != 3)
        {
            fout << "Numar prea mare pentru CountSort"<<endl;
        }

        else
        {
            fout << "CountSort nu poate sorta" << endl;;
        }
            
            
        if (N <= 10000000) 
        {
                auto startTime3 = chrono::high_resolution_clock::now();
                RadixSort(v, N);
                auto stopTime3 = chrono::high_resolution_clock::now();
                fout << "Radix Sort LSD Baza 2:" << endl;
                Sortat(v, N);
                chrono::duration<float> duration3 = stopTime3 - startTime3;
                fout << endl << "Durata:" << duration3.count() << " secunde" << endl;
                fout << endl;

                for (i = 0; i < N; i++)
                {
                    v[i] = vect_princ[i];
                }
        }
        else
        {
            fout << "Numar prea mare pentru RadixSort LSD Baza 2" << endl;
        }


        if (N <= 10000000) 
        {
                auto startTime6 = chrono::high_resolution_clock::now();
                RadixSort1(v, N);
                auto stopTime6 = chrono::high_resolution_clock::now();
                fout << "Radix Sort LSD Baza 8:" << endl;
                Sortat(v, N);
                chrono::duration<float> duration6 = stopTime6 - startTime6;
                fout << endl << "Durata:" << duration6.count() << " secunde" << endl;
                fout << endl;

                for (i = 0; i < N; i++)
                {
                    v[i] = vect_princ[i];
                }
        }
        else
        {
                fout << "Numar prea mare pt RadixSort LSD Baza 8 "<<endl;
        }

            
        if (N <= 100000000) 
        {
            auto startTime4 = chrono::high_resolution_clock::now();
            MergeSort(v, 0, N - 1);
            auto stopTime4 = chrono::high_resolution_clock::now();
            fout << "MergeSort:" << endl;
            Sortat(v, N);
            chrono::duration<float> duration4 = stopTime4 - startTime4;
            fout << endl << "Durata:" << duration4.count() << " secunde" << endl;
            fout << endl;

            for (i = 0; i < N; i++)
            {
                v[i] = vect_princ[i];
            }
        }

        else
        {
            fout << "Numar prea mare pentru MergeSort"<<endl;
        }


            
        if (N <= 10000000) 
        {
            auto startTime5 = chrono::high_resolution_clock::now();
            QuickSort(v, N);
            auto stopTime5 = chrono::high_resolution_clock::now();
            fout << "QuickSort:" << endl;
            Sortat(v, N);
            chrono::duration<float> duration5 = stopTime5 - startTime5;
            fout << endl << "Durata:" << duration5.count() << " secunde" << endl;
            fout << endl;
        }

        else
        {
            fout << "Numar prea mare pentru QuickSort \n"<<endl;
        }
         
        
        
    }
    
    fout.close();
    return 0;
}