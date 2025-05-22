// Medicament.h
#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <string>
#include "Vanzabil.h"

class Medicament : public Vanzabil {
private:
    int id;
    std::string nume;
    std::string producator;
    double pret;
    int cantitate;
    bool necesitaReteta;
    static int totalMedicamenteCreate;
    //int tip;

public:

    // Constructori
    Medicament();
    Medicament(int id, const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesitaReteta);
    Medicament(const Medicament& other); 

    // Destructor
    virtual ~Medicament() override;

    // Getteri
    int getId() const;
    std::string getNume() const override;
    std::string getProducator() const ;
    double getPret() const override;
    int getCantitate() const override;
    bool getNecesitaReteta() const;
    static int getTotalMedicamenteCreate();

    // Setteri
    void setId(int id);
    void setNume(const std::string& nume);
    void setProducator(const std::string& producator);
    void setPret(double pret);
    void setCantitate(int cantitate);
    void setNecesitaReteta(bool necesitaReteta);

    // Alte metode
    virtual void afisare() const override;
    virtual Medicament* clone() const = 0;
    void adaugaCantitate(int cantitate) override; 
    void scadeCantitate(int cantitate) override;
    bool esteDisponibil(int cantitateSolicitata) const override;


    // Supraincarcare operatori
    Medicament& operator=(const Medicament& other);
    bool operator==(const Medicament& other) const;
    bool operator<(const Medicament& other) const;
};

#endif 