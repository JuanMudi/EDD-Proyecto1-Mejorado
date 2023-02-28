
//
// Created by MuD on 27-Feb-23.
//

#ifndef EDD_PROYECTO1_LIMPIO_ANALISIS_H
#define EDD_PROYECTO1_LIMPIO_ANALISIS_H


class Analisis {
private:
    char* tipo_analisis = new char[100];
    char* objeto = new char[100];
    char* comentario = new char[200];
public:
    char *getTipoAnalisis() const;

    void setTipoAnalisis(char *tipoAnalisis);

    char *getObjeto() const;

    void setObjeto(char *objeto);

    char *getComentario() const;

    void setComentario(char *comentario);
};


#endif //EDD_PROYECTO1_LIMPIO_ANALISIS_H
