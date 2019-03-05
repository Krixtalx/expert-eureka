/* 
 * File:   main.cpp
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:11
 */

#include <iostream>

#include "Arma.h"
#include "Enemigo.h"
#include "PersonajeVideojuego.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int enemigosDerrotados = 0;
    
    string nombre;
    Arma armaPorDefecto;
    Arma bastonMagico("Baston Magico", 12);
    Arma EspadaLegendaria("Excalibur", 25);
    Enemigo Limo("Limo", 100,0,5);

    cout << "Introduzca el nombre del Héroe: ";
    getline(cin>>ws, nombre);

    PersonajeVideojuego Heroe(nombre, 0, 0, 100, 50, &EspadaLegendaria);

    bool fight = false;

    while (!fight && Heroe.GetVidaAct() > 0) {

        movimientoPersonaje(Heroe, enemigosDerrotados);
        if (spawner()) {
            combate(Heroe, Limo);
            enemigosDerrotados++;
        }
    }
    
    cout << "El juego ha terminado! :D" << endl;
    
    return 0;
}