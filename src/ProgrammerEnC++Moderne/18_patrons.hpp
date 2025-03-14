#pragma once

export template <typename T> T minimum(T a, T b) {
    if (a < b) return a; // ou return a < b ? a : b;
    else return b;
}