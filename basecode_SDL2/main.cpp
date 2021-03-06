#include "utils.h"
#include "CArcher.h"
#include "CMage.h"
#include "CRogue.h"
#include "CWarrior.h"
#include "CCharacter.h"
#include "CWeapon.h"
#include "team.h"
#include "CDagger.h"
#include "CSword.h"
#include "CBow.h"
#include "CStaff.h"
#include "ascii.h"


enum class ePosition
{
	DOWN,
	LEFT,
	UP,
	RIGHT,
	NB_POSITION
};

struct sWeapon
{
	std::string s_type = "";
	std::string s_name = "";
	float s_critical = 0;
	int s_damage = 0;
	int s_HP = 0;
	int s_cout = 0;
	int s_durabilite = 0;
	int s_defense = 0;
	int s_fleche = 0;
	int s_intelligence = 0;
	int s_attack = 0;

};

struct sCharacter
{
	std::string s_class = "";
	std::string s_nom = "";
	int s_vitesse = 0;
	int s_attaque = 0;
	int s_intelligence = 0;
	int s_HP = 0;
	int s_defense = 0;
	float s_dodge = 0;
	int s_agilite = 0;
	float s_special = 0;

};







int main(int argc, char** argv)
{
	sWeapon weapons;
	sCharacter characters;
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* texture;
	SDL_Surface* image;
	SDL_Rect spriteRect;
	SDL_Rect positionRect;

	

	SDL_Event e;
	int quit = 0;

	ePosition pos = ePosition::DOWN;

	std::ifstream file("data/weapons.jdc");
	std::ifstream file_2("data/characters.jdc");
	std::string line;
	std::string line_2;
	std::string word;
	std::string word_2;
	std::vector<std::string> f_word;
	std::vector<std::string> f_word_2;
	std::stringstream ss;
	std::ostringstream oss;
	std::vector <std::string> tab;
	std::vector <std::string> tab_2;

	std::vector <CWeapon> TabWeapons;
	std::vector <CCharacter*> TabCharacters;

	int action;

	int j = 0;
	srand(time(NULL));
	int tour  = (rand() % 1);

	StartPrint();

	if (!file.is_open())
	{
		std::cout << "ERREUR";
		return EXIT_FAILURE;
	}

	while (std::getline(file, line))
		tab.push_back(line);
	file.close();


	for (int i = 0; i < tab.size(); i++)
	{
	
		std::stringstream ss(tab[i]);
		std::getline(ss, word, '\t');
		
		f_word.push_back(word);
		while (ss.good())
		{
			ss >> word;
			f_word.push_back(word);
			
		}
	}



	for (int i = 0; i < f_word.size(); i++)
	{
		if (f_word[i] == "Weapon")
		{
			f_word[i + 1].clear();
			while (f_word[i] != "EndWeapon")
			{
				
				if (f_word[i] == "Type")
					weapons.s_type = f_word[i + 1];

				if (f_word[i] == "Nom")
					weapons.s_name = f_word[i + 1];

				if (f_word[i] == "Critique")
					weapons.s_critical = stof(f_word[i + 1]);

				if (f_word[i] == "Degat")
					weapons.s_damage = stoi(f_word[i + 1]);

				if (f_word[i] == "HP")
					weapons.s_HP = stoi(f_word[i + 1]);

				if (f_word[i] == "Intelligence")
					weapons.s_intelligence = stoi(f_word[i + 1]);

				if (f_word[i] == "Cout")
					weapons.s_cout = stoi(f_word[i + 1]);

				if (f_word[i] == "Fleche")
					weapons.s_fleche = stoi(f_word[i + 1]);

				if (f_word[i] == "Defense")
					weapons.s_defense = stoi(f_word[i + 1]);

				if (f_word[i] == "Durabilite")
					weapons.s_durabilite = stoi(f_word[i + 1]);

				if (f_word[i] == "Attack")
					weapons.s_attack = stoi(f_word[i + 1]);

				
				i++;
				
			

			}
		}


		if (weapons.s_type == "Epee")
			TabWeapons.push_back(CSword(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));

		if (weapons.s_type == "Dague")
			TabWeapons.push_back( CDagger(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));
		
		if (weapons.s_type == "Arc")
			TabWeapons.push_back(CStaff(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_fleche, 0));

		if (weapons.s_type == "Baton")
			TabWeapons.push_back(CBow(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_cout, 0));

		i++;
	}

	
		


	if (!file_2.is_open())
	{
		std::cout << "ERREUR";
		return EXIT_FAILURE;
	}

	while (std::getline(file_2, line_2))
	{
		tab_2.push_back(line_2);
		
	}
	file_2.close();



	for (int i = 0; i < tab_2.size(); i++)
	{
		
		std::stringstream ss(tab_2[i]);
		std::getline(ss, word_2, '\t');
	
		
		f_word_2.push_back(word_2);
		
		while (ss.good())
		{
			ss >> word_2;
			f_word_2.push_back(word_2);
			
			
			
			//f_word_2[i + 1].clear();
			
		}
		
		
	}
	//for (int i = 0; i < f_word_2.size(); i++)
	//std::cout << f_word_2[i] << "\n";


	for (int i = 0; i < f_word_2.size(); i++)
	{
		
		if (f_word_2[i] == "Character")
		{
			
			while (f_word_2[i] != "EndCharacter")
			{
				

				if (f_word_2[i] == "Classe")
					characters.s_class = f_word_2[i + 1];
				

				if (f_word_2[i] == "Nom")
					characters.s_nom = f_word_2[i + 1];

				if (f_word_2[i] == "Vitesse")
					characters.s_vitesse = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "Attaque")
					characters.s_attaque = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "HP")
					characters.s_HP = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "Intelligence")
					characters.s_intelligence = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "Defense")
					characters.s_defense = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "Dodge")
					characters.s_dodge = stof(f_word_2[i + 1]);

				if (f_word_2[i] == "Agilite")
					characters.s_agilite = stoi(f_word_2[i + 1]);

				if (f_word_2[i] == "Special")
					characters.s_special = stof(f_word_2[i + 1]);


				i++;

			}

		}


	


		//TODO
		//Try de creer les instances

		if (characters.s_class == "Mage")
			TabCharacters.push_back(new CMage(characters.s_class, characters.s_nom, characters.s_HP, CWeapon(),characters.s_dodge, characters.s_vitesse, characters.s_attaque, characters.s_defense, characters.s_agilite, characters.s_intelligence, 0,0));

		if (characters.s_class == "Guerrier")
			TabCharacters.push_back(new CWarrior(characters.s_class, characters.s_nom, characters.s_HP, CWeapon(), characters.s_vitesse, characters.s_attaque, characters.s_intelligence, characters.s_HP, characters.s_dodge, characters.s_agilite, 0, 0));
			
		
		if (characters.s_class == "Archer")
			TabCharacters.push_back(new CArcher(characters.s_class, characters.s_nom, characters.s_HP,  CWeapon(), characters.s_dodge,characters.s_vitesse, characters.s_attaque, characters.s_defense, characters.s_agilite, characters.s_intelligence, 0));

		if (characters.s_class == "Voleur")
			TabCharacters.push_back(new CRogue(characters.s_class, characters.s_nom, characters.s_HP,  CWeapon(), characters.s_dodge, characters.s_vitesse, characters.s_attaque, characters.s_defense, characters.s_agilite, characters.s_intelligence, 0,0));

		

		//std::cout <<f_word_2[i] << "\n";
		
		
	}


	std::vector<CTeam> Teams;
	Teams.push_back(CTeam::CTeam());
	Teams.push_back(CTeam::CTeam());

	Teams[0].CreateTeam(1, TabCharacters, TabWeapons);
	system("cls");
	StartPrint();
	Teams[1].CreateTeam(2, TabCharacters, TabWeapons);
	
	for (int i = 4; i > 0; i--)
	{
		std::cout << "\rdebut de la partie dans " << i;
		Sleep(1000);
	}
	system("cls");
	StartPrint();

	std::cout << "\nC'est le joueur " << Teams[tour].m_name << " qui commence !\n";
	Teams[tour].m_perso1->Action(tour, Teams);

	while (tour != 3)
	{
		system("cls");
		StartPrint();
		std::cout << "\tInfos " << Teams[0].m_name << "\t\t\t" << "Infos " << Teams[1].m_name << "\n\n";
		std::cout << "\tVie perso 1 : " << Teams[0].m_perso1->m_health << "\n" << Teams[0].m_perso2->m_health << "\n" << Teams[0].m_perso1->m_health << "\n";

		tour = (tour + 1) % 2;
		std::cout << "\nC'est au tour de " << Teams[tour].m_name << " de jouer\n\n";
		std::cout << " de jouer\n\n Personnage : " << Teams[tour].m_perso1->m_name << "\n";
		Teams[tour].m_perso1->Action(tour, Teams);
		std::cout << " de jouer\n\n Personnage : " << Teams[tour].m_perso2->m_name << "\n";
		Teams[tour].m_perso2->Action(tour, Teams);
		std::cout << " de jouer\n\n Personnage : " << Teams[tour].m_perso3->m_name << "\n";
		Teams[tour].m_perso3->Action(tour, Teams);
	


		if (Teams[0].m_perso1->m_health < 0 || Teams[1].m_perso1->m_health < 0)
			tour = 3;

	}

	std::cout << "\nFINIIIIIIs";

	return EXIT_SUCCESS;


	//std::cout << TabCharacters[0].m_weapon.m_name;

	/*for (int i = 0; i < TabWeapons.size(); i++)
		TabWeapons[i].Print();*/





	/*if (!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cerr << "[-] ERROR - Failed to initialise SDL (" << SDL_GetError() << ")\n";
			return EXIT_FAILURE;
		}
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cerr << "[-] ERROR - Failed to initialise SDL_Image (" << SDL_GetError() << ")\n";
		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("Ma fenetre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cerr << "[-] ERROR - Failed to create SDL window (" << SDL_GetError() << ")\n";
		return EXIT_FAILURE;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	image = IMG_Load("data/sprite.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	SDL_SetRenderDrawColor(renderer, 40, 110, 0, 255);

	spriteRect.w = 120;
	spriteRect.h = 130;
	spriteRect.x = 0;
	spriteRect.y = 0;

	positionRect.w = 64;
	positionRect.h = 48;
	positionRect.x = 288;
	positionRect.y = 216;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = 1;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = 1;
					break;

				case SDLK_UP:
					pos = ePosition::UP;
					positionRect.y -= positionRect.h/2;
					break;

				case SDLK_DOWN:
					pos = ePosition::DOWN;
					positionRect.y += positionRect.h/2;
					break;

				case SDLK_RIGHT:
					pos = ePosition::RIGHT;
					positionRect.x += positionRect.w / 2;
					break;

				case SDLK_LEFT:
					pos = ePosition::LEFT;
					positionRect.x -= positionRect.w / 2;
					break;
				}
				break;

			default:
				break;
			}
		}

		spriteRect.y = (int)(pos) * spriteRect.h;

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, &spriteRect, &positionRect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;*/
}

