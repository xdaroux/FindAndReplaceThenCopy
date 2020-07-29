#include "FichierSortie.h"




FichierSortie::FichierSortie()
{
}


FichierSortie::~FichierSortie()
{
}

bool FichierSortie::ecrireFichierSortie(Usine usine,FichierEntree *fichierIn)
{
	std::ofstream fichierOut("fichier_sotie.txt");
	std::cout << "\n\n=================================================================================================== " << std::endl;
	std::cout << "                                        FICHIER DE SORTIE											  " << std::endl;
	std::cout << "=================================================================================================== " << std::endl;

	if (fichierOut)
	{
		for (int i = 0; i < fichierIn->nbLigneEnteteGlobal; i++)
		{
			fichierOut << fichierIn->TD_EnteteGlobal[i]<<std::endl; //afficher l<ente global 
		}
		fichierOut << std::endl;  ///mettre un entre pour separer 
	
		for (int i = 0; i < nbGroupeDeDonnee; i++)
		{
			fichierOut<<TD_groupeDeDonneeGlobal[i].TS_enteteDeDonnee[0] << std::endl;
			fichierOut << TD_groupeDeDonneeGlobal[i].TS_enteteDeDonnee[1] << std::endl;
		
			for (int y = 0; y < TD_groupeDeDonneeGlobal[i].nbTypeDeLigneDeDonnee; y++)
			{
				fichierOut<<TD_groupeDeDonneeGlobal[i].TD_TypeDeligneDeDonnee[y] << std::endl;
			}
			fichierOut << std::endl; // faire un espace
		}
		fichierOut << "[-------------------------------------------------End of Block List-------------------------------------------------]" << std::endl;
	}
	else
	{
		std::cout << " Erreur d'ouverture du ficher de SORTE !!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	}
	fichierOut.close();
	return false;
}
bool FichierSortie::afficherFichierSortie(Usine usine, FichierEntree *fichierIn)
{
	std::ofstream fichierOut("fichier_sotie.txt");

	if (fichierOut)
	{
		for (int i = 0; i < fichierIn->nbLigneEnteteGlobal; i++)
		{
			std::cout << fichierIn->TD_EnteteGlobal[i] << std::endl; //afficher l<ente global 
		}
		std::cout << std::endl;  ///mettre un entre pour separer 

		for (int i = 0; i < nbGroupeDeDonnee; i++)
		{
			std::cout << TD_groupeDeDonneeGlobal[i].TS_enteteDeDonnee[0] << std::endl;
			std::cout << TD_groupeDeDonneeGlobal[i].TS_enteteDeDonnee[1] << std::endl;

			for (int y = 0; y < TD_groupeDeDonneeGlobal[i].nbTypeDeLigneDeDonnee; y++)
			{
				std::cout << TD_groupeDeDonneeGlobal[i].TD_TypeDeligneDeDonnee[y] << std::endl;
			}
			std::cout << std::endl; // faire un espace
		}
		std::cout  << "[-------------------------------------------------End of Block List-------------------------------------------------]" << std::endl;
	}
	else
	{
		std::cout << " Erreur d'ouverture du ficher de SORTE !!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	}

	return false;
}

bool FichierSortie::ajouterLesDonnerPLC(Usine usine)
{

	for (int x = 0; x < usine.TD_GroupPlc[0].nbPlcGroupeDeDonnee; x++)
	{
		TD_groupeDeDonneeGlobal.push_back(TypeDeDonnee());   /// je cree ici le nombre qu<il faut cree d,espace selon le premier plc
		TD_groupeDeDonneeGlobal[x].TS_enteteDeDonnee[0] = usine.TD_GroupPlc[0].plcGroupeDeDonnee[x].TS_enteteDeDonnee[0];
		TD_groupeDeDonneeGlobal[x].TS_enteteDeDonnee[1] = usine.TD_GroupPlc[0].plcGroupeDeDonnee[x].TS_enteteDeDonnee[1];
		nbGroupeDeDonnee++;
	}
	for (int i = 0; i < usine.NbPlc; i++)
	{
		
		for (int y = 0; y < usine.TD_GroupPlc[i].nbPlcGroupeDeDonnee; y++)
		{   
			for (int z = 0; z < usine.TD_GroupPlc[i].plcGroupeDeDonnee[y].nbTypeDeLigneDeDonnee; z++)
			{
				TD_groupeDeDonneeGlobal[y].TD_TypeDeligneDeDonnee.push_back(usine.TD_GroupPlc[i].plcGroupeDeDonnee[y].TD_TypeDeligneDeDonnee[z]); // Y est a deux place car il faut que sa se suive AI toute ensemble DI tout ensemble TX aussi voila 
				TD_groupeDeDonneeGlobal[y].nbTypeDeLigneDeDonnee++;
			}
			
		}
		
	}
	
	return false;
}
