#pragma once
// Probiotic.h
#ifndef PROBIOTIC_H
#define PROBIOTIC_H

#include "Medicament.h"
#include <string>

class Probiotic : public Medicament {
private:
    bool refrigerare_necesara;

public:
    // Constructori
    Probiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
        bool refrigerare_necesara);

    // Destructor
    ~Probiotic() override;

    // Getter
    bool getRefrigerareNecesara() const;

    // Setter
    void setRefrigerareNecesara(bool refrigerare);

    // Alte metode
    void afisare() const override;

    // Supraincarcare operatori
    bool operator==(const Probiotic& other) const;
};

#endif