#include "utils.h"


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
	int index = 0;

	ePosition pos = ePosition::DOWN;

	std::ifstream file("data/weapons.jdc");
	std::ifstream file_2("data/characters.jdc");
	std::string line;
	std::string word;
	std::vector<std::string> f_word;
	std::stringstream ss;
	std::ostringstream oss;
	std::vector <std::string> tab;
	std::vector <CWeapon> TabWeapons;

	int j = 0;

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
				
				//std::cout << j;

			}
		}


		if (weapons.s_type == "Epee")
			TabWeapons.push_back(CSword(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));

		if (weapons.s_type == "Dague")
			TabWeapons.push_back(CDagger(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));

		if (weapons.s_type == "Arc")
			TabWeapons.push_back(CStaff(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_fleche, 0));

		if (weapons.s_type == "Baton")
			TabWeapons.push_back(CBow(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_cout, 0));

		i++;
	}

	/*for (int i = 0; i < TabWeapons.size(); i++)
	*	TabWeapons[i].Print();
	*/

	tab.clear();
	line.clear();
	f_word.clear();
	word.clear();



	//*****************************************************



	if (!file_2.is_open())
	{
		std::cout << "ERREUR";
		return EXIT_FAILURE;
	}

	while (std::getline(file, line))
		tab.push_back(line);
	file_2.close();


	for (int i = 0; i < tab.size(); i++)
	{

		std::stringstream ss(tab[i]);
		std::getline(ss, word, '\t');
		std::cout << i;
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
			std::cout << " OK" << "\n";
			while (f_word[i] != "EndWeapon")
			{

				if (f_word[i] == "Classe")
					characters.s_class = f_word[i + 1];

				if (f_word[i] == "Nom")
					characters.s_nom = f_word[i + 1];

				if (f_word[i] == "Vitesse")
					characters.s_vitesse = stof(f_word[i + 1]);

				if (f_word[i] == "Attaque")
					characters.s_attaque = stoi(f_word[i + 1]);

				if (f_word[i] == "HP")
					characters.s_HP = stoi(f_word[i + 1]);

				if (f_word[i] == "Intelligence")
					characters.s_intelligence = stoi(f_word[i + 1]);

				if (f_word[i] == "Defense")
					characters.s_defense = stoi(f_word[i + 1]);

				if (f_word[i] == "Dodge")
					characters.s_dodge = stoi(f_word[i + 1]);

				if (f_word[i] == "Agilite")
					characters.s_agilite = stoi(f_word[i + 1]);

				if (f_word[i] == "Special")
					characters.s_special = stoi(f_word[i + 1]);

				i++;

				//std::cout << j;

			}
		}


		//TODO
		//Try de creer les instances

		/*if (characters.s_class == "Mage")
			TabWeapons.push_back(CSword(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));

		if (characters.s_class == "Guerrier")
			TabWeapons.push_back(CDagger(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_durabilite));

		if (characters.s_class == "Archer")
			TabWeapons.push_back(CStaff(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_fleche, 0));

		if (characters.s_class == "Voleur")
			TabWeapons.push_back(CBow(weapons.s_name, weapons.s_damage, weapons.s_critical, 0, weapons.s_cout, 0));*/

		i++;
		std::cout << characters.s_class;
	}





	if (!SDL_WasInit(SDL_INIT_VIDEO))
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

	return EXIT_SUCCESS;
}

