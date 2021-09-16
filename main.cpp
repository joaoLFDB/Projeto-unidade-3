#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Sculptor.hpp"
#include "Interpretador.hpp"

int main() 
{
	
	Sculptor *s1;
	
  	Interpretador parser;
	
	std::vector<FiguraGeometrica*> figs;
	
	figs = parser.parse("jogador.txt");
	
	s1= new Sculptor(parser. getDimx(), parser.getDimy(), parser.getDimz());
	
	for(size_t i=0; i<figs.size(); i++)
	{
		std:: cout << "draw\n";
		figs[i]	-> draw(*s1);	
	}
	
	s1->writeOFF((char*)"jogador.off");
	for(size_t i=0; i<figs.size(); i++)
	{
		delete figs[i];
	} 
	
	delete s1;
	return 0;
}
