#pragma once
// Angajat.h
#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <string>
#include <vector>
#include<iostream>

enum class TipAngajat {
    FARMACIST,
    ASISTENT_FARMACIST,
    CASIER,
    MANAGER,
    ADMINISTRATOR
};

class Angajat {
private:
    int id;
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string dataAngajare;
    double salariu;
    TipAngajat tip;
    bool esteActiv;
    int oreLucrateLuna;
    std::vector<std::string> tureLucrate; 

public:
    // Constructori
    Angajat();
    Angajat(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, const std::string& dataAngajare,
        double salariu, TipAngajat tip);
    Angajat(const Angajat& other);

    // Destructor
    ~Angajat();

    // Getteri
    int getId() const;
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getCnp() const;
    std::string getDataAngajare() const;
    double getSalariu() const;
    TipAngajat getTip() const;
    bool getEsteActiv() const;
    int getOreLucrateLuna() const;
    std::vector<std::string> getTureLucrate() const;

    // Setteri
    void setId(int id);
    void setNume(const std::string& nume);
    void setPrenume(const std::string& prenume);
    void setCnp(const std::string& cnp);
    void setDataAngajare(const std::string& dataAngajare);
    void setSalariu(double salariu);
    void setTip(TipAngajat tip);
    void setEsteActiv(bool esteActiv);

    // Alte metode
    void adaugaTura(const std::string& data, int oraInceput, int oraFinal);
    void stergeTura(const std::string& turaCod);
    void calculeazaOreLucrateLuna(const std::string& luna); // format: "YYYY-MM"
    double calculeazaSalariuLunar(const std::string& luna) const;
    void afisare() const;
    std::string getTipAngajatString() const;
    bool poateEliberaReteta() const;

    // Supraincarcare operatori
    Angajat& operator=(const Angajat& other);
    bool operator==(const Angajat& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Angajat& angajat);

};

#endif