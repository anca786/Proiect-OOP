// sirop.cpp
#include "sirop.h"
#include <iostream>

// Constructori
Sirop::Sirop(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
    double volum)
    : Medicament(id, nume, producator, pret, cantitate, necesita_reteta), m_volum(volum) {
}

// Destructor
Sirop::~Sirop() = default;

// Getter
double Sirop::GetVolum() const { return m_volum; }

// Setter
void Sirop::SetVolum(double volum) { this->m_volum = volum; }

// Alte metode
void Sirop::Afisare() const {
    Medicament::Afisare();
    std::cout << " - Sirop: Volum " << m_volum << "ml" << std::endl;
}

Medicament* Sirop::Clone() const {
    return new Sirop(*this);
}


// Supraincarcare operatori
bool Sirop::operator==(const Sirop& other) const {
    return Medicament::operator==(other) && m_volum == other.m_volum;
}