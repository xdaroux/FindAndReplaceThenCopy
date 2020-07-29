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
		MonFichierEntree.separationSectionFichierIn();
		
		MonFichierEntree.genereTypeDeDonne();
		

		MonUsine.ajouterLesPlc(MonFichierEntree.nomUsine, MonFichierEntree.TD_nomPlc, MonFichierEntree.nbPlc, MonFichierEntree.TD_typeDonnee, MonFichierEntree.nbtypeDonnee);
		MonUsine.Usine_FindAndReplacePlcName(MonFichierEntree.nomToReplace);

		MonFichierSortie.ajouterLesDonnerPLC(MonUsine);
		MonFichierSortie.ecrireFichierSortie(MonUsine, &MonFichierEntree);
		MonFichierSortie.afficherFichierSortie(MonUsine, &MonFichierEntree);
	}
	system("PAUSE");
}




	
