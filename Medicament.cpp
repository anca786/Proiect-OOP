// Medicament.cpp
#include "Medicament.h"
#include <iostream>

// Constructori
Medicament::Medicament() : id(0), nume(""), producator(""), pret(0.0), cantitate(0), necesitaReteta(false) {}

Medicament::Medicament(int id, const std::string& nume, const std::string& producator,
    double pret, int cantitate, bool necesitaReteta)
    : id(id), nume(nume), producator(producator), pret(pret), cantitate(cantitate), necesitaReteta(necesitaReteta) {
}

Medicament::Medicament(const Medicament& other)
    : id(other.id), nume(other.nume), producator(other.producator),
    pret(other.pret), cantitate(other.cantitate), necesitaReteta(other.necesitaReteta) {
}

// Destructor
Medicament::~Medicament() {}

// Getteri
int Medicament::getId() const { return id; }
std::string Medicament::getNume() const { return nume; }
std::string Medicament::getProducator() const { return producator; }
double Medicament::getPret() const { return pret; }
int Medicament::getCantitate() const { return cantitate; }
bool Medicament::getNecesitaReteta() const { return necesitaReteta; }

// Setteri
void Medicament::setId(int id) { this->id = id; }
void Medicament::setNume(const std::string& nume) { this->nume = nume; }
void Medicament::setProducator(const std::string& producator) { this->producator = producator; }
void Medicament::setPret(double pret) { this->pret = pret; }
void Medicament::setCantitate(int cantitate) { this->cantitate = cantitate; }
void Medicament::setNecesitaReteta(bool necesitaReteta) { this->necesitaReteta = necesitaReteta; }

// Alte metode
void Medicament::afisare() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Producator: " << producator << std::endl;
    std::cout << "Pret: " << pret << " RON" << std::endl;
    std::cout << "Cantitate: " << cantitate << std::endl;
    std::cout << "Necesita reteta: " << (necesitaReteta ? "Da" : "Nu") << std::endl;
}

void Medicament::adaugaStoc(int cantitate) {
    if (cantitate > 0) {
        this->cantitate += cantitate;
    }
}

bool Medicament::scadeStoc(int cantitate) {
    if (cantitate > 0 && this->cantitate >= cantitate) {
        this->cantitate -= cantitate;
        return true;
    }
    return false;
}

// Supraincarcare operatori
Medicament& Medicament::operator=(const Medicament& other) {
    if (this != &other) {
        id = other.id;
        nume = other.nume;
        producator = other.producator;
        pret = other.pret;
        cantitate = other.cantitate;
        necesitaReteta = other.necesitaReteta;
    }
    return *this;
}

bool Medicament::operator==(const Medicament& other) const {
    return id == other.id;
}

bool Medicament::operator<(const Medicament& other) const {
    return pret < other.pret;
}