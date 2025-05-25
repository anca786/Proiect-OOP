#pragma once
// antibiotic.h
#ifndef ANTIBIOTIC_H
#define ANTIBIOTIC_H

#include "medicament.h"

class Antibiotic : public Medicament {
private:
	int m_concentratie;
	std::string m_substanta_activa;
public:
	//constructori
	Antibiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
		int concentratie, const std::string& substanta_activa);

	//Destructor
	~Antibiotic() override = default;


	//Getteri
	int GetConcentratie() const;
	std::string GetSubstantaActiva() const;

	//Setteri
	void SetConcentratie(int concentratie);
	void SetSubstantaActiva(const std::string& substanta_activa);


	//Alte metode
	void Afisare() const override;
	Medicament* Clone() const override;

	// Supraincarcare operatori
	Antibiotic& operator=(const Antibiotic& other);
	bool operator==(const Antibiotic& other) const;
};

#endif