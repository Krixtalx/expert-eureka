/* 
 * File:   Arma.cpp
 * Author: david
 * 
 * Created on 1 de marzo de 2019, 19:10
 */


#include <iostream>
#include "Arma.h"

/**
 * @brief Constructor parametrizado de la clase Arma
 * @param nombre: Nombre del arma creada
 * @param damage: Daño del arma creada
 */
Arma::Arma(std::string nombre, int damage) :
nombre(nombre), damage(damage) {
    
    if (damage <= 0)
        throw std::string ("Arma::Arma, variable damage <= 0");

}

/**
 * @brief Constructor de copia de la clase Arma (No implementado)
 * @param orig: Arma del que se hará la copia
 */
Arma::Arma(const Arma& orig) {

    throw std::string("Arma::Arma, llamando al constructor de copia no implementado");

}

Arma::~Arma() {
}

/**
 * @brief Getter del atributo damage
 * @return damage
 */
int Arma::getDamage() const {
    return damage;
}

/**
 * @brief Getter del atributo nombre
 * @return nombre
 */
std::string Arma::getNombre() const {
    return nombre;
}

/**
 * @brief Establecer el daño del arma. Se puede usar en cascada.
 * @param[in] damage
 * @return Devuelve el objeto.
 */
Arma& Arma::setDamage(int damage) {

    if (damage <= 0)
        throw std::string("Arma::setDamage, variable damage <= 0");

    this->damage = damage;
    return *this;
}

