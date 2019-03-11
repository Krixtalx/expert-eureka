/* 
 * File:   PersonajeVideojuego.cpp
 * Author: José Antonio
 * 
 * Created on 27 de febrero de 2019, 21:23
 */

#include "PersonajeVideojuego.h"
#include "Arma.h"
#include "Enemigo.h"


//------------------------------------------CONSTRUCTORES-------------------------------------------------


/**
 * @Brief Constructor por defecto de la clase PersonajeVideojuego
 */
PersonajeVideojuego::PersonajeVideojuego() :
posX(0), posY(0), vidaMax(100), vidaAct(100), manaMax(50), manaAct(100) {

}

/**
 * @Brief Constructor parametrizado de la clase PersonajeVideojuego
 * @param nombre: Nombre para asignarle al objeto
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
 * @param nombre: Nombre para asignarle al objeto
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
 * @brief Constructor parametrizado de la clase PersonajeVideojuego
  * @param nombre: Nombre para asignarle al objeto
 * @param x: Posicion x donde inicializar el objeto
 * @param y: Posicion y donde inicializar el objeto
 * @param vitalidad: Vitalidad con la que inicializar el objeto
 * @param inteligencia: Inteligencia con la que inicializar el objeto
 * @param fuerza: Fuerza con la que inicializar el objeto
 * @param Arma: Puntero a un objeto de la clase Arma (Arma.h) 
 * @param pociones: Puntero a un objeto de la clase Pocion (Pocion.h)
 */
PersonajeVideojuego::PersonajeVideojuego(std::string nombre, int x, int y, int vitalidad, int inteligencia, int fuerza, Arma* Arma, Pocion pociones[]):
nombre(nombre), posX(x), posY(y), vidaMax(vitalidad*10), vidaAct(vitalidad*10), manaMax(inteligencia*8), manaAct(inteligencia*8), armaEquipada(Arma),pociones(pociones){
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




//------------------------------------------GETTERS-----------------------------------------------------




/**
 * @brief Método que obtiene el daño del arma equipada
 * @return Daño:int del arma equipada
 */
int PersonajeVideojuego::GetDamage() const {
    return this->armaEquipada->getDamage();
}

/**
 * @brief Getter del atributo nombre
 * @return El nombre
 */
std::string PersonajeVideojuego::getNombre() const {
    return nombre;
}

int PersonajeVideojuego::getFuerza() const {
    return fuerza;
}

int PersonajeVideojuego::getInteligencia() const {
    return inteligencia;
}

int PersonajeVideojuego::getVitalidad() const {
    return vitalidad;
}

int PersonajeVideojuego::getExperiencia() const {
    return experiencia;
}

/**
 * @brief Getter del atributo consumoHab2
 * @return consumoHab2
 */
int PersonajeVideojuego::getConsumoHab2() const {
    return consumoHab2;
}

int PersonajeVideojuego::getNivel() const {
    return nivel;
}

/**
 * @brief Getter del atributo consumoHab1
 * @return consumoHab1
 */
int PersonajeVideojuego::getConsumoHab1() const {
    return consumoHab1;
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
 * @brief Getter del atributo Pocion
 * @return Puntero del atributo pocion
 */
Pocion* PersonajeVideojuego::getPocion() const {
    return this->pociones;
}



//----------------------------------------SETTERS---------------------------------------------



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
 * @brief Setter del atributo VidaAct
 * @param vidaAct: Nuevo valor de VidaAct
 */
void PersonajeVideojuego::setVidaAct(int vidaAct) {
    this->vidaAct = vidaAct;
}

void PersonajeVideojuego::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

void PersonajeVideojuego::setInteligencia(int inteligencia) {
    this->inteligencia = inteligencia;
}

void PersonajeVideojuego::setVitalidad(int vitalidad) {
    this->vitalidad = vitalidad;
}

void PersonajeVideojuego::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

void PersonajeVideojuego::setNivel(int nivel) {
    this->nivel = nivel;
}



//----------------------------------------ATAQUES--------------------------------------------------------------




/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::ataqueBasico(Enemigo& golpeado) {
    golpeado.SetVida(golpeado.getVidaAct() - (this->GetDamage()*(fuerza/10)));
}

/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::hab1(Enemigo& golpeado) {
    if (manaAct >= consumoHab1) {
        golpeado.SetVida(golpeado.getVidaAct() - this->GetDamage() * this->damageHab1*(inteligencia/10));
        manaAct -= consumoHab1;
    }
}

/**
 * @brief Metodo encargado de quitarle vida al "Enemigo" golpeado en función al daño del arma
 * @param golpeado: Enemigo que recibirá el daño
 */
void PersonajeVideojuego::hab2(Enemigo& golpeado) {
    if (manaAct >= consumoHab2) {
        golpeado.SetVida(golpeado.getVidaAct() - this->GetDamage() * this->damageHab2*(inteligencia/10));
        manaAct -= consumoHab2;
    }
}



//----------------------------------------OTROS MÉTODOS-----------------------------------------------------



/**
 * @brief Incrementa el atributo vidaAct en x cantidad
 * @param cantidad: Cantidad a incrementar
 */
void PersonajeVideojuego::incrementarVida(int cantidad) {
    this->vidaAct+=cantidad;
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

/**
 * @brief Hace que el atributo Arma pase a ser la que se pasa por parametro
 * @param arma: Puntero al arma a equipar
 */
void PersonajeVideojuego::equiparArma(Arma* arma) {
    armaEquipada = arma;
}

/**
 * @brief Toma una pocion del vector de pociones
 * @param tipoPocion: Tipo de pocion del vector a tomar
 */
void PersonajeVideojuego::tomarPocion(int tipoPocion) {
    
    if (pociones[tipoPocion].GetNpociones()>0) {
        
        if (pociones[tipoPocion].GetVida()+vidaAct>vidaMax) {
            vidaAct=vidaMax;
        }else{
            vidaAct+=pociones[tipoPocion].GetVida();
        }

         if (pociones[tipoPocion].GetMana()+manaAct>manaMax) {
            manaAct=manaMax;
        }else{
             manaAct+=pociones[tipoPocion].GetMana();
        }        
        
        pociones[tipoPocion].SetNpociones(pociones[tipoPocion].GetNpociones()-1);       
    }
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
 * @brief Método encarga de administrar la subida de nivel del personaje
 * @param vitalidad: Cantidad en la que se incrementará el atributo Vitalidad
 * @param inteligencia: Cantidad en la que se incrementará el atributo Inteligencia
 * @param fuerza: Cantidad en la que se incrementará el atributo Fuerza
 */
void PersonajeVideojuego::subidaNivel(int vitalidad, int inteligencia, int fuerza) {
    nivel++;
    experiencia=0;
    this->vitalidad+=vitalidad;
    this->inteligencia+=inteligencia;
    this->fuerza+=fuerza;
    this->vidaAct=this->vitalidad*10;
    this->vidaMax=this->vitalidad*10;
    this->manaAct=this->inteligencia*8;
    this->manaMax=this->inteligencia*8;
}
