/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: José Antonio
 * 
 * Created on 1 de marzo de 2019, 23:42
 */

#include "FuncionesAuxiliares.h"
#include <cstdlib>
#include <iostream>
#include "PersonajeVideojuego.h"
#include "Enemigo.h"

using std::cout;
using std::endl;
using std::cin;
/**
 * @brief Función encargada de limpiar la consola
 */
void ScreenClear() {
    bool windows = false;

    if (windows) {
        system("cls");
    } else {
        system("clear");
    }
}

/**
 * @brief Funcion encargada de decidir aleatoriamente si se genera un enemigo o no.
 * @return True si se genera, false si no
 */
bool  spawner(){
    
    int aux=rand()%100;
    
    if(aux<35)
        return true;
    return false;
}

/**
 * @brief Funcion encargada del daño del Enemigo al PersonajeVideojuego
 * @param heroe: PersonajeVideojuego que recibirá el daño
 * @param malo: Enemigo que hará el daño
 */
void ataqueMalo(PersonajeVideojuego& heroe, Enemigo& malo){
    heroe.setVidaAct(heroe.GetVidaAct()-malo.getDamage());
}

/**
 * @brief Función encargada de mostrar la vida del enemigo
 * @param malo: Enemigo del que se mostrará la vida
 */
void vidaEnemigo(Enemigo& malo){
    cout <<endl<<"Vida enemigo: "<<malo.getVida();
}

/**
 * @brief Función encargada de mostrar la vida y maná actual del personaje
 * @param heroe:
 */
void atribHeroe(PersonajeVideojuego& heroe){
    cout<<endl<< "Vida de "<<heroe.getNombre()<<": "<<heroe.GetVidaAct();
    cout<<"        "<< "Mana de "<<heroe.getNombre()<<": "<<heroe.GetManaAct();
}

/**
 * @brief Función encargada de iniciar el combate 
 * @param heroe: PersonajeVideojuego con el que se interaccionará
 * @param malo: Enemigo con el que se interaccionará
 */
void combate(PersonajeVideojuego& heroe, Enemigo malo){
    ScreenClear();
    
    int opcionMenu = 0;
    bool terminar = false, mana = true;
    
    cout <<malo.getNombre()<<" apareció en combate";
    
    while (!terminar) {
        
        vidaEnemigo(malo);
        atribHeroe(heroe);
        cout <<endl<<"1. Ataque básico";
        cout <<endl<<"2. Habilidad 1";
        cout <<endl<<"3. Habilidad 2";
        cout <<endl<<"Que desea hacer?: ";
        cin >> opcionMenu;
        
        cout << "\n";
        
        if (heroe.GetManaAct() <= heroe.getConsumoHab1() && opcionMenu == 2) {
            cout << "No tienes suficiente maná para usar esta habilidad" << endl;
            mana = false;
        
        }else if (heroe.GetManaAct() <= heroe.getConsumoHab2() && opcionMenu == 3) {
            cout << "No tienes suficiente maná para usar esta habilidad" << endl;
            mana = false;
            
        }
        
        if (mana) {
            
            switch (opcionMenu) {

                case 1:
                    heroe.ataqueBasico(malo);
                    finCombate(heroe, malo, terminar);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido un ataque básico, vida restante: " << malo.getVida() << endl;
                    break;

                case 2:
                    heroe.hab1(malo);
                    finCombate(heroe, malo, terminar);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido daño de habilidad 1, vida restante: " << malo.getVida() << endl;
                    break;

                case 3:
                    heroe.hab2(malo);
                    finCombate(heroe, malo, terminar);
                    ScreenClear();
                    cout << malo.getNombre() << " ha recibido daño de habilidad 2, vida restante: " << malo.getVida() << endl;
                    break;
                    
                case 8085: //Shhhh... Esto es secreto :)
                    heroe.incrementarMana(50);
                    break;
                    
                case 69: //Shhhh... Esto es secreto ;)
                    heroe.setVidaAct(100);
                    break;
                    
                default:
                    cout << "Opción errónea, vuelva a introducir una" << endl;
                    break;
            }
        }
        
        if (!terminar) {
            ataqueMalo(heroe, malo);
            cout << malo.getNombre() << " ha atacado a " << heroe.getNombre();
        }
        
        mana = true;       
    }
}

/**
 * @brief Función que determina si el combate ha finalizado o no
 * @param heroe: PersonajeVideojuego que está en combate
 * @param malo:Enemigo que está en combate
 * @param terminar: Bool donde se almacenará el resultado
 */
void finCombate(PersonajeVideojuego& heroe, Enemigo& malo, bool& terminar) {
    
        if(malo.getVida() <= 0) {

            malo.SetVida(0);
            terminar = true;
            cout <<heroe.getNombre()<<" ha vencido!";
            
        }else if (heroe.GetVidaAct() <= 0) {
            
            heroe.setVidaAct(0);
            terminar = true;
            cout <<malo.getNombre() <<" ha vencido!";
            
        }
    
}

/**
 * @brief Función encargada del menu de movimiento de personaje
 * @param heroe:PersonajeVideojuego con el que se interaccionará
 */
void movimientoPersonaje(PersonajeVideojuego& heroe) {
    ScreenClear();
    cout << "Actualmente se encuentra en la posicion x: " << heroe.GetPosX() << "  y: " << heroe.GetPosY() << endl;
    cout << endl << "1. Hacia la derecha";
    cout << endl << "2. Hacia arriba";
    if (heroe.GetPosX() != 0)
        cout << endl << "3. Hacia la izquierda";
    if (heroe.GetPosY() != 0)
        cout << endl << "4. Hacia abajo";
    cout <<endl<< "Hacia donde desea moverse?: ";
    int aux;
    bool opcionincorrecta(true);
    
    while (opcionincorrecta) {
        cin >>aux;
        switch (aux) {
            case 1:
                heroe.movimiento(1, 0);
                opcionincorrecta = false;
                break;
            case 2:
                heroe.movimiento(0, 1);
                opcionincorrecta = false;
                break;
            case 3:
                heroe.movimiento(-1, 0);
                opcionincorrecta = false;
                break;
            case 4:
                heroe.movimiento(0, -1);
                opcionincorrecta = false;
                break;
            default:
                cout<<"Introduzca una opcion correcta: ";
                break;
        }
    }

}
