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
        char * adr1{"monsieur"}, * adr2{"bonjour"};
        std::cout << "min(adr1, adr2) = " << minimum(adr1, adr2) << std::endl;
    }

    // Au delà du fait qu'il est déconseillé de convertir une chaîne constante en char*, ici
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

    template <typename T, typename U> T fct_1_3_2(T a, T * b, U c) {
        T x;                // variable locale de type T
        U * adr;            // variable locale de type U
        //...
        adr = new T[10];    // allocation tableau de 10 éléments de type T
        //...
        int n = sizeof(T);
        //...
        return x;
    }


    // 2.2 - Identification des paramètres de type d'une fonction patron
    // -----------------------------------------------------------------

    // Exemples d'appels de minimum() qui précisent la fonction instanciée
    void run_2_2() {
        int n; char c; unsigned int q;
        const int ci1 = 10, ci2 = 12;
        int t[10];
        int * adi;

        //minimum(n, c);      // erreur
        //minimum(n, q);      // erreur
        //minimum(n, ci1);    // erreur
        minimum(ci1, ci2);  // minimum(const int, const int)
        minimum(t, adi);    // minimum(int *, int *) car t est converti
                            // en int *, avant appel

        // Nous pouvons aussi intervenir dans l'identification de type, en le
        // spécifiant lors de l'appel du patron
        minimum<int>(c, n);
        minimum<char>(q, n);
    }

    // Exemple avec plusieurs paramètres de type
    template <typename T, typename U> T fct_2_2_bis(T x, U y, T z) {
        return x + y + z;
    }

    void run_2_2_bis() {
        int n = 1, p = 2, q = 3;
        float x = 2.5, y = 5.0;

        std::cout << fct_2_2_bis(n, x, p) << std::endl;   // affiche la valeur (int) 5
        std::cout << fct_2_2_bis(x, n, y) << std::endl;   // affiche la valeur (float) 8.5
        std::cout << fct_2_2_bis(n, p, q) << std::endl;   // affiche la valeur (int) 6
        //std::cout << fct_2(n, p, x) << std::endl;   // erreur, pas de correspondance

        // Ici aussi nous pouvons forcer certains paramètres de type
        fct_2_2_bis<int, float>(n, p, x); // force l'utilisation de fct_2<int, float>, et donc
                                    // la conversion de p en float et de x en int
        fct_2_2_bis<float>(n, p, x);      // force l'utilisation de float pour T. U est 
                                    // déterminé par les règles habituelles,
                                    // c'est-à-dire int (type de p)
                                    // n sera converti en float
    }


    // 2.3 - Retour sur la syntaxe d'initialisation des variables
    // ----------------------------------------------------------

    template <typename T> T fct_2_3(T a) {
        T x(3); // x est un objet loacal de type T qu'on construit
                // en transmettant la valeur 3 à son constructeur
        //...
    }

    // Appel de fct_2_3() pour un type standard, int en l'occurance
    // fct(int a) {
    //     int x(3);    // équivalent à int x = 3;
    //     ...
    // }

    // L'appel parenthésé à été introduit pour cet usage

    template <typename T> T fct_2_3_bis(T a) {
        T x{3};
        //...
    }
    // Notation ambigue dans le cas de constructeurs attendant des
    // arguments de type initialier_list, traité en 2.5


    // 2.4 - Limitations des patrons de fonction
    // -----------------------------------------

} // namespace PatronsDeFonctions
