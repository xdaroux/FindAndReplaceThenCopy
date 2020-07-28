
#include "Plc.h"
#include <iostream>
#include <cstring>


Plc::Plc()
{
}


Plc::~Plc()
{
}



bool Plc::enregistrerPlcGroupeDeDonnee(std::string NomPlc, std::vector<TypeDeDonnee> PlcGroupDeDonnee,int nbtypeDonnee)
{
	nomPlc = NomPlc;
	plcGroupeDeDonnee = PlcGroupDeDonnee;
	nbPlcGroupeDeDonnee = nbtypeDonnee;//aller chercher le nb de de groupe de donnee


	//std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

	//std::cout << plcGroupeDeDonnee[0].afficherSeparationDesDonnees()<<std::endl;
	//std::cout << plcGroupeDeDonnee[1].afficherSeparationDesDonnees()<<std::endl;
	//std::cout << plcGroupeDeDonnee[2].afficherSeparationDesDonnees()<<std::endl;

	//std::cout << nbPlcGroupeDeDonnee << std::endl;


	return false;
}

bool Plc::afficherPlc()
{
	std::cout << "Nom du PLC : " << nomPlc << std::endl;
	std::cout << "Donnee du PLC : " << std::endl;

	for (int i = 0; i < nbPlcGroupeDeDonnee; i++)
	{
		plcGroupeDeDonnee[i].afficherSeparationDesDonnees();
	}

	return false;
}

bool Plc::PlcFindAndReplace(std::string replaceName)
{
	

	for (int i = 0; i < nbPlcGroupeDeDonnee; i++) // faire toute les type de donnee AI DI TX etc..
	{
		for (int y = 0; y < plcGroupeDeDonnee[i].nbTypeDeLigneDeDonnee; y++) // faire chaque ligne d'un type
		{
			int z = 0;
			while (plcGroupeDeDonnee[i].TD_TypeDeligneDeDonnee[y][z] != '\0')
			{
				std :: size_t PlaceReplace;
				PlaceReplace = plcGroupeDeDonnee[i].TD_TypeDeligneDeDonnee[y].find(replaceName);
				if (PlaceReplace < 500000)
				{
					plcGroupeDeDonnee[i].TD_TypeDeligneDeDonnee[y].replace(PlaceReplace, NB_CARACTERE_A_CHANGER, nomPlc); ///ici faudrai faire un changement et aller chercher directement le nombre de caractere pour faire quelque chose de plus solide plutot que de hard  code la valeur nb de caractere
				}
				z++;
			}
		}
		
		
	}///wrok nowwww
	return false;
}
