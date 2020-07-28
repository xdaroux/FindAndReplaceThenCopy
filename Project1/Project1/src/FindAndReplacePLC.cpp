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

	
	MonFichierEntree.enregistreFichierIn();  // Si il ny a pas derreru continue 
	
		MonFichierEntree.affichierFichierIn();
		MonFichierEntree.separationSectionFichierIn();
		//MonFichierEntree.afficherDonnee();
		MonFichierEntree.genereTypeDeDonne();
		//MonFichierEntree.afficherSeparationTypeDonne();

		MonUsine.ajouterLesPlc(MonFichierEntree.nomUsine, MonFichierEntree.TD_nomPlc, MonFichierEntree.nbPlc, MonFichierEntree.TD_typeDonnee, MonFichierEntree.nbtypeDonnee);
		MonUsine.Usine_FindAndReplacePlcName(MonFichierEntree.nomToReplace);

		MonFichierSortie.ajouterLesDonnerPLC(MonUsine);
		MonFichierSortie.ecrireFichierSortie(MonUsine, &MonFichierEntree);

		//MonFichierSortie.afficherFichierSortie(MonUsine, &MonFichierEntree);
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

		///semaine prochaine je dois faire une creation de tout mes PLC les mettre egale a fichier entree typededonneee faire un FIND REPLACE et reconstruire le fichier de sortie et j<ai fini
}


	// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
	// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

	// Conseils pour bien démarrer : 
	//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
	//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
	//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
	//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
	//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
	//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

	
