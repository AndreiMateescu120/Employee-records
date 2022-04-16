#include "Angajat.h"

//functii Angajat

Angajat::Angajat(std::string tip, std::string nume, std::string departament) :tip(tip), nume(nume), departament(departament) {};

std::string Angajat::get_nume() { return nume; }

std::string Angajat::get_departament() { return departament; }

std::string Angajat::get_tip() { return tip; }


//functii Salariat

Salariat::Salariat(std::string tip, std::string nume, std::string departament, int norma, int vechime, float salariu_net) :Angajat(tip, nume, departament), norma(norma), vechime(vechime), salariu_net(salariu_net) {
    zile_concediu = 20;
    int i = 3;
    while (i <= vechime)
    {
        zile_concediu = zile_concediu + 1;
        i = i + 3;
    }
};

int Salariat::get_norma() { return norma; }

int Salariat::get_vechime() { return vechime; }

float Salariat::get_salariu_net() { return salariu_net; }

void Salariat::set_norma(int norma) { this->norma = norma; }

void Salariat::set_vechime(int vechime) { this->vechime = vechime; }

void Salariat::set_salariu_net(float salariu_net) { this->salariu_net = salariu_net; }

float Salariat::calcul_salariu_brut(float impozit)
{
    return (float)(12.00 * salariu_net) / (float)(1.0 - impozit);
}

float Salariat::rentabilitate_angajat()
{
    if (get_departament() == "IT")
    {
        return (norma * (250 - zile_concediu)) / (calcul_salariu_brut(0.35) * 12);
    }
    else
        return (norma * (250 - zile_concediu)) / (calcul_salariu_brut(0.45) * 12);

}

void Salariat::afisare()
{
    std::cout << get_nume() << " " << norma << " " << vechime << " " << salariu_net << "\n";
}

//functii Colaborator

Colaborator::Colaborator(std::string tip, std::string nume, std::string departament, float onorariu, float nr_prestari_anuale) :Angajat(tip, nume, departament), onorariu(onorariu), nr_prestari_anuale(nr_prestari_anuale) {};

float Colaborator::get_onorariu() { return onorariu; }

float Colaborator::get_nr_prestari_anuale() { return nr_prestari_anuale; }

void Colaborator::set_onorariu(float onorariu) { this->onorariu = onorariu; }

void Colaborator::set_nr_prestari_anuale(float nr_prestari_anuale) { this->nr_prestari_anuale = nr_prestari_anuale; }

float Colaborator::calcul_salariu_brut(float impozit)
{
    return (float)(onorariu * nr_prestari_anuale) / (float)(1.0 - impozit);
}

void Colaborator::afisare()
{
    std::cout << get_nume() << " " << onorariu << " " << nr_prestari_anuale << "\n";
}

