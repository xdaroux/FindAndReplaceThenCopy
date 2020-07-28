#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "TypeDeDonnee.h"

class FichierEntree
{
public:
	FichierEntree();
	~FichierEntree();



	bool enregistreFichierIn();
	bool affichierFichierIn();
	bool afficherDonnee();
	bool separationSectionFichierIn();
	bool genereTypeDeDonne();
	bool afficherSeparationTypeDonne();




	std::string nomUsine; //ligne 0
	std::vector<std::string> TD_nomPlc; //ligne 2 a n
	int nbPlc = 0;
	std::vector<std::string> TD_EnteteGlobal;
	int nbLigneEnteteGlobal = 0;
	std::vector<TypeDeDonnee> TD_typeDonnee; //ligne n+2 a x
	int nbtypeDonnee = 0;
	std::ifstream fichierIn;
	std::string nomToReplace;
	
private:

	
	std::vector<std::string> ligneFichierIn;
	int nbLigneFichierIn;

	int nbSection = 0;





	
};

