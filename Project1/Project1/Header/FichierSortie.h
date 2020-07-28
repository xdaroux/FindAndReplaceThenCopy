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


	//bool enregistreEnteteGlobal(std::string* enteteGlobal);
	//bool enregistreNomFichierSortie(std::string nomFichierSortie);
	//
	//bool ajouterTypeDeDonnee(std::string type);
	//bool ajouterLigneDeDonne(std::string type, std::string donnee); // pt mettre des ligne de donne car je vais pt ici en placer plusieur et meme temps pour un meme plc

	bool ecrireFichierSortie(Usine usine,FichierEntree *fichierIn);
	bool afficherFichierSortie(Usine usine, FichierEntree *fichierIn);

	bool ajouterLesDonnerPLC(Usine);
	


	std::string nomFichierSortie; // si je suis capable
	std::string TS_enteteGlobal[2];
	std::vector<TypeDeDonnee> TD_groupeDeDonneeGlobal; // Pour le moment j'ai juste besoin de AI,DI,TX donc statique 3 
	int nbGroupeDeDonnee = 0;

};

