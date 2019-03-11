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
#include "Pocion.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int TAMENEMIGOS = 5;
    const int TAMARMAS = 5;
    const int TAMPOCIONES=2;
    
    
    int enemigosDerrotados = 0, indiceEnemigoAleatorio = 0;
    
    string nombre;
    
    try {
        
        //----------ARMAS-----------

        Arma armas[TAMARMAS] = { {"Espada de madera", 8}, {"Espada de metal", 10}, 
        {"Bastón de caramelo", 6}, {"Absorbe espíritus", 11}, {"Varita de Sauco", 13} };
        
        //----------ENEMIGOS-----------
        
        Enemigo enemigos[TAMENEMIGOS] = {{"Limo", 100, 4, 8}, {"Minotauro", 200, 2, 12}, {"Espíritu de fuego", 100, 6, 11}, 
        {"Espíritu de hielo", 130, 5, 10}, {"Grifo", 150, 7, 20}};

        //---------POCIONES--------
        
        Pocion pociones[TAMPOCIONES]={{"Pocion de vida",60,0,4},{"Pocion de Mana",0,50,2}};
        
        

        cout << "Introduzca el nombre del Héroe: ";
        getline(cin>>ws, nombre);

        PersonajeVideojuego Heroe(nombre, 0, 0, 12, 10, 10, &armas[0],&pociones[0]);

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
        
        cout << "VIVA WILLYREX";
    
    }catch (string& error) {
        
        cerr << "Error: " + error;
        
    }
    
    return 0;
}
