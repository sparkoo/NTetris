#include "define.h"
#include <ncurses.h>

class Bod {
        int x,y;    //souradnice bodu
        Bod *next;

    public:
        Bod(int x, int y);
        ~Bod();
        void setNext(Bod *x);
        void tisk(WINDOW *w, int x, int y);
        Bod* getNext();
        int isNext();
        void nullNext();

        int getX();
        int getY();
        void decY();
};
