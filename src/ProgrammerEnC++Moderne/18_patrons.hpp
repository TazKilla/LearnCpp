#pragma once

#include <iostream>

using namespace std;

export template <typename T> T minimum(T a, T b) {
    if (a < b) return a; // ou return a < b ? a : b;
    else return b;
}

export template <typename T> void f(initializer_list<T> val) {
    cout << val.size() << " valeurs : ";
    for(T v : val) cout << v << " ";
    cout << endl;
}