Porównanie struktur danych w C++

Program służy do porównania czasu działania różnych struktur danych podczas pracy z 100 000, a następnie 200 000 losowych liczb.

Wykorzystane struktury

Program porównuje:

zwykłą tablicę int[]

vector

stos stack – LIFO

kolejkę queue – FIFO

drzewo set

Jak działa program?

Na początku program losuje 200 000 liczb z zakresu od 1 do 1 000 000.

Następnie każda struktura jest testowana w dwóch etapach:

dodanie/przygotowanie pierwszych 100 000 liczb i wykonanie operacji,

dodanie kolejnych 100 000 liczb i wykonanie operacji na wszystkich 200 000 liczbach.

Czas wykonywania operacji jest mierzony za pomocą biblioteki chrono.

Opis funkcji
losuj(int n)

Losuje n liczb całkowitych i zwraca je w postaci vector<int>.

tablica()

Tworzy zwykłą tablicę o rozmiarze 200 000 elementów.

Najpierw sortuje 100 000 liczb, a następnie po dodaniu kolejnych 100 000 sortuje wszystkie 200 000.

wektor()

Wykorzystuje strukturę vector.

Dodaje 100 000 elementów, sortuje je, następnie dodaje kolejne 100 000 i ponownie sortuje całość.

lifo()

Wykorzystuje stos stack.

LIFO oznacza Last In, First Out, czyli ostatni dodany element jest pobierany jako pierwszy.

Ponieważ stack nie posiada funkcji sort(), elementy są przenoszone do vector, a następnie sortowane.

kolejka()

Wykorzystuje queue.

FIFO oznacza First In, First Out, czyli pierwszy dodany element jest pobierany jako pierwszy.

Tak samo jak w przypadku stosu, elementy są przenoszone do vector, aby można było je posortować.

drzewo()

Wykorzystuje set.

Elementy w set są automatycznie przechowywane w uporządkowanej kolejności, dlatego nie trzeba wykonywać osobnego sort().

Pomiar czasu

Do pomiaru czasu wykorzystano:

chrono::high_resolution_clock


Czas jest podawany w milisekundach (ms).

Przykładowy wynik:

POROWNANIE STRUKTUR DANYCH

Tablica - 100k: 8 ms
Tablica - 200k: 17 ms

Vector - 100k: 7 ms
Vector - 200k: 15 ms

LIFO - 100k: 10 ms
LIFO - 200k: 22 ms

Kolejka - 100k: 11 ms
Kolejka - 200k: 23 ms

Drzewo - 100k: 30 ms
Drzewo - 200k: 65 ms


Wyniki mogą być różne w zależności od komputera, obciążenia systemu oraz kompilatora.

Kompilacja

Program wymaga kompilatora obsługującego standard C++11 lub nowszy.

Przykładowa kompilacja przy użyciu g++:

g++ main.cpp -o program


Uruchomienie:

./program


Na Windows:

program.exe

Biblioteki

Program korzysta z:

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>


Służą one odpowiednio do obsługi wejścia/wyjścia, struktur danych, sortowania, losowania liczb oraz pomiaru czasu.

Cel programu

Celem programu jest praktyczne porównanie różnych struktur danych oraz sprawdzenie, jak zmienia się czas wykonywania operacji po zwiększeniu liczby elementów z 100 000 do 200 000.
