#include "Angajat.h"
#include<iostream>
#include<string>
#include<iomanip>

int main()
{
    Angajat** angajat;
    int n;
    std::string tip;
    std::string nume;
    std::string departament;
    int norma;
    int vechime;
    float salariu_net;
    float onorariu;
    float nr_prestari_anuale;
    int x;
    float max;
    float salariu_mediu_per_departament = 0;
    int numar = 0;
    std::cin >> n;

    angajat = new Angajat * [n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> tip;
        std::cin >> nume;
        std::cin >> departament;

        //   std::cout<<tip<<"\n"<<nume<<"\n"<<departament<<"\n";

        if (tip == "salariat")
        {
            std::cin >> norma;
            std::cin >> vechime;
            std::cin >> salariu_net;


            (*(angajat + i)) = new Salariat(tip, nume, departament, norma, vechime, salariu_net);
        }
        else
        {
            std::cin >> onorariu;
            std::cin >> nr_prestari_anuale;
            (*(angajat + i)) = new Colaborator(tip, nume, departament, onorariu, nr_prestari_anuale);
        }
    }

    std::cin >> x;


    switch (x)
    {
    case 1:
        std::cin >> departament;



        for (int i = 0; i < n; i++)
        {
            if ((*(angajat + i))->get_departament() == departament)
                (*(angajat + i))->afisare();
        }

        break;

    case 2:
        std::cin >> nume;

        for (int i = 0; i < n; i++)
        {
            if ((*(angajat + i))->get_nume() == nume)
            {
                if ((*(angajat + i))->get_departament() == "IT")
                {
                    std::cout << std::fixed;
                    std::cout << std::setprecision(3);
                    printf("%.5f", (*(angajat + i))->calcul_salariu_brut(0.35));
                }
                else
                    printf("%.5f", (*(angajat + i))->calcul_salariu_brut(0.45));
            }
        }


        break;

    case 3:

        max = (*(angajat))->rentabilitate_angajat();

        for (int i = 0; i < n; i++)
        {
            if ((*(angajat + i))->get_tip() == "salariat")
                if ((*(angajat + i))->rentabilitate_angajat() > max)
                    max = (*(angajat + i))->rentabilitate_angajat();
        }

        for (int i = 0; i < n; i++)
        {
            if ((*(angajat + i))->rentabilitate_angajat() == max)
                std::cout << (*(angajat + i))->get_nume() << "\n";
        }

        break;

    case 4:
        std::cin >> departament;
        for (int i = 0; i < n; i++)
        {
            if ((*(angajat + i))->get_departament() == departament)
            {
                if ((*(angajat + i))->get_departament() == "IT")
                {
                    salariu_mediu_per_departament = salariu_mediu_per_departament + (*(angajat + i))->calcul_salariu_brut(0.35);
                }
                else
                {
                    salariu_mediu_per_departament = salariu_mediu_per_departament + (*(angajat + i))->calcul_salariu_brut(0.45);
                }
                numar++;
            }
        }

        salariu_mediu_per_departament = salariu_mediu_per_departament / numar;

        printf("%.2f", salariu_mediu_per_departament);

        break;

    }


    return 0;
}
