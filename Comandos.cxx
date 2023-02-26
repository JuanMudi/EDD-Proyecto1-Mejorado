//
// Created by mudx2 on 14/02/23.
//

#include "Comandos.h"
//Getter Input
char *Comandos::getInput() const
{
    return input;
}
//Setter Input
void Comandos::setInput(char *input)
{
    Comandos::input = input;
}
//Inicializar el switchmap con los comandos
void Comandos::iniciar_mapa()
{
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
//Procesar el comando y los parametros dados
void Comandos::procesamiento()
{
    char *token;
    parametros.clear();
    //Tokenizar la cadena de entrada con la funcion std::strtok()
    token = std::strtok(input, " "); 
    while (token != NULL)
    {
        //Uso de vector<> para almacenar los parametros
        parametros.push_back(token);
        token = (std::strtok(NULL, " "));
    }
    seleccion();
}
void Comandos::seleccion()
{
    //Uso de switch-case co el switchmap.find() para determinar el comando a realizar
    switch (switchmap.find(std::string(parametros[0]))->second)
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
bool Comandos::validar_parametros(int cant_parametros) {
    //Validacion de parametros
    if (parametros.size()<= cant_parametros)
    {
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return false;
    }else if (parametros.size()>cant_parametros+1)
    {
        std::cout << "SE HAN INGRESADO MAS PARAMETROS DE LOS REQUERIDOS" << std::endl;
        return false;
    }
    return true;

}
int Comandos::cargar_comandos()
{
    if(validar_parametros(1)==false) return 1;
    cola_comandos.empty();
    //Apertura de archivo
    std::fstream datos(parametros[1], std::ios::in);
    if(datos.fail()) {
        std::cout << parametros[1] << " no se encuentra o no puede leerse." << std::endl;
        datos.close();
        return 1;
    }
    char *inf = new char[100];
    inf[0]='-';
    datos.getline(inf,100);
    if(inf[0] == '\000')
    {
        std::cout << parametros[1] << " no tiene comandos." << std::endl;
        datos.close();
        return 1;
    }
    int i=1;
    while(!datos.eof()){
        cola_comandos.push(inf);
        i++;
        datos.getline(inf,100);
    }
    std::cout << i << " comandos cargados correctamente desde " << parametros[1] << std::endl;
    datos.close();
    return 0;
}

int Comandos::cargar_elementos()
{
    if(validar_parametros(1)==false) return 1;
    cola_elementos.empty();
    //Apertura de archivo
    std::fstream datos(parametros[1], std::ios::in);
    if(datos.fail()) {
        std::cout << parametros[1] << " no se encuentra o no puede leerse." << std::endl;
        datos.close();
        return 1;
    }
    char *inf = new char[100];
    inf[0]='-';
    datos.getline(inf,100);
    if(inf[0] == '\000')
    {
        std::cout << parametros[1] << " no tiene elementos." << std::endl;
        datos.close();
        return 1;
    }
    int i=1;
    while(!datos.eof()){
        cola_elementos.push(inf);
        i++;
        datos.getline(inf,100);
    }
    std::cout << i << " elementos cargados correctamente desde " << parametros[1] << std::endl;
    datos.close();


    return 0;
}
int Comandos::agregar_movimiento()
{
    if(validar_parametros(3)==false) return 1;
    if(stricmp(parametros[1],"avanzar")!= 0 && stricmp(parametros[1],"girar")!= 0 )
    {
        std::cout << "La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)." << std::endl;
        return 1;
    }
    std::cout << "El comando de movimiento ha sido agregado exitosamente." << std::endl;
    cola_comandos.push(std::string(parametros[0]) + " " + std::string(parametros[1]) + std::string(parametros[2]) + std::string(parametros[3]));
    return 0;
}

int Comandos::agregar_analisis() {
    if(validar_parametros(2)==false) return 1;


    return 0;
}
int Comandos::agregar_elemento()
{
    if(validar_parametros(5)==false) return 1;

    return 0;
}
int Comandos::guardar()
{
    if(validar_parametros(2)==false) return 1;


    return 0;
}
int Comandos::simular_comandos()
{
    if(validar_parametros(2)==false) return 1;

    return 0;
}
int Comandos::salir()
{
    if(validar_parametros(0)==false) return 1;

    return 1;
    
}
int Comandos::ubicar_elementos() {
    if(validar_parametros(0)==false) return 1;

    return 0;
}
int Comandos::en_cuadrante()
{
    if(validar_parametros(4)==false) return 1;

    return 0;
}
int Comandos::crear_mapa() {
    if (validar_parametros(1) == false) return 1;



    return 0;
}
int Comandos::ruta_mas_larga()
{
    if(validar_parametros(0)==false) return 1;


    return 0;
}
int Comandos::ayuda()
{
    return 0;
}


