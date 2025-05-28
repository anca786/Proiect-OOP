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
	while (true)                            // meniul principal al farmaciei
	{
		int opt;
		std::cout << std::endl;
		std::cout << "--- Meniu Principal Farmacie ---" << std::endl;
		std::cout << "1. Gestionare Medicamente" << std::endl;
		std::cout << "2. Gestionare Clienti" << std::endl;
		std::cout << "3. Gestionare Vanzari" << std::endl;
		std::cout << "4. Rapoarte" << std::endl;
		std::cout << "0. Iesire" << std::endl;
		std::cout << "Introduceti optiunea: ";
		std::cin >> opt;												//in functie de optiunea aleasa,se va afisa un al doilea meniu
		std::cout << std::endl;
		if (opt == 0)                      // daca optiunea este 0,programul se va inchide
			return 0;
		else if (opt == 1)
		{
			while (true)
			{
				std::cout << std::endl << "--- Gestionare Medicamente ---" << std::endl;              // afiseaza meniul de gestionare a medicamentelor
				std::cout << "1. Adauga medicament" << std::endl;
				std::cout << "2. Afiseaza medicamente" << std::endl;
				std::cout << "3. Afiseaza analgezice" << std::endl;
				std::cout << "4. Afiseaza siropuri" << std::endl;
				std::cout << "5. Afiseaza antibiotice" << std::endl;
				std::cout << "6. Afiseaza probiotice" << std::endl;
				std::cout << "7. Cauta medicament dupa id" << std::endl;
				std::cout << "8. Cauta medicament dupa nume" << std::endl;
				std::cout << "9. Actualizeaza medicament" << std::endl;
				std::cout << "10.Actualizeaza stocul unui medicament" << std::endl;
				std::cout << "0. Meniu principal" << std::endl;
				std::cout << "Introduceti optiunea: ";
				int optiune;
				std::cin >> optiune;                              //in functie de optiunea aleasa se va apela o anumita functie
				std::cout << std::endl;
				std::cin.ignore();
				if (optiune == 0)                          //se intoarce la meniul principal
					break;
				else if (optiune == 1)
				{                                                                // adauga un medicament nou si il retine in functie de tipul sau
					std::string nume, producator;
					double pret;
					int cantitate;
					bool necesita_reteta;
					int tip;
					Medicament* nou_medicament = nullptr;                      // pointer pentru a retine tipul de medicament creat
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
				else if (optiune == 2)              // afiseaza toate medicamentele din stoc
				{
					farmacie.AfisareMedicamente();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)              // afiseaza toate analgezicele din stoc  // afiseaza toate analgezicele din stoc
				{
					farmacie.AfisareAnalgezice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)                   // afiseaza toate siropurile din stoc
				{
					farmacie.AfisareSiropuri();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)						// afiseaza toate antibioticele din stoc
				{
					farmacie.AfisareAntibiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)                         // afiseaza toate probioticele din stoc
				{
					farmacie.AfisareProbiotice();
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 7)                       // cauta un medicament dupa ID
				{
					int id;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id;
					std::cin.ignore();
					Medicament* medicament = farmacie.CautaMedicament(id);
					if (medicament)
						medicament->Afisare();
					else
						std::cout << std::endl << "Medicamentul cu ID-ul " << id << " nu a fost gasit!";
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 8)                           // cauta un medicament dupa nume
				{
					std::string nume;
					std::cout << "Introduceti numele medicamentului: ";
					std::cin >> nume;
					std::cin.ignore();
					Medicament* medicament = farmacie.CautaMedicamentDupaNume(nume);
					if (medicament)
						medicament->Afisare();
					else
						std::cout << std::endl << "Medicamentul cu numele " << nume << " nu a fost gasit!";
					std::cout << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 9)							// actualizeaza un medicament existent
				{
					int id;
					std::string nume, producator;
					double pret;
					int cantitate;
					bool necesita_reteta = false;
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
					std::cin.ignore();
					farmacie.ActualizareMedicament(id, nume, producator, pret, cantitate, necesita_reteta);
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();

				}
				else if (optiune == 10)                  // actualizeaza stocul unui medicament existent
				{
					int id;
					int cantitate;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id;
					std::cout << "Introduceti cantitatea de adaugat: ";
					std::cin >> cantitate;
					std::cin.ignore();
					farmacie.ActualizeazaStoc(id, cantitate);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}
		}
		else if (opt == 2)                  // afiseaza meniul de gestionare a clientilor
		{
			while (true)
			{
				std::cout << std::endl << "--- Gestionare Clienti ---" << std::endl;
				std::cout << "1. Adauga client" << std::endl;
				std::cout << "2. Afiseaza clienti" << std::endl;
				std::cout << "3. Cauta client dupa ID" << std::endl;
				std::cout << "4. Cauta client dupa CNP" << std::endl;
				std::cout << "5. Actualizeaza client" << std::endl;
				std::cout << "6. Sterge client" << std::endl;
				std::cout << "0. Meniu principal" << std::endl;
				std::cout << "Introduceti optiunea: ";
				int optiune;
				std::cin >> optiune;             //in functie de optiunea aleasa se va apela o anumita functie
				std::cout << std::endl;
				std::cin.ignore();
				if (optiune == 0)              // se intoarce la meniul principal
					break;
				else if (optiune == 1)         // adauga un client nou
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
					std::cin.ignore();
					farmacie.AdaugaClient(nume, prenume, cnp, are_asigurare);
					std::cout << std::endl;
					std::cout << "Client adaugat cu succes!" << std::endl;
					std::cout << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)                        // afiseaza toti clientii din baza de date
				{
					farmacie.AfisareClienti();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)                  // cauta un client dupa ID
				{
					int id;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id;
					std::cin.ignore();
					Client* client = farmacie.CautaClient(id);
					if (client)
						client->Afisare();
					else
						std::cout << std::endl << "Clientul cu ID-ul " << id << " nu a fost gasit!" << std::endl;
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)                       // cauta un client dupa CNP
				{ 
					std::string cnp;
					std::cout << "Introduceti CNP-ul clientului: ";
					std::cin >> cnp;
					std::cin.ignore();
					Client* client = farmacie.CautaClientDupaCnp(cnp);
					if (client)
						client->Afisare();
					else
						std::cout << std::endl << "Clientul cu CNP-ul " << cnp << " nu a fost gasit!" << std::endl;
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				} 
				else if (optiune == 5)                          // actualizeaza un client existent
				{
					int id;
					std::string nume, prenume;
					bool are_asigurare = false;
					std::cout << "Introduceti ID-ul clientului de actualizat: ";
					std::cin >> id;
					std::cout << "Introduceti noul nume al clientului: ";
					std::cin >> nume;
					std::cout << "Introduceti noul prenume al clientului: ";
					std::cin >> prenume;
					std::cout << "Are asigurare? (1 - da, 0 - nu): ";
					std::cin >> are_asigurare;
					std::cin.ignore();
					farmacie.ActualizeazaClient(id, nume, prenume,  are_asigurare);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)                    // sterge un client dupa ID
				{
					int id;
					std::cout << "Introduceti ID-ul clientului de sters: ";
					std::cin >> id;
					std::cin.ignore();
					farmacie.StergeClient(id);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}

		}
		else if (opt == 3)               // afiseaza meniul de gestionare a vanzarilor
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
				if (optiune == 0)            // se intoarce la meniul principal
					break; 
				else if (optiune == 1)            // creeaza o vanzare noua
				{
					int id_client;
					std::string data_vanzare;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id_client;
					std::cout << "Introduceti data vanzarii (YYYY-MM-DD): ";
					std::cin >> data_vanzare;
					std::cin.ignore();

					Client* client = farmacie.CautaClient(id_client);             // cauta clientul dupa ID,iar daca exista creeaza vanzarea
					if (client) {
						Vanzare vanzare_noua = farmacie.CreeazaVanzare(id_client, data_vanzare);
						std::cout << "Vanzare cu ID-ul " << vanzare_noua.GetId() << " creata cu succes.\n";
					}
					else {
						std::cout << "Clientul cu ID-ul " << id_client << " nu a fost gasit.\n";
					}
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)               // adauga un medicament la o vanzare existenta
				{
					int id_vanzare, id_medicament, cantitate;
					std::cout << "Introduceti ID-ul vanzarii: ";
					std::cin >> id_vanzare;
					std::cout << "Introduceti ID-ul medicamentului: ";
					std::cin >> id_medicament;
					std::cout << "Introduceti cantitatea: ";
					std::cin >> cantitate;
					std::cin.ignore();
					farmacie.AdaugaItemLaVanzare(id_vanzare, id_medicament, cantitate);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)            // sterge un medicament dintr-o vanzare existenta
				{
					int id_vanzare, index_item;
					std::cout << "Introduceti ID-ul vanzarii: ";
					std::cin >> id_vanzare;
					std::cout << "Introduceti indexul produsului de sters: ";
					std::cin >> index_item;
					std::cin.ignore();
					farmacie.StergeItemDinVanzare(id_vanzare, index_item);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)            // finalizeaza o vanzare existenta,generandu-i si un bon
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii de finalizat: ";
					std::cin >> id_vanzare;
					std::cin.ignore();
					farmacie.FinalizeazaVanzare(id_vanzare);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 5)           // afiseaza toate vanzarile din baza de date
				{
					farmacie.AfisareVanzari();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 6)             // cauta o vanzare dupa ID
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii de cautat: ";
					std::cin >> id_vanzare;
					std::cin.ignore();
					Vanzare* vanzare = farmacie.CautaVanzare(id_vanzare);
					if (vanzare) {
						vanzare->Afisare();
					}
					else {
						std::cout << "Vanzarea cu ID-ul " << id_vanzare << " nu a fost gasita.\n";
					}
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 7)             // genereaza un bon pentru o vanzare existenta
				{
					int id_vanzare;
					std::cout << "Introduceti ID-ul vanzarii pentru care doriti bonul: ";
					std::cin >> id_vanzare;
					std::cin.ignore();
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
		else if (opt == 4)                  // afiseaza meniul de rapoarte
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
				std::cin.ignore();
				if (optiune == 0)            // se intoarce la meniul principal
					break;
				else if (optiune == 1)         // afiseaza raportul stocului de medicamente
				{
					farmacie.RaportStoc();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 2)           // afiseaza raportul vanzarilor pe o perioada specificata
				{
					std::string data_inceput;
					std::string data_sfarsit;
					std::cout << "Introduceti data de inceput (YYYY-MM-DD): ";
					std::cin >> data_inceput;
					std::cout << "Introduceti data de sfarsit (YYYY-MM-DD): ";
					std::cin >> data_sfarsit;
					std::cin.ignore();
					farmacie.RaportVanzariPerioada(data_inceput, data_sfarsit);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 3)	          // afiseaza raportul vanzarilor pentru un anumit client
				{
					int id_client;
					std::cout << "Introduceti ID-ul clientului: ";
					std::cin >> id_client;
					std::cin.ignore();
					farmacie.RaportVanzariClient(id_client);
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
				else if (optiune == 4)          // afiseaza raportul celor mai vandute medicamente
				{
					farmacie.RaportTopMedicamente();
					std::cout << std::endl << "Apasa ENTER pentru a te intoarce la meniu" << std::endl;
					std::cin.get();
				}
			}

		}
	}
	return 0;
}