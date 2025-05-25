// vanzare.h
#ifndef VANZARE_H
#define VANZARE_H

#include "client.h"
#include "item_vanzare.h"
#include <vector>
#include <string>

class Vanzare {
private:
    int m_id;
    std::string m_data;
    Client m_client;
    std::vector<ItemVanzare> m_items;
    double m_total_vanzare;
    double m_discount;

public:
    // Constructori
    Vanzare();
    Vanzare(int id, const std::string& data, const Client& client);
    Vanzare(const Vanzare& other);

    // Destructor
    ~Vanzare();

    // Getteri
    int GetId() const;
    std::string GetData() const;
    Client GetClient() const;
    std::vector<ItemVanzare> GetItems() const;
    double GetTotalVanzare() const;
    double GetDiscount() const;

    // Setteri
    void SetId(int id);
    void SetData(const std::string& data);
    void SetClient(const Client& client);

    // Alte metode
    void AdaugaItem(const Medicament& medicament, int cantitate);
    void StergeItem(int index);
    void CalculeazaTotal();
    void AplicaDiscount();
    void Afisare() const;
    void GenereazaBon() const;

    // Supraincarcare operatori
    Vanzare& operator=(const Vanzare& other);
    bool operator==(const Vanzare& other) const;
    Vanzare& operator+(const ItemVanzare& item);

private:
    // Metode private
    void _CalculeazaTotalHelper();
    void _AplicaDiscountHelper();
};

#endif