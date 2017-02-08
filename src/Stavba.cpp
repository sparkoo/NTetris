#include "Stavba.h"

Stavba::Stavba() {
    body=NULL;
}

Stavba::~Stavba() {
    if (body)
        delete(body);
}

void Stavba::tisk(WINDOW *w) {
    Bod *b=body;
    while(b){
        b->tisk(w,1,Y);
        b=b->getNext();
    }
}

void Stavba::addBody(Bod *x) {
    Bod *b=x;
    Bod *c;
    while(b){
        c=new Bod(b->getX(),b->getY());
        c->setNext(body);
        body=c;
        b=b->getNext();
    }
}
