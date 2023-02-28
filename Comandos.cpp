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
    //Borrar los pametros anteriores
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
    //Validacion de los parametros
    if(validar_parametros(1)==false) return 1;
    //Vaciar la cola
    cola_comandos.empty();
    //Apertura de archivo
    std::fstream datos(parametros[1], std::ios::in);
    //Verificacion de la apertura del archivo
    if(datos.fail()) {
        std::cout << parametros[1] << " no se encuentra o no puede leerse." << std::endl;
        datos.close();
        return 1;
    }
    //Verificacion del contenido del archivo
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
    //Obtencion de los datos del archivo
    Movimiento aux = *new Movimiento();
    while(!datos.eof()){
        std::vector<char*> dd;
        dd.clear();
        char *token;
        //Tokenizar la cadena de entrada con la funcion std::strtok()
        token = std::strtok(input, " ");
        while (token != NULL)
        {
            //Uso de vector<> para almacenar los parametros
            dd.push_back(token);
            token = (std::strtok(NULL, " "));
        }
        aux.setTipo(dd[0]);
        aux.setMedida(atof(dd[1]));
        aux.setUMedida(dd[2]);
        cola_comandos.push(aux);
        i++;
        datos.getline(inf,100);
    }
    std::cout << i << " comandos cargados correctamente desde " << parametros[1] << std::endl;
    datos.close();
    return 0;
}

int Comandos::cargar_elementos()
{
    //Validacion de los parametros
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
    //Obtencion de los datos del archivo
    Elemento aux = *new Elemento();
    while(!datos.eof()){
        std::vector<char*> dd;
        dd.clear();
        char *token;
        //Tokenizar la cadena de entrada con la funcion std::strtok()
        token = std::strtok(input, " ");
        while (token != NULL)
        {
            //Uso de vector<> para almacenar los parametros
            dd.push_back(token);
            token = (std::strtok(NULL, " "));
        }
        aux.setTipoComp(dd[0]);
        aux.setTamanio(atof(dd[1]));
        aux.setUMedida(dd[2]);
        aux.setCoordX(atof(dd[3]));
        aux.setCoordX(atof(dd[4]));
        cola_elementos.push(aux);
        i++;
        datos.getline(inf,100);
    }


    return 0;
}
int Comandos::agregar_movimiento()
{
    //Validacion de parametros
    if(validar_parametros(3)==false) return 1;
    //Validacion de los tipos de movimiento
    if(stricmp(parametros[1],"avanzar")!= 0 && stricmp(parametros[1],"girar")!= 0 )
    {
        std::cout << "La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)." << std::endl;
        return 1;
    }
    std::cout << "El comando de movimiento ha sido agregado exitosamente." << std::endl;
    //Guardar en la cola los datos
    Movimiento aux = *new Movimiento;
    aux.setTipo(parametros[1]);
    aux.setMedida(atof(parametros[2]));
    aux.setUMedida(parametros[3]);
    cola_comandos.push(aux);
    return 0;
}

int Comandos::agregar_analisis() {
    //Validacion de parametros
    if(validar_parametros(2)==false) return 1;
    //Validacion de los tipos de movimiento
    if(stricmp(parametros[1],"fotografia")!= 0 && stricmp(parametros[1],"compisicion")!= 0 && stricmp(parametros[1],"perforar")!= 0)
    {
        std::cout << "La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario)." << std::endl;
        return 1;
    }
    std::cout << "El comando de analisis ha sido agregado exitosamente." << std::endl;
    //Guardar en la cola los datos
    Analisis aux = *new Analisis;
    aux.setTipoAnalisis(parametros[1]);
    aux.setObjeto(parametros[2]);
    aux.setComentario(parametros[3]);
    cola_analisis.push(aux);
    return 0;
}
int Comandos::agregar_elemento()
{
    if(validar_parametros(5)==false) return 1;
    if(stricmp(parametros[1],"roca")!= 0 && stricmp(parametros[1],"crater")!= 0 && stricmp(parametros[1],"monticulo")!= 0 && stricmp(parametros[1],"duna")!= 0)
    {
        std::cout << "La información del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)." << std::endl;
        return 1;
    }
    Elemento aux = *new Elemento;
    aux.setTipoComp(parametros[1]);
    aux.setTamanio(atof(parametros[2]));
    aux.setUMedida(parametros[3]);
    aux.setCoordX(atof(parametros[3]));
    aux.setCoordY(atof(parametros[3]));
    cola_elementos.push(aux);


    std::cout << "El elemento ha sido agregado exitosamente." << std::endl;

    return 0;
}
int Comandos::guardar()
{
    if(validar_parametros(2)==false) return 1;
    std::ofstream arch(parametros[1]);
    if(arch.fail())
    {
        std::cout << "Error guardando en " << parametros[1] << std::endl;
    }
    std::cout << "La información ha sido guardada en " << parametros[1] << std::endl;


    return 0;
}
int Comandos::simular_comandos()
{
    if(validar_parametros(2)==false) return 1;
    float coord_X = atof(parametros[1]);
    float coord_Y = atof(parametros[2]);
    float giro = 0;

    for(int i=0; i<cola_comandos.size();i++)
    {
        if(cola_comandos.front().getTipo() == "avanzar"  )
        {
            coord_X = cola_comandos.front().getMedida() * std::cos(giro);
            coord_Y = cola_comandos.front().getMedida() * std::sin(giro);
            cola_comandos.pop();
        }
        if(cola_comandos.front().getTipo() == "girar"  )
        {
            giro += cola_comandos.front().getMedida();
            cola_comandos.pop();
        }

    }
    return 0;
}
int Comandos::salir()
{
    if(validar_parametros(0)==false) return 1;

    exit (0);
    
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




