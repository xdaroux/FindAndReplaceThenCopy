
#include "TypeDeDonnee.h"
#include <iostream>


TypeDeDonnee::TypeDeDonnee()
{
}


TypeDeDonnee::~TypeDeDonnee()
{
}

bool TypeDeDonnee::separationDonnee()
{
	TS_enteteDeDonnee[0] = TD_ligneDeDonnee[0];	//metrte l'entete
	TS_enteteDeDonnee[1] = TD_ligneDeDonnee[1];
	
	typeDeDonne.push_back(TD_ligneDeDonnee[2][1]); // aller chercher le AI, DI , TX au debut de la phrase !!
	typeDeDonne.push_back(TD_ligneDeDonnee[2][2]);
	

	for (int i = 2; i < nbLigneDeDonnee;i++) // commence a deux car le 0 et le 1 c'est l'entete
	{
		TD_TypeDeligneDeDonnee.push_back(TD_ligneDeDonnee[i]);
		nbTypeDeLigneDeDonnee++;
	}
	return false;
}

bool TypeDeDonnee::enregistreEnteteDeDonnee()
{
	return false;
}

bool TypeDeDonnee::enregistreTypeDeDonee()
{
	return false;
}

bool TypeDeDonnee::ajouterLigneDeDonnee(std::string ligne)
{
	TD_ligneDeDonnee.push_back(ligne);
	nbLigneDeDonnee++;
	return false;
}

bool TypeDeDonnee::afficherDonne()
{
	for (int i = 0; i < nbLigneDeDonnee; i++)
	{
		std::cout << TD_ligneDeDonnee[i] << std::endl;
	}
	return false;
}

bool TypeDeDonnee::afficherSeparationDesDonnees()
{
	std::cout << std::endl;
	std::cout << "Entete : "<< std::endl;
	std::cout << TS_enteteDeDonnee[0] << std::endl;
	std::cout << TS_enteteDeDonnee[1] << std::endl;
	std::cout << std::endl;
	std::cout << typeDeDonne << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < nbTypeDeLigneDeDonnee; i++)
	{
		std::cout << TD_TypeDeligneDeDonnee[i] << std::endl; //affiche tout les ligne
	}
	return false;
}




