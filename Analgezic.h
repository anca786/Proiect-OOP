#pragma once
// Analgezic.h
#ifndef ANALGEZIC_H
#define ANALGEZIC_H

#include "Medicament.h"
#include <string>

class Analgezic : public Medicament {
private:
    std::string tip_durere;

public:
    // Constructori
    Analgezic(int id, const std::string& nume, const std::string& producator, double pret, int cantitate, bool necesitaReteta,
        const std::string& tip_durere);

    // Destructor
    ~Analgezic() override;

    // Getter
    std::string getTipDurere() const;

    // Setter
    void setTipDurere(const std::string& tip);

    // Alte metode
    void afisare() const override;
    Medicament* clone() const override;

    // Supraincarcare operatori
    bool operator==(const Analgezic& other) const;
};

#endif