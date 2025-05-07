// Vanzare.cpp
#include "Vanzare.h"
#include <iostream>
#include <iomanip>

// Constructori
Vanzare::Vanzare() : id(0), data(""), totalVanzare(0.0), discount(0.0) {}

Vanzare::Vanzare(int id, const std::string& data, const Client& client)
    : id(id), data(data), client(client), totalVanzare(0.0), discount(0.0) {
}

Vanzare::Vanzare(const Vanzare& other)
    : id(other.id), data(other.data), client(other.client),
    items(other.items), totalVanzare(other.totalVanzare), discount(other.discount) {
}

// Destructor
Vanzare::~Vanzare() {}

// Getteri
int Vanzare::getId() const { return id; }
std::string Vanzare::getData() const { return data; }
Client Vanzare::getClient() const { return client; }
std::vector<ItemVanzare> Vanzare::getItems() const { return items; }
double Vanzare::getTotalVanzare() const { return totalVanzare; }
double Vanzare::getDiscount() const { return discount; }

// Setteri
void Vanzare::setId(int id) { this->id = id; }
void Vanzare::setData(const std::string& data) { this->data = data; }
void Vanzare::setClient(const Client& client) { this->client = client; }

// Alte metode
void Vanzare::adaugaItem(const Medicament& medicament, int cantitate) {
    if (cantitate <= 0 || medicament.getCantitate() < cantitate) {
        std::cout << "Cantitate invalida sau stoc insuficient!" << std::endl;
        return;
    }

    if (medicament.getNecesitaReteta() && !client.getAreAsigurare()) {
        std::cout << "Clientul nu poate cumpara acest medicament fara reteta!" << std::endl;
        return;
    }

    ItemVanzare item;
    item.medicament = medicament;
    item.cantitate = cantitate;
    item.pretTotal = medicament.getPret() * cantitate;

    items.push_back(item);
    calculeazaTotal();
}

void Vanzare::stergeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        calculeazaTotal();
    }
}

void Vanzare::calculeazaTotal() {
    totalVanzare = 0.0;
    for (const auto& item : items) {
        totalVanzare += item.pretTotal;
    }
    aplicaDiscount();
}

void Vanzare::aplicaDiscount() {
    double ratioDiscount = client.calculeazaDiscount();
    discount = totalVanzare * ratioDiscount;
    totalVanzare -= discount;
}

void Vanzare::afisare() const {
    std::cout << "ID Vanzare: " << id << std::endl;
    std::cout << "Data: " << data << std::endl;
    std::cout << "Client: " << client.getNume() << " " << client.getPrenume() << std::endl;
    std::cout << "Medicamente:" << std::endl;

    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i].medicament.getNume()
            << " x " << items[i].cantitate
            << " = " << items[i].pretTotal << " RON" << std::endl;
    }

    std::cout << "Total brut: " << totalVanzare + discount << " RON" << std::endl;
    std::cout << "Discount: " << discount << " RON" << std::endl;
    std::cout << "Total de plata: " << totalVanzare << " RON" << std::endl;
}

void Vanzare::genereazaBon() const {
    std::cout << "==================================================" << std::endl;
    std::cout << "                 FARMACIE BON FISCAL             " << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "Nr. bon: " << id << std::endl;
    std::cout << "Data: " << data << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::left << std::setw(30) << "Produs"
        << std::right << std::setw(10) << "Cantitate"
        << std::right << std::setw(10) << "Pret" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (const auto& item : items) {
        std::cout << std::left << std::setw(30) << item.medicament.getNume()
            << std::right << std::setw(10) << item.cantitate
            << std::right << std::setw(10) << item.pretTotal << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(30) << "Total brut:"
        << std::right << std::setw(20) << totalVanzare + discount << " RON" << std::endl;
    std::cout << std::left << std::setw(30) << "Discount:"
        << std::right << std::setw(20) << discount << " RON" << std::endl;
    std::cout << std::left << std::setw(30) << "Total de plata:"
        << std::right << std::setw(20) << totalVanzare << " RON" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "                Va multumim!                     " << std::endl;
    std::cout << "==================================================" << std::endl;
}

// Supraincarcare operatori
Vanzare& Vanzare::operator=(const Vanzare& other) {
    if (this != &other) {
        id = other.id;
        data = other.data;
        client = other.client;
        items = other.items;
        totalVanzare = other.totalVanzare;
        discount = other.discount;
    }
    return *this;
}

bool Vanzare::operator==(const Vanzare& other) const {
    return id == other.id;
}