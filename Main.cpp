//Main
#include "angajat.h"
#include "analgezic.h"
#include "probiotic.h"
#include "medicament.h"
#include "client.h"
#include "farmacie.h"
#include "medicament.h"
#include "antibiotic.h"
#include "sirop.h"
#include "vanzare.h"
#include<iostream>

int main()
{
	Adresa adresa_farmacie("Strada Teilor", 4, "Bucuresti", 254628);
	Farmacie farmacie("Pharmacin", adresa_farmacie);
	/*farmacie.AdaugaMedicament("Paracetamol", "Producator A", 10.0, 100, false);
	farmacie.AdaugaMedicament("Ibuprofen", "Producator B", 15.0, 50, true);
	farmacie.AfisareMedicamente();
	farmacie.AdaugaClient("Ion", "Popescu", "1234567890123", true);
	farmacie.AdaugaClient("Maria", "Ionescu", "9876543210987", false);
	farmacie.AfisareClienti();
	Vanzare vanzare = farmacie.CreeazaVanzare(1, "2023-10-01");
	farmacie.AdaugaItemLaVanzare(vanzare.GetId(), 1, 2);
	farmacie.FinalizeazaVanzare(vanzare.GetId());
	farmacie.RaportStoc();
	farmacie.RaportVanzariPerioada("2023-10-01", "2023-10-31");
	farmacie.ActualizareMedicament(3,"Paracetamol","Producator A",10.0,100,"Nu");*/
	while (true)
	{
		int opt;
		std::cout << "--- Meniu Principal Farmacie ---" << std::endl;
		std::cout << "1. Gestionare Medicamente" << std::endl;
		std::cout << "2. Gestionare Clienti" << std::endl;
		std::cout << "3. Gestionare Vanzari" << std::endl;
		std::cout << "4. Rapoarte" << std::endl;
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
					bool necesita_reteta;
					int tip;
					Medicament* nou_medicament = nullptr;
					std::cout << "Introduceti numele medicamentului: ";
					std::cin >> nume;
					std::cout << "Introduceti producatorul medicamentului: ";
					std::cin >> producator;
					std::cout << "Introduceti pretul medicamentului: ";
					std::cin >> pret;
					std::cout << "Introduceti cantitatea medicamentului: ";
					std::cin >> cantitate;
					std::cout << "Necesar reteta? (1 - da, 0 - nu): ";
					std::cin >> necesita_reteta;
					std::cout << "Tip medicament: 1 - Antibiotic, 2 - Analgezic, 3 - Probiotic, 4 - Sirop ";
					std::cin >> tip;
					if (tip == 1) {
						std::string tip_durere;
						std::cout << "Tip durere (ex: musculara, cap, dentara): ";
						std::cin >> tip_durere;
						nou_medicament = new Analgezic(0, nume, producator, pret, cantitate, necesita_reteta, tip_durere);
					}
					else if (tip == 2) {
						int concentratie;
						std::string substanta_activa;
						std::cout << "Concentratie (mg): ";
						std::cin >> concentratie;
						std::cout << "Substanta activa: ";
						std::cin >> substanta_activa;
						nou_medicament = new Antibiotic(0, nume, producator, pret, cantitate, necesita_reteta, concentratie, substanta_activa);
					}
					else if (tip == 3) {
						bool refrigerare_necesara;
						std::cout << "Necesita refrigerare (1-Da, 0-Nu): ";
						std::cin >> refrigerare_necesara;
						nou_medicament = new Probiotic(0, nume, producator, pret, cantitate, necesita_reteta, refrigerare_necesara);
					}
					else if (tip == 4) {
						double volum;
						std::cout << "Volum (ml): ";
						std::cin >> volum;
						nou_medicament = new Sirop(0, nume, producator, pret, cantitate, necesita_reteta, volum);
					}
					else {
						std::cout << "Optiune invalida." << std::endl;
					}
					if (nou_medicament) {
						farmacie.AdaugaMedicament(nou_medicament);
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
					farmacie.AfisareMedicamente();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					farmacie.AfisareAnalgezice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)
				{
					farmacie.AfisareSiropuri();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)
				{
					farmacie.AfisareAntibiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)
				{
					farmacie.AfisareProbiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 7)
				{
					int id;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id;
					Medicament* medicament = farmacie.CautaMedicament(id);
					if (medicament)
						medicament->Afisare();
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
					Medicament* medicament = farmacie.CautaMedicamentDupaNume(nume);
					if (medicament)
						medicament->Afisare();
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
					bool necesita_reteta = false;
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
					std::cin >> necesita_reteta;
					farmacie.ActualizareMedicament(id, nume, producator, pret, cantitate, necesita_reteta);
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
					bool are_asigurare = false;
					std::cout << "Introduceti numele clientului: ";
					std::cin >> nume;
					std::cout << "Introduceti prenumele clientului: ";
					std::cin >> prenume;
					std::cout << "Introduceti CNP-ul clientului: ";
					std::cin >> cnp;
					std::cout << "Are asigurare? (1 - da, 0 - nu): ";
					std::cin >> are_asigurare;
					farmacie.AdaugaClient(nume, prenume, cnp, are_asigurare);
					std::cout << std::endl;
					std::cout << "Client adaugat cu succes!" << std::endl;
					std::cin.get();
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)
				{
					farmacie.AfisareClienti();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					int id;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id;
					Client* client = farmacie.CautaClient(id);
					if (client)
						client->Afisare();
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
					Client* client = farmacie.CautaClientDupaCnp(cnp);
					if (client)
						client->Afisare();
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
					bool are_asigurare = false;
					std::cout << "Introduceti ID-ul clientului de actualizat: ";
					std::cin >> id;
					std::cout << "Introduceti noul nume al clientului: ";
					std::cin >> nume;
					std::cout << "Introduceti noul prenume al clientului: ";
					std::cin >> prenume;
					std::cout << "Introduceti noul CNP al clientului: ";
					std::cin >> cnp;
					std::cout << "Are asigurare? (1 - da, 0 - nu): ";
					std::cin >> are_asigurare;
					farmacie.ActualizeazaClient(id, nume, prenume, cnp, are_asigurare);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)
				{
					int id;
					std::cout << "Introduceti ID-ul clientului de sters: ";
					std::cin >> id;
					farmacie.StergeClient(id);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}

		}
		else if (opt == 3)
		{
			while (true)
			{
				std::cout << std::endl << "--- Gestionare Vanzari ---" << std::endl;
				std::cout << "1. Creeaza vanzare noua" << std::endl;
				std::cout << "2. Adaugare medicament la vanzare" << std::endl;
				std::cout << "3. Stergere medicament din vanzare" << std::endl;
				std::cout << "4. Finalizeaza vanzare" << std::endl;
				std::cout << "5. Afiseaza toate vanzarile" << std::endl;
				std::cout << "6. Cauta vanzare dupa id" << std::endl;
				std::cout << "7. Generare bon pentru vanzare" << std::endl;
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
					int id_client;
					std::string data_vanzare;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id_client;
					std::cin.ignore();
					std::cout << "Introduceti data vanzarii (YYYY-MM-DD): ";
					std::cin >> data_vanzare;

					Client* client = farmacie.CautaClient(id_client);
					if (client) {
						Vanzare vanzare_noua = farmacie.CreeazaVanzare(id_client, data_vanzare);
						std::cout << "Vanzare cu ID-ul " << vanzare_noua.GetId() << " creata cu succes.\n";
					}
					else {
						std::cout << "Clientul cu ID-ul " << id_client << " nu a fost gasit.\n";
					}
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)
				{
					int id_vanzare, id_medicament, cantitate;
					std::cout << "Introduceti ID-ul vanzarii: ";
					std::cin >> id_vanzare;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id_medicament;
					std::cout << "Introduceti cantitatea: ";
					std::cin >> cantitate;
					farmacie.AdaugaItemLaVanzare(id_vanzare, id_medicament, cantitate);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					int id_vanzare, index_item;
					std::cout << "Introduceti ID-ul vanzarii: ";
					std::cin >> id_vanzare;
					std::cout << "Introduceti indexul produsului de sters: ";
					std::cin >> index_item;
					farmacie.StergeItemDinVanzare(id_vanzare, index_item);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii de finalizat: ";
					std::cin >> id_vanzare;
					farmacie.FinalizeazaVanzare(id_vanzare);
					std::cout << "Vanzare finalizata cu succes.\n";
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)
				{
					farmacie.AfisareVanzari();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii de cautat: ";
					std::cin >> id_vanzare;
					Vanzare* vanzare = farmacie.CautaVanzare(id_vanzare);
					if (vanzare) {
						vanzare->Afisare();
					}
					else {
						std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita.\n";
					}
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 7)
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii pentru care doriti bonul: ";
					std::cin >> id_vanzare;
					Vanzare* vanzare = farmacie.CautaVanzare(id_vanzare);
					if (vanzare) {
						vanzare->GenereazaBon();
					}
					else {
						std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita.\n";
					}

				}
			}
		}
		else if (opt == 4)
		{
			while (true)
			{
				int optiune;
				std::cout << "\n--- Meniu Rapoarte ---\n";
				std::cout << "1. Raport Stoc Medicamente\n";
				std::cout << "2. Raport Vanzari pe Perioada\n";
				std::cout << "3. Raport Vanzari Client\n";
				std::cout << "4. Raport Top Medicamente Vandute\n";
				std::cout << "0. Inapoi la Meniul Principal\n";
				std::cout << "Introduceti optiunea : ";
				std::cin >> optiune;
				if (optiune == 0)
					break;
				else if (optiune == 1)
				{
					farmacie.RaportStoc();
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)
				{
					std::string data_inceput;
					std::string data_sfarsit;
					std::cout << "Introduceti data de inceput (YYYY-MM-DD): ";
					std::cin >> data_inceput;
					std::cout << "Introduceti data de sfarsit (YYYY-MM-DD): ";
					std::cin >> data_sfarsit;
					farmacie.RaportVanzariPerioada(data_inceput, data_sfarsit);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)
				{
					int id_client;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id_client;
					farmacie.RaportVanzariClient(id_client);
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)
				{
					farmacie.RaportTopMedicamente();
					std::cin.get();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}

		}
	}
	return 0;
}