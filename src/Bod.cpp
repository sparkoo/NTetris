#include "Bod.h"

Bod::Bod(int x, int y) {
    this->x=x;
    this->y=y;
    next=NULL;
}

Bod::~Bod() {
    if (next)
        delete(next);
    next=NULL;
}

void Bod::setNext(Bod *x) {
    next=x;
}

void Bod::tisk(WINDOW *w, int x, int y) {
    wattron(w,COLOR_PAIR(COLOR_MAIN));
    mvwprintw(w,y+this->y,x+(2*this->x),"  ");
}

Bod* Bod::getNext() {
    return next;
}

int Bod::isNext() {
    if (next)
        return 1;
    return 0;
}

void Bod::nullNext() {
    next=NULL;
}


void Bod::decY() {
    y++;
}

int Bod::getX() {
    return x;
}

int Bod::getY() {
    return y;
}
