// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int id;
    std::string nume;
    std::string prenume;
    std::string cnp;
    bool areAsigurare;

public:
    // Constructori
    Client();
    Client(int id, const std::string& nume, const std::string& prenume,
        const std::string& cnp, bool areAsigurare);
    Client(const Client& other); 

    // Destructor
    ~Client();

    // Getteri
    int getId() const;
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getCnp() const;
    bool getAreAsigurare() const;

    // Setteri
    void setId(int id);
    void setNume(const std::string& nume);
    void setPrenume(const std::string& prenume);
    void setCnp(const std::string& cnp);
    void setAreAsigurare(bool areAsigurare);

    // Alte metode
    void afisare() const;
    double calculeazaDiscount() const;

    // Supraincarcare operatori
    Client& operator=(const Client& other);
    bool operator==(const Client& other) const;
};

#endif