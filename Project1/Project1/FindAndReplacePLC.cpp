// FindAndReplacePLC.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Usine.h"

#include "FichierEntree.h"
#include "FichierSortie.h"
#include "FindAndReplacePLC.h"
#include "plc.h"

#define DEBUG 1
using namespace std;

int main()
{
	Usine MonUsine = Usine();
	FichierEntree MonFichierEntree;
	FichierSortie MonFichierSortie;
	Plc MonPlcTest = Plc();

	if (MonFichierEntree.enregistreFichierIn())  // S'il n y a pas d'erreur on continue 
	{
		MonFichierEntree.affichierFichierIn();

		if (MonFichierEntree.separationSectionFichierIn()) // S'il n y a pas d'erreur on continue 
		{
			MonFichierEntree.genereTypeDeDonne();


			MonUsine.ajouterLesPlc(MonFichierEntree.nomUsine, MonFichierEntree.TD_nomPlc, MonFichierEntree.nbPlc, MonFichierEntree.TD_typeDonnee, MonFichierEntree.nbtypeDonnee);
			MonUsine.Usine_FindAndReplacePlcName(MonFichierEntree.nomToReplace);

			MonFichierSortie.ajouterLesDonnerPLC(MonUsine);
			MonFichierSortie.ecrireFichierSortie(MonUsine, &MonFichierEntree);
			MonFichierSortie.afficherFichierSortie(MonUsine, &MonFichierEntree);

			std::cout << "\n\n ===================================================================================================" << std::endl;
			std::cout << "                                            SUCCESS"												<< std::endl;
			std::cout << " ===================================================================================================" << std::endl;
		}
		else
		{
			std::cout << "\n\n ===================================================================================================" << std::endl;
			std::cout << "                                            FAIL" << std::endl;
			std::cout << " ===================================================================================================" << std::endl;
			std::cout << "Erreur dans l'indentation du fuchier d'entree !!!!" << std::endl;
			system("PAUSE");
			
		}
	}
	else 
	{
		std::cout << "\n\n ===================================================================================================" << std::endl;
		std::cout << "                                            FAIL" << std::endl;
		std::cout << " ===================================================================================================" << std::endl;
		std::cout << "Erreur Ouverture du fichier, FICHIER \"fichier_entree.txt\" Introuvable\n" << std::endl;
		std::cout << "Assurez-vous que votre fichier d'entree est dans le meme repetoire que l'executable et qu'il est nommer : \"fichier_entree.txt\"\n\n" << std::endl;

		system("PAUSE");
	}
	return EXIT_SUCCESS;
}




	
