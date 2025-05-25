#pragma once
// sirop.h
#ifndef SIROP_H
#define SIROP_H

#include "medicament.h"
#include <string>

class Sirop : public Medicament {
private:
    double m_volum;

public:
    // Constructori
    Sirop(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
        double volum);

    // Destructor
    ~Sirop() override;

    // Getter
    double GetVolum() const;

    // Setter
    void SetVolum(double volum);

    // Alte metode
    void Afisare() const override;
    Medicament* Clone() const override;

    // Supraincarcare operatori
    bool operator==(const Sirop& other) const;
};

#endif