#include "Interpretador.hpp"
#include "FiguraGeometrica.hpp"
#include "putVoxel.hpp"
#include "cutVoxel.hpp"
#include "putBox.hpp"
#include "cutBox.hpp"
#include "putSphere.hpp"
#include "cutSphere.hpp"
#include "putEllipsoid.hpp"
#include "cutEllipsoid.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


Interpretador::Interpretador(){
}


std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename){
std::vector<FiguraGeometrica*> figs;
    std:: ifstream fin;
    std:: string s, token;
    std:: stringstream ss;
 	
	fin.open(filename.c_str());
//Verificar se o fluxo foi realmente aberto de forma correta
if(!fin.is_open())
{
	std:: cout<<"nao abriu "<< filename << std:: endl;
	exit(0);
}

//}
 
    while(fin.good()){
        // fin >> s
		std::getline(fin, s); 
        if(fin.good()){
         //lança a string s no fluxo ss
		    ss.clear();
            ss.str(s);
            ss >> token;
            //realiza o parsing dos tokens
			if(ss.good()){
                //dimensoes da tela
				if (token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                }
                //usuario define o brush
				else if(token.compare("putVoxel")==0){
                    int x ,y,z;
                    float r,g,b,a;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new putVoxel(x, y, z, r, g, b, a));
                }
                else if(token.compare("cutVoxel")==0){
                    int x,y,z;
                    ss >> x >> y >> z;
                    figs.push_back(new cutVoxel(x, y, z));
                }
                else if(token.compare("putBox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    float r, g, b, a;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if(token.compare("cutBox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putSphere")==0){
                    int xc, yc, zc, e;
                    float r, g, b, a;
                    ss >> xc >> yc >> zc >> e >> r >> g >> b >> a;
                    figs.push_back(new putSphere(xc, yc, zc, e, r, g, b, a));
                }
                else if(token.compare("cutSphere")==0){
                    int xc, yc, zc, e;
                    ss >> xc >> yc >> zc >> e;
                    figs.push_back(new cutSphere(xc, yc, zc, e));
                }
                else if(token.compare("putEllipsoid")==0){
                    int xc, yc, zc, rx, ry, rz;
                    float r, g, b, a;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new putEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                }
                else if(token.compare("cutEllipsoid")==0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figs.push_back(new cutEllipsoid(xc, yc, zc, rx, ry, rz));
                }
            }
        }
    }
    return (figs);
}


int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}
