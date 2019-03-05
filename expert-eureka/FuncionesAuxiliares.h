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
void combate(PersonajeVideojuego& heroe, Enemigo malo);
void movimientoPersonaje(PersonajeVideojuego& heroe, int enemigosDerrotados);
void finCombate(PersonajeVideojuego& heroe, Enemigo& malo, bool& terminar);

#endif /* FUNCIONESAUXILIARES_H */
