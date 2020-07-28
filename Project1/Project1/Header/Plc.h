#pragma once
#include <vector>
#include "TypeDeDonnee.h"
#define NB_CARACTERE_A_CHANGER 4
class Plc
{
public:
	Plc();
	~Plc();
	std::string nomPlc;

	
	std::vector<TypeDeDonnee> plcGroupeDeDonnee;
	int nbPlcGroupeDeDonnee = 0;

public:
	bool enregistrerPlcGroupeDeDonnee(std::string NomPlc,std::vector<TypeDeDonnee>,int nbtypeDonnee);
	bool afficherPlc();
	bool PlcFindAndReplace(std::string replaceName);
};

