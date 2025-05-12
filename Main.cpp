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
	Farmacie farmacie("Farmacia Ta", "Strada Exemplu 123");
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
	while (true)
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
			farmacie.adaugaMedicament(nume, producator, pret, cantitate, necesitaReteta);
		}
		else if (optiune == 2)
		{
			farmacie.afisareMedicamente();
		}
		else if (optiune == 3)
		{
			int id;
			std::cout << "Introduceti ID-ul medicamentului: ";
			std::cin >> id;
			Medicament* medicament = farmacie.cautaMedicament(id);
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
			bool necesitaReteta = false;
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
			std::cout << "Necesar reteta? (1 - da, 0 - nu)";
			farmacie.actualizareMedicament(id, nume, producator, pret, cantitate, necesitaReteta);

		}
		return 0;
	}
}