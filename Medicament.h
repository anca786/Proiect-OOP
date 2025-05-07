// Medicament.h
#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <string>

class Medicament {
private:
    int id;
    std::string nume;
    std::string producator;
    double pret;
    int cantitate;
    bool necesitaReteta;

public:
    // Constructori
    Medicament();
    Medicament(int id, const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesitaReteta);
    Medicament(const Medicament& other); 

    // Destructor
    ~Medicament();

    // Getteri
    int getId() const;
    std::string getNume() const;
    std::string getProducator() const;
    double getPret() const;
    int getCantitate() const;
    bool getNecesitaReteta() const;

    // Setteri
    void setId(int id);
    void setNume(const std::string& nume);
    void setProducator(const std::string& producator);
    void setPret(double pret);
    void setCantitate(int cantitate);
    void setNecesitaReteta(bool necesitaReteta);

    // Alte metode
    void afisare() const;
    void adaugaStoc(int cantitate);
    bool scadeStoc(int cantitate);

    // Supraincarcare operatori
    Medicament& operator=(const Medicament& other);
    bool operator==(const Medicament& other) const;
    bool operator<(const Medicament& other) const;
};

#endif 