#include "Kostka.h"
#include <stdlib.h>

Kostka::Kostka() {
    body=NULL;
}

Kostka::~Kostka() {
    if (body)
        delete(body);
}

void Kostka::addBod(Bod *x) {
    if (body) {
        x->setNext(body);
        body=x;
    }else{
        body=x;
    }
}

void Kostka::addBod(int x, int y) {
    Bod *a=new Bod(x,y);
    addBod(a);
}
void Kostka::tisk(WINDOW *w) {

}

void Kostka::removeBod(Bod *b2,Bod *b) {
    b2=b->getNext();
}

void Kostka::tisk(WINDOW *w, int x, int y) {
    Bod *b=body;
    while(b){
        b->tisk(w,x,y);
        b=b->getNext();
    }
}

void Kostka::copy(Kostka *x) {
    this->body=x->body;
}

void Kostka::deepCopy(Kostka *x) {
    Bod *b;
    b=x->getBody();
    while (b) {
        addBod(b->getX(),b->getY());
        b=b->getNext();
    }
}

void Kostka::unsetBody() {
    body=NULL;
}

int Kostka::colisionXBox(int x) {
    Bod *b=body;
    while(b){
        //printf("%d\n",b->getX()+x);
        if (b->getX()+x >= X-1 || b->getX()+x <= 0)
            return 1;
        b=b->getNext();
    }
    return 0;
}

int Kostka::colisionYBox(int y) {
    Bod *b=body;
    while(b){
        //printf("%d\n",b->getX()+x);
        if (b->getY()+y >= Y-1)
            return 1;
        b=b->getNext();
    }
    return 0;
}

int Kostka::colisionWith(Kostka *x,int curX, int curY) {
    Bod *a,*b;
    a=body;
    b=x->getBody();
    while (a) {
        while (b) {
            if (b->getX()==a->getX()+curX && b->getY()==a->getY()+curY)
                return 1;
            b=b->getNext();
        }
        b=x->getBody();
        a=a->getNext();
    }
    return 0;
}

Bod* Kostka::getBody() {
    return body;
}

int Kostka::getTop() {
    Bod *b=body;
    int topY=b->getY();
    do{
        b=b->getNext();
        if (b->getY()<topY)
            topY=b->getY();
    }while(b->getNext());

    return topY;
}

void Kostka::addBody(Bod *x,int curX, int curY) {
    Bod *b=x;
    Bod *c;
    while(b){
        c=new Bod(b->getX()+curX,b->getY()+curY-1);
        c->setNext(body);
        body=c;
        b=b->getNext();
    }
}

int Kostka::removeFullLines() {
    int count;
    int lines=0;
    Bod *b,*b2;
    for (int row=Y-2;row>0;row--) {
        b=body;
        count=0;
        while(b) {
            if (b->getY()==row) {
                count++;
            }
            b=b->getNext();
        }
        //return count;
        if (!count) {
            return lines;
        }

        //pokavad je radek plnej
        if (count==X-2) {
            lines++;
            b=body;
            b2=b;
            b=b->getNext();
            //projdem seznam a smazeme body pozadovaneho radku
            while(b->isNext()) {
                if (b->getY()==row) {
                    b2->setNext(b->getNext());
                    b->nullNext();
                    delete(b);
                    b=b2->getNext();
                }else{
                    b2=b;
                    b=b->getNext();
                }
            }
            //zkontroluje a pripadne smaze posledni prvek
            if (b->getY()==row) {
                b2->nullNext();
                delete(b);
            }
            //zkontroluje a pripadne smaze prvni prvek
            b=body;
            b2=body;
            if (b->getY()==row) {
                body=b->getNext();
                b2->nullNext();
                delete(b2);
            }
            //posunuti vsech vyssich bodu dolu
            b=body;
            while(b) {
                if (b->getY()<row) {
                    b->decY();
                }
                b=b->getNext();
            }
            row++;
        }
    }
    return lines;
}
