//
// Created by MuD on 27-Feb-23.
//

#ifndef EDD_PROYECTO1_LIMPIO_MOVIMIENTO_H
#define EDD_PROYECTO1_LIMPIO_MOVIMIENTO_H


class Movimiento {
private:
    char* tipo = new char[100];
    float medida;
    char* u_medida  = new char [100];
public:
    char *getTipo() const;

    void setTipo(char *tipo);

    float getMedida() const;

    void setMedida(float medida);

    char *getUMedida() const;

    void setUMedida(char *uMedida);

};


#endif //EDD_PROYECTO1_LIMPIO_MOVIMIENTO_H
