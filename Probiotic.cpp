// probiotic.cpp
#include "probiotic.h"
#include <iostream>

// Constructori
Probiotic::Probiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
    bool refrigerare_necesara)
    : Medicament(id, nume, producator, pret, cantitate, necesita_reteta), m_refrigerare_necesara(refrigerare_necesara) {
}

// Destructor
Probiotic::~Probiotic() = default;

// Getter
bool Probiotic::GetRefrigerareNecesara() const { return m_refrigerare_necesara; }

// Setter
void Probiotic::SetRefrigerareNecesara(bool refrigerare) { m_refrigerare_necesara = refrigerare; }

// Alte metode
void Probiotic::Afisare() const {   
    Medicament::Afisare();
	std::cout << " - Probiotic: " << (m_refrigerare_necesara ? "Necesita refrigerare" : "Nu necesita refrigerare") << std::endl;   //afiseaza daca necesita refrigerare sau nu
}

Medicament* Probiotic::Clone() const {   //creeaza o copie a obiectului Probiotic
    return new Probiotic(*this);
}

// Supraincarcare operatori
bool Probiotic::operator==(const Probiotic& other) const {
    return Medicament::operator==(other) && m_refrigerare_necesara == other.m_refrigerare_necesara;
}