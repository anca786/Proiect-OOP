// Sirop.cpp
#include "Sirop.h"
#include <iostream>

// Constructori
Sirop::Sirop(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
    double volum)
    : Medicament(id, nume, producator, pret, cantitate, necesitaReteta), volum(volum) {
}

// Destructor
Sirop::~Sirop() = default;

// Getter
double Sirop::getVolum() const { return volum; }

// Setter
void Sirop::setVolum(double volum) { this->volum = volum; }

// Alte metode
void Sirop::afisare() const {
    Medicament::afisare();
    std::cout << " - Sirop: Volum " << volum << "ml" << std::endl;
}

Medicament* Sirop::clone() const {
    return new Sirop(*this);
}


// Supraincarcare operatori
bool Sirop::operator==(const Sirop& other) const {
    return Medicament::operator==(other) && volum == other.volum;
}