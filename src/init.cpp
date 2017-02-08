#include "Tvar.h"

void kostkyInit(Tvar **kostky) {
    Kostka *a;
    kostky[0]=new Tvar(1);  //ctverec
    kostky[1]=new Tvar(4);  //L
    kostky[2]=new Tvar(4);  //obraceny L
    kostky[3]=new Tvar(2);  //S
    kostky[4]=new Tvar(2);  //obraceny S
    kostky[5]=new Tvar(2);  //dlouha
    kostky[6]=new Tvar(4);  //skorokriz

    a=new Kostka();

    //ctverec
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(1,0);
    a->addBod(1,1);
    kostky[0]->addKostka(a,0);

    //L
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(0,2);
    a->addBod(1,2);
    kostky[1]->addKostka(a,0);
    a->addBod(0,1);
    a->addBod(1,1);
    a->addBod(2,1);
    a->addBod(2,0);
    kostky[1]->addKostka(a,1);
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(1,1);
    a->addBod(1,2);
    kostky[1]->addKostka(a,2);
    a->addBod(0,1);
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(2,0);
    kostky[1]->addKostka(a,3);

    //obraceny L
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(2,0);
    a->addBod(2,1);
    kostky[2]->addKostka(a,3);
    a->addBod(1,0);
    a->addBod(1,1);
    a->addBod(1,2);
    a->addBod(0,2);
    kostky[2]->addKostka(a,2);
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(1,1);
    a->addBod(2,1);
    kostky[2]->addKostka(a,1);
    a->addBod(1,0);
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(0,2);
    kostky[2]->addKostka(a,0);

    //S
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(1,1);
    a->addBod(1,2);
    kostky[3]->addKostka(a,0);
    a->addBod(0,1);
    a->addBod(1,1);
    a->addBod(1,0);
    a->addBod(2,0);
    kostky[3]->addKostka(a,1);

    //obraceny S
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(1,1);
    a->addBod(2,1);
    kostky[4]->addKostka(a,0);
    a->addBod(1,0);
    a->addBod(1,1);
    a->addBod(0,1);
    a->addBod(0,2);
    kostky[4]->addKostka(a,1);

    //dlouha
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(0,2);
    a->addBod(0,3);
    kostky[5]->addKostka(a,0);
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(2,0);
    a->addBod(3,0);
    kostky[5]->addKostka(a,1);

    //kriz
    a->addBod(0,0);
    a->addBod(0,1);
    a->addBod(0,2);
    a->addBod(1,1);
    kostky[6]->addKostka(a,3);
    a->addBod(0,0);
    a->addBod(1,0);
    a->addBod(2,0);
    a->addBod(1,1);
    kostky[6]->addKostka(a,2);
    a->addBod(1,0);
    a->addBod(1,1);
    a->addBod(1,2);
    a->addBod(0,1);
    kostky[6]->addKostka(a,1);
    a->addBod(1,0);
    a->addBod(0,1);
    a->addBod(1,1);
    a->addBod(2,1);
    kostky[6]->addKostka(a,0);


}

void initColors() {
    init_pair(COLOR_BOX,COLOR_WHITE,COLOR_BLACK);
    init_pair(COLOR_MAIN,COLOR_BLACK,COLOR_WHITE);
}
