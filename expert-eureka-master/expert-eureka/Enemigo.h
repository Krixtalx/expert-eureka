/* 
 * File:   Enemigo.h
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:23
 */





#ifndef ENEMIGO_H
#define ENEMIGO_H

 #include <string>

class Enemigo {
public:
    Enemigo() = default;
    Enemigo(std::string nombre, int vida, int damageBasico);
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();

    int getVida() const;
    int getDamage() const;

    Enemigo& setPosicion(int posX, int posY);
    Enemigo& SetVida(int vida);
    Enemigo& setNombre(std::string nombre);
    std::string getNombre() const;

private:

    std::string nombre = "Jiren";
    int vida = 40;
    int damageBasico = 5;
    int posX = 1;
    int posY = 1;

};

#endif /* ENEMIGO_H */

