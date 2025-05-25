// client.cpp
#include "client.h"
#include <iostream>

// Constructori
Client::Client() : m_id(0), m_nume(""), m_prenume(""), m_cnp(""), m_are_asigurare(false) {}

Client::Client(int id, const std::string& nume, const std::string& prenume,
    const std::string& cnp, bool are_asigurare)
    : m_id(id), m_nume(nume), m_prenume(prenume), m_cnp(cnp), m_are_asigurare(are_asigurare) {
}

Client::Client(const Client& other)
    : m_id(other.m_id), m_nume(other.m_nume), m_prenume(other.m_prenume),
    m_cnp(other.m_cnp), m_are_asigurare(other.m_are_asigurare) {
}

// Destructor
Client::~Client() {}

// Getteri
int Client::GetId() const { return m_id; }
std::string Client::GetNume() const { return m_nume; }
std::string Client::GetPrenume() const { return m_prenume; }
std::string Client::GetCnp() const { return m_cnp; }
bool Client::GetAreAsigurare() const { return m_are_asigurare; }

// Setteri
void Client::SetId(int id) { this->m_id = id; }
void Client::SetNume(const std::string& nume) { this->m_nume = nume; }
void Client::SetPrenume(const std::string& prenume) { this->m_prenume = prenume; }
void Client::SetCnp(const std::string& cnp) { this->m_cnp = cnp; }
void Client::SetAreAsigurare(bool are_asigurare) { this->m_are_asigurare = are_asigurare; }

// Alte metode
void Client::Afisare() const {
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nume: " << m_nume << " " << m_prenume << std::endl;
    std::cout << "CNP: " << m_cnp << std::endl;
    std::cout << "Are asigurare: " << (m_are_asigurare ? "Da" : "Nu") << std::endl;
}

double Client::CalculeazaDiscount() const {
    if (m_are_asigurare) {
        return 0.5;
    }
    return 0.0;
}

// Supraincarcare operatori
Client& Client::operator=(const Client& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_nume = other.m_nume;
        m_prenume = other.m_prenume;
        m_cnp = other.m_cnp;
        m_are_asigurare = other.m_are_asigurare;
    }
    return *this;
}

bool Client::operator==(const Client& other) const {
    return m_cnp == other.m_cnp;
}