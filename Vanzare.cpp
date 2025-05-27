// vanzare.cpp
#include "vanzare.h"
#include <iostream>
#include <iomanip>

// Constructori
Vanzare::Vanzare() : m_id(0), m_data(""), m_total_vanzare(0.0){}

Vanzare::Vanzare(int id, const std::string& data, const Client& client)
    : m_id(id), m_data(data), m_client(client), m_total_vanzare(0.0), m_discount(0.0) {
}

Vanzare::Vanzare(const Vanzare& other)
    : m_id(other.m_id), 
    m_data(other.m_data),
    m_client(other.m_client),
    m_items(other.m_items), 
    m_total_vanzare(other.m_total_vanzare),
    m_discount(other.m_discount) {
}

// Destructor
Vanzare::~Vanzare() {}

// Getteri
int Vanzare::GetId() const { return m_id; }
std::string Vanzare::GetData() const { return m_data; }
Client Vanzare::GetClient() const { return m_client; }
std::vector<ItemVanzare> Vanzare::GetItems() const { return m_items; }
double Vanzare::GetTotalVanzare() const { return m_total_vanzare; }
double Vanzare::GetDiscount() const { return m_discount; }

// Setteri
void Vanzare::SetId(int id) { this->m_id = id; }
void Vanzare::SetData(const std::string& data) { this->m_data = data; }
void Vanzare::SetClient(const Client& client) { this->m_client = client; }

// Alte metode
void Vanzare::AdaugaItem(const Medicament& medicament, int cantitate) {        // adauga un item la vanzare
    if (cantitate <= 0 || medicament.GetCantitate() < cantitate) {
        std::cout << "Cantitate invalida sau stoc insuficient!" << std::endl;
        return;
    }

    if (medicament.GetNecesitaReteta() && !m_client.GetAreAsigurare()) {
        std::cout << "Clientul nu poate cumpara acest medicament fara reteta!" << std::endl;
        return;
    }
    ItemVanzare item(&medicament, cantitate);

    m_items.push_back(item);
    CalculeazaTotal();
}

void Vanzare::StergeItem(int index) {            // sterge un item din vanzare
    if (index >= 0 && index < m_items.size()) {
        m_items.erase(m_items.begin() + index);
        CalculeazaTotal();
    }
}

void Vanzare::CalculeazaTotal() {         // calculeaza totalul vanzarii
    m_total_vanzare = 0.0;
    for (const auto& item : m_items) {
        m_total_vanzare += item.pret_total;
    }
    AplicaDiscount();
}

void Vanzare::AplicaDiscount() {          //aplica discount la clientii care au asigurare
    double ratio_discount = m_client.CalculeazaDiscount();
    m_discount = m_total_vanzare * ratio_discount;
    m_total_vanzare -= m_discount;
}

void Vanzare::Afisare() const {
    std::cout << "ID Vanzare: " << m_id << std::endl;
    std::cout << "Data: " << m_data << std::endl;
    std::cout << "Client: " << m_client.GetNume() << " " << m_client.GetPrenume() << std::endl;
    std::cout << "Medicamente:" << std::endl;

    for (size_t i = 0; i < m_items.size(); ++i) {
        std::cout << i + 1 << ". " << m_items[i].medicament->GetNume()
            << " x " << m_items[i].cantitate
            << " = " << m_items[i].pret_total << " RON" << std::endl;
    }

    std::cout << "Total brut: " << m_total_vanzare + m_discount << " RON" << std::endl;
    std::cout << "Discount: " << m_discount << " RON" << std::endl;
    std::cout << "Total de plata: " << m_total_vanzare << " RON" << std::endl;
}

void Vanzare::GenereazaBon() const {
    std::cout << "==================================================" << std::endl;
    std::cout << "                 FARMACIE BON FISCAL             " << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "Nr. bon: " << m_id << std::endl;
    std::cout << "Data: " << m_data << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::left << std::setw(30) << "Produs"
        << std::right << std::setw(10) << "Cantitate"
        << std::right << std::setw(10) << "Pret" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (const auto& item : m_items) {
        std::cout << std::left << std::setw(30) << item.medicament->GetNume()
            << std::right << std::setw(10) << item.cantitate
            << std::right << std::setw(10) << item.pret_total << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(30) << "Total brut:"
        << std::right << std::setw(20) << m_total_vanzare + m_discount << " RON" << std::endl;
    std::cout << std::left << std::setw(30) << "Discount:"
        << std::right << std::setw(20) << m_discount << " RON" << std::endl;
    std::cout << std::left << std::setw(30) << "Total de plata:"
        << std::right << std::setw(20) << m_total_vanzare << " RON" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "                Va multumim!                     " << std::endl;
    std::cout << "==================================================" << std::endl;
}

// Metode private
void Vanzare::_CalculeazaTotalHelper() {
    // Helper method pentru calcule complexe
}

void Vanzare::_AplicaDiscountHelper() {
    // Helper method pentru aplicarea discount-ului
}

// Supraincarcare operatori
Vanzare& Vanzare::operator=(const Vanzare& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_data = other.m_data;
        m_client = other.m_client;
        m_items = other.m_items;
        m_total_vanzare = other.m_total_vanzare;
        m_discount = other.m_discount;
    }
    return *this;
}

bool Vanzare::operator==(const Vanzare& other) const {
    return m_id == other.m_id;
}

Vanzare& Vanzare::operator+(const ItemVanzare& item) {
    if (item.cantitate <= 0 || item.medicament->GetCantitate() < item.cantitate) {
        std::cout << "Cantitate invalida sau stoc insuficient pentru adaugare prin operator!" << std::endl;
        return *this;
    }
    if (item.medicament->GetNecesitaReteta() && !m_client.GetAreAsigurare()) {
        std::cout << "Clientul nu poate cumpara acest medicament fara reteta prin operator!" << std::endl;
        return *this;
    }

    ItemVanzare new_item = item;
    new_item.pret_total = item.medicament->GetPret() * item.cantitate;
    m_items.push_back(new_item);
    CalculeazaTotal();
    return *this;
}