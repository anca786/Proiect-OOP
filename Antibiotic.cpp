// Antibiotic.cpp
#include "Antibiotic.h"
#include <iostream>
#include <string>

// Constructori
Antibiotic::Antibiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
    int concentratie, const std::string& substanta_activa)
    : Medicament(id, nume, producator, pret, cantitate, necesitaReteta), concentratie(concentratie), substanta_activa(substanta_activa) {
}

// Getteri
int Antibiotic::getConcentratie() const { return concentratie; }
std::string Antibiotic::getSubstantaActiva() const { return substanta_activa; }

// Setteri
void Antibiotic::setConcentratie(int concentratie) { this->concentratie = concentratie; }
void Antibiotic::setSubstantaActiva(const std::string& substanta) { substanta_activa = substanta; }

// Alte metode
void Antibiotic::afisare() const {
    Medicament::afisare();
    std::cout << " - Antibiotic: " << substanta_activa << ", " << concentratie << "mg" << std::endl;
}

Medicament* Antibiotic::clone() const {
	return new Antibiotic(*this);
}


//Supraincarcare operatori
Antibiotic& Antibiotic::operator=(const Antibiotic& other) {
	if (this != &other) {
		Medicament::operator=(other);
		concentratie = other.concentratie;
		substanta_activa = other.substanta_activa;
	}
	return *this;
}
bool Antibiotic::operator==(const Antibiotic& other) const {
	return Medicament::operator==(other) && concentratie == other.concentratie && substanta_activa == other.substanta_activa;

}