// medicament.h
#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <string>
#include "vanzabil.h"

class Medicament : public Vanzabil {
private:
    int m_id;
    std::string m_nume;
    std::string m_producator;
    double m_pret;
    int m_cantitate;
    bool m_necesita_reteta;
    static int m_total_medicamente_create;

public:

    // Constructori
    Medicament();
    Medicament(int id, const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesita_reteta);
    Medicament(const Medicament& other);

    // Destructor
    virtual ~Medicament() override;

    // Getteri
    int GetId() const;
    std::string GetNume() const override;
    std::string GetProducator() const;
    double GetPret() const override;
    int GetCantitate() const override;
    bool GetNecesitaReteta() const;
    static int GetTotalMedicamenteCreate();

    // Setteri
    void SetId(int id);
    void SetNume(const std::string& nume);
    void SetProducator(const std::string& producator);
    void SetPret(double pret);
    void SetCantitate(int cantitate);
    void SetNecesitaReteta(bool necesita_reteta);

    // Alte metode
    virtual void Afisare() const override;
    virtual Medicament* Clone() const = 0;
    void AdaugaCantitate(int cantitate) override;
    void ScadeCantitate(int cantitate) override;
    bool EsteDisponibil(int cantitate_solicitata) const override;


    // Supraincarcare operatori
    Medicament& operator=(const Medicament& other);
    bool operator==(const Medicament& other) const;
    bool operator<(const Medicament& other) const;
};

#endif