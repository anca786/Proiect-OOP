#pragma once
// probiotic.h
#ifndef PROBIOTIC_H
#define PROBIOTIC_H

#include "medicament.h"
#include <string>

class Probiotic : public Medicament {
private:
    bool m_refrigerare_necesara;

public:
    // Constructori
    Probiotic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
        bool refrigerare_necesara);

    // Destructor
    ~Probiotic() override;

    // Getter
    bool GetRefrigerareNecesara() const;

    // Setter
    void SetRefrigerareNecesara(bool refrigerare);

    // Alte metode
    void Afisare() const override;
    Medicament* Clone() const override;

    // Supraincarcare operatori
    bool operator==(const Probiotic& other) const;
};

#endif