// item_vanzare.cpp
#include "item_vanzare.h"
#include <iostream> 

// Constructori
ItemVanzare::ItemVanzare() : medicament(nullptr), cantitate(0), pret_total(0.0) {}

ItemVanzare::ItemVanzare(const Medicament* med_ptr, int qty) : cantitate(qty) {
    if (med_ptr) {
        medicament = med_ptr->Clone();
        pret_total = medicament->GetPret() * cantitate;
    }
    else {
        medicament = nullptr;
        pret_total = 0.0;

    }
}

ItemVanzare::ItemVanzare(const ItemVanzare& other)
    : cantitate(other.cantitate), pret_total(other.pret_total) {
    if (other.medicament) {
        medicament = other.medicament->Clone();
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
        pret_total = other.pret_total;
        if (other.medicament) {
            medicament = other.medicament->Clone();
        }
    }
    return *this;
}

// Destructor
ItemVanzare::~ItemVanzare() {
    delete medicament;
    medicament = nullptr;
}