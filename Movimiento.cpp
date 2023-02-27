//
// Created by MuD on 27-Feb-23.
//

#include "Movimiento.h"

char *Movimiento::getTipo() const {
    return tipo;
}

void Movimiento::setTipo(char *tipo) {
    Movimiento::tipo = tipo;
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
    u_medida = uMedida;
}
