// Client.cpp
#include "Client.h"
#include <iostream>

// Constructori
Client::Client() : id(0), nume(""), prenume(""), cnp(""), areAsigurare(false) {}

Client::Client(int id, const std::string& nume, const std::string& prenume,
    const std::string& cnp, bool areAsigurare)
    : id(id), nume(nume), prenume(prenume), cnp(cnp), areAsigurare(areAsigurare) {
}

Client::Client(const Client& other)
    : id(other.id), nume(other.nume), prenume(other.prenume),
    cnp(other.cnp), areAsigurare(other.areAsigurare) {
}

// Destructor
Client::~Client() {}

// Getteri
int Client::getId() const { return id; }
std::string Client::getNume() const { return nume; }
std::string Client::getPrenume() const { return prenume; }
std::string Client::getCnp() const { return cnp; }
bool Client::getAreAsigurare() const { return areAsigurare; }

// Setteri
void Client::setId(int id) { this->id = id; }
void Client::setNume(const std::string& nume) { this->nume = nume; }
void Client::setPrenume(const std::string& prenume) { this->prenume = prenume; }
void Client::setCnp(const std::string& cnp) { this->cnp = cnp; }
void Client::setAreAsigurare(bool areAsigurare) { this->areAsigurare = areAsigurare; }

// Alte metode
void Client::afisare() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nume: " << nume << " " << prenume << std::endl;
    std::cout << "CNP: " << cnp << std::endl;
    std::cout << "Are asigurare: " << (areAsigurare ? "Da" : "Nu") << std::endl;
}

double Client::calculeazaDiscount() const {
    if (areAsigurare) {
        return 0.5; 
    }
    return 0.0; 
}

// Supraincarcare operatori
Client& Client::operator=(const Client& other) {
    if (this != &other) {
        id = other.id;
        nume = other.nume;
        prenume = other.prenume;
        cnp = other.cnp;
        areAsigurare = other.areAsigurare;
    }
    return *this;
}

bool Client::operator==(const Client& other) const {
    return cnp == other.cnp;
}