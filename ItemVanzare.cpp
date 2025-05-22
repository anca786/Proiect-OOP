// ItemVanzare.cpp
#include "ItemVanzare.h"
#include <iostream> 

// Constructori
ItemVanzare::ItemVanzare() : medicament(nullptr), cantitate(0), pretTotal(0.0) {}

ItemVanzare::ItemVanzare(const Medicament* med_ptr, int qty) : cantitate(qty) {
    if (med_ptr) {
        medicament = med_ptr->clone();
        pretTotal = medicament->getPret() * cantitate;
    }
    else {
        medicament = nullptr;
        pretTotal = 0.0;
        
    }
}

ItemVanzare::ItemVanzare(const ItemVanzare& other)
    : cantitate(other.cantitate), pretTotal(other.pretTotal) {
    if (other.medicament) {
        medicament = other.medicament->clone();
    }
    else {
        medicament = nullptr;
    }
}

ItemVanzare& ItemVanzare::operator=(const ItemVanzare& other) {
    if (this != &other) { 
        delete medicament;
        medicament = nullptr; 
        cantitate = other.cantitate;
        pretTotal = other.pretTotal;
        if (other.medicament) {
            medicament = other.medicament->clone(); 
        }
    }
    return *this;
}

// Destructor
ItemVanzare::~ItemVanzare() {
    delete medicament; 
    medicament = nullptr; 
}