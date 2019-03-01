/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigo.h
 * Author: José Antonio
 *
 * Created on 27 de febrero de 2019, 21:23
 */

#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo {
public:
    Enemigo() = default;
    Enemigo(int vida, int mana, int damageBasico);
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();
    int GetMana() const;
    int GetVida() const;
    Enemigo& setPosicion(int posX, int posY);
    
    
    
private:
    
    int vida = 40;
    int mana = 0;
    int damageBasico = 5;
    int posX = 1;
    int posY = 1;
    
};

#endif /* ENEMIGO_H */

