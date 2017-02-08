#include "Tvar.h"


Tvar::Tvar(int n) {
    this->n=n;
    k=(Kostka*)malloc(n*sizeof(Kostka));
}

Tvar::Tvar() {

}

Tvar::~Tvar() {
    free(k);
}

void Tvar::addKostka(Kostka *x,int n) {
    k[n].copy(x);
    x->unsetBody();
}

Kostka* Tvar::getKostka(int n) {
    return &k[n];
}

Kostka *Tvar::getKostka() {
    return &k[0];
}

int Tvar::getN() {
    return n;
}
