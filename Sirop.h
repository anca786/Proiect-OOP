#pragma once
// Sirop.h
#ifndef SIROP_H
#define SIROP_H

#include "Medicament.h"
#include <string>

class Sirop : public Medicament {
private:
    double volum;

public:
    // Constructori
    Sirop(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
        double volum);

    // Destructor
    ~Sirop() override;

    // Getter
    double getVolum() const;

    // Setter
    void setVolum(double volum);

    // Alte metode
    void afisare() const override;
    Medicament* clone() const override;

    // Supraincarcare operatori
    bool operator==(const Sirop& other) const;
};

#endif