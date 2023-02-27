//
// Created by MuD on 27-Feb-23.
//

#include "Elemento.h"

char *Elemento::getTipoComp() const {
    return tipo_comp;
}

void Elemento::setTipoComp(char *tipoComp) {
    tipo_comp = tipoComp;
}

float Elemento::getTamanio() const {
    return tamanio;
}

void Elemento::setTamanio(float tamanio) {
    Elemento::tamanio = tamanio;
}

char *Elemento::getUMedida() const {
    return u_medida;
}

void Elemento::setUMedida(char *uMedida) {
    u_medida = uMedida;
}

float Elemento::getCoordX() const {
    return coord_x;
}

void Elemento::setCoordX(float coordX) {
    coord_x = coordX;
}

float Elemento::getCoordY() const {
    return coord_y;
}

void Elemento::setCoordY(float coordY) {
    coord_y = coordY;
}
