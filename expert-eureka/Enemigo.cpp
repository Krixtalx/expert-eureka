/* 
 * File:   Enemigo.cpp
 * Author: José Antonio
 * 
 * Created on 27 de febrero de 2019, 21:23
 */

#include "Enemigo.h"

/**
 * @brief Constructor parametrizado de la clase Enemigo
 * @param nombre: 
 * @param vida
 * @param mana
 * @param damageBasico
 */
Enemigo::Enemigo(std::string nombre, int vida, int mana, int damageBasico) :
 nombre(nombre), vida(vida), mana(mana), damageBasico(damageBasico) {
}

/**
 * @brief Constructor de copia de la clase Enemigo
 * @param orig: Enemigo del que se hará la copia
 */
Enemigo::Enemigo(const Enemigo& orig) {

    this->nombre=orig.nombre;
    this->vida=orig.vida;
    this->mana=orig.mana;
    this->damageBasico=orig.damageBasico;
    this->posX=orig.posX;
    this->posY=orig.posY;

}

Enemigo::~Enemigo() {
}

/**
 * @brief Getter del atributo Mana
 * @return  mana
 */
int Enemigo::getMana() const {
    return mana;
}

/**
 * @brief Getter del atributo Vida
 * @return vida
 */
int Enemigo::getVida() const {
    return vida;
}

/**
 * @brief Getter del atributo Damage
 * @return damageBasico
 */
int Enemigo::getDamage() const {
    return damageBasico;
}


/**
 * @brief Establece la posición del personaje. Se puede utilizar en cascada
 * @param[in] posX
 * @param[in] posY
 */
Enemigo& Enemigo::setPosicion(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;

    return *this;
}

/**
 * @brief Setter del atributo vida
 * @param vida: Nuevo valor del atributo vida
 */
void Enemigo::SetVida(int vida) {
    this->vida = vida;
}


/**
 * @brief Establece el nombre del personaje
 * @param[in] nombre, Nombre del personaje
 * @return Devuelve *this para encadenar setters
 */
Enemigo& Enemigo::setNombre(std::string nombre) {

    if (nombre.length() == 0)
        throw std::string("Enemigo::setNombre, variable nombre vacía");
    this->nombre = nombre;
    return *this;
}

/**
 * @brief Getter del atributo Nombre
 * @return nombre
 */
std::string Enemigo::getNombre() const {
    return nombre;
}



