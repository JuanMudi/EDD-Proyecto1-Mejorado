//
// Created by mudx2 on 14/02/23.
//

#include "Comandos.h"
#include <iostream>
#include <cstring>
#include <list>


char *Comandos::getInput() const {
    return input;
}

void Comandos::setInput(char *input) {
    Comandos::input = input;
}
void Comandos::iniciar_mapa() {
    switchmap["cargar_comandos"] = 1;
    switchmap["cargar_elementos"] = 2;
    switchmap["agregar_movimiento"] = 3;
    switchmap["agregar_analisis"] = 4;
    switchmap["agregar_elemento"] = 5;
    switchmap["guardar"] = 6;
    switchmap["simular_comandos"] = 7;
    switchmap["salir"] = 8;
    switchmap["ubicar_elementos"] = 9;
    switchmap["en_cuadrante"] = 10;
    switchmap["crear_mapa"] = 11;
    switchmap["ruta_mas_larga"] = 12;
    switchmap["ayuda"] = 13;
}
void Comandos::procesamiento(){
    char* token;
    token = std::strtok(input, " ");
    while (token!=NULL) {
        parametros.push_back(token);
        token = (std::strtok(NULL, " "));

    }
}
void Comandos::seleccion() {
    switch(switchmap.find(std::string(parametros[0]))->second)
    {
        case 1:
            cargar_comandos();
            break;
        case 2:
            cargar_elementos();
            break;
        case 3:
            agregar_movimiento();
            break;
        case 4:
            agregar_analisis();
            break;
        case 5:
            agregar_elemento();
            break;
        case 6:
            guardar();
            break;
        case 7:
            simular_comandos();
            break;
        case 8:
            salir();
            break;
        case 9:
            ubicar_elementos();
            break;
        case 10:
            en_cuadrante();
            break;
        case 11:
            crear_mapa();
            break;
        case 12:
            ruta_mas_larga();
            break;
        case 13:
            ayuda();
            break;
        default:
            std::cout << "No existe el comando" << std::endl;
            break;
    }

}
int Comandos::cargar_comandos()
{}
int Comandos::cargar_elementos(){}
int Comandos::agregar_movimiento(){}
int Comandos::agregar_analisis(){}
int Comandos::agregar_elemento(){}
int Comandos::guardar(){}
int Comandos::simular_comandos(){}
int Comandos::salir(){}
int Comandos::ubicar_elementos(){}
int Comandos::en_cuadrante(){}
int Comandos::crear_mapa(){}
int Comandos::ruta_mas_larga(){}
int Comandos::ayuda(){}

int main()
{
    char *input = new char[100];
    Comandos comandos;
    std::cout << "$ ";
    std::cin.getline(input, 100);
    comandos.setInput(input);
    comandos.procesamiento();

}

