// medicament.cpp
#include "medicament.h"
#include <iostream>

int Medicament::m_total_medicamente_create = 0;

// Constructori
Medicament::Medicament() : m_id(0), m_nume(""), m_producator(""), m_pret(0.0), m_cantitate(0), m_necesita_reteta(false) {
    m_total_medicamente_create++;
}

Medicament::Medicament(int id, const std::string& nume, const std::string& producator,
    double pret, int cantitate, bool necesita_reteta)
    : m_id(id), m_nume(nume), m_producator(producator), m_pret(pret), m_cantitate(cantitate), m_necesita_reteta(necesita_reteta) {
    m_total_medicamente_create++;
}

Medicament::Medicament(const Medicament& other)
    : m_id(other.m_id), m_nume(other.m_nume), m_producator(other.m_producator),
    m_pret(other.m_pret), m_cantitate(other.m_cantitate), m_necesita_reteta(other.m_necesita_reteta) {
    m_total_medicamente_create++;
}

// Destructor
Medicament::~Medicament() {}

// Getteri
int Medicament::GetId() const { return m_id; }
std::string Medicament::GetNume() const { return m_nume; }
std::string Medicament::GetProducator() const { return m_producator; }
double Medicament::GetPret() const { return m_pret; }
int Medicament::GetCantitate() const { return m_cantitate; }
bool Medicament::GetNecesitaReteta() const { return m_necesita_reteta; }

// Setteri
void Medicament::SetId(int id) { this->m_id = id; }
void Medicament::SetNume(const std::string& nume) { this->m_nume = nume; }
void Medicament::SetProducator(const std::string& producator) { this->m_producator = producator; }
void Medicament::SetPret(double pret) { this->m_pret = pret; }
void Medicament::SetCantitate(int cantitate) { this->m_cantitate = cantitate; }
void Medicament::SetNecesitaReteta(bool necesita_reteta) { this->m_necesita_reteta = necesita_reteta; }

// Alte metode
void Medicament::Afisare() const {
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nume: " << m_nume << std::endl;
    std::cout << "Producator: " << m_producator << std::endl;
    std::cout << "Pret: " << m_pret << " RON" << std::endl;
    std::cout << "Cantitate: " << m_cantitate << std::endl;
    std::cout << "Necesita reteta: " << (m_necesita_reteta ? "Da" : "Nu") << std::endl;
}

void Medicament::AdaugaCantitate(int cantitate) {
    if (cantitate > 0) {
        this->m_cantitate += cantitate;
    }
}

void Medicament::ScadeCantitate(int cantitate) {
    if (cantitate > 0 && this->m_cantitate >= cantitate) {
        this->m_cantitate -= cantitate;
    }
}

bool Medicament::EsteDisponibil(int cantitate_solicitata) const {
    return cantitate_solicitata > 0 && this->m_cantitate >= cantitate_solicitata;
}

int Medicament::GetTotalMedicamenteCreate() {
    return m_total_medicamente_create;
}


// Supraincarcare operatori
Medicament& Medicament::operator=(const Medicament& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_nume = other.m_nume;
        m_producator = other.m_producator;
        m_pret = other.m_pret;
        m_cantitate = other.m_cantitate;
        m_necesita_reteta = other.m_necesita_reteta;
    }
    return *this;
}

bool Medicament::operator==(const Medicament& other) const {
    return m_id == other.m_id;
}

bool Medicament::operator<(const Medicament& other) const {
    return m_pret < other.m_pret;
}