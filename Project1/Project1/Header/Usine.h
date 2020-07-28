#pragma once

#include <string>
#include <vector>
#include "TypeDeDonnee.h"
#include "Plc.h"

class Usine
{
public:
	Usine();
	~Usine();

	bool ajouterLesPlc( std::string nomUsine,std::vector<std::string> nomPlc,int nbPlc,std::vector<TypeDeDonnee>plcGroupeDonnee,int );
	bool Usine_FindAndReplacePlcName(std::string nomToReplace);
	

	std::string NomUsine;
	std::vector<Plc> TD_GroupPlc;
	int NbPlc = 0;
	std::string nomToReplace;

};

