// Analgezic.cpp
#include "Analgezic.h"
#include <iostream>

// Constructori
Analgezic::Analgezic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
    const std::string& tip_durere)
    : Medicament(id, nume, producator, pret, cantitate, necesitaReteta), tip_durere(tip_durere) {
}

// Destructor
Analgezic::~Analgezic() = default;

// Getter
std::string Analgezic::getTipDurere() const { return tip_durere; }

// Setter
void Analgezic::setTipDurere(const std::string& tip) { tip_durere = tip; }

// Alte metode
void Analgezic::afisare() const {
    Medicament::afisare();
    std::cout << " - Analgezic pentru: " << tip_durere << std::endl;
}

// Supraincarcare operatori
bool Analgezic::operator==(const Analgezic& other) const {
    return Medicament::operator==(other) && tip_durere == other.tip_durere;
}