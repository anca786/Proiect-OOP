//Main
#include "Angajat.h"
#include "Reteta.h"
#include "Analgezic.h"
#include "Probiotic.h"
#include "Medicament.h"
#include "Client.h"
#include "Farmacie.h"
#include "Medicament.h"
#include "Antibiotic.h"
#include "Sirop.h"
#include "Vanzare.h"
#include<iostream>

int main()
{
	Adresa adresaFarmacie("Strada Teilor", 4, "Bucuresti", 254628);
	Farmacie farmacie("Pharmacin", adresaFarmacie);
	/*farmacie.adaugaMedicament("Paracetamol", "Producator A", 10.0, 100, false);
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
	while(true)
	{
		int opt;
		std::cout << "--- Meniu Principal Farmacie ---" << std::endl; 
		std::cout << "1. Gestionare Medicamente" << std::endl;
		std::cout << "2. Gestionare Clienti" << std::endl;
		std::cout << "3. Gestionare Vanzari" << std::endl;
		std::cout << "0. Iesire" << std::endl;
		std::cout << "Introduceti optiunea: ";
		std::cin >> opt;
		std::cout << std::endl;
		if (opt == 0)
			return 0;
		else if (opt == 1)
		{
			while (true)
			{
				std::cout << std::endl << "--- Gestionare Medicamente ---" << std::endl;
				std::cout << "1. Adauga medicament" << std::endl;
				std::cout << "2. Afiseaza medicamente" << std::endl;
				std::cout << "3. Afiseaza analgezice" << std::endl;
				std::cout << "4. Afiseaza siropuri" << std::endl;
				std::cout << "5. Afiseaza antibiotice" << std::endl;
				std::cout << "6. Afiseaza probiotice" << std::endl;
				std::cout << "7. Cauta medicament dupa id" << std::endl;
				std::cout << "8. Cauta medicament dupa nume" << std::endl;
				std::cout << "9. Actualizeaza medicament" << std::endl;
				std::cout << "0. Meniu principal" << std::endl;
				std::cout << "Introduceti optiunea: ";
				int optiune;
				std::cin >> optiune;
				std::cout << std::endl;
				std::cin.ignore();
				if (optiune == 0)
					break;
				else if (optiune == 1)
				{
					std::string nume, producator;
					double pret;
					int cantitate;
					bool necesitaReteta;
					int tip;
					Medicament* nouMedicament = nullptr;
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
					std::cout << "Tip medicament: 1 - Antibiotic, 2 - Analgezic, 3 - Probiotic, 4 - Sirop ";
					std::cin >> tip;
					if (tip == 1) {
						std::string tip_durere;
						std::cout << "Tip durere (ex: musculara, cap, dentara): ";
						std::cin >> tip_durere;
						nouMedicament = new Analgezic(0, nume, producator, pret, cantitate, necesitaReteta, tip_durere);
					}
					else if (tip == 2) {
						int concentratie;
						std::string substanta_activa;
						std::cout << "Concentratie (mg): ";
						std::cin >> concentratie;
						std::cout << "Substanta activa: ";
						std::cin >> substanta_activa;
						nouMedicament = new Antibiotic(0, nume, producator, pret, cantitate, necesitaReteta, concentratie, substanta_activa);
					}
					else if (tip == 3) {
						bool refrigerare_necesara;
						std::cout << "Necesita refrigerare (1-Da, 0-Nu): ";
						std::cin >> refrigerare_necesara;
						nouMedicament = new Probiotic(0, nume, producator, pret, cantitate, necesitaReteta, refrigerare_necesara);
					}
					else if (tip == 4) {
						double volum;
						std::cout << "Volum (ml): ";
						std::cin >> volum;
						nouMedicament = new Sirop(0, nume, producator, pret, cantitate, necesitaReteta, volum);
					}
					else {
						std::cout << "Optiune invalida." << std::endl;
					}
					if (nouMedicament) {
						farmacie.adaugaMedicament(nouMedicament);
						std::cout << std::endl;
						std::cout << "Medicament adaugat cu succes!" << std::endl;
						std::cin.get();
						std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
						std::cin.get();
					}
					else
					{
						std::cout << "Eroare la adaugarea medicamentului." << std::endl;
					}
				}
				else if (optiune == 2)
				{
					farmacie.afisareMedicamente();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					farmacie.afisareAnalgezice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)
				{
					farmacie.afisareSiropuri();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)
				{
					farmacie.afisareAntibiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)
				{
					farmacie.afisareProbiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 7)
				{
					int id;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id;
					Medicament* medicament = farmacie.cautaMedicament(id);
					if (medicament)
						medicament->afisare();
					else
						std::cout << std::endl << "Medicamentul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 8)
				{
					std::string nume;
					std::cout << "Introduceti numele medicamentului: ";
					std::cin >> nume;
					Medicament* medicament = farmacie.cautaMedicamentDupaNume(nume);
					if (medicament)
						medicament->afisare();
					else
						std::cout << std::endl << "Medicamentul cu numele " << nume << " nu a fost gasit!" << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 9)
				{
					int id;
					std::string nume, producator;
					double pret;
					int cantitate;
					bool necesitaReteta = false;
					//int tip;
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
					std::cout << "Necesar reteta? (1 - da, 0 - nu): ";
					std::cin >> necesitaReteta;
					farmacie.actualizareMedicament(id, nume, producator, pret, cantitate, necesitaReteta);
					std::cin.get();
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();

				}
			}
		}
		else if (opt == 2)
		{
			while (true)
			{
				std::cout << std::endl << "--- Gestionare Clienti ---" << std::endl;
				std::cout << "1. Adauga client" << std::endl;
				std::cout << "2. Afiseaza clienti" << std::endl;
				std::cout << "3. Cauta client dupa id" << std::endl;
				std::cout << "4. Cauta client dupa cnp" << std::endl;
				std::cout << "5. Actualizeaza client" << std::endl;
				std::cout << "6. Sterge client" << std::endl;
				std::cout << "0. Meniu principal" << std::endl;
				std::cout << "Introduceti optiunea: ";
				int optiune;
				std::cin >> optiune;
				std::cout << std::endl;
				std::cin.ignore();
				if (optiune == 0)
					break;
				else if (optiune == 1)
				{
					std::string nume, prenume, cnp;
					bool areAsigurare = false;
					std::cout << "Introduceti numele clientului: ";
					std::cin >> nume;
					std::cout << "Introduceti prenumele clientului: ";
					std::cin >> prenume;
					std::cout << "Introduceti CNP-ul clientului: ";
					std::cin >> cnp;
					std::cout << "Are asigurare? (1 - da, 0 - nu): ";
					std::cin >> areAsigurare;
					farmacie.adaugaClient(nume, prenume, cnp, areAsigurare);
					std::cout << std::endl;
					std::cout << "Client adaugat cu succes!" << std::endl;
					std::cin.get();
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)
				{
					farmacie.afisareClienti();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					int id;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id;
					Client* client = farmacie.cautaClient(id);
					if (client)
						client->afisare();
					else
						std::cout << std::endl << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)
				{
					std::string cnp;
					std::cout << "Introduceti CNP-ul clientului: ";
					std::cin >> cnp;
					Client* client = farmacie.cautaClientDupaCnp(cnp);
					if (client)
						client->afisare();
					else
						std::cout << std::endl << "Clientul cu CNP-ul " << cnp << " nu a fost gasit!" << std::endl;
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)
				{
					int id;
					std::string nume, prenume, cnp;
					bool areAsigurare = false;
					std::cout << "Introduceti ID-ul clientului de actualizat: ";
					std::cin >> id;
					std::cout << "Introduceti noul nume al clientului: ";
					std::cin >> nume;
					std::cout << "Introduceti noul prenume al clientului: ";
					std::cin >> prenume;
					std::cout << "Introduceti noul CNP al clientului: ";
					std::cin >> cnp;
					std::cout << "Are asigurare? (1 - da, 0 - nu): ";
					std::cin >> areAsigurare;
					farmacie.actualizeazaClient(id, nume, prenume, cnp, areAsigurare);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)
				{
					int id;
					std::cout << "Introduceti ID-ul clientului de sters: ";
					std::cin >> id;
					farmacie.stergeClient(id);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}

		}
	}
	return 0;
}