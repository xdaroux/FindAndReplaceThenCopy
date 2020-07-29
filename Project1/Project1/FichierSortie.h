#pragma once
#include <string>
#include "TypeDeDonnee.h"
#include <vector>
#include "Usine.h"
#include "FichierEntree.h"
#include<iostream>
#include <fstream>


class FichierSortie
{
public:
	FichierSortie();
	~FichierSortie();

	bool ecrireFichierSortie(Usine usine,FichierEntree *fichierIn);
	bool afficherFichierSortie(Usine usine, FichierEntree *fichierIn);

	bool ajouterLesDonnerPLC(Usine);
	


	std::string nomFichierSortie; // si je suis capable d'offrir un nom variable je pourrait utiliser la partie usine dans le text
	std::string TS_enteteGlobal[2];
	std::vector<TypeDeDonnee> TD_groupeDeDonneeGlobal; // Pour le moment j'ai juste besoin de AI,DI,TX donc statique 3 
	int nbGroupeDeDonnee = 0;

};

