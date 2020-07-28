#pragma once
#include <string>
#include <vector>


class TypeDeDonnee
{
public:
	TypeDeDonnee();
	~TypeDeDonnee();

	bool separationDonnee();
	bool enregistreEnteteDeDonnee();
	bool enregistreTypeDeDonee();

	bool ajouterLigneDeDonnee(std::string ligne);

	bool afficherDonne();
	bool afficherSeparationDesDonnees();
	//ici je dois faire sortir certaine donnee pas par adresse dans le fond je veut que d<autre classe puisse venir les cherchers comme le plc et le fichier de sortie
	//std::string sortirTypeDeDonne();
	//std::vector<std::string> sortirTD_TypeDeligneDeDonnee();

	std::vector<std::string> TD_TypeDeligneDeDonnee; //dynamique, car je peux en avoir vraiment beaucoup yeah it works :) // apres la separation des donnee
	int nbTypeDeLigneDeDonnee = 0;
	std::string TS_enteteDeDonnee[2];

	std::string typeDeDonne = ""; //surment devoir le mettre public pour faire des comparaisons

private:
	

	

	std::vector<std::string> TD_ligneDeDonnee; //dynamique, car je peux en avoir vraiment beaucoup yeah it works :) // avant la separation des donnee
	int nbLigneDeDonnee = 0;


	

	

	
};

