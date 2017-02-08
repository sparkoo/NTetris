#include "include.h"
#include "Kostka.h"
class Tvar {
        int n;  //pocet variaci
        Kostka *k;  //pole jednotlivych natoceni kostek

    public:
        Tvar(int n);
        Tvar();
        ~Tvar();

        void addKostka(Kostka*, int n);
        Kostka* getKostka(int n);
        Kostka* getKostka();
        int getN();
};
