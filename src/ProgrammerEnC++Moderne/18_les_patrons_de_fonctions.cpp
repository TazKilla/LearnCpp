#include <iostream>

#include "18_les_patrons_de_fonctions.hpp"

namespace PatronsDeFonctions {

    // 1 - Example de création et d'utilisation d'un patron de fonctions
    // -----------------------------------------------------------------
    // 1.1 - Création d'un patron de fontions
    // --------------------------------------

    /*int minimum(int a, int b) {
        if (a < b) return a; // ou return a < b ? a : b;
        else return b;
    }

    float minimum(float a, float b) {
        if (a < b) return a; // ou return a < b ? a : b;
        else return b;
    }*/

    //...
    // Cette technique nous pousse à créer une fonction par type, alors
    // que rien d'autre ne change d'une fonction à l'autre.
    // Nous pouvons simplifier les choses en définissant un seul patron
    // fonctions :
    // cf fichier 18_patrons.hpp, fonction minimum()

    // 1.2 - Premières utilisations du patron de fonctions
    // ---------------------------------------------------

    void run_1_2() {
        int n = 4, p = 12;
        float x = 2.5, y = 3.25;
        std::cout << "min(n, p) = " << minimum(n, p) << std::endl; // int min(int, int);
        std::cout << "min(x, y) = " << minimum(x, y) << std::endl; // float min(float, float);
    }

    // 1.3 - Autres utilisations du patron de fonctions
    // ------------------------------------------------
    // 1.3.1 - Application au type char*
    // ---------------------------------

    void run_1_3_1() {
        char * adr1 = "monsieur", * adr2 = "bonjour";
        std::cout << "min(adr1, adr2) = " << minimum(adr1, adr2) << std::endl;
    }

    // Au delà du fait qu'il est déconseillé de converting une chaîne constante en char*, ici
    // le compilateur crée une fonction qui va comparer la valeur des pointeurs, pas les chaînes.
    // Le résultat peut donc changer d'une machine à l'autre.

    // 1.3.2 - Application à un type classe
    // ------------------------------------

    class vect {
        public:
            vect (int abs = 0, int ord = 0) : x(abs), y(ord) {}
            void affiche() {std::cout << x << " " << y << std::endl;}
            friend int operator < (vect, vect);
        private:
            int x, y;
    };
    int operator < (vect a, vect b) {
        return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
    }

    // Exemple d'utilisation de minimum
    void run_1_3_2() {
        vect u(3, 2), v(4, 1), w;
        w = minimum(v, u);
        std::cout << "min(u, v) = "; w.affiche();
    }

    // 1.4 - Contraintes d'utilisation d'un patron
    // -------------------------------------------

    // -----------------------------------------------------
    // /!\ La définition d'un patron est une déclaration /!\
    // -----------------------------------------------------
    // Bien que le patron de la fonction minimum() semble contenir
    // des instructions, il s'agit en fait d'une déclaration, que le 
    // compilateur utilise pour générer la définition des fonctions requises.



    // 2 - Les paramètres de type d'un patron de fonctions
    // --------------------------------------------------
    // 2.1 - Utilisation des paramètres de type dans la définition d'un patron
    // -----------------------------------------------------------------------

    

} // namespace PatronsDeFonctions
