
#include "Usine.h"
#include <iostream>



Usine::Usine()
{
}


Usine::~Usine()
{
}

bool Usine::ajouterLesPlc(std::string nomUsine, std::vector<std::string> nomPlc, int nbPlc, std::vector<TypeDeDonnee> plcGroupeDonnee, int nbGroupeDeDonnee)
{
	NomUsine = nomUsine;
	
	for (int i = 0; i < nbPlc; i++)
	{

		TD_GroupPlc.push_back(Plc());// j'apelle le copntructeur de PLC
		TD_GroupPlc[i].enregistrerPlcGroupeDeDonnee(nomPlc[i], plcGroupeDonnee, nbGroupeDeDonnee);
		NbPlc++;
	}
	
	//std::cout << NbPlc << "!!!!!!!!!!!!!!!!!!!" << NomUsine << std::endl;
	//std::cout << TD_GroupPlc[5].afficherPlc() << std::endl;
	return false;
}

bool Usine::Usine_FindAndReplacePlcName(std::string nomToReplace)
{
	for (int i = 0; i < NbPlc; i++)
	{
		TD_GroupPlc[i].PlcFindAndReplace(nomToReplace);
		//TD_GroupPlc[i].afficherPlc();
	}
	return false;
}
