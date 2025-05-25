// client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int m_id;
    std::string m_nume;
    std::string m_prenume;
    std::string m_cnp;
    bool m_are_asigurare;

public:
    // Constructori
    Client();
    Client(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool are_asigurare);
    Client(const Client& other);

    // Destructor
    ~Client();

    // Getteri
    int GetId() const;
    std::string GetNume() const;
    std::string GetPrenume() const;
    std::string GetCnp() const;
    bool GetAreAsigurare() const;

    // Setteri
    void SetId(int id);
    void SetNume(const std::string& nume);
    void SetPrenume(const std::string& prenume);
    void SetCnp(const std::string& cnp);
    void SetAreAsigurare(bool are_asigurare);

    // Alte metode
    void Afisare() const;
    double CalculeazaDiscount() const;

    // Supraincarcare operatori
    Client& operator=(const Client& other);
    bool operator==(const Client& other) const;
};

#endif