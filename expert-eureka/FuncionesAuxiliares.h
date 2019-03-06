/* 
 * File:   FuncionesAuxiliares.h
 * Author: José Antonio
 *
 * Created on 1 de marzo de 2019, 23:42
 */


#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include "PersonajeVideojuego.h"

    
void ScreenClear();
bool spawner();

void ataqueMalo(PersonajeVideojuego& heroe, Enemigo& malo);
void vidaEnemigo(PersonajeVideojuego& malo);
void atribHeroe(PersonajeVideojuego& heroe);
void combate(PersonajeVideojuego& heroe, Enemigo malo, int& enemigosDerrotados);
int armaAleatoria(int tamArmas);
int enemigoAleatorio(int tamEnemigos);
void armaEncontrada(PersonajeVideojuego& heroe, /*const*/ Arma armas[], int tamArmas);
void movimientoPersonaje(PersonajeVideojuego& heroe, int& enemigosDerrotados, /*const*/ Arma armas[], int tamArmas);
void finCombate(PersonajeVideojuego& heroe, Enemigo& malo, bool& terminar, int& enemigosDerrotados);


#endif /* FUNCIONESAUXILIARES_H */
