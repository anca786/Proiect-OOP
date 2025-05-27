// angajat.cpp
#include "angajat.h"
#include <iostream>
#include <algorithm>
#include <sstream>

// Constructori
Angajat::Angajat()
    : m_id(0), m_nume(""), m_prenume(""), m_cnp(""), m_data_angajare(""),
    m_salariu(0.0), m_tip(Tip_Angajat::CASIER), m_este_activ(true), m_ore_lucrate_luna(0) {
}

Angajat::Angajat(int id, const std::string& nume, const std::string& prenume, 
    const std::string& cnp, const std::string& data_angajare,
    double salariu, Tip_Angajat tip)
    : m_id(id), m_nume(nume), m_prenume(prenume), m_cnp(cnp), m_data_angajare(data_angajare),
    m_salariu(salariu), m_tip(tip), m_este_activ(true), m_ore_lucrate_luna(0) {
}

Angajat::Angajat(const Angajat& other)
    : m_id(other.m_id), m_nume(other.m_nume), m_prenume(other.m_prenume), m_cnp(other.m_cnp),
    m_data_angajare(other.m_data_angajare), m_salariu(other.m_salariu), m_tip(other.m_tip),
    m_este_activ(other.m_este_activ), m_ore_lucrate_luna(other.m_ore_lucrate_luna),
    m_ture_lucrate(other.m_ture_lucrate) {
}

// Destructor
Angajat::~Angajat() {}

// Getteri
int Angajat::GetId() const { return m_id; }
std::string Angajat::GetNume() const { return m_nume; }
std::string Angajat::GetPrenume() const { return m_prenume; }
std::string Angajat::GetCnp() const { return m_cnp; }
std::string Angajat::GetDataAngajare() const { return m_data_angajare; }
double Angajat::GetSalariu() const { return m_salariu; }
Tip_Angajat Angajat::GetTip() const { return m_tip; }
bool Angajat::GetEsteActiv() const { return m_este_activ; }
int Angajat::GetOreLucrateLuna() const { return m_ore_lucrate_luna; }
std::vector<std::string> Angajat::GetTureLucrate() const { return m_ture_lucrate; }

// Setteri
void Angajat::SetId(int id) { this->m_id = id; }
void Angajat::SetNume(const std::string& nume) { this->m_nume = nume; }
void Angajat::SetPrenume(const std::string& prenume) { this->m_prenume = prenume; }
void Angajat::SetCnp(const std::string& cnp) { this->m_cnp = cnp; }
void Angajat::SetDataAngajare(const std::string& data_angajare) { this->m_data_angajare = data_angajare; }
void Angajat::SetSalariu(double salariu) { this->m_salariu = salariu; }
void Angajat::SetTip(Tip_Angajat tip) { this->m_tip = tip; }
void Angajat::SetEsteActiv(bool este_activ) { this->m_este_activ = este_activ; }

// Alte metode
void Angajat::AdaugaTura(const std::string& data, int ora_inceput, int ora_final) {       // Adauga o tura lucrata
    if (ora_inceput < 0 || ora_inceput > 23 || ora_final < 0 || ora_final > 23 || ora_inceput >= ora_final) {
        std::cout << "Intervalul orar este invalid!" << std::endl;
        return;
    }

    std::string tura_cod = data + ":" + std::to_string(ora_inceput) + "-" + std::to_string(ora_final);    //modul in care este salvata o tura YYYY-MM-DD:HH-HH


    auto it = std::find(m_ture_lucrate.begin(), m_ture_lucrate.end(), tura_cod);  // Cauta daca tura exista deja,iar daca nu exista o adauga
    if (it != m_ture_lucrate.end()) {
        std::cout << "Această tură există deja în program!" << std::endl;
        return;
    }

    m_ture_lucrate.push_back(tura_cod);
    std::cout << "Tură adăugată cu succes!" << std::endl;
}

void Angajat::StergeTura(const std::string& tura_cod) {   //Sterge o tura existenta
    auto it = std::find(m_ture_lucrate.begin(), m_ture_lucrate.end(), tura_cod);
    if (it != m_ture_lucrate.end()) {
        m_ture_lucrate.erase(it);
        std::cout << "Tură ștearsă cu succes!" << std::endl;
    }
    else {
        std::cout << "Această tură nu există în program!" << std::endl;
    }
}

void Angajat::CalculeazaOreLucrateLuna(const std::string& luna) {   //Calculeaza orele lucrrate intr-o anumita luna
    m_ore_lucrate_luna = 0;

    for (const auto& tura : m_ture_lucrate) {
        if (tura.substr(0, 7) == luna) {    //verifica daca tura se incadreaza in luna specificate
            size_t pos1 = tura.find(":");          //cauta ora la care incepe tura
            size_t pos2 = tura.find("-", pos1);     //cauta ora la care se termina tura

            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                int ora_inceput = std::stoi(tura.substr(pos1 + 1, pos2 - pos1 - 1));   //extrage ora de inceput,respectiv de final
                int ora_final = std::stoi(tura.substr(pos2 + 1));

                m_ore_lucrate_luna += (ora_final - ora_inceput);
            }
        }
    }
}

double Angajat::CalculeazaSalariuLunar(const std::string& luna) const {
    int ore_lucrate = 0;

    for (const auto& tura : m_ture_lucrate) {           //calculeaza cate ore a lucrat un angajat intr-o anumita luna ca mai sus
        if (tura.substr(0, 7) == luna) {
            size_t pos1 = tura.find(":");
            size_t pos2 = tura.find("-", pos1);

            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                int ora_inceput = std::stoi(tura.substr(pos1 + 1, pos2 - pos1 - 1));
                int ora_final = std::stoi(tura.substr(pos2 + 1));

                ore_lucrate += (ora_final - ora_inceput);
            }
        }
    }

    const int ore_standard = 160;
    double salariu_lunar = m_salariu;            

    if (ore_lucrate > ore_standard) {               //calculeaza salariul in functie de cate ore a lucrat angajatul in acea luna
        double tarif_orar = m_salariu / ore_standard; 
        salariu_lunar += (ore_lucrate - ore_standard) * tarif_orar * 1.5;
    }

    return salariu_lunar;
}

std::string Angajat::GetTipAngajatString() const {    //returneaza tipul angajatului 
    switch (m_tip) {
    case Tip_Angajat::FARMACIST:
        return "Farmacist";
    case Tip_Angajat::ASISTENT_FARMACIST:
        return "Asistent farmacist";
    case Tip_Angajat::CASIER:
        return "Casier";
    case Tip_Angajat::MANAGER:
        return "Manager";
    case Tip_Angajat::ADMINISTRATOR:
        return "Administrator";
    default:
        return "Necunoscut";
    }
}

/*bool Angajat::PoateEliberaReteta() const {
	return m_tip == Tip_Angajat::FARMACIST || m_tip == Tip_Angajat::ASISTENT_FARMACIST;  //verifica daca angajatul poate elibera retete
}*/

void Angajat::Afisare() const {
    std::cout << "ID: " << m_id << std::endl;
    std::cout << "Nume: " << m_nume << " " << m_prenume << std::endl;
    std::cout << "CNP: " << m_cnp << std::endl;
    std::cout << "Data angajare: " << m_data_angajare << std::endl;
    std::cout << "Salariu: " << m_salariu << " RON" << std::endl;
    std::cout << "Tip angajat: " << GetTipAngajatString() << std::endl;
    std::cout << "Status: " << (m_este_activ ? "Activ" : "Inactiv") << std::endl;
    std::cout << "Ore lucrate luna curentă: " << m_ore_lucrate_luna << std::endl;
}

// Supraincarcare operatori
Angajat& Angajat::operator=(const Angajat& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_nume = other.m_nume;
        m_prenume = other.m_prenume;
        m_cnp = other.m_cnp;
        m_data_angajare = other.m_data_angajare;
        m_salariu = other.m_salariu;
        m_tip = other.m_tip;
        m_este_activ = other.m_este_activ;
        m_ore_lucrate_luna = other.m_ore_lucrate_luna;
        m_ture_lucrate = other.m_ture_lucrate;
    }
    return *this;
}

bool Angajat::operator==(const Angajat& other) const {
    return m_cnp == other.m_cnp;
}

std::ostream& operator<<(std::ostream& os, const Angajat& angajat)
{
    os << "ID: " << angajat.GetId() << "\n";
    os << "Nume: " << angajat.GetNume() << " " << angajat.GetPrenume() << "\n";
    os << "CNP: " << angajat.GetCnp() << "\n";
    os << "Data angajare: " << angajat.GetDataAngajare() << "\n";
    os << "Salariu: " << angajat.GetSalariu() << " RON\n";
    os << "Tip angajat: " << angajat.GetTipAngajatString() << "\n";
    os << "Status: " << (angajat.GetEsteActiv() ? "Activ" : "Inactiv") << "\n";
    os << "Ore lucrate luna curentă: " << angajat.GetOreLucrateLuna() << "\n";
    return os;
}