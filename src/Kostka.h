//#include "define.h"
#include "Bod.h"
class Kostka {
        Bod *body;
        int x, y;

    public:
        Kostka();
        ~Kostka();
        void addBod(Bod*);
        void addBod(int x, int y);
        void addBody(Bod*,int curX, int curY);
        void tisk(WINDOW *w);
        void tisk(WINDOW *w, int x, int y);

        void copy(Kostka*);
        void deepCopy(Kostka*);
        void unsetBody();

        Bod* getBody();

        int colisionXBox(int x);
        int colisionYBox(int y);
        int colisionWith(Kostka*, int curX, int curY);
        int getTop();
        int removeFullLines();
        void removeBod(Bod*,Bod*);
};
