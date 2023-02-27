//
// Created by MuD on 27-Feb-23.
//

#ifndef EDD_PROYECTO1_LIMPIO_ELEMENTO_H
#define EDD_PROYECTO1_LIMPIO_ELEMENTO_H


class Elemento {
private:
    char *tipo_comp = new char[100];
    float tamanio;
    char* u_medida = new char[100];
    float coord_x;
    float coord_y;
public:
    char *getTipoComp() const;

    void setTipoComp(char *tipoComp);

    float getTamanio() const;

    void setTamanio(float tamanio);

    char *getUMedida() const;

    void setUMedida(char *uMedida);

    float getCoordX() const;

    void setCoordX(float coordX);

    float getCoordY() const;

    void setCoordY(float coordY);
};


#endif //EDD_PROYECTO1_LIMPIO_ELEMENTO_H
