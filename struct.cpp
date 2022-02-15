#include "struct.h"

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>


using namespace sf;
using namespace std;

    
    void boardstate::reset(){
        char tab[8][9]={
            "wsgqkgsw",
            "pppppppp",
            "00000000",
            "00000000",
            "00000000",
            "00000000",
            "PPPPPPPP",
            "WSGQKGSW"
        };
    }
    void boardstate::clear(){
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
                tab[i][j]='0';
    }
    void boardstate::ruch(Vector2i f,Vector2i t){
        tab[t.x][t.y]=tab[f.x][f.y];
        tab[f.x][f.y]='0';
    }
    char boardstate::checkpiece(Vector2i v){
        return tab[v.x][v.y];
    }
     //plansza
    //male znaki biale
    //duze znaki czarne
    /* PIONY
    puste = '0'
    pion = 'p'
    wieza = 'w'
    skoczek = 's'
    goniec = 'g'
    krolowa = 'q'
    krol = 'k'
    mozliwe ruchy ='*'
    mozliwe bicia = 'x'
    */
    //puste pole = 0 lub 1 -> czarny 0, bialy 1

boardstate moves(Vector2i v, boardstate board,int initialstate){
    boardstate moves;
    int kontabx[8]={1,1,-1,-1,2,2,-2,-2};
    int kontaby[8]={2,-2,2,-2,1,-1,1,-1};
    int krolx[8]={1,1,-1,-1,0,0,1,-1};
    int kroly[8]={1,-1,1,-1,1,-1,0,0};
    int k,kx,ky;
    moves.clear();
    switch(board.tab[v.x][v.y])
    {
    case 'p':
        if(v.x<7){
            if (board.tab[v.x+1][v.y]=='0'){
                moves.tab[v.x+1][v.y]='*';
                if (initialstate){
                    if (board.tab[v.x+2][v.y]=='0')
                        moves.tab[v.x+2][v.y]='*';
                }
            }   
            if(v.y>0){
                if (turn(board.tab[v.x+1][v.y-1])!='0' && turn(board.tab[v.x+1][v.y-1])!=turn(board.tab[v.x][v.y]))
                    moves.tab[v.x+1][v.y-1]='x';
            }
            if(v.y<7){
                if (turn(board.tab[v.x+1][v.y+1])!=turn(board.tab[v.x][v.y]) && turn(board.tab[v.x+1][v.y+1])!='0')
                    moves.tab[v.x+1][v.y+1]='x';
            }
        }
        break;
    case 'P':
        if(v.x>0){
            if (board.tab[v.x-1][v.y]=='0'){
                moves.tab[v.x-1][v.y]='*';
                if (initialstate){
                    if (board.tab[v.x-2][v.y]=='0')
                        moves.tab[v.x-2][v.y]='*';
                }
            }
            if(v.y>0){
                if (turn(board.tab[v.x-1][v.y-1])!='0' && turn(board.tab[v.x-1][v.y-1])!=turn(board.tab[v.x][v.y]))
                    moves.tab[v.x-1][v.y-1]='x';
            }
            if(v.y<7){
                if (turn(board.tab[v.x-1][v.y+1])!='0' && turn(board.tab[v.x-1][v.y+1])!=turn(board.tab[v.x][v.y]))
                    moves.tab[v.x-1][v.y+1]='x';
            }
        }
        break;
    case 'w':   case 'W':
        for (int i=4;i<8;i++){
            kx=krolx[i];
            ky=kroly[i];
            while (v.x+kx<8 && v.y+ky<8 && v.x+kx>=0 && v.y+ky>=0){
                if (board.tab[v.x+kx][v.y+ky]=='0')
                    moves.tab[v.x+kx][v.y+ky]='*';
                else if (board.tab[v.x+kx][v.y+ky]!='0' && turn(board.tab[v.x+kx][v.y+ky])!=turn(board.tab[v.x][v.y])){
                    moves.tab[v.x+kx][v.y+ky]='x';
                    break;
                }
                else break;
                kx+=krolx[i];
                ky+=kroly[i];
            }
        }
        break;
    case 's':   case 'S':
        for (int i=0;i<8;i++){
            if (v.x+kontabx[i]<8 && v.y+kontaby[i]<8 && v.x+kontabx[i]>=0 && v.y+kontaby[i]>=0){
                if (board.tab[v.x+kontabx[i]][v.y+kontaby[i]]=='0')
                    moves.tab[v.x+kontabx[i]][v.y+kontaby[i]]='*';
                if (board.tab[v.x+kontabx[i]][v.y+kontaby[i]]!='0' && turn(board.tab[v.x+kontabx[i]][v.y+kontaby[i]])!=turn(board.tab[v.x][v.y]))
                    moves.tab[v.x+kontabx[i]][v.y+kontaby[i]]='x';
            }
        }
        break;
    case 'g':   case 'G':
        for (int i=0;i<4;i++){
            kx=krolx[i];
            ky=kroly[i];
            while (v.x+kx<8 && v.y+ky<8 && v.x+kx>=0 && v.y+ky>=0){
                if (board.tab[v.x+kx][v.y+ky]=='0')
                    moves.tab[v.x+kx][v.y+ky]='*';
                else if (board.tab[v.x+kx][v.y+ky]!='0' && turn(board.tab[v.x+kx][v.y+ky])!=turn(board.tab[v.x][v.y])){
                    moves.tab[v.x+kx][v.y+ky]='x';
                    break;
                }
                else break;
                kx+=krolx[i];
                ky+=kroly[i];
            }
        }
        break;
    case 'q':   case 'Q':

        for (int i=0;i<8;i++){
            kx=krolx[i];
            ky=kroly[i];
            while (v.x+kx<8 && v.y+ky<8 && v.x+kx>=0 && v.y+ky>=0){
                if (board.tab[v.x+kx][v.y+ky]=='0')
                    moves.tab[v.x+kx][v.y+ky]='*';
                else if (board.tab[v.x+kx][v.y+ky]!='0' && turn(board.tab[v.x+kx][v.y+ky])!=turn(board.tab[v.x][v.y])){
                    moves.tab[v.x+kx][v.y+ky]='x';
                    break;
                }
                else break;
                kx+=krolx[i];
                ky+=kroly[i];
            }
        }

        break;
    case 'k':   case 'K':
        for (int i=0;i<8;i++){
            if (v.x+krolx[i]<8 && v.y+kroly[i]<8 && v.x+krolx[i]>=0 && v.y+kroly[i]>=0){
                if (board.tab[v.x+krolx[i]][v.y+kroly[i]]=='0')
                    moves.tab[v.x+krolx[i]][v.y+kroly[i]]='*';
                if (board.tab[v.x+krolx[i]][v.y+kroly[i]]!='0' && turn(board.tab[v.x+krolx[i]][v.y+kroly[i]])!=turn(board.tab[v.x][v.y]))
                    moves.tab[v.x+krolx[i]][v.y+kroly[i]]='x';
            }
        }
        break;
    }
    return moves;
}
void boardstate::drawmoves(RenderWindow& window){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (tab[i][j]=='*'){
                kwadrat sqr(to_vector2f({i*boxWidth,j*boxHeight}),5);
                sqr.draw(window);
            }
            if (tab[i][j]=='x'){
                kwadrat sqr(to_vector2f({i*boxWidth,j*boxHeight}),6);
                sqr.draw(window);
            }
        }
    }
}
Vector2f to_vector2f(Vector2i v){
    return {static_cast<float>(v.x),static_cast<float>(v.y)};
}
Vector2i to_vector2i(Vector2f v){
    return {static_cast<int>(v.x),static_cast<int>(v.y)};
}
    kwadrat::kwadrat(Vector2f v,int c){
        box.setPosition(v.x,v.y);
        box.setSize(to_vector2f({boxWidth,boxHeight}));
        if (c==1) box.setFillColor(Color::Black);
        else if (!c) box.setFillColor(Color::White); 
        else if (c==3) box.setFillColor(Color::Blue);
        else if (c==4) box.setFillColor(Color::Green);
        else if (c==5) box.setFillColor(Color::Yellow);
        else if (c==6) box.setFillColor(Color::Red);
    }
    void kwadrat::draw(RenderWindow& window){
        window.draw(box);
        //(*zawartosc).draw(window);
    }
    void kwadrat::move(Vector2f v){
        box.setPosition(v);
    }
    void plansza::printtab(){
    for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                cout<<actualboardstate.tab[i][j];
        }
        cout<<endl;
    }
    }
    plansza::plansza(){
        int s=0;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                tab.emplace_back(to_vector2f({i*boxWidth,j*boxHeight}),(i+j)%2);
                if (actualboardstate.tab[i][j]!='0'){
                    figtab.emplace_back(to_vector2f({i,j}),actualboardstate.tab[i][j]);
                    postab[i][j]=s++;
                }
                else postab[i][j]=-1;
            }
        }
    }
    void plansza::draw(RenderWindow& window){
        for (int i=0;i<tab.size();i++){
            tab[i].draw(window);
        }
    }
    void plansza::figdraw(RenderWindow& window){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (postab[i][j]>=0){
                    int k=postab[i][j];
                    if(figtab[k].typ)
                        figtab[k].draw(window,to_vector2f({i,j}),actualboardstate.tab[i][j]);
                }
            }
        }
    }

    char plansza::checkpiece(Vector2i v){
        return actualboardstate.checkpiece(v);
    }
    bool plansza::ruch(Vector2i f, Vector2i t,RenderWindow& window){
        if (postab[f.x][f.y]>=0){
            if (postab[t.x][t.y]>=0){
                if(actualboardstate.tab[t.x][t.y]=='K' && turn(actualboardstate.tab[f.x][f.y])=='a'){
                    write_text(window,"Mate",to_vector2f({windowWidth+10,200}));
                    write_text(window,"White",to_vector2f({windowWidth+10,300}));
                    write_text(window,"Won",to_vector2f({windowWidth+10,400}));
                    mat=1;
                }
                if(actualboardstate.tab[t.x][t.y]=='k' && turn(actualboardstate.tab[f.x][f.y])=='A'){
                    write_text(window,"Mate",to_vector2f({windowWidth+10,200}));
                    write_text(window,"Black",to_vector2f({windowWidth+10,300}));
                    write_text(window,"Won",to_vector2f({windowWidth+10,400}));
                    mat=1;
                }
            }
            if(figtab[postab[f.x][f.y]].typ=='p' && t.x==7){
                figtab[postab[f.x][f.y]].toqueen();
                actualboardstate.tab[f.x][f.y]='q';
            }
            if(figtab[postab[f.x][f.y]].typ=='P' && t.x==0){
                figtab[postab[f.x][f.y]].toqueen();
                actualboardstate.tab[f.x][f.y]='Q';
            }
            figtab[postab[f.x][f.y]].move(to_vector2f(t));
            if (postab[t.x][t.y]>=0){
                actualboardstate.tab[t.x][t.x]='0';
                figtab[postab[t.x][t.y]].move(to_vector2f({-100,-100}));
            }
            postab[t.x][t.y]=postab[f.x][f.y];
            postab[f.x][f.y]=-1;
        }
        else return false;
        //if (postab[t.x][t.y]>0)
        //    figtab[postab[t.x][t.y]].move(to_vector2f(f));
        //swap(postab[f.x][f.y],postab[t.x][t.y]);
        actualboardstate.ruch(f,t);
        return true;
    }


    int plansza::return_state(Vector2i v)
    {
        int a=figtab[postab[v.x][v.y]].initialstate;
        return a;
    }

    void plansza::change_state(Vector2i v,int n)
    {
        figtab[postab[v.x][v.y]].initialstate=n;
    }
    int plansza::szach(){
        Vector2i krolw;
        Vector2i krolb;
        int szachw=0,szachb=0;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (postab[i][j]>=0){
                    if(actualboardstate.tab[i][j]=='K')
                        krolb={i,j};
                    if (actualboardstate.tab[i][j]=='k')
                        krolw={i,j};
                }
            }
        }
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (postab[i][j]>=0){
                    if(actualboardstate.tab[i][j]!='K' && turn('K')==turn(actualboardstate.tab[i][j]))
                        if (moves({i,j},actualboardstate,return_state({i,j})).tab[krolw.x][krolw.y]=='x')
                            szachw=1;
                    if(actualboardstate.tab[i][j]!='k' && turn('k')==turn(actualboardstate.tab[i][j]))
                        if (moves({i,j},actualboardstate,return_state({i,j})).tab[krolb.x][krolb.y]=='x')
                            szachb=1;
                }
            }
        }
        return szachb+szachw;
        
    }
    void write_text(RenderWindow& okno,string tekst,Vector2f pos){
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text(tekst, font, 50);
        text.setPosition(pos);
        okno.draw(text);
    }
    