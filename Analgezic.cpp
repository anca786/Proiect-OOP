// analgezic.cpp
#include "analgezic.h"
#include <iostream>

// Constructori
Analgezic::Analgezic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
    const std::string& tip_durere)
    : Medicament(id, nume, producator, pret, cantitate, necesita_reteta), m_tip_durere(tip_durere) {
}

// Destructor
Analgezic::~Analgezic() = default;

// Getter
std::string Analgezic::GetTipDurere() const { return m_tip_durere; }

// Setter
void Analgezic::SetTipDurere(const std::string& tip) { m_tip_durere = tip; }

// Alte metode
void Analgezic::Afisare() const {
    Medicament::Afisare();
	std::cout << " - Analgezic pentru: " << m_tip_durere << std::endl; // Afiseaza tipul de durere pentru care este destinat analgezicul
}

Medicament* Analgezic::Clone() const {  // Crează o copie a obiectului Analgezic
    return new Analgezic(*this);
}

// Supraincarcare operatori
bool Analgezic::operator==(const Analgezic& other) const {
    return Medicament::operator==(other) && m_tip_durere == other.m_tip_durere;
}