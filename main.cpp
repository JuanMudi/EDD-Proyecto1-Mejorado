//
// Created by J_mud on 22/02/2023.
//
#include "Comandos.h"
int main()
{
    //Cadena de caracteres para recibir los comandos.
    char *input = new char[100];
    Comandos comandos;
    comandos.iniciar_mapa();
    while(true){
        std::cout << "$ ";
        std::cin.getline(input, 100);
        comandos.setInput(input);
        comandos.procesamiento();
    }
}