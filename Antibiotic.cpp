// antibiotic.cpp
#include "antibiotic.h"
#include <iostream>
#include <string>

// Constructori
Antibiotic::Antibiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
	int concentratie, const std::string& substanta_activa)
	: Medicament(id, nume, producator, pret, cantitate, necesita_reteta), m_concentratie(concentratie), m_substanta_activa(substanta_activa) {
}

// Getteri
int Antibiotic::GetConcentratie() const { return m_concentratie; }
std::string Antibiotic::GetSubstantaActiva() const { return m_substanta_activa; }

// Setteri
void Antibiotic::SetConcentratie(int concentratie) { this->m_concentratie = concentratie; }
void Antibiotic::SetSubstantaActiva(const std::string& substanta) { m_substanta_activa = substanta; }

// Alte metode
void Antibiotic::Afisare() const {
	Medicament::Afisare();
	std::cout << " - Antibiotic: " << m_substanta_activa << ", " << m_concentratie << "mg" << std::endl;
}

Medicament* Antibiotic::Clone() const {
	return new Antibiotic(*this);
}

//Supraincarcare operatori
Antibiotic& Antibiotic::operator=(const Antibiotic& other) {
	if (this != &other) {
		Medicament::operator=(other);
		m_concentratie = other.m_concentratie;
		m_substanta_activa = other.m_substanta_activa;
	}
	return *this;
}
bool Antibiotic::operator==(const Antibiotic& other) const {
	return Medicament::operator==(other) && m_concentratie == other.m_concentratie && m_substanta_activa == other.m_substanta_activa;
}