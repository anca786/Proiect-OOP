// Farmacie.cpp
#include "Farmacie.h"
#include <iostream>
#include <algorithm>
#include <map>
#include "Analgezic.h"
#include "Antibiotic.h"
#include "Probiotic.h"
#include "Sirop.h"

// Constructori
Farmacie::Farmacie() : nume(""), adresa(), nextIdMedicament(1), nextIdClient(1), nextIdVanzare(1) {}

Farmacie::Farmacie(const std::string& nume, const Adresa& adresa)
    : nume(nume), adresa(adresa), nextIdMedicament(1), nextIdClient(1), nextIdVanzare(1) {
}

Farmacie::Farmacie(const Farmacie& other)
    : nume(other.nume), adresa(other.adresa),
    clienti(other.clienti), vanzari(other.vanzari),
    nextIdMedicament(other.nextIdMedicament), nextIdClient(other.nextIdClient),
    nextIdVanzare(other.nextIdVanzare) {
	for (const auto& med_ptr : other.stocMedicamente){
		if (med_ptr) {
			stocMedicamente.push_back(med_ptr->clone());
		}
	}
	
}

// Destructor
Farmacie::~Farmacie() {
	for (Medicament* med : stocMedicamente) {
		delete med; 
	}
	stocMedicamente.clear();
}

// Getteri
std::string Farmacie::getNume() const { return nume; }
Adresa Farmacie::getAdresa() const { return adresa; }

// Setteri
void Farmacie::setNume(const std::string& nume) { this->nume = nume; }
void Farmacie::setAdresa(const Adresa& adresa) { this->adresa = adresa; }

// Metode pentru gestiunea medicamentelor
void Farmacie::adaugaMedicament(Medicament* med) {
	if (med) {
		med->setId(nextIdMedicament++);
		stocMedicamente.push_back(med);
	}
}

void Farmacie::actualizareMedicament(int id, const std::string& nume, const std::string& producator,
    double pret, int cantitate, bool necesitaReteta) {
    Medicament* med = cautaMedicament(id);
    if (med) {
        med->setNume(nume);
        med->setProducator(producator);
        med->setPret(pret);
        med->setCantitate(cantitate);
        med->setNecesitaReteta(necesitaReteta);
        std::cout << "Medicament actualizat cu succes!" << std::endl;
    } else {
        std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
    }
}

void Farmacie::stergeMedicament(int id) { 
	auto it = std::remove_if(stocMedicamente.begin(), stocMedicamente.end(),
		[id](Medicament* med) {
			if (med && med->getId() == id) {
				delete med; 
				return true;
			}
			return false;
		});
	stocMedicamente.erase(it, stocMedicamente.end());
	if (it != stocMedicamente.end()) {
		std::cout << "Medicamentul cu ID-ul " << id << " a fost sters cu succes!" << std::endl;
	}
	else {
		std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}

Medicament* Farmacie::cautaMedicament(int id) {
	for (Medicament* med : stocMedicamente) {
		if (med && med->getId() == id) {
			return med;
		}
	}
	return nullptr;
}

Medicament* Farmacie::cautaMedicamentDupaNume(const std::string& nume) {
    auto it = std::find_if(stocMedicamente.begin(), stocMedicamente.end(),
        [&nume](const Medicament* m) { return m->getNume() == nume; });

    if (it != stocMedicamente.end()) {
        return *it;
    }
    return nullptr;
}

void Farmacie::afisareMedicamente() const {
	if (stocMedicamente.empty()) {
		std::cout << "Nu exista medicamente in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Medicamente in stoc ---" << std::endl;
	for (const auto& med : stocMedicamente) {
		if (med) {
			med->afisare();
			std::cout << "--------------------" << std::endl;
		}
	}
}

void Farmacie::afisareAnalgezice() const {
	if (stocMedicamente.empty()) {
		std::cout << "Nu exista analgezice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Analgezice in stoc ---" << std::endl;
	for (const auto& med : stocMedicamente) {
		if (med) {
			Analgezic* analgezic = dynamic_cast<Analgezic*>(med);
			if (analgezic) {
				analgezic->afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}

void Farmacie::afisareAntibiotice() const {
	if (stocMedicamente.empty()) {
		std::cout << "Nu exista antibiotice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Antibiotice in stoc ---" << std::endl;
	for (const auto& med : stocMedicamente) {
		if (med) {
			Antibiotic* antibiotic = dynamic_cast<Antibiotic*>(med);
			if (antibiotic) {
				antibiotic->afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}

void Farmacie::afisareProbiotice() const {
	if (stocMedicamente.empty()) {
		std::cout << "Nu exista probiotice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Probiotice in stoc ---" << std::endl;
	for (const auto& med : stocMedicamente) {
		if (med) {
			Probiotic* probiotic = dynamic_cast<Probiotic*>(med);
			if (probiotic) {
				probiotic->afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}

void Farmacie::afisareSiropuri() const {
	if (stocMedicamente.empty()) {
		std::cout << "Nu exista siropuri in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Siropuri in stoc ---" << std::endl;
	for (const auto& med : stocMedicamente) {
		if (med) {
			Sirop* sirop = dynamic_cast<Sirop*>(med);
			if (sirop) {
				sirop->afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}


// Metode pentru gestiunea clientilor
void Farmacie::adaugaClient(const std::string& nume, const std::string& prenume,
    const std::string& cnp, bool areAsigurare) {
    auto it = std::find_if(clienti.begin(), clienti.end(),
        [&cnp](const Client& c) { return c.getCnp() == cnp; });

    if (it != clienti.end()) {
        std::cout << "Un client cu acest CNP exista deja!" << std::endl;
        return;
    }

    Client client(nextIdClient++, nume, prenume, cnp, areAsigurare);
    clienti.push_back(client);
    std::cout << "Client adaugat cu succes!" << std::endl;
}

void Farmacie::actualizeazaClient(int id, const std::string& nume, const std::string& prenume,
    const std::string& cnp, bool areAsigurare) {
    Client* client = cautaClient(id);
    if (client) {
        auto it = std::find_if(clienti.begin(), clienti.end(),
            [&cnp, id](const Client& c) { return c.getCnp() == cnp && c.getId() != id; });

        if (it != clienti.end()) {
            std::cout << "Un alt client cu acest CNP exista deja!" << std::endl;
            return;
        }

        client->setNume(nume);
        client->setPrenume(prenume);
        client->setCnp(cnp);
        client->setAreAsigurare(areAsigurare);
        std::cout << "Client actualizat cu succes!" << std::endl;
    }
    else {
        std::cout << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
    }
}

void Farmacie::stergeClient(int id) {
    auto it = std::find_if(clienti.begin(), clienti.end(),
        [id](const Client& c) { return c.getId() == id; });

    if (it != clienti.end()) {
        clienti.erase(it);
        std::cout << "Client sters cu succes" << std::endl;
    }
    else {
        std::cout << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
    }
}
Client* Farmacie::cautaClient(int id) {
	auto it = std::find_if(clienti.begin(), clienti.end(),
		[id](const Client& c) { return c.getId() == id; });
	if (it != clienti.end()) {
		return &(*it);
	}
	return nullptr;
}      
Client* Farmacie::cautaClientDupaCnp(const std::string& cnp) {
	auto it = std::find_if(clienti.begin(), clienti.end(),
		[&cnp](const Client& c) { return c.getCnp() == cnp; });
	if (it != clienti.end()) {
		return &(*it);
	}
	return nullptr;
}
void Farmacie::afisareClienti() const {
	std::cout << "Lista de clienti:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& client : clienti) {
		client.afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}
// Metode pentru gestiunea vanzarilor
Vanzare Farmacie::creeazaVanzare(int idClient, const std::string& data) {
	Client* client = cautaClient(idClient);
	if (client) {
		Vanzare vanzare(nextIdVanzare++, data, *client);
		vanzari.push_back(vanzare);
		return vanzare;
	}
	else {
		std::cout << "Clientul cu ID-ul " << idClient << " nu a fost gasit!" << std::endl;
		return Vanzare();
	}
}
Vanzare* Farmacie::cautaVanzare(int id) {
	auto it = std::find_if(vanzari.begin(), vanzari.end(),
		[id](const Vanzare& v) { return v.getId() == id; });
	if (it != vanzari.end()) {
		return &(*it);
	}
	return nullptr;
}
void Farmacie::adaugaVanzare(const Client& client) {
	Vanzare vanzare(nextIdVanzare++, "2023-10-01", client);
	vanzari.push_back(vanzare);
	std::cout << "Vanzare adaugata cu succes!" << std::endl;
}
void Farmacie::actualizeazaVanzare(int id, const Client& client) {
	Vanzare* vanzare = cautaVanzare(id);
	if (vanzare) {
		vanzare->setClient(client);
		std::cout << "Vanzare actualizata cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::stergeVanzare(int id) {
	auto it = std::find_if(vanzari.begin(), vanzari.end(),
		[id](const Vanzare& v) { return v.getId() == id; });
	if (it != vanzari.end()) {
		vanzari.erase(it);
		std::cout << "Vanzare stearsa cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::afisareVanzari() const {
	std::cout << "Lista de vanzari:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : vanzari) {
		vanzare.afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}
void Farmacie::afisareVanzare(int idVanzare) {
	Vanzare* vanzare = cautaVanzare(idVanzare);
	if (vanzare) {
		vanzare->afisare();
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << idVanzare << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::adaugaItemLaVanzare(int idVanzare, int idMedicament, int cantitate) {
	Vanzare* vanzare = cautaVanzare(idVanzare);
	Medicament* medicament = cautaMedicament(idMedicament);
	if (vanzare && medicament) {
		vanzare->adaugaItem(*medicament, cantitate);
		std::cout << "Item adaugat la vanzare cu succes!" << std::endl;
	}
	else {
		if (!vanzare) {
			std::cout << "Vanzarea cu ID-ul " << idVanzare << " nu a fost gasita!" << std::endl;
		}
		if (!medicament) {
			std::cout << "Medicamentul cu ID-ul " << idMedicament << " nu a fost gasit!" << std::endl;
		}
	}
}
void Farmacie::stergeItemDinVanzare(int idVanzare, int indexItem) {
	Vanzare* vanzare = cautaVanzare(idVanzare);
	if (vanzare) {
		vanzare->stergeItem(indexItem);
		std::cout << "Item sters din vanzare cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << idVanzare << " nu a fost gasita!" << std::endl;
	}
}   
void Farmacie::finalizeazaVanzare(int idVanzare) {
	Vanzare* vanzare = cautaVanzare(idVanzare);
	if (vanzare) {
		vanzare->genereazaBon();
		std::cout << "Vanzare finalizata cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << idVanzare << " nu a fost gasita!" << std::endl;
	}
}

void Farmacie::raportStoc() const {
	std::cout << "Raport stoc medicamente:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& medicament : stocMedicamente) {
		medicament->afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}
void Farmacie::raportVanzariPerioada(const std::string& dataInceput, const std::string& dataSfarsit) const {
	std::cout << "Raport vanzari perioada " << dataInceput << " - " << dataSfarsit << ":" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : vanzari) {
		if (vanzare.getData() >= dataInceput && vanzare.getData() <= dataSfarsit) {
			vanzare.afisare();
			std::cout << "----------------------------------------" << std::endl;
		}
	}
}
void Farmacie::raportVanzariClient(int idClient) const {
	std::cout << "Raport vanzari pentru clientul cu ID-ul " << idClient << ":" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : vanzari) {
		if (vanzare.getClient().getId() == idClient) {
			vanzare.afisare();
			std::cout << "----------------------------------------" << std::endl;
		}
	}
}
/*void Farmacie::raportTopMedicamente() const {
	std::cout << "Raport top medicamente:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::map<std::string, int> medicamenteVandute;
	for (const auto& vanzare : vanzari) {
		for (const auto& item : vanzare.getItems()) {
			medicamenteVandute[item.medicament.getNume()] += item.cantitate;
		}
	}
	std::vector<std::pair<std::string, int>> topMedicamente(medicamenteVandute.begin(), medicamenteVandute.end());
	std::sort(topMedicamente.begin(), topMedicamente.end(),
		[](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
			return a.second > b.second;
		});
	for (const auto& medicament : topMedicamente) {
		std::cout << "Medicament: " << medicament.first << ", Cantitate vanduta: " << medicament.second << std::endl;
	}
}*/

// Supraincarcare operatori
Farmacie& Farmacie::operator=(const Farmacie& other) {
	if (this != &other) {
		for (Medicament* med : stocMedicamente) {
			delete med;
		}
		stocMedicamente.clear();
		nume = other.nume;
		adresa = other.adresa;
		clienti = other.clienti;
		vanzari = other.vanzari;
		nextIdMedicament = other.nextIdMedicament;
		nextIdClient = other.nextIdClient;
		nextIdVanzare = other.nextIdVanzare;
		for (const auto& med_ptr : other.stocMedicamente) {
			if (med_ptr) {
				stocMedicamente.push_back(med_ptr->clone()); 
			}
		}

	}
	return *this;
}
