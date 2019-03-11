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
Enemigo::Enemigo(std::string nombre, int vida, int damageBasico) :
 nombre(nombre), vidaAct(vida),vidaMax(vida), damageBasico(damageBasico) {
}

/**
 * @brief Constructor parametrizado de la clase Enemigo
 * @param nombre: 
 * @param vida
 * @param mana
 * @param damageBasico
 * @param experiencia
 */
Enemigo::Enemigo(std::string nombre, int vida, int damageBasico, int experiencia) :
 nombre(nombre), vidaAct(vida),vidaMax(vida), damageBasico(damageBasico), experiencia(experiencia) {
}

/**
 * @brief Constructor de copia de la clase Enemigo
 * @param orig: Enemigo del que se hará la copia
 */
Enemigo::Enemigo(const Enemigo& orig) {

    this->nombre=orig.nombre;
    this->vidaAct=orig.vidaAct;
    this->vidaMax=orig.vidaMax;
    this->damageBasico=orig.damageBasico;
    this->experiencia=orig.experiencia;
}

Enemigo::~Enemigo() {
}

/**
 * @brief Getter del atributo VidaAct
 * @return vidaAct
 */
int Enemigo::getVidaAct() const {
    return vidaAct;
}

/**
 * @brief Getter del atributo VidaMax
 * @return vidaMax
 */
int Enemigo::getVidaMax() const {
    return vidaMax;
}

/**
 * @brief Getter del atributo Damage
 * @return damageBasico
 */
int Enemigo::getDamage() const {
    return damageBasico;
}

/**
 * @brief Setter del atributo vidaAct
 * @param vida: Nuevo valor del atributo vida
 */
Enemigo& Enemigo::SetVida(int vida) {
    
    this->vidaAct = vida;
    
    return *this;
    
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

int Enemigo::getExperiencia() const {
    return experiencia;
}