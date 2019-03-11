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
    Enemigo(std::string nombre, int vida, int damageBasico, int experiencia);
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();

    int getVidaAct() const;
    int getVidaMax() const;
    int getDamage() const;

    Enemigo& SetVida(int vida);
    Enemigo& setNombre(std::string nombre);
    std::string getNombre() const;

private:

    std::string nombre = "Jiren";
    int vidaAct = 40;
    int vidaMax=40;
    int damageBasico = 5;
    int experiencia=10;

};

#endif /* ENEMIGO_H */

