 #pragma once
// Antibiotic.h
#ifndef ANTIBIOTIC_H
#define ANTIBIOTIC_H

#include "Medicament.h"

class Antibiotic : public Medicament {
	int concentratie;
	std::string substanta_activa;
public:
	//constructori
	Antibiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
		int concentratie, const std::string& substanta_activa);

	//Destructor
	~Antibiotic() override=default;

	
	//Getteri
	int getConcentratie() const;
	std::string getSubstantaActiva() const;

	//Setteri
	void setConcentratie(int concentratie);
	void setSubstantaActiva(const std::string& substanta_activa);


	//Alte metode
	void afisare() const override;
	Medicament* clone() const override;

	// Supraincarcare operatori
	Antibiotic& operator=(const Antibiotic& other);
	bool operator==(const Antibiotic& other) const;
};

#endif