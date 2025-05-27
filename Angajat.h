#pragma once
// angajat.h
#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <string>
#include <vector>
#include<iostream>

enum class Tip_Angajat {     //l-am folosit pentru claritate,ca sa se inteleaga sau cunoasca mai bine tipurile de angajati
    FARMACIST,
    ASISTENT_FARMACIST,
    CASIER,
    MANAGER,
    ADMINISTRATOR
};

class Angajat {
private:
    int m_id;
    std::string m_nume;
    std::string m_prenume;
    std::string m_cnp;
    std::string m_data_angajare;
    double m_salariu;
    Tip_Angajat m_tip;
    bool m_este_activ;
    int m_ore_lucrate_luna;
    std::vector<std::string> m_ture_lucrate;

public:
    // Constructori
    Angajat();
    Angajat(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, const std::string& data_angajare,
        double salariu, Tip_Angajat tip);
    Angajat(const Angajat& other);

    // Destructor
    ~Angajat();

    // Getteri
    int GetId() const;
    std::string GetNume() const;
    std::string GetPrenume() const;
    std::string GetCnp() const;
    std::string GetDataAngajare() const;
    double GetSalariu() const;
    Tip_Angajat GetTip() const;
    bool GetEsteActiv() const;
    int GetOreLucrateLuna() const;
    std::vector<std::string> GetTureLucrate() const;

    // Setteri
    void SetId(int id);
    void SetNume(const std::string& nume);
    void SetPrenume(const std::string& prenume);
    void SetCnp(const std::string& cnp);
    void SetDataAngajare(const std::string& data_angajare);
    void SetSalariu(double salariu);
    void SetTip(Tip_Angajat tip);
    void SetEsteActiv(bool este_activ);

    // Alte metode
    void AdaugaTura(const std::string& data, int ora_inceput, int ora_final);
    void StergeTura(const std::string& tura_cod);
    void CalculeazaOreLucrateLuna(const std::string& luna);
    double CalculeazaSalariuLunar(const std::string& luna) const;
    void Afisare() const;
    std::string GetTipAngajatString() const;
    bool PoateEliberaReteta() const;

    // Supraincarcare operatori
    Angajat& operator=(const Angajat& other);
    bool operator==(const Angajat& other) const;
};

#endif