#pragma once
// Vanzabil.h
#ifndef VANZABIL_H
#define VANZABIL_H

#include <string>
#include <iostream> 

class Vanzabil {
public:
    // Metode virtuale pure
    virtual std::string getNume() const = 0;
    virtual double getPret() const = 0;
    virtual int getCantitate() const = 0;
    virtual void scadeCantitate(int cantitate) = 0;
    virtual void adaugaCantitate(int cantitate) = 0;
    virtual bool esteDisponibil(int cantitateSolicitata) const = 0;
    virtual void afisare() const = 0;

    //Destructor virtual
    virtual ~Vanzabil() = default;

};

#endif 