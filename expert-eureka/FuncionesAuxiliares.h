/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
void vidaEnemigo(PersonajeVideojuego& malo);
void atribHeroe(PersonajeVideojuego& heroe);
void combate(PersonajeVideojuego& heroe, PersonajeVideojuego& malo);
void movimientoPersonaje(PersonajeVideojuego& heroe);
void finCombate(PersonajeVideojuego& heroe, PersonajeVideojuego& malo, bool& terminar);

#endif /* FUNCIONESAUXILIARES_H */
