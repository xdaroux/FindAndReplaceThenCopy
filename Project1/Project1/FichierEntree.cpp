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
	bool good = true;
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
		good = false;
	}
	fichierIn.close();
	return good;
}

bool FichierEntree::affichierFichierIn()
{
	int i;
	std::cout << "=================================================================================================== " << std::endl;
	std::cout << "                                        FICHIER D'ENTREE											  " << std::endl;
	std::cout << "=================================================================================================== " << std::endl;
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

	int flag_err = 1;
	bool err = true;

	nbSection = 0;
	
	while (i < nbLigneFichierIn-1) // car si nn on depasse ... 
	{
		while (ligneFichierIn[i][0] != '\0' && i < nbLigneFichierIn) //Quand on rencontre un '\0' = nouvelle section 
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
			flag_err = 0; //etre certain qu'on passe ici entre les sections pour detecter un double '\0'

		}
		if (nbSection > SECTION_IFIX_AND_MORE)
		{
			nbtypeDonnee++; // ajouter un type car la on a fini d'ajouter tout les types de donee dans le precedans
		}
		// Detection des erreurs dans la contruction du fichier 
		if (flag_err > 0 )
		{
			std::cout << "ERREUR dans la contruction du fichier  : ligne " << i << std::endl;
			err = false; 
		}
		flag_err++;

		nbSection++;//quand on change de section on a donc rencontre '\0'
		i++; //Pour avancer de ligne car '\0' SKIP L'AUTRE SECTION


		/// Je peut faire quelque chose quand on passe deux fois de suite back a back ici comme si on rencontre 2 ligne ou meme 3 avec des '\0'
	}

	return err;
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


