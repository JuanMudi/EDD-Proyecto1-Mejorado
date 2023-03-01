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
    int i=0;
    //Obtencion de los datos del archivo

    std::vector<char*> dd;
    dd.clear();
    datos.seekg(0);
    while(!datos.eof()){
        Movimiento aux = *new Movimiento();
        datos.getline(inf,100);
        char *token;
        //Tokenizar la cadena de entrada con la funcion std::strtok()
        token = std::strtok(inf, " ");
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

        dd.clear();
    }
    std::cout << i << " comando(s) cargado(s) correctamente desde " << parametros[1] << std::endl;
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
    std::vector<char*> dd;
    Elemento aux = *new Elemento();
    datos.seekg(0);
    while(!datos.eof()){
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
    std::cout << i << " elemento(s) cargado(s) correctamente desde " << parametros[1] << std::endl;


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
    if (parametros.size()<= 3)
    {
        std::cout << "INSUFIENTES PARAMETROS PARA EJECUTAR LA FUNCION" << std::endl;
        return false;
    }else if (parametros.size()>4)
    {
        std::cout << "SE HAN INGRESADO MAS PARAMETROS DE LOS REQUERIDOS" << std::endl;
        return false;
    }
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
    int x = cola_comandos.size();
    for(int i=0; i< x ;i++)
    {
        if(std::strcmp(cola_comandos.front().getTipo(),"avanzar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"metros")==0 )
        {
            coord_X += cola_comandos.front().getMedida() * std::cos(giro*PI/180);
            coord_Y += cola_comandos.front().getMedida() * std::sin(giro*PI/180);

        }
        else if(std::strcmp(cola_comandos.front().getTipo(),"avanzar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"milimetros")==0)
        {
            coord_X += (cola_comandos.front().getMedida()/1000) * std::cos(giro);
            coord_Y += (cola_comandos.front().getMedida()/1000) * std::sin(giro);
        }
        else if(std::strcmp(cola_comandos.front().getTipo(),"avanzar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"centimetros")==0)
        {
            coord_X += (cola_comandos.front().getMedida()/100) * std::cos(giro);
            coord_Y += (cola_comandos.front().getMedida()/100) * std::sin(giro);
        }
        else if(std::strcmp(cola_comandos.front().getTipo(),"avanzar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"kilometros")==0)
        {
            coord_X += (cola_comandos.front().getMedida()*1000) * std::cos(giro);
            coord_Y += (cola_comandos.front().getMedida()*1000) * std::sin(giro);
        }
        if(std::strcmp(cola_comandos.front().getTipo(),"girar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"grados")==0)
        {
            giro += cola_comandos.front().getMedida();

        }
        else if(std::strcmp(cola_comandos.front().getTipo(),"girar")==0 && std::strcmp(cola_comandos.front().getUMedida(),"radianes")==0)
        {
            giro += cola_comandos.front().getMedida()*PI/180;
        }
        cola_comandos.pop();


    }
    std::cout << "Coordenada x: " << coord_X << " Coordenada y: " << coord_Y << std::endl;
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
int Comandos::ayuda() {
    if (parametros.size() == 1) {
        std::cout << "LISTA DE COMANDOS EXISTENTES " << std::endl;
        std::cout << "1. cargar_comandos nombre_archivo" << std::endl;
        std::cout << "2. cargar_elementos nombre_archivo" << std::endl;
        std::cout << "3. agregar_movimiento tipo_mov magnitud unidad_med" << std::endl;
        std::cout << "4. agregar_analisis tipo_analisis objeto comentario" << std::endl;
        std::cout << "5. agregar_elemento tipo_comp tamaño unidad_med coordX coordY" << std::endl;
        std::cout << "6. guardar tipo_archivo nombre_archivo" << std::endl;
        std::cout << "7. simular_comandos coordX coordY" << std::endl;
        std::cout << "8. salir" << std::endl;
        std::cout << "9. ubicar_elementos" << std::endl;
        std::cout << "10. en_cuadrante coordX1 coordX2 coordY1 coordY2" << std::endl;
        std::cout << "11. crear_mapa coeficiente_conectividad" << std::endl;
        std::cout << "12. ruta_mas_larga" << std::endl;
        std::cout << "13. ayuda comando" << std::endl;
    } else {

        switch (switchmap.find(std::string(parametros[1]))->second) {
            case 1:
                std::cout << "cargar_comandos nombre_archivo" << std::endl;
                std::cout << "Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo"
                        << std::endl;
                break;
            case 2:
                std::cout << "cargar_elementos nombre_archivo" << std::endl;
                std::cout << "Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo\n"
                             "identificado por nombre_archivo" << std::endl;
                break;
            case 3:
                std::cout << "agregar_movimiento tipo_mov magnitud unidad_med" << std::endl;
                std::cout << "Agrega el comando de movimiento descrito a la lista de comandos del robot “Curios-\n"
                             "ity”. El movimiento puede ser de dos tipos: avanzar o girar. La magnitud corresponde al valor del\n"
                             "movimiento; si es avanzar, el número de unidades que se espera avanzar, si es girar la cantidad de grados\n"
                             "que debe girar. La unidad de medida corresponde a la convención con la que se mide la magnitud del\n"
                             "2movimiento (centimetros, metros, grados, ...). Si no se envía la información completa y adecuada\n"
                             "del comando de movimiento, éste no puede agregarse a la lista de los comandos que se enviarán al robot\n"
                             "desde la tierra";
                break;
            case 4:
                std::cout << "agregar_analisis tipo_analisis objeto comentario" << std::endl;
                std::cout << "Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity”. El\n"
                         "análisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del\n"
                         "elemento que se quiere analizar (roca, arena, monticulo, ...). El comentario es opcional y permite agregar\n"
                         "más información sobre el elemento o el análisis, este comentario estará encerrado entre comillas simples\n"
                         "(ejemplo: ’roca_cuadrante_32’). Si no se envía la información completa y adecuada del comando de\n"
                         "análisis, éste no puede agregarse a la lista de los comandos que se enviarán al robot desde la tierra.";
                break;
            case 5:
                std::cout << "agregar_elemento tipo_comp tamaño unidad_med coordX coordY" << std::endl;
                std::cout << "Agrega el componente o elemento descrito a la lista de puntos de interés del robot “Cu-\n"
                             "riosity”. El tipo de componente puede ser uno entre roca, crater, monticulo o duna. El tamaño\n"
                             "es un valor real que da cuenta de qué tan grande es el elemento; y la unidad de medida complementa\n"
                             "este valor con la convención que se usó para su medición (centimetros, metros, ...). Finalmente, las\n"
                             "coordenadas x y y corresponden a números reales que permiten conocer la ubicación del elemento en\n"
                             "el sistema de coordenadas del suelo marciano utilizado por el vehículo. Si no se envía la información\n"

                             "completa y adecuada del elemento, éste no puede agregarse a la lista de puntos de interés que se enviarán\n"
                             "al robot desde la tierra.";
                break;
            case 6:
                std::cout << "guardar tipo_archivo nombre_archivo" << std::endl;
                std::cout
                        << "Guarda en el archivo nombre_archivo la información solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la información de comandos de movimiento y de análisis que debe ejecutar el robot";
                break;
            case 7:
                std::cout << "simular_comandos coordX coordY" << std::endl;
                std::cout
                        << "Permite simular el resultado de los comandos de movimiento que se enviarán al robot “Curiosity” desde la Tierra, facilitando asi la validación de la nueva posición en la que podría ubicarse. Para ejecutarse adecuadamente, requiere conocer la posición actual (coordenadas x y y) del vehículo.";
                break;
            case 8:
                std::cout << "salir" << std::endl;
                std::cout << "Termina la ejecución de la aplicación";
                break;
            case 9:
                std::cout << "ubicar_elementos" << std::endl;
                std::cout << "Permite realizar consultas geográficas sobre los elementos ingresados";
                break;
            case 10:
                std::cout << "en_cuadrante coordX1 coordX2 coordY1 coordY2" << std::endl;
                std::cout
                        << "Permite utilizar la estructura creada con el comando anterior para retornar una lista de los componentes o elementos que están dentro del cuadrante geográfico descrito por los límites de coordenadas en x y y. Es necesario haber ejecutado el comando ubicar_elementos para poder realizar la búsqueda por cuadrantes. Los límites de coordenadas deben garantizar que coordX1 <coordX2 y coordY1 <coordY2 . ";
                break;
            case 11:
                std::cout << "crear_mapa coeficiente_conectividad " << std::endl;
                std::cout
                        << " El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conectividad dado. El objetivo es que cada elemento esté conectado a los demás elementos más cercanos a él, midiendo la cercanía a través de la distancia euclidiana entre los elementos";
                break;
            case 12:
                std::cout << "ruta_mas_larga" << std::endl;
                std::cout
                        << " Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí de acuerdo a las conexiones generadas.";
                break;
            case 13:
                std::cout << "ayuda" << std::endl;
                std::cout << "Permite obtener informacion de los comandos existentes";
                break;
            default:
                std::cout << "No existe descripción para ese comando" << std::endl;
                break;
        }

    }
    return 0;
}




