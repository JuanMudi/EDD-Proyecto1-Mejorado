//
// Created by J_mud on 22/02/2023.
//
#include "Comandos.h"
int main()
{
    //Cadena de caracteres para recibir los comandos.
    char *input = new char[100];
    //Instancia de la clase Comandos
    Comandos comandos;
    //Inicializacion del Map para ejecutar los comandos
    comandos.iniciar_mapa();
    while(true){
        std::cout << "$ ";
        //Recepcion de datos de entrada
        std::cin.getline(input, 100);
        //Setter de los comandos
        comandos.setInput(input);
        //Procesamiento de comandos
        comandos.procesamiento();
    }
}