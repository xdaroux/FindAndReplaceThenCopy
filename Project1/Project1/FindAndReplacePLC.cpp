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

	
	if (MonFichierEntree.enregistreFichierIn())  // Si il ny a pas derreru continue 
	{
		MonFichierEntree.affichierFichierIn();
		MonFichierEntree.separationSectionFichierIn();
		//MonFichierEntree.afficherDonnee();
		MonFichierEntree.genereTypeDeDonne();
		//MonFichierEntree.afficherSeparationTypeDonne();

		MonUsine.ajouterLesPlc(MonFichierEntree.nomUsine, MonFichierEntree.TD_nomPlc, MonFichierEntree.nbPlc, MonFichierEntree.TD_typeDonnee, MonFichierEntree.nbtypeDonnee);
		MonUsine.Usine_FindAndReplacePlcName(MonFichierEntree.nomToReplace);

		MonFichierSortie.ajouterLesDonnerPLC(MonUsine);
		MonFichierSortie.ecrireFichierSortie(MonUsine, &MonFichierEntree);
		MonFichierSortie.afficherFichierSortie(MonUsine, &MonFichierEntree);
	}
	system("PAUSE");
	
		//
		//MonPlcTest.enregistrerPlcGroupeDeDonnee(MonFichierEntree.sortirToutLesTypeDeDonnee()); // plc test

		//cout << "Ici j'affiche mon AI dans mon plc Test " << endl;
		//MonPlcTest.plcGroupeDeDonnee[0].afficherSeparationDesDonnees();
		//
		//MonPlcTest.plcGroupeDeDonnee[0].~TypeDeDonnee(); //destruction faut je regarde si sa detruit l,autre aussi car si oui alors c,est passser par adresse et sa c pas bon car moi je veux des copies
		//cout << "Ici j'ai detruit le AI pour mon plc" << endl; ///c'est bien passer par copies 
		//
		//cout << "Ici j<affiche la donne que je ne veut pas perdre tres important" << endl;
		//MonFichierEntree.afficherSeparationTypeDonne();

		//cout << "Ici jaffiche mon plc dont jai demolie un itemps sa devrai pt ici environ " << endl;  //// c'est parfait sa fonctionne numeros 1 cette partie !!!
		//MonPlcTest.plcGroupeDeDonnee[0].afficherSeparationDesDonnees();
}




	
