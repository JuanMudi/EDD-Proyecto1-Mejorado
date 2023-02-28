//
// Created by MuD on 27-Feb-23.
//

#include "Movimiento.h"
#include <iostream>
#include <cstring>
Movimiento::Movimiento() {
    medida = 0;
}

char *Movimiento::getTipo() const {
    return tipo;
}

void Movimiento::setTipo(char *tipo) {
    std::strcpy(Movimiento::tipo, tipo);
}

float Movimiento::getMedida() const {
    return medida;
}

void Movimiento::setMedida(float medida) {
    Movimiento::medida = medida;
}

char *Movimiento::getUMedida() const {
    return u_medida;
}

void Movimiento::setUMedida(char *uMedida) {
    std::strcpy(Movimiento::u_medida, uMedida);
}
