#pragma once
// analgezic.h
#ifndef ANALGEZIC_H
#define ANALGEZIC_H

#include "medicament.h"
#include <string>

class Analgezic : public Medicament {
private:
    std::string m_tip_durere;

public:
    // Constructori
    Analgezic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesita_reteta,
        const std::string& tip_durere);

    // Destructor
    ~Analgezic() override;

    // Getter
    std::string GetTipDurere() const;

    // Setter
    void SetTipDurere(const std::string& tip);

    // Alte metode
    void Afisare() const override;
    Medicament* Clone() const override;

    // Supraincarcare operatori
    bool operator==(const Analgezic& other) const;
};

#endif