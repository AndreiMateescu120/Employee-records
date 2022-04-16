#ifndef ANGAJAT_H
#define ANGAJAT_H

#include<string>
#include<iostream>

class Angajat {
private:
    std::string tip;
    std::string nume;
    std::string departament;
public:
    virtual void afisare() = 0;
    virtual float rentabilitate_angajat() = 0;
    virtual float calcul_salariu_brut(float) = 0;
    Angajat(std::string, std::string, std::string);
    std::string get_tip();
    std::string get_nume();
    std::string get_departament();

};

class Salariat : public Angajat
{
private:
    int norma;
    int vechime;
    float salariu_net;
    int zile_concediu;
public:
    void afisare();
    float rentabilitate_angajat();

    Salariat(std::string, std::string, std::string, int, int, float);
    int get_norma();
    int get_vechime();
    float get_salariu_net();
    void set_norma(int);
    void set_vechime(int);
    void set_salariu_net(float);
    float calcul_salariu_brut(float);
};

class Colaborator : public Angajat
{
private:
    float onorariu;
    float nr_prestari_anuale;
public:
    void afisare();
    float rentabilitate_angajat() { return 0; };

    Colaborator(std::string, std::string, std::string, float, float);
    float get_onorariu();
    float get_nr_prestari_anuale();
    void set_onorariu(float);
    void set_nr_prestari_anuale(float);
    float calcul_salariu_brut(float);



};





#endif