#include "include.h"
#include "Bod.h"
class Stavba {
    Bod *body;

    public:
        Stavba();
        ~Stavba();
        void tisk(WINDOW *w);
        void addBody(Bod*);
};
