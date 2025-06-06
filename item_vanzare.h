#pragma once
// item_vanzare.h
#ifndef ITEM_H
#define ITEM_H

#include "Medicament.h" 
#include <string> 

class ItemVanzare {
public:
    Medicament* medicament;
    int cantitate;
    double pret_total;

    // Constructori
    ItemVanzare();
    ItemVanzare(const Medicament* med_ptr, int qty);

    ItemVanzare(const ItemVanzare& other);
    ItemVanzare& operator=(const ItemVanzare& other);

    // Destructor
    ~ItemVanzare();
};

#endif