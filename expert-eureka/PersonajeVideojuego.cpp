/* 
 * File:   PersonajeVideojuego.cpp
 * Author: José Antonio
 * 
 * Created on 27 de febrero de 2019, 21:23
 */

#include "PersonajeVideojuego.h"
#include "Arma.h"
#include "Enemigo.h"

/**
 * @Brief Constructor por defecto de la clase PersonajeVideojuego
 */
PersonajeVideojuego::PersonajeVideojuego() :
posX(0), posY(0), vidaMax(100), vidaAct(100), manaMax(50), manaAct(100) {

}

/**
 * @Brief Constructor parametrizado de la clase PersonajeVideojuego
 * @param x: Posicion x donde inicializar el objeto
 * @param y: Posicion y donde inicializar el objeto
 * @param vida: Vida con la que inicializar el objeto
 * @param mana: Mana con el que inicializar el objeto
 * @param Arma: Puntero a un objeto de la clase Arma (Arma.h) 
 */
PersonajeVideojuego::PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma) :
nombre(nombre), posX(x), posY(y), vidaMax(vida), vidaAct(vida), manaMax(mana), manaAct(mana), armaEquipada(Arma) {

    if (nombre.length() == 0)
        throw std::string("PersonajeVideojuego::PersonajeVideojuego, el nombre establecido es cadena vacía");

}

/**
 * @Brief Constructor parametrizado de la clase PersonajeVideojuego
 * @param x: Posicion x donde inicializar el objeto
 * @param y: Posicion y donde inicializar el objeto
 * @param vida: Vida con la que inicializar el objeto
 * @param mana: Mana con el que inicializar el objeto
 * @param Arma: Puntero a un objeto de la clase Arma (Arma.h) 
 * @param pociones: Puntero a un objeto de la clase Pocion (Pocion.h)
 */
PersonajeVideojuego::PersonajeVideojuego(std::string nombre, int x, int y, int vida, int mana, Arma* Arma, Pocion pociones[]):
nombre(nombre), posX(x), posY(y), vidaMax(vida), vidaAct(vida), manaMax(mana), manaAct(mana), armaEquipada(Arma),pociones(pociones){
    if (nombre.length() == 0)
        throw std::string("PersonajeVideojuego::PersonajeVideojuego, el nombre establecido es cadena vacía");    
}

/**
 * @Brief Método encargado de cambiar las posiciones x e y
 * @param x: Cantidad en la que se incrementara posX
 * @param y: Cantidad en la que se incrementara posy
 */
void PersonajeVideojuego::movimiento(int x, int y){
    this->posX+=x;
    this->posY+=y;
}
/**
 * @brief Método que obtiene el daño del arma equipada
 * @return Daño:int del arma equipada
 */
int PersonajeVideojuego::GetDamage() const {
    return this->armaEquipada->getDamage();
}

/**
 * @brief Setter del atributo nombre 
 * @param nombre: Nuevo nombre
 * @return *this para encadenar setters
 */
PersonajeVideojuego& PersonajeVideojuego::setNombre(std::string nombre) {

    if (nombre.length() == 0)
        throw std::string("PersonajeVideojuego::setNombre, variable nombre vacía");

    this->nombre = nombre;
}

/**
 * @brief Getter del atributo nombre
 * @return El nombre
 */
std::string PersonajeVideojuego::getNombre() const {
    return nombre;
}

/**
 * @brief Setter del atributo VidaAct
 * @param vidaAct: Nuevo valor de VidaAct
 */
void PersonajeVideojuego::setVidaAct(int vidaAct) {
    this->vidaAct = vidaAct;
}

/**
 * @brief Getter del atributo consumoHab2
 * @return consumoHab2
 */
int PersonajeVideojuego::getConsumoHab2() const {
    return consumoHab2;
}

/**
 * @brief Getter del atributo consumoHab1
 * @return consumoHab1
 */
int PersonajeVideojuego::getConsumoHab1() const {
    return consumoHab1;
}

/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::ataqueBasico(Enemigo& golpeado) {
    golpeado.SetVida(golpeado.getVida() - this->GetDamage());
}

/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::hab1(Enemigo& golpeado) {
    if (manaAct >= consumoHab1) {
        golpeado.SetVida(golpeado.getVida() - this->GetDamage() * this->damageHab1);
        manaAct -= consumoHab1;
    }
}

/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::hab2(Enemigo& golpeado) {
    if (manaAct >= consumoHab2) {
        golpeado.SetVida(golpeado.getVida() - this->GetDamage() * this->damageHab2);
        manaAct -= consumoHab2;
    }
}

/**
 * @brief Constructor de copia (No implementado)
 * @param orig: PersonajeVideojuego del que se hará la copia
 */
PersonajeVideojuego::PersonajeVideojuego(const PersonajeVideojuego& orig) {
    throw std::string("Error en constructor de copia de PersonajeVideojuego: No implementado");
}

PersonajeVideojuego::~PersonajeVideojuego() {
}
/**
 * @brief Getter del atributo ManaMax 
 * @return ManaMax
 */
int PersonajeVideojuego::GetManaMax() const {
    return manaMax;
}

/**
 * @brief Getter del atributo ManaAct 
 * @return ManaAct
 */
int PersonajeVideojuego::GetManaAct() const {
    return manaAct;
}

/**
 * @brief Getter del atributo VidaMax 
 * @return VidaMax
 */
int PersonajeVideojuego::GetVidaMax() const {
    return vidaMax;
}

/**
 * @brief Getter del atributo VidaAct 
 * @return VidaAct
 */
int PersonajeVideojuego::GetVidaAct() const {
    return vidaAct;
}

/**
 * @brief Getter del atributo PosY
 * @return PosY
 */
int PersonajeVideojuego::GetPosY() const {
    return posY;
}

/**
 * @brief Getter del atributo PosX
 * @return PosX
 */
int PersonajeVideojuego::GetPosX() const {
    return posX;
}

/**
 * @brief Incrementa el mana actual según "cantidad"
 * @param cantidad: int cuanto se incrementará el atributo manaAct
 */
void PersonajeVideojuego::incrementarMana(int cantidad) {
    
    if(manaAct + cantidad >= manaMax)
        manaAct = manaMax;
    else
        manaAct = cantidad; 
}

void PersonajeVideojuego::equiparArma(Arma* arma) {
    
    armaEquipada = arma;
    
}

void PersonajeVideojuego::incrementarVida(int cantidad) {
    this->vidaAct+=cantidad;
}

void PersonajeVideojuego::tomarPocion(int tipoPocion) {
    
    if (pociones[tipoPocion].GetNpociones()>0) {
        vidaAct+=pociones[tipoPocion].GetVida();
        manaAct+=pociones[tipoPocion].GetMana();
        pociones[tipoPocion].SetNpociones(pociones[tipoPocion].GetNpociones()-1);
        
        if (this->vidaAct > this->vidaMax)
            vidaAct = vidaMax;
        
    }
}

Pocion* PersonajeVideojuego::getPocion() const {
    return this->pociones;
}


