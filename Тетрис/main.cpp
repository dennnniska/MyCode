#include <SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
#include<conio.h>
//400 360
using namespace sf;
using namespace std;
const int h = 20;
const int w = 10;
const int q = 30;
const int kolfig = 7;
const int kolcolor = 7;
struct figura{
    int y[4];
    int x[4];
};
class List{
private:
    class Node{
    public:
        Node*adr;
        int data;
        int color;
        Node(int data = 0, Node* adr = nullptr){
            this->color= color;
            this->data = data;
            this->adr = adr;
        }
    };
    Node *head;
    int size;
public:
    List(int size = 0);
    ~List();
    void push_back(int values = 0);
    void pop_front();
    int getSize();

};

int List::getSize(){
    return size;
}


List::List(int size){
    this->size = size;
    head = nullptr;
    Node *cur = head;
    for(int i = 0; i < size; i++){
        cur = new Node;
        cur = cur->adr;
    }
}
void List::push_back(int values){
    Node *cur = head;
    while(cur != nullptr){
        cur = cur->adr;
    }
    cur = new Node(values);
    size++;
}
void List::pop_front(){
    if(size > 0){
        Node *cur = head->adr;
        delete head;
        head = cur;
        size--;
    }
}
List::~List(){
    if(size > 0){
        Node *cur = head;
        while(head != nullptr){
            head = head->adr;
            delete cur;
            cur = head;
        }
    }
}
class figu{
public:
    Image figimage;
    Texture figtexture;
    Sprite figsprite;
    int x;
    int y;
    int color;
    figu(int color = 0, int x = 0, int y = 0){
        figimage.loadFromFile("image/fig.jpg");
        figtexture.loadFromImage(figimage);
        figsprite.setTexture(figtexture);
        figsprite.setTextureRect(IntRect(color*q, 0, q, q));
        this->color = color;
        this->x = x;
        this->y = y;
    }
    void create(int color = 0, int x = 0, int y = 0){
        figsprite.setTextureRect(IntRect(color*q, 0, q, q));
        figsprite.setPosition(x*q, y*q);
        this->color = color;
        this->x = x;
        this->y = y;
    }
    void drow(){
        figsprite.setPosition(x*q, y*q);
    }
};
int main()
{
    ifstream scormaxfilein("scormax.txt");
    int scormax;
    scormaxfilein >> scormax;
    scormaxfilein.close();
    ofstream scormaxfile("scormax.txt", ios::trunc);
    int speed = 500;
    figura fig[kolfig];
    fig[0] = {
        1, 1, 0, 0,
        5, 6, 6, 5
    };
    fig[1] = {
        0, 0, 0, 0,
        4, 5, 6, 7
    };
    fig[2] = {
        1, 1, 0, 0,
        5, 6, 5, 4
    };
    fig[3] = {
        2, 2, 1, 0,
        5, 6, 5, 5
    };
    fig[4] = {
        1, 0, 0, 0,
        6, 6, 7, 5
    };
    fig[5] = {
        2, 2, 1, 0,
        4, 5, 5, 5
    };
    fig[6] = {
        1, 1, 0, 0,
        4, 5, 5, 6
    };
    RenderWindow window(VideoMode(q*10+ 300,q * 20), "123.ru");
    Image poleimage;
    poleimage.loadFromFile("image/pole.jpg");
    Texture poletexture;
    poletexture.loadFromImage(poleimage);
    Sprite polesprite;
    polesprite.setTexture(poletexture);

    Image fonimage;
    fonimage.loadFromFile("image/fon.jpg");
    Texture fontexture;
    fontexture.loadFromImage(fonimage);
    Sprite fonsprite;
    fonsprite.setTexture(fontexture);

    Image numbersimage;
    numbersimage.loadFromFile("image/numbers.jpg");
    Texture numberstexture;
    numberstexture.loadFromImage(numbersimage);
    Sprite numberssprite;
    numberssprite.setTexture(numberstexture);

    Image gameoverimage;
    gameoverimage.loadFromFile("image/gameover.jpg");
    Texture gameovertexture;
    gameovertexture.loadFromImage(gameoverimage);
    Sprite gameoversprite;
    gameoversprite.setTexture(gameovertexture);
    gameoversprite.setPosition(30, 90);

    Clock clock;
    List pred;
    bool gameover = false;
    int scor = 0;
    float perem = 0;
    float timemove = 0;
    bool movee = true;
    int turn;
    int polee[20][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 20; j++)
            polee[j][i] = 0;
    int colorfig = rand()%kolcolor;
    int randfig = rand()%kolfig;
    int randfignext = rand()%kolfig;
    int colorfignext = rand()%kolcolor;
    figu figuranext[4];
    figu figuranew[4];
    for(int i = 0; i < 4; i++){
        figuranew[i].create(colorfig, fig[randfig].x[i], fig[randfig].y[i]);
    }
    for(int i = 0; i < 4; i++){
        figuranext[i].create(colorfignext, fig[randfignext].x[i], fig[randfignext].y[i]);
        figuranext[i].x+=9;
        figuranext[i].y+=3;
        figuranext[i].drow();
    }
    turn = 0;
    float staticc = false;
    bool OK;
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                window.close();
        }
        if(!gameover){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;


        if(staticc){
            turn = 0;
            randfig = randfignext;
            colorfig = colorfignext;
            colorfignext = rand()%kolcolor;
            randfignext = rand()%kolfig;
            if(pred.getSize() > 5){
                pred.pop_front();
            }
            staticc = false;
            for(int i = 0; i < 4; i++){
                figuranew[i].create(colorfig, fig[randfig].x[i], fig[randfig].y[i]);
            }
            for(int i = 0; i < 4; i++){
        figuranext[i].create(colorfignext, fig[randfignext].x[i], fig[randfignext].y[i]);
        figuranext[i].x+=9;
        figuranext[i].y+=3;
        figuranext[i].drow();
    }
        }
        perem+= time;
        if(perem > speed){
            perem = 0;
            for(int i = 0; i < 4; i++){
                if(figuranew[i].y >= 19 || polee[figuranew[i].y + 1][figuranew[i].x] != 0){
                    staticc = true;
                }
            }
            if(!staticc){
                for(int i = 0; i < 4; i++){
                    figuranew[i].y++;
                }
            }
            if(staticc){
                for(int i = 0; i < 4; i++){
                    polee[figuranew[i].y][figuranew[i].x] = figuranew[i].color+1;
                }
            }
        }
        if(!staticc)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            OK = true;
            for(int i = 0; i < 4; i++){
                if(figuranew[i].x - 1 < 0){
                    OK = false;
                    break;
                }
                else
                if(polee[figuranew[i].y][figuranew[i].x-1] != 0){
                    OK = false;
                    break;
                }
            }
            if(OK && movee){
                for(int i = 0; i < 4; i++){
                    figuranew[i].x--;
                }
                movee = false;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
            gameover = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            if(movee && speed >= 200){
                speed-=100;
                movee = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            if(movee){
                speed+=100;
                movee = false;
            }
        }
        if(!staticc)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            OK = true;
            for(int i = 0; i < 4; i++){
                if(figuranew[i].x + 1 >= 10 ){
                    OK = false;
                    break;
                }
                else
                if(polee[figuranew[i].y][figuranew[i].x+1] != 0){
                    OK = false;
                    break;
                }
            }
            if(OK&& movee){
                for(int i = 0; i < 4; i++){
                    figuranew[i].x++;
                }
                movee = false;
            }
        }
        if(!staticc)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && movee){
            OK = true;
            if(randfig == 1){
                if(turn == 0){
                    for(int i = 0; i < 4; i++)
                        if(polee[figuranew[i].y - 1][figuranew[i].x] || polee[figuranew[i].y-2][figuranew[i].x] || polee[figuranew[i].y-3][figuranew[i].x]){
                            OK = false;
                            break;
                        }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[2].x--;
                        figuranew[3].x-=2;
                        figuranew[1].y--;
                        figuranew[2].y-=2;
                        figuranew[3].y-=3;
                        turn = 1;
                        movee = false;
                    }
                }
                else{
                    for(int i = 0; i < 4; i++)
                        if(polee[figuranew[i].y][figuranew[i].x+1] || polee[figuranew[i].y][figuranew[i].x+2] || polee[figuranew[i].y][figuranew[i].x - 1]){
                            OK = false;
                            break;
                        }
                        else{
                            if(figuranew[i].x - 1 < 0 || figuranew[i].x + 2 >= 10){
                            OK = false;
                            break;
                        }
                        }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[2].x++;
                        figuranew[3].x+=2;
                        figuranew[1].y++;
                        figuranew[2].y+=2;
                        figuranew[3].y+=3;
                        turn = 0;
                        movee = false;
                    }
                }
            }
            if(randfig == 2){
                if(turn == 0){
                    if(polee[figuranew[1].y-1][figuranew[1].x] !=0 || polee[figuranew[1].y-2][figuranew[1].x]!=0
                       || polee[figuranew[2].y-1][figuranew[2].x]!=0  || polee[figuranew[3].y-1][figuranew[3].x]!=0  || polee[figuranew[3].y+1][figuranew[3].x]!=0 ){
                            OK = false;
                        }
                    if(OK){
                        figuranew[0].y--;
                        figuranew[1].y-=2;
                        figuranew[3].y+=1;
                        figuranew[1].x--;
                        figuranew[2].x--;
                        movee = false;
                        turn = 1;
                    }
                }
                else{
                    if(polee[figuranew[0].y+1][figuranew[0].x]!=0  || polee[figuranew[0].y+1][figuranew[0].x+1]!=0  ||polee[figuranew[0].y][figuranew[0].x+1]!=0  ||
                       polee[figuranew[1].y][figuranew[1].x+1]!=0  ||polee[figuranew[2].y][figuranew[2].x-1]!=0  ||polee[figuranew[3].y][figuranew[3].x-1]!=0  ){
                            OK = false;
                        }
                        if(figuranew[1].x + 1 >= 10){
                            OK = false;
                        }
                    if(OK){
                        figuranew[0].y++;
                        figuranew[1].y+=2;
                        figuranew[3].y-=1;
                        figuranew[1].x++;
                        figuranew[2].x++;
                        movee = false;
                        turn = 0;
                    }
                }
            }
            if(randfig == 3){
                OK = true;
                if(turn == 0){
                    for(int i = figuranew[3].x; i < figuranew[3].x + 3; i++)
                        for(int j = figuranew[3].y-1; j < figuranew[3].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[3].x - 1 < 0){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[3].x--;
                        figuranew[1].y--;
                        figuranew[2].y++;
                        figuranew[3].y+=2;
                        movee = false;
                        turn = 1;
                    }
                }
                else
                if(turn == 1){
                    for(int i = figuranew[1].x - 1; i < figuranew[1].x + 1; i++)
                        for(int j = figuranew[1].y-1; j < figuranew[1].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[0].y-=2;
                        figuranew[1].y--;
                        figuranew[2].y--;
                        figuranew[1].x--;
                        figuranew[2].x++;
                        figuranew[3].x+=2;
                        movee = false;
                        turn = 2;
                    }
                }
                else
                if(turn == 2){
                    for(int i = figuranew[1].x - 1; i < figuranew[1].x + 2; i++)
                        for(int j = figuranew[1].y; j < figuranew[1].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[1].x - 1 < 0){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x-=2;
                        figuranew[1].x--;
                        figuranew[2].x--;
                        figuranew[0].y++;
                        figuranew[1].y+=2;
                        figuranew[3].y--;
                        turn = 3;
                        movee = false;
                    }
                }
                else
                if(turn == 3){
                    for(int i = figuranew[0].x; i < figuranew[0].x + 3; i++)
                        for(int j = figuranew[0].y-1; j < figuranew[0].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[1].x+=2;
                        figuranew[3].x--;
                        figuranew[0].y++;
                        figuranew[3].y--;
                        turn = 0;
                        movee = false;
                    }
                }
            }
            if(randfig == 4){
                OK = true;
                if(turn == 0){
                    for(int i = figuranew[3].x; i < figuranew[3].x + 3; i++)
                        for(int j = figuranew[3].y-1; j < figuranew[3].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[2].x--;
                        figuranew[3].x++;
                        figuranew[0].y--;
                        figuranew[2].y--;
                        figuranew[3].y++;
                        movee = false;
                        turn = 1;
                       }
                }
                else
                if(turn == 1){
                    for(int i = figuranew[2].x-1; i < figuranew[2].x + 2; i++)
                        for(int j = figuranew[3].y; j < figuranew[3].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[2].x-1 < 0){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[2].x--;
                        figuranew[3].x++;
                        figuranew[1].y++;
                        figuranew[2].y+=2;
                        turn = 2;
                        movee = false;
                    }
                }
                else
                if(turn == 2){
                    for(int i = figuranew[0].x-1; i < figuranew[0].x + 2; i++)
                        for(int j = figuranew[0].y - 1; j < figuranew[0].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[2].x++;
                        figuranew[3].x--;
                        figuranew[1].y--;
                        figuranew[3].y-=2;
                        turn = 3;
                        movee = false;
                    }
                }
                else
                if(turn == 3){
                    for(int i = figuranew[3].x-1; i < figuranew[3].x + 2; i++)
                        for(int j = figuranew[3].y; j < figuranew[3].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[3].x+1>=20){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[2].x++;
                        figuranew[3].x--;
                        figuranew[0].y++;
                        figuranew[2].y--;
                        figuranew[3].y++;
                        turn =0;
                        movee = false;
                    }
                }
            }
            if(randfig == 6){
                OK = true;
                if(turn == 0){
                    if(polee[figuranew[0].y-1][figuranew[0].x] ||polee[figuranew[0].y-2][figuranew[0].x] ||polee[figuranew[2].y-1][figuranew[2].x] ||
                    polee[figuranew[3].y-1][figuranew[3].x] ||polee[figuranew[3].y+1][figuranew[3].x]){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x++;
                        figuranew[2].x--;
                        figuranew[3].x-=2;
                        figuranew[1].y--;
                        figuranew[3].y--;
                        turn = 1;
                        movee = false;
                    }
                }
                else{
                    for(int i = figuranew[3].x; i < figuranew[3].x + 3; i++)
                        for(int j = figuranew[3].y; j < figuranew[3].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[3].x+2 >= 10){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[2].x++;
                        figuranew[3].x+=2;
                        figuranew[1].y++;
                        figuranew[3].y++;
                        turn = 0;
                        movee = false;
                    }
                }
            }
            if(randfig == 5){
                OK = true;
                if(turn == 0){
                    for(int i = figuranew[3].x - 1; i < figuranew[3].x + 2; i++)
                        for(int j = figuranew[3].y; j < figuranew[3].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[3].x+1 >= 10){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x+=2;
                        figuranew[1].x++;
                        figuranew[3].x--;
                        figuranew[1].y--;
                        figuranew[3].y++;
                        turn = 1;
                        movee = false;
                    }
                }
                else
                if(turn == 1){
                    for(int i = figuranew[3].x ; i < figuranew[3].x + 3; i++)
                        for(int j = figuranew[3].y - 1; j < figuranew[3].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[1].x-=2;
                        figuranew[2].x--;
                        figuranew[0].y-=2;
                        figuranew[1].y--;
                        figuranew[3].y++;
                        turn = 2;
                        movee = false;
                    }
                }
                else
                if(turn == 2){
                    for(int i = figuranew[1].x ; i < figuranew[1].x + 3; i++)
                        for(int j = figuranew[1].y; j < figuranew[1].y + 3; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(figuranew[0].x+1 >=10){
                        OK = false;
                    }
                    if(OK){
                        figuranew[0].x--;
                        figuranew[2].x++;
                        figuranew[3].x+=2;
                        figuranew[0].y++;
                        figuranew[1].y+=2;
                        figuranew[2].y++;
                        turn = 3;
                        movee = false;
                    }
                }
                else
                if(turn == 3){
                    for(int i = figuranew[0].x ; i < figuranew[0].x + 3; i++)
                        for(int j = figuranew[0].y - 1; j < figuranew[0].y + 2; j++)
                        if(polee[j][i] != 0 && ((i != figuranew[0].x && j!= figuranew[0].y) || (i != figuranew[1].x && j!= figuranew[1].y)
                                                || (i != figuranew[2].x && j!= figuranew[2].y) || (i != figuranew[3].x && j!= figuranew[3].y)))
                        {
                        OK = false;
                        break;
                       }
                    if(OK){
                        figuranew[1].x++;
                        figuranew[3].x--;
                        figuranew[0].y++;
                        figuranew[2].y--;
                        figuranew[3].y-=2;
                        turn = 0;
                        movee = false;
                    }
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && movee){
            /*OK = true;
            movee = false;
            while(OK){
                for(int i = 0; i < 4; i++){
                    if(figuranew[i].y + 1 >= 20 || polee[figuranew[i].y + 1][figuranew[i].x] != 0){
                        OK = false;
                        break;
                    }
                }
            if(OK){
                for(int i = 0; i < 4; i++){
                    figuranew[i].y++;
                }
                scor++;
            }
            }*/
            perem+= time*2;

        }
        if(!movee){
            timemove +=time;
            if(timemove > max(speed/2,200)){
                movee = true;
                timemove = 0;
            }
        }
        int zz = 0;
        bool stuct;
    for(int i = 0; i < h; i++){
        stuct = true;
        for(int j = 0; j < w; j++){
            if(polee[i][j] == 0){
                stuct = false;
                break;
                }
        }
        if(stuct){
            zz++;
            for(int p = i - 1; p >= 0; p--)
                for(int j = 0; j < w; j++)
                    polee[p+1][j] = polee[p][j];
        }
    }
    if(zz == 1) scor+=100;
    if(zz == 2) scor+=300;
    if(zz == 3) scor+=900;
    if(zz == 4) scor += 3600;
    for(int i = 0; i < w; i ++)
        if(polee[0][i] != 0){
            gameover = true;
            break;
        }
        }
        else{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            break;
        }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::R))){
                gameover = false;
                scor = 0;
                for(int i = 0; i < 10; i++)
                for(int j = 0; j < 20; j++)
                    polee[j][i] = 0;
            }
            staticc = true;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B))){
            scormax = 0;
        }
        if(!gameover){
            scormax = max(scormax, scor);
        }
        window.clear();
        window.draw(fonsprite);
        int scor1 = scor;
        int koll = 0;
        int numb;
        do{
            numb = scor1 % 10;
            numberssprite.setTextureRect(IntRect(numb*20, 0, 20, 30));
            numberssprite.setPosition(500 - koll*20, 300);
            window.draw(numberssprite);
            scor1/=10;
            koll++;
        }while(scor1 != 0);
        scor1 = scormax;
        koll = 0;
        do{
            numb = scor1 % 10;
            numberssprite.setTextureRect(IntRect(numb*20, 0, 20, 30));
            numberssprite.setPosition(500 - koll*20, 400);
            window.draw(numberssprite);
            scor1/=10;
            koll++;
        }while(scor1 != 0);
        for(int i = 0; i < 20; i++)
        for(int j = 0; j < 10; j++){
            polesprite.setTextureRect(IntRect(polee[i][j]*q, 0, q, q));
            polesprite.setPosition(j*q, i*q);
            window.draw(polesprite);
        }
        for(int i = 0; i < 4; i++){
            figuranew[i].drow();
            window.draw(figuranew[i].figsprite);
        }
        if(gameover){
            window.draw(gameoversprite);
        }
        for(int i = 0; i < 4; i++){
            window.draw(figuranext[i].figsprite);
        }
        window.display();
    }
    scormax = max(scormax, scor);
    scormaxfile << scormax;
    scormaxfile.close();
    return 0;
}
