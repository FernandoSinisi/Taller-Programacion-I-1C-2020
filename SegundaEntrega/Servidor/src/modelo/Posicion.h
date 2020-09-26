#ifndef SERVIDOR_POSICION_H
#define SERVIDOR_POSICION_H

#include <vector>

class Posicion {
private:
    std::vector<double> pos;

public:
    Posicion();
    Posicion(double pos_x, double pos_y);
    Posicion(const Posicion& pos_copia);
    double getX() const;
    double getY() const;
    void setX(double new_x);
    void setY(double new_y);
    Posicion& operator+=(Posicion otra_posicion);
    Posicion& operator-=(Posicion otra_posicion);
    bool operator==(Posicion otra_posicion);
    bool operator!=(Posicion otra_posicion);
    Posicion operator+(Posicion otra_posicion);
    Posicion operator*(double entero);

    ~Posicion();

};


#endif //SERVIDOR_POSICION_H
