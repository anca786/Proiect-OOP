#pragma once
// Reteta.h
#ifndef RETETA_H
#define RETETA_H

#include <string>
#include <vector>
#include "Client.h"
#include "Medicament.h"

class Reteta {
private:
    int id;
    std::string numarReteta;
    std::string dataEmitere;
    std::string dataExpirare;
    std::string numeMedic;
    Client client;
    std::vector<std::pair<std::string, int>> medicamentePrescrise; 
    bool esteCompensata;
    int procentCompensare;

public:
    // Constructori
    Reteta();
    Reteta(int id, const std::string& numarReteta, const std::string& dataEmitere,
        const std::string& dataExpirare, const std::string& numeMedic,
        const Client& client, bool esteCompensata, int procentCompensare);
    Reteta(const Reteta& other);

    // Destructor
    ~Reteta();

    // Getteri
    int getId() const;
    std::string getNumarReteta() const;
    std::string getDataEmitere() const;
    std::string getDataExpirare() const;
    std::string getNumeMedic() const;
    Client getClient() const;
    std::vector<std::pair<std::string, int>> getMedicamentePrescrise() const;
    bool getEsteCompensata() const;
    int getProcentCompensare() const;

    // Setteri
    void setId(int id);
    void setNumarReteta(const std::string& numarReteta);
    void setDataEmitere(const std::string& dataEmitere);
    void setDataExpirare(const std::string& dataExpirare);
    void setNumeMedic(const std::string& numeMedic);
    void setClient(const Client& client);
    void setEsteCompensata(bool esteCompensata);
    void setProcentCompensare(int procentCompensare);

    // Alte metode
    void adaugaMedicament(const std::string& numeMedicament, int cantitate);
    void stergeMedicament(const std::string& numeMedicament);
    bool verificaValabilitate(const std::string& dataCurenta) const;
    void afisare() const;
    double calculeazaValoareCompensata(double pretTotal) const;

    // Supraincarcare operatori
    Reteta& operator=(const Reteta& other);
    bool operator==(const Reteta& other) const;
};

#endif