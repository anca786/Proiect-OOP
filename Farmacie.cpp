// Farmacie.cpp
#include "Farmacie.h"
#include <iostream>
#include <algorithm>
#include <map>

// Constructori
Farmacie::Farmacie() : nume(""), adresa(""), nextIdMedicament(1), nextIdClient(1), nextIdVanzare(1) {}

Farmacie::Farmacie(const std::string& nume, const std::string& adresa)
    : nume(nume), adresa(adresa), nextIdMedicament(1), nextIdClient(1), nextIdVanzare(1) {
}

Farmacie::Farmacie(const Farmacie& other)
    : nume(other.nume), adresa(other.adresa), stocMedicamente(other.stocMedicamente),
    clienti(other.clienti), vanzari(other.vanzari),
    nextIdMedicament(other.nextIdMedicament), nextIdClient(other.nextIdClient),
    nextIdVanzare(other.nextIdVanzare) {
}

// Destructor
Farmacie::~Farmacie() {}

// Getteri
std::string Farmacie::getNume() const { return nume; }
std::string Farmacie::getAdresa() const { return adresa; }

// Setteri
void Farmacie::setNume(const std::string& nume) { this->nume = nume; }
void Farmacie::setAdresa(const std::string& adresa) { this->adresa = adresa; }

// Metode pentru gestiunea medicamentelor
void Farmacie::adaugaMedicament(const std::string& nume, const std::string& producator,
    double pret, int cantitate, bool necesitaReteta) {
    Medicament medicament(nextIdMedicament++, nume, producator, pret, cantitate, necesitaReteta);
    stocMedicamente.push_back(medicament);
    std::cout << "Medicament adaugat cu succes!" << std::endl;
}

void Farmacie::actualizareMedicament(int id, const std::string& nume, const std::string& producator,
    double pret, int cantitate, bool necesitaReteta) {
    Medicament* medicament = cautaMedicament(id);
    if (medicament) {
        medicament->setNume(nume);
        medicament->setProducator(producator);
        medicament->setPret(pret);
        medicament->setCantitate(cantitate);
        medicament->setNecesitaReteta(necesitaReteta);
        std::cout << "Medicament actualizat cu succes!" << std::endl;
    }
    else {
        std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
    }
}

void Farmacie::stergeMedicament(int id) {
    auto it = std::find_if(stocMedicamente.begin(), stocMedicamente.end(),
        [id](const Medicament& m) { return m.getId() == id; });

    if (it != stocMedicamente.end()) {
        stocMedicamente.erase(it);
        std::cout << "Medicament sters cu succes!" << std::endl;
    }
    else {
        std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
    }
}

Medicament* Farmacie::cautaMedicament(int id) {
    auto it = std::find_if(stocMedicamente.begin(), stocMedicamente.end(),
        [id](const Medicament& m) { return m.getId() == id; });

    if (it != stocMedicamente.end()) {
        return &(*it);
    }
    return nullptr;
}

Medicament* Farmacie::cautaMedicamentDupaNume(const std::string& nume) {
    auto it = std::find_if(stocMedicamente.begin(), stocMedicamente.end(),
        [&nume](const Medicament& m) { return m.getNume() == nume; });

    if (it != stocMedicamente.end()) {
        return &(*it);
    }
    return nullptr;
}

void Farmacie::afisareMedicamente() const {
    std::cout << "Lista de medicamente in stoc:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (const auto& medicament : stocMedicamente) {
        medicament.afisare();
        std::cout << "----------------------------------------" << std::endl;
    }
}

void Farmacie::actualizeazaStoc(int id, int cantitate) {
    Medicament* medicament = cautaMedicament(id);
    if (medicament) {
        if (cantitate > 0) {
            medicament->adaugaStoc(cantitate);
            std::cout << "Stoc actualizat cu succes!" << std::endl;
        }
        else if (cantitate < 0) {
            if (medicament->scadeStoc(-cantitate)) {
                std::cout << "Stoc actualizat cu succes!" << std::endl;
            }
            else {
                std::cout << "Cantitate insuficienta in stoc!" << std::endl;
            }
        }
    }
    else {
        std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
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
// Supraincarcare operatori
Farmacie& Farmacie::operator=(const Farmacie& other) {
	if (this != &other) {
		nume = other.nume;
		adresa = other.adresa;
		stocMedicamente = other.stocMedicamente;
		clienti = other.clienti;
		vanzari = other.vanzari;
		nextIdMedicament = other.nextIdMedicament;
		nextIdClient = other.nextIdClient;
		nextIdVanzare = other.nextIdVanzare;
	}
	return *this;
}
void Farmacie::raportStoc() const {
	std::cout << "Raport stoc medicamente:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (const auto& medicament : stocMedicamente) {
		medicament.afisare();
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
void Farmacie::raportTopMedicamente() const {
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
}
int main()
{
	/*Farmacie farmacie("Farmacia Ta", "Strada Exemplu 123");
	farmacie.adaugaMedicament("Paracetamol", "Producator A", 10.0, 100, false);
	farmacie.adaugaMedicament("Ibuprofen", "Producator B", 15.0, 50, true);
	farmacie.afisareMedicamente();
	farmacie.adaugaClient("Ion", "Popescu", "1234567890123", true);
	farmacie.adaugaClient("Maria", "Ionescu", "9876543210987", false);
	farmacie.afisareClienti();
	Vanzare vanzare = farmacie.creeazaVanzare(1, "2023-10-01");
	farmacie.adaugaItemLaVanzare(vanzare.getId(), 1, 2);
	farmacie.finalizeazaVanzare(vanzare.getId());
	farmacie.raportStoc();
	farmacie.raportVanzariPerioada("2023-10-01", "2023-10-31");
	farmacie.actualizareMedicament(3,"Paracetamol","Producator A",10.0,100,"Nu");*/
	/*while (true)
	{
		std::cout << "1. Adauga medicament" << std::endl;
		std::cout << "2. Afiseaza medicamente" << std::endl;
		std::cout << "3. Cauta medicament" << std::endl;
		std::cout << "4. Actualizeaza medicament" << std::endl;
		std::cout << "5. Sterge medicament" << std::endl;
		std::cout << "6. Adauga client" << std::endl;
		std::cout << "7. Afiseaza clienti" << std::endl;
		std::cout << "8. Cauta client" << std::endl;
		std::cout << "9. Actualizeaza client" << std::endl;
		std::cout << "10. Sterge client" << std::endl;
		std::cout << "11. Adauga vanzare" << std::endl;
		std::cout << "12. Afiseaza vanzari" << std::endl;
		std::cout << "13. Cauta vanzare" << std::endl;
		std::cout << "14. Actualizeaza vanzare" << std::endl;
		std::cout << "15. Sterge vanzare" << std::endl;
		std::cout << "16. Raport stoc medicamente" << std::endl;
		std::cout << "17. Raport vanzari perioada" << std::endl;
		std::cout << "18. Raport vanzari client" << std::endl;
		std::cout << "19. Raport top medicamente" << std::endl;
		std::cout << "0. Iesi din program" << std::endl;
		int optiune;
		std::cin >> optiune;
		if (optiune == 1)
		{
			std::string nume, producator;
			double pret;
			int cantitate;
			bool necesitaReteta;
			std::cout << "Introduceti numele medicamentului: ";
			std::cin >> nume;
			std::cout << "Introduceti producatorul medicamentului: ";
			std::cin >> producator;
			std::cout << "Introduceti pretul medicamentului: ";
			std::cin >> pret;
			std::cout << "Introduceti cantitatea medicamentului: ";
			std::cin >> cantitate;
			std::cout << "Necesar reteta? (1 - da, 0 - nu): ";
			std::cin >> necesitaReteta;
			adaugaMedicament(nume, producator, pret, cantitate, necesitaReteta);
		}
		else if (optiune == 2)
		{
			afisareMedicamente();
		}
		else if (optiune == 3)
		{
			int id;
			std::cout << "Introduceti ID-ul medicamentului: ";
			std::cin >> id;
			Medicament* medicament = cautaMedicament(id);
			if (medicament)
				medicament->afisare();
			else
				std::cout << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
		}
		else if (optiune == 4)
		{
			int id;
			std::string nume, producator;
			double pret;
			int cantitate;
			bool necesitaReteta;
			std::cout << "Introduceti ID-ul medicamentului de actualizat: ";
			std::cin >> id;
			std::cout << "Introduceti noul nume al medicamentului: ";
			std::cin >> nume;
			std::cout << "Introduceti noul producator al medicamentului: ";
			std::cin >> producator;
			std::cout << "Introduceti noul pret al medicamentului: ";
			std::cin >> pret;
			std::cout << "Introduceti noua cantitate a medicamentului: ";
			std::cin >> cantitate;
			std::cout << "Necesar reteta? (1 - da, 0 - nu
	}*/
	return 0;
}
