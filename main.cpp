#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

const int N = 100000;

// Losuje n liczb z zakresu 1-1000000
vector<int> losuj(int n)
{
    vector<int> a(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> los(1, 1000000);

    for (int i = 0; i < n; i++)
        a[i] = los(gen);

    return a;
}

// Test zwyk³ej tablicy.
// Sortuje najpierw 100k, a nastêpnie 200k liczb i mierzy czas.
void tablica()
{
    int a[200000];

    vector<int> liczby = losuj(200000);

    // Pierwsze 100k liczb
    for (int i = 0; i < N; i++)
        a[i] = liczby[i];

    auto start = chrono::high_resolution_clock::now();

    sort(a, a + N);

    auto stop = chrono::high_resolution_clock::now();

    auto czas = chrono::duration_cast<chrono::milliseconds>
                (stop - start).count();

    cout << "Tablica - 100k: " << czas << " ms" << endl;

    // Dodajemy kolejne 100k
    for (int i = N; i < 2 * N; i++)
        a[i] = liczby[i];

    start = chrono::high_resolution_clock::now();

    sort(a, a + 2 * N);

    stop = chrono::high_resolution_clock::now();

    czas = chrono::duration_cast<chrono::milliseconds>
           (stop - start).count();

    cout << "Tablica - 200k: " << czas << " ms" << endl;
}

// Test vectora.
// Dodaje 100k liczb, sortuje je, nastêpnie dodaje kolejne 100k i sortuje ca³oœæ.
void wektor()
{
    vector<int> a;
    vector<int> liczby = losuj(200000);

    // Rezerwujemy miejsce na 200k elementów
    a.reserve(200000);

    for (int i = 0; i < N; i++)
        a.push_back(liczby[i]);

    auto start = chrono::high_resolution_clock::now();

    sort(a.begin(), a.end());

    auto stop = chrono::high_resolution_clock::now();

    auto czas = chrono::duration_cast<chrono::milliseconds>
                (stop - start).count();

    cout << "Vector - 100k: " << czas << " ms" << endl;

    // Dodajemy kolejne 100k
    for (int i = N; i < 2 * N; i++)
        a.push_back(liczby[i]);

    start = chrono::high_resolution_clock::now();

    sort(a.begin(), a.end());

    stop = chrono::high_resolution_clock::now();

    czas = chrono::duration_cast<chrono::milliseconds>
           (stop - start).count();

    cout << "Vector - 200k: " << czas << " ms" << endl;
}

// Test stosu LIFO.
// Elementy s¹ wyjmowane od ostatniego dodanego.
// Poniewa¿ stack nie ma sort(), elementy s¹ przenoszone do vectora.
void lifo()
{
    stack<int> stos;
    vector<int> liczby = losuj(200000);
    vector<int> a;

    for (int i = 0; i < N; i++)
        stos.push(liczby[i]);

    auto start = chrono::high_resolution_clock::now();

    while (!stos.empty())
    {
        a.push_back(stos.top());
        stos.pop();
    }

    sort(a.begin(), a.end());

    auto stop = chrono::high_resolution_clock::now();

    auto czas = chrono::duration_cast<chrono::milliseconds>
                (stop - start).count();

    cout << "LIFO - 100k: " << czas << " ms" << endl;

    // Dodajemy kolejne 100k
    for (int i = N; i < 2 * N; i++)
        stos.push(liczby[i]);

    // Wk³adamy wczeœniej posortowane elementy z powrotem na stos
    for (int x : a)
        stos.push(x);

    a.clear();

    start = chrono::high_resolution_clock::now();

    while (!stos.empty())
    {
        a.push_back(stos.top());
        stos.pop();
    }

    sort(a.begin(), a.end());

    stop = chrono::high_resolution_clock::now();

    czas = chrono::duration_cast<chrono::milliseconds>
           (stop - start).count();

    cout << "LIFO - 200k: " << czas << " ms" << endl;
}

// Test kolejki FIFO.
// Pierwszy dodany element jest wyjmowany jako pierwszy.
// Elementy s¹ przenoszone do vectora, aby mo¿na by³o je posortowaæ.
void kolejka()
{
    queue<int> q;
    vector<int> liczby = losuj(200000);
    vector<int> a;

    for (int i = 0; i < N; i++)
        q.push(liczby[i]);

    auto start = chrono::high_resolution_clock::now();

    while (!q.empty())
    {
        a.push_back(q.front());
        q.pop();
    }

    sort(a.begin(), a.end());

    auto stop = chrono::high_resolution_clock::now();

    auto czas = chrono::duration_cast<chrono::milliseconds>
                (stop - start).count();

    cout << "Kolejka - 100k: " << czas << " ms" << endl;

    // Dodajemy kolejne 100k
    for (int i = N; i < 2 * N; i++)
        q.push(liczby[i]);

    // Wk³adamy poprzednie elementy z powrotem do kolejki
    for (int x : a)
        q.push(x);

    a.clear();

    start = chrono::high_resolution_clock::now();

    while (!q.empty())
    {
        a.push_back(q.front());
        q.pop();
    }

    sort(a.begin(), a.end());

    stop = chrono::high_resolution_clock::now();

    czas = chrono::duration_cast<chrono::milliseconds>
           (stop - start).count();

    cout << "Kolejka - 200k: " << czas << " ms" << endl;
}

// Test drzewa.
// Wykorzystuje set, który przechowuje elementy w uporz¹dkowanej kolejnoœci.
void drzewo()
{
    set<int> drzewo;
    vector<int> liczby = losuj(200000);

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        drzewo.insert(liczby[i]);

    auto stop = chrono::high_resolution_clock::now();

    auto czas = chrono::duration_cast<chrono::milliseconds>
                (stop - start).count();

    cout << "Drzewo - 100k: " << czas << " ms" << endl;

    start = chrono::high_resolution_clock::now();

    for (int i = N; i < 2 * N; i++)
        drzewo.insert(liczby[i]);

    stop = chrono::high_resolution_clock::now();

    czas = chrono::duration_cast<chrono::milliseconds>
           (stop - start).count();

    cout << "Drzewo - 200k: " << czas << " ms" << endl;
}

// Uruchamia wszystkie testy po kolei.
int main()
{
    cout << "POROWNANIE STRUKTUR DANYCH\n\n";

    tablica();
    cout << endl;

    wektor();
    cout << endl;

    lifo();
    cout << endl;

    kolejka();
    cout << endl;

    drzewo();

    return 0;
}
