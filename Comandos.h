//
// Created by mudx2 on 14/02/23.
//

#ifndef EDD_PROYECTO1_LIMPIO_COMANDOS_H
#define EDD_PROYECTO1_LIMPIO_COMANDOS_H
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <cstring>
#include <fstream>
#include "Movimiento.h"
#include "Elemento.h"

class Comandos {
private:
    //Mapa de los comandos
    std::map<std::string,int> switchmap;
    //Vector con los parametros recibidos
    std::vector<char*> parametros;
    //Estructuras lineales para almacenar los datos
    std::queue<Movimiento> cola_comandos;
    std::queue<Elemento> cola_elementos;



    char* input;
public:
    explicit Comandos(const std::queue<Movimiento> &colaComandos);

//Encabezado de las funciones
    char *getInput() const;
    void setInput(char *input);
    void iniciar_mapa();
    void procesamiento();
    int cargar_comandos();
    int cargar_elementos();
    int agregar_movimiento();
    int agregar_analisis();
    int agregar_elemento();
    int guardar();
    int simular_comandos();
    int salir();
    int ubicar_elementos();
    int en_cuadrante();
    int crear_mapa();
    int ruta_mas_larga();
    int ayuda();
    void seleccion();
    bool validar_parametros(int cant_parametros);
};


#endif //EDD_PROYECTO1_LIMPIO_COMANDOS_H
