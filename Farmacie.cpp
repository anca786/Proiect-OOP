// farmacie.cpp
#include "farmacie.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include "Analgezic.h"
#include "Antibiotic.h"
#include "Probiotic.h"
#include "Sirop.h"

// Constructori
Farmacie::Farmacie() : m_nume(""), m_adresa(), m_next_id_medicament(1), m_next_id_client(1), m_next_id_vanzare(1) {}

Farmacie::Farmacie(const std::string& nume, const Adresa& adresa)
	: m_nume(nume), m_adresa(adresa), m_next_id_medicament(1), m_next_id_client(1), m_next_id_vanzare(1) {
}

Farmacie::Farmacie(const Farmacie& other)
	: m_nume(other.m_nume), m_adresa(other.m_adresa),
	m_clienti(other.m_clienti), m_vanzari(other.m_vanzari),
	m_next_id_medicament(other.m_next_id_medicament), m_next_id_client(other.m_next_id_client),
	m_next_id_vanzare(other.m_next_id_vanzare) {
	for (const auto& med_ptr : other.m_stoc_medicamente) {
		if (med_ptr) {
			m_stoc_medicamente.push_back(med_ptr->Clone());
		}
	}

}

// Destructor
Farmacie::~Farmacie() {
	for (Medicament* med : m_stoc_medicamente) {
		delete med;
	}
	m_stoc_medicamente.clear();
}

// Getteri
std::string Farmacie::GetNume() const { return m_nume; }
Adresa Farmacie::GetAdresa() const { return m_adresa; }

// Setteri
void Farmacie::SetNume(const std::string& nume) { this->m_nume = nume; }
void Farmacie::SetAdresa(const Adresa& adresa) { this->m_adresa = adresa; }

// Metode pentru gestiunea medicamentelor
void Farmacie::AdaugaMedicament(Medicament* med) {
	if (med) {
		med->SetId(m_next_id_medicament++);
		m_stoc_medicamente.push_back(med);
	}
}

void Farmacie::ActualizareMedicament(int id, const std::string& nume, const std::string& producator,      //actualizeaza un medicament dupa ID
	double pret, int cantitate, bool necesita_reteta) {
	Medicament* med = CautaMedicament(id);
	if (med) {
		med->SetNume(nume);
		med->SetProducator(producator);
		med->SetPret(pret);
		med->SetCantitate(cantitate);
		med->SetNecesitaReteta(necesita_reteta);
		std::cout << "Medicament actualizat cu succes!" << std::endl;
	}
	else {
		std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}

void Farmacie::StergeMedicament(int id) {                                                    // sterge un medicament dupa ID
	auto it = std::remove_if(m_stoc_medicamente.begin(), m_stoc_medicamente.end(),
		[id](Medicament* med) {
			if (med && med->GetId() == id) {
				delete med;
				return true;
			}
			return false;
		});
	m_stoc_medicamente.erase(it, m_stoc_medicamente.end());
	if (it != m_stoc_medicamente.end()) {
		std::cout << "Medicamentul cu ID-ul " << id << " a fost sters cu succes!" << std::endl;
	}
	else {
		std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}

Medicament* Farmacie::CautaMedicament(int id) {        // cauta un medicament dupa ID
	for (Medicament* med : m_stoc_medicamente) {
		if (med && med->GetId() == id) {
			return med;
		}
	}
	return nullptr;
}

Medicament* Farmacie::CautaMedicamentDupaNume(const std::string& nume) {           // cauta un medicament dupa nume
	auto it = std::find_if(m_stoc_medicamente.begin(), m_stoc_medicamente.end(),
		[&nume](const Medicament* m) { return m->GetNume() == nume; });

	if (it != m_stoc_medicamente.end()) {
		return *it;
	}
	return nullptr;
}

void Farmacie::AfisareMedicamente() const {                  // afiseaza toate medicamentele din stoc,indiferent de tipul lor
	if (m_stoc_medicamente.empty()) {
		std::cout << "Nu exista medicamente in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Medicamente in stoc ---" << std::endl;
	for (const auto& med : m_stoc_medicamente) {
		if (med) {
			med->Afisare();
			std::cout << "--------------------" << std::endl;
		}
	}
}

void Farmacie::ActualizeazaStoc(int id, int cantitate)                         // actualizeaza cantitatea unui medicament in stoc
{               
	Medicament* med = CautaMedicament(id);
	if (med) {
		med->SetCantitate(med->GetCantitate() + cantitate);
		std::cout << "Stocul medicamentului cu ID-ul " << id << " a fost actualizat cu succes!" << std::endl;
	}
	else {
		std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}

void Farmacie::AfisareAnalgezice() const {                          // afiseaza toate analgezicele din stoc
	if (m_stoc_medicamente.empty()) {
		std::cout << "Nu exista analgezice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Analgezice in stoc ---" << std::endl;
	for (const auto& med : m_stoc_medicamente) {
		if (med) {
			Analgezic* analgezic = dynamic_cast<Analgezic*>(med);
			if (analgezic) {
				analgezic->Afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}
 
void Farmacie::AfisareAntibiotice() const {                          // afiseaza toate antibioticele din stoc
	if (m_stoc_medicamente.empty()) {
		std::cout << "Nu exista antibiotice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Antibiotice in stoc ---" << std::endl;
	for (const auto& med : m_stoc_medicamente) {
		if (med) {
			Antibiotic* antibiotic = dynamic_cast<Antibiotic*>(med);
			if (antibiotic) {
				antibiotic->Afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}

void Farmacie::AfisareProbiotice() const {                              // afiseaza toate probioticele din stoc
	if (m_stoc_medicamente.empty()) {
		std::cout << "Nu exista probiotice in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Probiotice in stoc ---" << std::endl;
	for (const auto& med : m_stoc_medicamente) {
		if (med) {
			Probiotic* probiotic = dynamic_cast<Probiotic*>(med);
			if (probiotic) {
				probiotic->Afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}

void Farmacie::AfisareSiropuri() const {                                 // afiseaza toate siropurile din stoc
	if (m_stoc_medicamente.empty()) {
		std::cout << "Nu exista siropuri in stoc." << std::endl;
		return;
	}
	std::cout << "\n--- Siropuri in stoc ---" << std::endl;
	for (const auto& med : m_stoc_medicamente) {
		if (med) {
			Sirop* sirop = dynamic_cast<Sirop*>(med);
			if (sirop) {
				sirop->Afisare();
				std::cout << "--------------------" << std::endl;
			}
		}
	}
}


// Metode pentru gestiunea clientilor
void Farmacie::AdaugaClient(const std::string& nume, const std::string& prenume,               //adauga un client nou
	const std::string& cnp, bool are_asigurare) {
	if (cnp.size() != 13)
	{
		std::cout << " CNP-ul nu este valid!" << std::endl;
		return;
	}
	auto it = std::find_if(m_clienti.begin(), m_clienti.end(),
		[&cnp](const Client& c) { return c.GetCnp() == cnp; });

	if (it != m_clienti.end()) {
		std::cout << "Un client cu acest CNP exista deja!" << std::endl;
		return;
	}

	Client client(m_next_id_client++, nume, prenume, cnp, are_asigurare);
	m_clienti.push_back(client);
	std::cout << "Client adaugat cu succes!" << std::endl;
}

void Farmacie::ActualizeazaClient(int id, const std::string& nume, const std::string& prenume,              //actualizeza datele despre un client
	 bool are_asigurare) {
	Client* client = CautaClient(id);
	if (client) {
		auto it = std::find_if(m_clienti.begin(), m_clienti.end(),
			[id](const Client& c) { return c.GetId() != id; });

		if (it != m_clienti.end()) {
			std::cout << "Un alt client cu acest CNP exista deja!" << std::endl;
			return;
		}

		client->SetNume(nume);
		client->SetPrenume(prenume);
		client->SetAreAsigurare(are_asigurare);
		std::cout << "Client actualizat cu succes!" << std::endl;
	}
	else {
		std::cout << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}

void Farmacie::StergeClient(int id) {                                     // sterge un client dupa ID
	auto it = std::find_if(m_clienti.begin(), m_clienti.end(),
		[id](const Client& c) { return c.GetId() == id; });

	if (it != m_clienti.end()) {
		m_clienti.erase(it);
		std::cout << "Client sters cu succes" << std::endl;
	}
	else {
		std::cout << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
	}
}
Client* Farmacie::CautaClient(int id) {										// cauta un client dupa ID
	auto it = std::find_if(m_clienti.begin(), m_clienti.end(),
		[id](const Client& c) { return c.GetId() == id; });
	if (it != m_clienti.end()) {
		return &(*it);
	}
	return nullptr;
}
Client* Farmacie::CautaClientDupaCnp(const std::string& cnp) {					// cauta un client dupa CNP	
	auto it = std::find_if(m_clienti.begin(), m_clienti.end(),
		[&cnp](const Client& c) { return c.GetCnp() == cnp; });
	if (it != m_clienti.end()) {
		return &(*it);
	}
	return nullptr;
}
void Farmacie::AfisareClienti() const {									// afiseaza toti clientii din lista
	std::cout << "Lista de clienti:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& client : m_clienti) {
		client.Afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}
// Metode pentru gestiunea vanzarilor
Vanzare Farmacie::CreeazaVanzare(int id_client, const std::string& data) {         // creeaza o vanzare noua
	Client* client = CautaClient(id_client);
	if (client) {
		Vanzare vanzare(m_next_id_vanzare++, data, *client);
		m_vanzari.push_back(vanzare);
		std::cout << "Vanzare noua creata cu ID: " << vanzare.GetId() << std::endl;
		m_finalizata = false;
		return vanzare;
	}
	else {
		std::cout << "Clientul cu ID-ul " << id_client << " nu a fost gasit!" << std::endl;
		return Vanzare();
	}
}

Vanzare* Farmacie::CautaVanzare(int id) {         // cauta o vanzare dupa ID
	for (auto& vanzare : m_vanzari) {
		if (vanzare.GetId() == id) {
			return &vanzare;
		}
	}
	return nullptr;
}

void Farmacie::ActualizeazaVanzare(int id, const Client& client) {                   // actualizeaza o vanzare dupa ID
	Vanzare* vanzare = CautaVanzare(id);
	if (vanzare) {
		vanzare->SetClient(client);
		std::cout << "Vanzare actualizata cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::StergeVanzare(int id) {							// sterge o vanzare dupa ID
	auto it = std::find_if(m_vanzari.begin(), m_vanzari.end(),
		[id](const Vanzare& v) { return v.GetId() == id; });
	if (it != m_vanzari.end()) {
		m_vanzari.erase(it);
		std::cout << "Vanzare stearsa cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::AfisareVanzari() const {                  // afiseaza toate vanzarile din lista
	std::cout << "Lista de vanzari:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : m_vanzari) {
		vanzare.Afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}
void Farmacie::AfisareVanzare(int id_vanzare) {                     // afiseaza o vanzare dupa ID
	Vanzare* vanzare = CautaVanzare(id_vanzare);
	if (vanzare) {
		vanzare->Afisare();
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita!" << std::endl;
	}
}
void Farmacie::AdaugaItemLaVanzare(int id_vanzare, int id_medicament, int cantitate) {              // adauga un mediament la o vanzare existenta
		if (m_finalizata == true)
		{
			std::cout << "Vanzarea cu ID-ul " << id_vanzare << " a fost deja finalizata!" << std::endl;        //verifica daca vanzarea este finalizata,in caz pozitiv,nu mai adauga niciun medicament
			return;
		}
		Vanzare* vanzare = CautaVanzare(id_vanzare);
		if (!vanzare) {
			std::cout << "Eroare: Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita.\n";        //verifica daca vanzarea sau medicamentul exista
			return;
		}
		Medicament* medicament = CautaMedicament(id_medicament);
		if (vanzare && medicament) {

			vanzare->AdaugaItem(*medicament, cantitate);
			std::cout << "Medicamentul " << medicament->GetNume() << " a fost adaugat la vanzare cu succes!" << std::endl;        
		}
		else {
			if (!vanzare) {
				std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita!" << std::endl;
			}
			if (!medicament) {
				std::cout << "Medicamentul cu ID-ul " << id_medicament << " nu a fost gasit!" << std::endl;
			}
		}
}
void Farmacie::StergeItemDinVanzare(int id_vanzare, int index_item) {                  // sterge un item dintr-o vanzare existenta
	Vanzare* vanzare = CautaVanzare(id_vanzare);
	if (vanzare) {
		vanzare->StergeItem(index_item);
		std::cout << "Item sters din vanzare cu succes!" << std::endl;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita!" << std::endl;
	}
}

void Farmacie::FinalizeazaVanzare(int id_vanzare) {              // finalizeaza o vanzare existenta si genereaza bonul pentru aceasta
	Vanzare* vanzare = CautaVanzare(id_vanzare);
	if (vanzare) {
		vanzare->GenereazaBon();
		std::cout << "Vanzare finalizata cu succes!" << std::endl;
		m_finalizata = true;
	}
	else {
		std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita!" << std::endl;
	}
}



void Farmacie::RaportStoc() const {             // afiseaza raportul stocului de medicamente
	std::cout << "--- Raport stoc medicamente ---" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& medicament : m_stoc_medicamente) {
		medicament->Afisare();
		std::cout << "----------------------------------------" << std::endl;
	}
}


void Farmacie::RaportVanzariPerioada(const std::string& data_inceput, const std::string& data_sfarsit) const {             // afiseaza raportul vanzarilor pe o perioada specificata
	std::cout << "--- Raport vanzari perioada " << data_inceput << " - " << data_sfarsit << " ---" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : m_vanzari) {
		if (vanzare.GetData() >= data_inceput && vanzare.GetData() <= data_sfarsit) {
			vanzare.Afisare();
			std::cout << "----------------------------------------" << std::endl;
		}
	}
} 


void Farmacie::RaportVanzariClient(int id_client) const {                                 // afiseaza raportul vanzarilor pentru un client specificat
	std::cout << "--- Raport vanzari pentru clientul cu ID-ul " << id_client << " ---" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& vanzare : m_vanzari) {
		if (vanzare.GetClient().GetId() == id_client) {
			vanzare.Afisare();
			std::cout << "----------------------------------------" << std::endl;
		}
	}
}


void Farmacie::RaportTopMedicamente() const {               // afiseaza raportul celor mai vandute medicamente
	std::cout << std::endl << "--- Raport top medicamente ---" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::map<std::string, int> medicamente_vandute;
	for (const auto& vanzare : m_vanzari) {
		for (const auto& item : vanzare.GetItems()) {
			medicamente_vandute[item.medicament->GetNume()] += item.cantitate;        //cauta fiecare item din fiecare vanzare si le aduna cantitatile
		}
	}
	std::vector<std::pair<std::string, int>> top_medicamente(medicamente_vandute.begin(), medicamente_vandute.end());           //creeaza un vector pe care il initializeaza cu toate perechile pe care le gaseste in vanzari 
	std::sort(top_medicamente.begin(), top_medicamente.end(),                                                                  //le sorteaza dupa cantitate vanduta
		[](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {                                       //criteriu de sortare, sorteaza dupa al doleilea element al perechii ,cantitatea vanduta
			return a.second > b.second;
		});
	if (top_medicamente.empty()) {
		std::cout << "Nu s-au gasit medicamente vandute." << std::endl;
	}
	else {
		std::cout << std::left << std::setw(30) << "Medicament"               
			<< std::right << std::setw(20) << "Cantitate Vanduta\n";
		std::cout << "--------------------------------------------------\n";
		for (const auto& medicament : top_medicamente) {
			std::cout << std::left << std::setw(30) << medicament.first
				<< std::right << std::setw(20) << medicament.second << std::endl;
		}
	}
}

// Supraincarcare operatori
Farmacie& Farmacie::operator=(const Farmacie& other) {
	if (this != &other) {
		for (Medicament* med : m_stoc_medicamente) {
			delete med;
		}
		m_stoc_medicamente.clear();
		m_nume = other.m_nume;
		m_adresa = other.m_adresa;
		m_clienti = other.m_clienti;
		m_vanzari = other.m_vanzari;
		m_next_id_medicament = other.m_next_id_medicament;
		m_next_id_client = other.m_next_id_client;
		m_next_id_vanzare = other.m_next_id_vanzare;
		for (const auto& med_ptr : other.m_stoc_medicamente) {
			if (med_ptr) {
				m_stoc_medicamente.push_back(med_ptr->Clone());
			}
		}

	}
	return *this;
}