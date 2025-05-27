#pragma once
// vanzabil.h
#ifndef VANZABIL_H
#define VANZABIL_H

#include <string>
#include <iostream> 

class Vanzabil {       //clasa abstracta pentru toate produsele care pot fi vandute
public:
    // Metode virtuale pure
    virtual std::string GetNume() const = 0;
    virtual double GetPret() const = 0;
    virtual int GetCantitate() const = 0;
    virtual void ScadeCantitate(int cantitate) = 0;
    virtual void AdaugaCantitate(int cantitate) = 0;
    virtual bool EsteDisponibil(int cantitate_solicitata) const = 0;
    virtual void Afisare() const = 0;

    //Destructor virtual
    virtual ~Vanzabil() = default;

};

#endif