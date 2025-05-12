// Angajat.cpp
#include "Angajat.h"
#include <iostream>
#include <algorithm>
#include <sstream>

// Constructori
Angajat::Angajat()
    : id(0), nume(""), prenume(""), cnp(""), dataAngajare(""),
    salariu(0.0), tip(TipAngajat::CASIER), esteActiv(true), oreLucrateLuna(0) {
}

Angajat::Angajat(int id, const std::string& nume, const std::string& prenume,
    const std::string& cnp, const std::string& dataAngajare,
    double salariu, TipAngajat tip)
    : id(id), nume(nume), prenume(prenume), cnp(cnp), dataAngajare(dataAngajare),
    salariu(salariu), tip(tip), esteActiv(true), oreLucrateLuna(0) {
}

Angajat::Angajat(const Angajat& other)
    : id(other.id), nume(other.nume), prenume(other.prenume), cnp(other.cnp),
    dataAngajare(other.dataAngajare), salariu(other.salariu), tip(other.tip),
    esteActiv(other.esteActiv), oreLucrateLuna(other.oreLucrateLuna),
    tureLucrate(other.tureLucrate) {
}

// Destructor
Angajat::~Angajat() {}

// Getteri
int Angajat::getId() const { return id; }
std::string Angajat::getNume() const { return nume; }
std::string Angajat::getPrenume() const { return prenume; }
std::string Angajat::getCnp() const { return cnp; }
std::string Angajat::getDataAngajare() const { return dataAngajare; }
double Angajat::getSalariu() const { return salariu; }
TipAngajat Angajat::getTip() const { return tip; }
bool Angajat::getEsteActiv() const { return esteActiv; }
int Angajat::getOreLucrateLuna() const { return oreLucrateLuna; }
std::vector<std::string> Angajat::getTureLucrate() const { return tureLucrate; }

// Setteri
void Angajat::setId(int id) { this->id = id; }
void Angajat::setNume(const std::string& nume) { this->nume = nume; }
void Angajat::setPrenume(const std::string& prenume) { this->prenume = prenume; }
void Angajat::setCnp(const std::string& cnp) { this->cnp = cnp; }
void Angajat::setDataAngajare(const std::string& dataAngajare) { this->dataAngajare = dataAngajare; }
void Angajat::setSalariu(double salariu) { this->salariu = salariu; }
void Angajat::setTip(TipAngajat tip) { this->tip = tip; }
void Angajat::setEsteActiv(bool esteActiv) { this->esteActiv = esteActiv; }

// Alte metode
void Angajat::adaugaTura(const std::string& data, int oraInceput, int oraFinal) {
    if (oraInceput < 0 || oraInceput > 23 || oraFinal < 0 || oraFinal > 23 || oraInceput >= oraFinal) {
        std::cout << "Intervalul orar este invalid!" << std::endl;
        return;
    }

    std::string turaCod = data + ":" + std::to_string(oraInceput) + "-" + std::to_string(oraFinal);

    // Verificăm dacă tura există deja
    auto it = std::find(tureLucrate.begin(), tureLucrate.end(), turaCod);
    if (it != tureLucrate.end()) {
        std::cout << "Această tură există deja în program!" << std::endl;
        return;
    }

    tureLucrate.push_back(turaCod);
    std::cout << "Tură adăugată cu succes!" << std::endl;
}

void Angajat::stergeTura(const std::string& turaCod) {
    auto it = std::find(tureLucrate.begin(), tureLucrate.end(), turaCod);
    if (it != tureLucrate.end()) {
        tureLucrate.erase(it);
        std::cout <<"Tură ștearsă cu succes!" << std::endl;
    }
    else {
        std::cout << "Această tură nu există în program!" << std::endl;
    }
}

void Angajat::calculeazaOreLucrateLuna(const std::string& luna) {
    oreLucrateLuna = 0;

    for (const auto& tura : tureLucrate) {
        // Verificăm dacă tura este din luna specificată
        if (tura.substr(0, 7) == luna) {
            // Extragem orele din formatul "YYYY-MM-DD:HH-HH"
            size_t pos1 = tura.find(":");
            size_t pos2 = tura.find("-", pos1);

            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                int oraInceput = std::stoi(tura.substr(pos1 + 1, pos2 - pos1 - 1));
                int oraFinal = std::stoi(tura.substr(pos2 + 1));

                oreLucrateLuna += (oraFinal - oraInceput);
            }
        }
    }
}

double Angajat::calculeazaSalariuLunar(const std::string& luna) const {
    // Presupunem un salariu de bază plus ore suplimentare
    int oreLucrate = 0;

    for (const auto& tura : tureLucrate) {
        // Verificăm dacă tura este din luna specificată
        if (tura.substr(0, 7) == luna) {
            // Extragem orele din formatul "YYYY-MM-DD:HH-HH"
            size_t pos1 = tura.find(":");
            size_t pos2 = tura.find("-", pos1);

            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                int oraInceput = std::stoi(tura.substr(pos1 + 1, pos2 - pos1 - 1));
                int oraFinal = std::stoi(tura.substr(pos2 + 1));

                oreLucrate += (oraFinal - oraInceput);
            }
        }
    }

    // Presupunem 160 de ore standard pe lună
    const int oreStandard = 160;
    double salariuLunar = salariu;

    if (oreLucrate > oreStandard) {
        // Ore suplimentare plătite cu 150%
        double tarifOrar = salariu / oreStandard;
        salariuLunar += (oreLucrate - oreStandard) * tarifOrar * 1.5;
    }

    return salariuLunar;
}

std::string Angajat::getTipAngajatString() const {
    switch (tip) {
    case TipAngajat::FARMACIST:
        return "Farmacist";
    case TipAngajat::ASISTENT_FARMACIST:
        return "Asistent farmacist";
    case TipAngajat::CASIER:
        return "Casier";
    case TipAngajat::MANAGER:
        return "Manager";
    case TipAngajat::ADMINISTRATOR:
        return "Administrator";
    default:
        return "Necunoscut";
    }
}

bool Angajat::poateEliberaReteta() const {
    // Doar farmaciștii și asistenții farmaciști pot elibera rețete
    return tip == TipAngajat::FARMACIST || tip == TipAngajat::ASISTENT_FARMACIST;
}

void Angajat::afisare() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nume: " << nume << " " << prenume << std::endl;
    std::cout << "CNP: " << cnp << std::endl;
    std::cout << "Data angajare: " << dataAngajare << std::endl;
    std::cout << "Salariu: " << salariu << " RON" << std::endl;
    std::cout << "Tip angajat: " << getTipAngajatString() << std::endl;
    std::cout << "Status: " << (esteActiv ? "Activ" : "Inactiv") << std::endl;
    std::cout << "Ore lucrate luna curentă: " << oreLucrateLuna << std::endl;
}

// Supraincarcare operatori
Angajat& Angajat::operator=(const Angajat& other) {
    if (this != &other) {
        id = other.id;
        nume = other.nume;
        prenume = other.prenume;
        cnp = other.cnp;
        dataAngajare = other.dataAngajare;
        salariu = other.salariu;
        tip = other.tip;
        esteActiv = other.esteActiv;
        oreLucrateLuna = other.oreLucrateLuna;
        tureLucrate = other.tureLucrate;
    }
    return *this;
}

bool Angajat::operator==(const Angajat& other) const {
    return cnp == other.cnp;
}

std::ostream& operator<<(std::ostream& os, const Angajat& angajat)
{
    os << "ID: " << angajat.id << "\n";
    os << "Nume: " << angajat.nume << " " << angajat.prenume << "\n";
    os << "CNP: " << angajat.cnp << "\n";
    os << "Data angajare: " << angajat.dataAngajare << "\n";
    os << "Salariu: " << angajat.salariu << " RON\n";
    os << "Tip angajat: " << angajat.getTipAngajatString() << "\n";
    os << "Status: " << (angajat.esteActiv ? "Activ" : "Inactiv") << "\n";
    os << "Ore lucrate luna curentă: " << angajat.oreLucrateLuna << "\n";
    return os;
}
