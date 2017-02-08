#include "include.h"
#include "define.h"
#include <iostream>

#include "Tvar.h"

#include "init.h"



WINDOW *mainW, *playfieldW, *nextW, *scoreW, *controlW;

int score, lines;
unsigned int timer = 1000000; //funkce ktera urcuje rychlost pohybu padajici kostky v pole/usec
int otimer = timer; //zaloha rychlosti kvuli zrychleni padu sipkou dolu
int pressedD = 0;
int posY = 0; //pocitacka vertikalni polohy aktualni kostky
int posX = 5; //pocitacka horizontalni polohy aktualni kostky
int rot = 0; //natoceni kostky
int levelLines = 5; //po kolika radach zdvojnasobit rychlost
int level = 1;
int game = 1;
int k; //aktualni kostka
int n; //dalsi kostka
int pauza = 0;
long curtime;
Kostka *act;
Kostka *next;
Kostka *stavba;

Tvar *kostky[7];

void windowsInit();
void refreshWindows();

void drawControl();
void drawPlayfield();
void drawScore();
void drawNext();
void drawAll();

void keyAction(int ch);

unsigned long getCurTime();

int main() {
    int i;
    int l = 0;
    int olines;

    lines = score = 0;
    olines = lines;

    windowsInit();
    kostkyInit(kostky);

    k = getCurTime() % 7;
    act = kostky[k]->getKostka(0);
    n = getCurTime() % 7;
    next = kostky[n]->getKostka(0);

    stavba = new Kostka();

    drawAll();
    while ((i = wgetch(controlW)) != KEY_F(10) && game) {

        drawPlayfield();
        wrefresh(playfieldW);
        drawNext();
        wrefresh(nextW);

        //nadesel cas
        if (getCurTime() - curtime > timer && !pauza) {
            posY++;

            curtime = getCurTime();

            if ((act->colisionYBox(posY) || act->colisionWith(stavba, posX, posY)) && !pauza) {
                stavba->addBody(act->getBody(), posX, posY);
                l = stavba->removeFullLines();
                lines += l;
                score += (l * l);

                if (lines - levelLines >= olines) {
                    otimer >>= 1;
                    timer = otimer;
                    olines += levelLines;
                    level++;
                }

                drawScore();
                wrefresh(scoreW);
                if (stavba->getTop() <= 1) {
                    //pauza=1;
                    game = 0;
                }
                posY = 0;
                posX = 5;
                rot = 0;

                act = next;
                k = n;
                n = getCurTime() % 7;
                next = kostky[n]->getKostka(0);
                wclear(nextW);
            }

            //drawAll();

            wclear(playfieldW);

        }
        next->tisk(nextW, 3, 1);
        keyAction(i);

        act->tisk(playfieldW, 2 * posX, posY);
        stavba->tisk(playfieldW, 0, 0);

        usleep(10000);
    }

    while (wgetch(controlW) != KEY_F(10)) {
        wclear(playfieldW);
        drawPlayfield();
        mvwprintw(playfieldW, Y / 2 - 1, X / 2 * 2 - 5, "GAME OVER");
        mvwprintw(playfieldW, Y / 2, X / 2 * 2 - 5, "SCORE: %2d", score);
        mvwprintw(playfieldW, Y / 2 + 1, X / 2 * 2 - 5, "LINES: %2d", lines);
        wrefresh(playfieldW);
        usleep(100000);
    }

    endwin();

    delete(next);
    delete(stavba);

    return 0;
}

void keyAction(int ch) {
    if (ch == KEY_UP && !pauza) {
        Kostka *a;
        rot++;
        if (rot >= kostky[k]->getN()) {
            rot = 0;
        }
        a = kostky[k]->getKostka(rot);
        while (a->colisionXBox(posX) || a->colisionWith(stavba, posX, posY)) {
            if (posX <= 2) {
                rot--;
                if (rot < 0)
                    rot = 0;
                break;
            } else
                posX--;
        }
        if (!a->colisionYBox(posY) && !a->colisionWith(stavba, posX, posY) && !a->colisionXBox(posX)) {
            act = a;
        }
        wclear(playfieldW);
    }

    if (ch == KEY_F(2)) {
        if (pauza)
            pauza = 0;
        else
            pauza = 1;
    }


    if (ch == KEY_DOWN && !pauza && !pressedD) {
        otimer = timer;
        timer = 1000;
        pressedD = 1;
    } else if (pressedD) {
        timer = otimer;
        pressedD = 0;
    }

    if (ch == KEY_LEFT && !pauza) {
        if (!act->colisionXBox(posX - 1) && !act->colisionWith(stavba, posX - 1, posY)) {
            posX--;
            wclear(playfieldW);
        }
    }

    if (ch == KEY_RIGHT && !pauza) {
        if (!act->colisionXBox(posX + 1) && !act->colisionWith(stavba, posX + 1, posY)) {
            posX++;
            wclear(playfieldW);
        }
    }
}

/* timestamp v usec*/
unsigned long getCurTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

/*obnoveni oken*/
void refreshWindows() {
    wrefresh(mainW);
    wrefresh(playfieldW);
    wrefresh(nextW);
    wrefresh(scoreW);
    wrefresh(controlW);
}

void drawScore() {
    mvwprintw(scoreW, 1, 3, "SCORE");
    mvwprintw(scoreW, 2, 1, "%d", score);
    mvwprintw(scoreW, 4, 3, "LINES");
    mvwprintw(scoreW, 5, 1, "%d", lines);
    mvwprintw(scoreW, 7, 3, "LEVEL");
    mvwprintw(scoreW, 8, 1, "%d", level);
    wattron(nextW, COLOR_PAIR(COLOR_BOX));
    box(scoreW, 0, 0);
}

void drawNext() {
    wattron(nextW, COLOR_PAIR(COLOR_BOX));
    box(nextW, 0, 0);
}

void drawControl() {
    //mvwprintw(controlW,2,2,"F1-START");
    mvwprintw(controlW, 3, 2, "F2-PAUSE");
    mvwprintw(controlW, 5, 2, "F10-QUIT");
}

void drawPlayfield() {
    wattron(playfieldW, COLOR_PAIR(COLOR_BOX));
    box(playfieldW, 0, 0);
}

void drawAll() {
    drawScore();
    drawNext();
    drawPlayfield();
    drawControl();
    refreshWindows();
}

/*inicializace oken*/
void windowsInit() {
    mainW = initscr();
    curs_set(0);
    noecho();
    cbreak();
    start_color();
    assume_default_colors(COLOR_WHITE, COLOR_BLACK);
    initColors();

    playfieldW = newwin(Y, Xb, 0, 0);
    scoreW = newwin(10, 12, 6, Xb);
    nextW = newwin(6, 12, 0, Xb);
    controlW = newwin(10, 12, 13, Xb);

    keypad(controlW, TRUE);
    nodelay(controlW, TRUE);

    drawAll();
}
