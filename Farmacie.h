// farmacie.h
#include <iostream>  
#ifndef FARMACIE_H
#define FARMACIE_H

#include "medicament.h"
#include "client.h"
#include "vanzare.h"
#include "vanzabil.h"
#include <vector>
#include <string>

struct Adresa {            //am folosit struct pentru ca adresa e o colectie simpla de date
    std::string strada;
    int numar;
    std::string oras;
    int cod_postal;
    Adresa() : strada(""), numar(0), oras(""), cod_postal(0) {}
    Adresa(const std::string& str, const int& nr, const std::string& oras, const int& cp)
        : strada(str), numar(nr), oras(oras), cod_postal(cp) {
    }
};

class Farmacie {
private:
    std::string m_nume;
    Adresa m_adresa;
    std::vector<Medicament*> m_stoc_medicamente;
    std::vector<Client> m_clienti;
    std::vector<Vanzare> m_vanzari;
    int m_next_id_medicament;
    int m_next_id_client;
    int m_next_id_vanzare;

public:
    // Constructori
    Farmacie();
    Farmacie(const std::string& nume, const Adresa& adresa);
    Farmacie(const Farmacie& other);

    // Destructor
    ~Farmacie();

    // Getteri
    std::string GetNume() const;
    Adresa GetAdresa() const;

    // Setteri
    void SetNume(const std::string& nume);
    void SetAdresa(const Adresa& adresa);

    // Metode pentru gestiunea medicamentelor
    void AdaugaMedicament(Medicament* med);
    void ActualizareMedicament(int id, const std::string& nume, const std::string& producator,
        double pret, int cantitate, bool necesita_reteta);
    void StergeMedicament(int id);
    Medicament* CautaMedicament(int id);
    Medicament* CautaMedicamentDupaNume(const std::string& nume);
    void AfisareMedicamente() const;
    void ActualizeazaStoc(int id, int cantitate);
    void AfisareAnalgezice() const;
    void AfisareAntibiotice() const;
    void AfisareProbiotice() const;
    void AfisareSiropuri() const;

    // Metode pentru gestiunea clientilor
    void AdaugaClient(const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool are_asigurare);
    void ActualizeazaClient(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool are_asigurare);
    void StergeClient(int id);
    Client* CautaClient(int id);
    Client* CautaClientDupaCnp(const std::string& cnp);
    void AfisareClienti() const;

    // Metode pentru gestiunea vanzarilor
    Vanzare CreeazaVanzare(int id_client, const std::string& data);
    void StergeVanzare(int id);
    void ActualizeazaVanzare(int id, const Client& client);
    Vanzare* CautaVanzare(int id);
    void AdaugaItemLaVanzare(int id_vanzare, int id_medicament, int cantitate);
    void StergeItemDinVanzare(int id_vanzare, int index_item);
    void FinalizeazaVanzare(int id_vanzare);
    void AfisareVanzari() const;
    void AfisareVanzare(int id_vanzare);

    // Metode pentru rapoarte
    void RaportStoc() const;
    void RaportVanzariPerioada(const std::string& data_inceput, const std::string& data_sfarsit) const;
    void RaportVanzariClient(int id_client) const;
    void RaportTopMedicamente() const;

    // Supraincarcare operatori
    Farmacie& operator=(const Farmacie& other);
};

#endif