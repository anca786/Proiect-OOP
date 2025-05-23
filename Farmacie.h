// Farmacie.h
#include <iostream>  
#ifndef FARMACIE_H
#define FARMACIE_H

#include "Medicament.h"
#include "Client.h"
#include "Vanzare.h"
#include "Vanzabil.h"
#include <vector>
#include <string>

struct Adresa {
	std::string strada;
	int numar;
	std::string oras;
	int codPostal;

    Adresa() : strada(""), numar(0), oras(""), codPostal(0) {}
    Adresa(const std::string& str, const int& nr, const std::string& oras, const int& cp)
       : strada(str), numar(nr), oras(oras), codPostal(cp) {
    }
};

class Farmacie {
private:
    std::string nume;
    Adresa adresa;
    std::vector<Medicament*> stocMedicamente;
    std::vector<Client> clienti;
    std::vector<Vanzare> vanzari;
    int nextIdMedicament;
    int nextIdClient;
    int nextIdVanzare;

public:
    // Constructori
    Farmacie();
    Farmacie(const std::string& nume, const Adresa& adresa);
    Farmacie(const Farmacie& other);

    // Destructor
    ~Farmacie();

    // Getteri
    std::string getNume() const;
    Adresa getAdresa() const;

    // Setteri
    void setNume(const std::string& nume);
    void setAdresa(const Adresa& adresa);

    // Metode pentru gestiunea medicamentelor
    /*void adaugaMedicament(const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesitaReteta,int tip);*/
    void adaugaMedicament(Medicament* med);
    void actualizareMedicament(int id, const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesitaReteta);
    void stergeMedicament(int id);
    Medicament* cautaMedicament(int id);
    Medicament* cautaMedicamentDupaNume(const std::string& nume);
    void afisareMedicamente() const;
    void actualizeazaStoc(int id, int cantitate);
    void afisareAnalgezice() const;
    void afisareAntibiotice() const;
    void afisareProbiotice() const;
    void afisareSiropuri() const;

    // Metode pentru gestiunea clientilor
    void adaugaClient(const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool areAsigurare);
    void actualizeazaClient(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool areAsigurare);
    void stergeClient(int id);
    Client* cautaClient(int id);
    Client* cautaClientDupaCnp(const std::string& cnp);
    void afisareClienti() const;

    // Metode pentru gestiunea vanzarilor
    Vanzare creeazaVanzare(int idClient, const std::string& data);
    void stergeVanzare(int id);
    void actualizeazaVanzare(int id, const Client& client);
	Vanzare* cautaVanzare(int id);
    void adaugaItemLaVanzare(int idVanzare, int idMedicament, int cantitate);
    void stergeItemDinVanzare(int idVanzare, int indexItem);
    void finalizeazaVanzare(int idVanzare);
    void afisareVanzari() const;
    void afisareVanzare(int idVanzare);

    // Metode pentru rapoarte
    void raportStoc() const;
    void raportVanzariPerioada(const std::string& dataInceput, const std::string& dataSfarsit) const;
    void raportVanzariClient(int idClient) const;
    void raportTopMedicamente() const;

    // Supraincarcare operatori
    Farmacie& operator=(const Farmacie& other);
};

#endif 