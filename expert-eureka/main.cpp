/* 
 * File:   main.cpp
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:11
 */

#include <iostream>
#include <time.h>

#include "Arma.h"
#include "Enemigo.h"
#include "PersonajeVideojuego.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int TAMENEMIGOS = 5;
    const int TAMARMAS = 5;
    int enemigosDerrotados = 0, indiceEnemigoAleatorio = 0;
    string nombre;
    
    try {
        
        //----------ARMAS-----------

        Arma armas[TAMARMAS] = { {"Espada de madera", 8}, {"Espada de metal", 10}, 
        {"Bastón de caramelo", 6}, {"Absorbe espíritus", 11}, {"Varita de Sauco", 13} };

        //----------------------------------------------------------------------------------
        
        
        
        //----------ENEMIGOS-----------
        
        Enemigo enemigos[TAMENEMIGOS] = { {"Limo", 100, 4}, {"Minotauro", 200, 2}, {"Espíritu de fuego", 100, 5}, 
        {"Espíritu de hielo", 100, 5}, {"Grifo", 100, 7}  };
        
        //----------------------------------------------------------------------------------
        
        
        
        Enemigo Limo("Limo", 100, 4);

        cout << "Introduzca el nombre del Héroe: ";
        getline(cin>>ws, nombre);

        PersonajeVideojuego Heroe(nombre, 0, 0, 120, 50, &armas[0]);

        bool fight = false;

        while (!fight && Heroe.GetVidaAct() > 0) {
            srand(time(0));
            movimientoPersonaje(Heroe, enemigosDerrotados, armas, TAMARMAS);
            if (spawner()) {
                indiceEnemigoAleatorio = enemigoAleatorio(TAMENEMIGOS);
                combate(Heroe, enemigos[indiceEnemigoAleatorio], enemigosDerrotados);
            }
        }

        cout << "El juego ha terminado! :D" << endl;

        cin>>ws;
    
    }catch (string& error) {
        
        cerr << "Error: " + error;
        
    }
    
    return 0;
}