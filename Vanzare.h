// Vanzare.h
#ifndef VANZARE_H
#define VANZARE_H

#include "Medicament.h"
#include "Client.h"
#include <vector>
#include <string>

struct ItemVanzare {
    Medicament medicament;
    int cantitate;
    double pretTotal;
};

class Vanzare {
private:
    int id;
    std::string data;
    Client client;
    std::vector<ItemVanzare> items;
    double totalVanzare;
    double discount;

public:
    // Constructori
    Vanzare();
    Vanzare(int id, const std::string& data, const Client& client);
    Vanzare(const Vanzare& other); 

    // Destructor
    ~Vanzare();

    // Getteri
    int getId() const;
    std::string getData() const;
    Client getClient() const;
    std::vector<ItemVanzare> getItems() const;
    double getTotalVanzare() const;
    double getDiscount() const;

    // Setteri
    void setId(int id);
    void setData(const std::string& data);
    void setClient(const Client& client);

    // Alte metode
    void adaugaItem(const Medicament& medicament, int cantitate);
    void stergeItem(int index);
    void calculeazaTotal();
    void aplicaDiscount();
    void afisare() const;
    void genereazaBon() const;

    // Supraincarcare operatori
    Vanzare& operator=(const Vanzare& other);
    bool operator==(const Vanzare& other) const;
};

#endif