// Probiotic.cpp
#include "Probiotic.h"
#include <iostream>

// Constructori
Probiotic::Probiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
    bool refrigerare_necesara)
    : Medicament(id, nume, producator, pret, cantitate, necesitaReteta), refrigerare_necesara(refrigerare_necesara) {
}

// Destructor
Probiotic::~Probiotic() = default;

// Getter
bool Probiotic::getRefrigerareNecesara() const { return refrigerare_necesara; }

// Setter
void Probiotic::setRefrigerareNecesara(bool refrigerare) { refrigerare_necesara = refrigerare; }

// Alte metode
void Probiotic::afisare() const {
    Medicament::afisare();
    std::cout << " - Probiotic: " << (refrigerare_necesara ? "Necesita refrigerare" : "Nu necesita refrigerare") << std::endl;
}

// Supraincarcare operatori
bool Probiotic::operator==(const Probiotic& other) const {
    return Medicament::operator==(other) && refrigerare_necesara == other.refrigerare_necesara;
}