//
// Created by MuD on 27-Feb-23.
//

#include "Analisis.h"

char *Analisis::getTipoAnalisis() const {
    return tipo_analisis;
}

void Analisis::setTipoAnalisis(char *tipoAnalisis) {
    tipo_analisis = tipoAnalisis;
}

char *Analisis::getObjeto() const {
    return objeto;
}

void Analisis::setObjeto(char *objeto) {
    Analisis::objeto = objeto;
}

char *Analisis::getComentario() const {
    return comentario;
}

void Analisis::setComentario(char *comentario) {
    Analisis::comentario = comentario;
}
