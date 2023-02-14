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
    seleccion();
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
int Comandos::cargar_comandos(){
    if(parametros[1]==NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[2]!=NULL){
        std::cout << "SE HAN INGRESADO MAS DE UN PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    std::cout << "COMANDO VALIDO" << std::endl;
    return 0;
}
int Comandos::cargar_elementos(){
    if(parametros[1]==NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[2]!=NULL){
        std::cout << "SE HAN INGRESADO MAS DE UN PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    std::cout << "COMANDO VALIDO" << std::endl;
    return 0;
}
int Comandos::agregar_movimiento(){
    if(parametros[3] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[4]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }

    return 0;
}
int Comandos::agregar_analisis(){
    if(parametros[2] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[4]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::agregar_elemento(){
    if(parametros[5] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[6]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::guardar(){
    if(parametros[2] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[3]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::simular_comandos(){
    if(parametros[2] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[3]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::salir(){
    if(parametros[1] != NULL){
        std::cout << "SE HAN INGRESASDO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::ubicar_elementos(){
    if(parametros[1] != NULL){
        std::cout << "SE HAN INGRESASDO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::en_cuadrante(){
    if(parametros[4] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[5]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    
    return 0;
}
int Comandos::crear_mapa(){
    if(parametros[1] == NULL){
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return 1;
    }
    if(parametros[2]!= NULL){
        std::cout << "SE HAN INGRESADO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::ruta_mas_larga(){
    if(parametros[1] != NULL){
        std::cout << "SE HAN INGRESASDO MAS DE TRES PARAMETROS: ERROR" << std::endl;
        return 1;
    }
    return 0;
}
int Comandos::ayuda(){
    return 0;
}

int main()
{
    char *input = new char[100];
    Comandos comandos;
    std::cout << "$ ";
    std::cin.getline(input, 100);
    comandos.iniciar_mapa();
    comandos.setInput(input);
    comandos.procesamiento();

}

