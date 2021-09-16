#include "putBox.hpp"
#include "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

putBox::putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a){
    this -> x0 = x0;
    this -> x1 = x1;
    this -> y0 = y0;
    this -> y1 = y1;
    this -> z0 = z0;
    this -> z1 = z1;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

void putBox::draw(Sculptor&s){
    s.setColor(this -> r, this -> g, this -> b, this -> a);  
    s.putBox(this -> x0, this -> x1, this -> y0, this -> y1, this -> z0, this -> z1);
}
