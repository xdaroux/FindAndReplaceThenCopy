#include "FichierEntree.h"
#include <string>

#define SECTION_NAME_TO_REPLACE 0
#define SECTION_NAME_USINE 1
#define SECTION_NAME_PLC 2
#define SECTION_IFIX_AND_MORE 3



FichierEntree::FichierEntree()
{
}


FichierEntree::~FichierEntree()
{
}

bool FichierEntree::enregistreFichierIn()
{
	bool err = true;
	fichierIn.open("fichier_entree.txt", std::ifstream::in);
	if (fichierIn)
	{
		std::string  tmp;
		int i = 0;
		while (getline(fichierIn,tmp)) // temps qui il y a quelque chopse a lire
		{

			ligneFichierIn.push_back(tmp);

			nbLigneFichierIn++;
			i++;
		}

	}
	else
	{
		std::cout << "ERREUR d'ouverture du fichier" << std::endl;
		err = false;
	}
	fichierIn.close();
	return err;
}

bool FichierEntree::affichierFichierIn()
{
	int i;
	for (i = 0; i < nbLigneFichierIn; i++)
	{
		std::cout << i << " : "<< ligneFichierIn[i]<< std::endl;
	}
	

	return false;
}

bool FichierEntree::afficherDonnee()
{
	int i = 0;
	std::cout << "section : " << i << std::endl;
	std::cout << nomUsine << std::endl;
	i++;

	std::cout << "section : " << i << std::endl;
	for (int y = 0; y < nbPlc; y++)
	{
		std::cout << y << " : " << TD_nomPlc[y] << std::endl;
	}
	i++;

	std::cout << "section : " << i << std::endl;
	for (int y = 0; y < nbLigneEnteteGlobal; y++)
	{
		std::cout << y << " : " << TD_EnteteGlobal[y] << std::endl;

	}
	i++;
	
		
	while ( i < nbSection)
	{
		
		
		
		for (int z = 0; z < nbtypeDonnee; z++)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "section : " << i << std::endl;
			TD_typeDonnee[z].afficherDonne();
			i++;
		}
		
		//manque les type apres test
	}
	return false;
}

bool FichierEntree::separationSectionFichierIn()
{

	int i = 0;
	int y = 0;
	nbSection = 0;
	
	while (i < nbLigneFichierIn-1) // car si nn on depasse ... 
	{
		while (ligneFichierIn[i][0] != '\0' && i < nbLigneFichierIn)
		{
			if (nbSection > SECTION_IFIX_AND_MORE) // des que j'ai depasser les 3 premiere secion 0,1,2 ben on est rendu dans les donne so a chaque fois faut cree un nouveau type de donnee
			{
				TD_typeDonnee.push_back(TypeDeDonnee()); // je cree un type de donnee

			}

			if (nbSection == SECTION_NAME_TO_REPLACE)
			{
				nomToReplace = ligneFichierIn[i];
				//std::cout << "Longueur du Mots a remplacer !!! : " <<nomToReplace.length << std::endl;

			}
			else if (nbSection == SECTION_NAME_USINE) // usine
			{
				nomUsine = ligneFichierIn[i];
			}
			else if (nbSection == SECTION_NAME_PLC)//plc
			{
				TD_nomPlc.push_back(ligneFichierIn[i]);
				nbPlc++;
			}
			else if (nbSection == SECTION_IFIX_AND_MORE)//entete global
			{
				TD_EnteteGlobal.push_back(ligneFichierIn[i]);
				nbLigneEnteteGlobal++;
			}
			else//les tags
			{

				//TD_typeDonnee[nbtypeDonnee].enregistreEnteteDeDonnee();
				TD_typeDonnee[nbtypeDonnee].ajouterLigneDeDonnee(ligneFichierIn[i]);

			}
			i++;//pour avancer de ligne

		}
		if (nbSection > SECTION_IFIX_AND_MORE)
		{
			nbtypeDonnee++; // ajouter un type car la on a fini d'ajouter tout les types de donee dans le precedans
		}
		nbSection++;//quand on change de section on a donc rencontre '\0'
		i++; //Pour avancer de ligne car '\0' SKIP L'AUTRE SECTION
	}

	return false;
}

bool FichierEntree::genereTypeDeDonne()
{
	for (int i = 0; i < nbtypeDonnee; i++)
	{
		TD_typeDonnee[i].separationDonnee();
	}
	return false;
}

bool FichierEntree::afficherSeparationTypeDonne()
{
	for (int i = 0; i < nbtypeDonnee; i++)
	{
		TD_typeDonnee[i].afficherSeparationDesDonnees();
	}
	return false;
	
}


