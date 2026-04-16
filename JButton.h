#ifndef JBUTTON_H_INCLUDED
#define JBUTTON_H_INCLUDED

#include <iostream>
#include <string>
#include <raylib.h>
#include <functional>
using namespace std;

class JButton{

private:
   std::string nome;
    Rectangle pos;
    float H = 10, W = 10;
    Color corButton = BLUE;
    Color corText = BLACK;
    int fontSize = 10;
    bool clic = false;


public:
    JButton(std::string n);
    ~JButton();
    void setColorButton(Color corButton){
        this->corButton = corButton;
    }
    void setColorText(Color corText){
        this->corText = corText;
    }
    void setPos(float X, float Y){
        pos.x = X;
        pos.y = Y;
    }
    bool getClic(){
        this->clic = !this->clic;
        return this->clic;
    }
    void setTamanho(float H , float W  ){
        pos.height = H;
        pos.width = W;
    }
    void setFontSize(int size ){
        this->fontSize = size;
    }
    void setButton(float X, float Y, float height, float width){
        pos.height = height;
        pos.width = width;
        pos.x =X;
        pos.y = Y;
    }
   
    void addButton(){
        DrawRectangleRec(pos, corButton);
        DrawText(nome.c_str(), (pos.x+pos.width*0.25),(pos.y+pos.height*0.3),fontSize,corText );
        
    }

private:
    std::function<void()> evento;

public:
 
    bool verificaClic() {
        Vector2 mouse = GetMousePosition();
        return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                CheckCollisionPointRec(mouse, pos);
              
    }

    void addAcionarEvento(std::function<void()> f) {
        evento = f;
         if(verificaClic()){
            if(evento) evento();
        }
        
    }

};

JButton::JButton(std::string n)
{
    this->nome = n;
}

JButton::~JButton()
{
}
#endif