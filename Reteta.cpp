// Reteta.cpp
#include "Reteta.h"
#include <iostream>
#include <algorithm>

// Constructori
Reteta::Reteta()
    : id(0), numarReteta(""), dataEmitere(""), dataExpirare(""),
    numeMedic(""), esteCompensata(false), procentCompensare(0) {
}

Reteta::Reteta(int id, const std::string& numarReteta, const std::string& dataEmitere,
    const std::string& dataExpirare, const std::string& numeMedic,
    const Client& client, bool esteCompensata, int procentCompensare)
    : id(id), numarReteta(numarReteta), dataEmitere(dataEmitere), dataExpirare(dataExpirare),
    numeMedic(numeMedic), client(client), esteCompensata(esteCompensata),
    procentCompensare(procentCompensare) {
    if (procentCompensare < 0) {
        this->procentCompensare = 0;
    }
    else if (procentCompensare > 100) {
        this->procentCompensare = 100;
    }
}

Reteta::Reteta(const Reteta& other)
    : id(other.id), numarReteta(other.numarReteta), dataEmitere(other.dataEmitere),
    dataExpirare(other.dataExpirare), numeMedic(other.numeMedic), client(other.client),
    medicamentePrescrise(other.medicamentePrescrise), esteCompensata(other.esteCompensata),
    procentCompensare(other.procentCompensare) {
}

// Destructor
Reteta::~Reteta() {}

// Getteri
int Reteta::getId() const { return id; }
std::string Reteta::getNumarReteta() const { return numarReteta; }
std::string Reteta::getDataEmitere() const { return dataEmitere; }
std::string Reteta::getDataExpirare() const { return dataExpirare; }
std::string Reteta::getNumeMedic() const { return numeMedic; }
Client Reteta::getClient() const { return client; }
std::vector<std::pair<std::string, int>> Reteta::getMedicamentePrescrise() const { return medicamentePrescrise; }
bool Reteta::getEsteCompensata() const { return esteCompensata; }
int Reteta::getProcentCompensare() const { return procentCompensare; }

// Setteri
void Reteta::setId(int id) { this->id = id; }
void Reteta::setNumarReteta(const std::string& numarReteta) { this->numarReteta = numarReteta; }
void Reteta::setDataEmitere(const std::string& dataEmitere) { this->dataEmitere = dataEmitere; }
void Reteta::setDataExpirare(const std::string& dataExpirare) { this->dataExpirare = dataExpirare; }
void Reteta::setNumeMedic(const std::string& numeMedic) { this->numeMedic = numeMedic; }
void Reteta::setClient(const Client& client) { this->client = client; }
void Reteta::setEsteCompensata(bool esteCompensata) { this->esteCompensata = esteCompensata; }

void Reteta::setProcentCompensare(int procentCompensare) {
    if (procentCompensare < 0) {
        this->procentCompensare = 0;
    }
    else if (procentCompensare > 100) {
        this->procentCompensare = 100;
    }
    else {
        this->procentCompensare = procentCompensare;
    }
}

// Alte metode
void Reteta::adaugaMedicament(const std::string& numeMedicament, int cantitate) {
    if (cantitate <= 0) {
        std::cout << "Cantitatea trebuie s? fie pozitiv?!" << std::endl;
        return;
    }

    // Verific?m dac? medicamentul exist? deja în re?et?
    auto it = std::find_if(medicamentePrescrise.begin(), medicamentePrescrise.end(),
        [&numeMedicament](const std::pair<std::string, int>& item) {
            return item.first == numeMedicament;
        });

    if (it != medicamentePrescrise.end()) {
        // Dac? exist?, actualiz?m cantitatea
        it->second += cantitate;
    }
    else {
        // Dac? nu exist?, ad?ug?m medicamentul nou
        medicamentePrescrise.push_back(std::make_pair(numeMedicament, cantitate));
    }
}

void Reteta::stergeMedicament(const std::string& numeMedicament) {
    auto it = std::find_if(medicamentePrescrise.begin(), medicamentePrescrise.end(),
        [&numeMedicament](const std::pair<std::string, int>& item) {
            return item.first == numeMedicament;
        });

    if (it != medicamentePrescrise.end()) {
        medicamentePrescrise.erase(it);
        std::cout << "Medicamentul a fost ?ters din re?et?!" << std::endl;
    }
    else {
        std::cout << "Medicamentul nu exist? în re?et?!" << std::endl;
    }
}

bool Reteta::verificaValabilitate(const std::string& dataCurenta) const {
    // Implementare simpl? - presupunem c? datele sunt în format "YYYY-MM-DD"
    return dataCurenta <= dataExpirare;
}

void Reteta::afisare() const {
    std::cout << "ID Re?et?: " << id << std::endl;
    std::cout << "Num?r re?et?: " << numarReteta << std::endl;
    std::cout << "Data emitere: " << dataEmitere << std::endl;
    std::cout << "Data expirare: " << dataExpirare << std::endl;
    std::cout << "Medic prescriptor: " << numeMedic << std::endl;
    std::cout << "Pacient: " << client.getNume() << " " << client.getPrenume() << std::endl;
    std::cout << "Medicamente prescrise:" << std::endl;

    for (const auto& med : medicamentePrescrise) {
        std::cout << "  - " << med.first << " x " << med.second << std::endl;
    }

    std::cout << "Este compensat?: " << (esteCompensata ? "Da" : "Nu") << std::endl;
    if (esteCompensata) {
        std::cout << "Procent compensare: " << procentCompensare << "%" << std::endl;
    }
}

double Reteta::calculeazaValoareCompensata(double pretTotal) const {
    if (!esteCompensata) {
        return 0.0;
    }
    return pretTotal * procentCompensare / 100.0;
}

// Supraincarcare operatori
Reteta& Reteta::operator=(const Reteta& other) {
    if (this != &other) {
        id = other.id;
        numarReteta = other.numarReteta;
        dataEmitere = other.dataEmitere;
        dataExpirare = other.dataExpirare;
        numeMedic = other.numeMedic;
        client = other.client;
        medicamentePrescrise = other.medicamentePrescrise;
        esteCompensata = other.esteCompensata;
        procentCompensare = other.procentCompensare;
    }
    return *this;
}

bool Reteta::operator==(const Reteta& other) const {
    return numarReteta == other.numarReteta;
}