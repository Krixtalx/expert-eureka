/* 
 * File:   Pocion.cpp
 * Author: José Antonio
 * 
 * Created on 6 de marzo de 2019, 13:27
 */

#include "Pocion.h"


/**
 * @brief Constructor parametrizado de la clase Pocion
 * @param nombre: Nombre de la pocion
 * @param vida: Cantidad de vida que incrementara
 * @param mana: Cantidad de mana que incrementara
 * @param npociones: Nº de pociones que hay
 */
Pocion::Pocion(std::string nombre, int vida, int mana, int npociones):
nombre(nombre), vida(vida), mana(mana), npociones(npociones){
}

/**
 * @brief Constructor de copia de la clase Pocion (NO IMPLEMENTADO)
 * @param orig: Pocion de la que se hará la copia
 */
Pocion::Pocion(const Pocion& orig) {
    throw std::string ("Constructor de copia de Pocion: No implementado");
}

/**
 * @brief Destructor de la clase Pocion
 */
Pocion::~Pocion() {
}

/**
 * @brief Getter del atributo Mana
 * @return Mana
 */
int Pocion::GetMana() const {
    return mana;
}

/**
 * @brief Getter del atributo Vida
 * @return Vida
 */
int Pocion::GetVida() const {
    return vida;
}

/**
 * @brief Getter del atributo Nombre
 * @return nombre
 */
std::string Pocion::GetNombre() const {
    return nombre;
}

/**
 * @brief Setter del atributo Npociones
 * @param npociones: Nuevo valor de Npociones
 */
void Pocion::SetNpociones(int npociones) {
    this->npociones = npociones;
}

/**
 * @brief Getter del atributo Npociones
 * @return Npociones
 */
int Pocion::GetNpociones() const {
    return npociones;
}

