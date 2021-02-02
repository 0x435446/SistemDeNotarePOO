#include "Game.h"
#include<iostream>

// Define our static variables
std::atomic<bool> GameTools::m_bAtomActive(false);
std::condition_variable GameTools::m_cvGameFinished;
std::mutex GameTools::m_muxGame;

bool Game::OnUserCreate()
{
	//Log In
	std::string username;
	std::string password;
	std::cout << "Username:";
	std::cin >> username;
	std::cout << username;
	std::cout << std::endl;
	std::cout << "Password:";
	std::cin >> password;
	//Set User
	user.setName(username);
	user.setPassword(password);
	//LogIn check
	LogInSystem& login = LogInSystem::GetInstance(user);
	while (login.getLevel() == 0)
	{
		login.destroyInstance();
		std::cout << std::endl;
		std::cout << "Parola e Grsita!";
		std::cout << std::endl;
		std::cout << "Password:";
		std::cin >> password;
		user.setPassword(password);
		LogInSystem& login = LogInSystem::GetInstance(user);
	}
	

	//Seteaza Player Name = Username
	PlayerName = new std::wstring(username.begin(), username.end());

	//Initializare selectie in Side Panel
	bSelected = 0;
	bTopPanelFull = 0;
	bGameLost = 0;
	bGameWon = 0;
	bResetGame = 0;
	bAllZombiesDead = 0;
	nNumberOfSunFlowers = 0;
	nNumberOfLevel = login.getLevel();
	nNumberOfZombiesInLevel = 2 * nNumberOfLevel;
	nNumberOfZombiesInMap = 0;
	nZombiesKilled = 0;
	nPlantsPlanted = 0;
	//Initializare Lista
	PlantList.clear();
	ZombieList.clear();

	//Set Score Panel
	sScorePanel += L"##############";
	sScorePanel += L"#............#";
	sScorePanel += L"#............#";
	sScorePanel += L"#............#";
	sScorePanel += L"#............#";
	sScorePanel += L"#............#";
	sScorePanel += L"#............#";
	sScorePanel += L"##############";

	//Set Top Panel
	sTopPanel += L"#######################################################";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sTopPanel += L"#######################################################";

	//Set Side Panel
	sSidePanel += L"##############";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"##############";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"##############";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"##############";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"##############";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"#............#";
	sSidePanel += L"##############";

	//Set Hard Level
	sMapHard += L"#######################################################";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#######################################################";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#######################################################";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#######################################################";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#######################################################";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapHard += L"#######################################################";
	//SetLevelMedium
	sMapMedium += L"#######################################################";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#######################################################";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#######################################################";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#######################################################";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapMedium += L"#######################################################";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapMedium += L"#######################################################";
	//SetLevelEasy
	sMapEasy += L"#######################################################";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#######################################################";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#######################################################";
	sMapEasy += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapEasy += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapEasy += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapEasy += L"#.....#.....#.....#.....#.....#.....#.....#.....#.....#";
	sMapEasy += L"#######################################################";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#######################################################";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#00000#00000#00000#00000#00000#00000#00000#00000#00000#";
	sMapEasy += L"#######################################################";

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	pMapUsed = &sMapHard;
	LogInSystem& login = LogInSystem::GetInstance(user);

	if (bResetGame)
	{
		//Reseteaza jocul daca flag ul de ResetGame e true
		//Clear Screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, ' ');

		bSelected = 0;
		bTopPanelFull = 0;
		bGameLost = 0;
		bResetGame = 0;
		nNumberOfSunFlowers = 0;
		nNumberOfZombiesInLevel = 2 * nNumberOfLevel;
		//Sterge Listele
		PlantList.clear();
		ZombieList.clear();
		sun.setResources(50);
		//Reset Panels
		
		sMapEasy.resetPanel();
		sMapMedium.resetPanel();
		sMapHard.resetPanel();
		
		//sMapHard.resetPanel();
		sTopPanel.resetPanel();
		sSidePanel.resetPanel();
		sScorePanel.resetPanel();
		//Reset Time
		fRunTime = 0;

		if (bGameWon)
		{
			nNumberOfLevel++;
			login.setLevel(nNumberOfLevel);
			login.setScore(nZombiesKilled);
			login.updateGame();
			nNumberOfZombiesInLevel = 2 * nNumberOfLevel;
			bGameWon = 0;
		}
	}
	// daca flag ul de joc pierdut sau flagul de joc castigat sunt active se face true flag ul de resetgame pentru a reincepe runda/trece la nivelul urmator
	if (bGameLost || bGameWon)
	{
		if (GetMouse(0).bPressed)
			bResetGame = true;
	}
	else
	{
		//daca niciunul dintre cele 3 flag uri nu este activ se continua jocul 

		//Clear Screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

		//Get New Mouse Coords
		Mouse.X = GetMouseX();
		Mouse.Y = GetMouseY();

		//Lambda De Center In Side Panel
		auto GetSidePanelCenter = [&]()
		{
			COORD Center{};
			Center.X = 7;
			Center.Y = 3 + (int)(((Mouse.Y - sSidePanel.getOffsetY() * PixelHeight) / PixelHeight) / 5) % 5 * 5;
			return Center;
		};
		//Lambda De Center In Top Panel
		auto GetCenterTopPanel = [&]()
		{
			COORD Center{};
			Center.X = 3 + (int)(((Mouse.X - sTopPanel.getOffsetX() * PixelWidth) / PixelWidth) / 6) % 9 * 6;
			Center.Y = 4;

			return Center;
		};
		//Lambda de Random Top Panel Square
		auto RandomTopPanelSquare = [&]()
		{
			COORD Center{};
			Center.X = 3 + rand() % 9 * 6;
			Center.Y = 4;

			return Center;
		};
		//Lambda de verificare daca un nou soare are loc in top panel
		auto TopPanelFull = [&]()
		{
			for (int i = 0; i < 9; i++)
			{
				if (sTopPanel.getChar(i, 4) == OtherSign::SPACE)
					return 0;
			}
			return 1;
		};
		//Lambda De Center In Level Panel
		auto GetCenterLevelPanel = [&](Panel& sMapUsed)
		{
			COORD Center;
			Center.X = 3 + (int)((int)((Mouse.X - (*pMapUsed).getOffsetX() * PixelWidth) / PixelWidth) / 6) % 9 * 6;
			Center.Y = 3 + (int)((int)((Mouse.Y - (*pMapUsed).getOffsetY() * PixelHeight) / PixelHeight) / 5) % 5 * 5;

			return Center;
		};
		//Lambda de Random Zombii
		auto RandomCenterLane = [&]()
		{
			COORD Center;
			Center.X = 3 + 8 * 6;
			Center.Y = 3 + rand() % 5 * 5;

			return Center;
		};
		//Lambda de Timing Zombii
		auto ItsTimeForZombies = [&]()
		{
			static auto StartCreate = std::chrono::high_resolution_clock::now();
			auto EndCreate = std::chrono::high_resolution_clock::now();
			if (fRunTime > 10)
			{
				if (std::chrono::duration_cast<std::chrono::milliseconds>(EndCreate - StartCreate).count() > 10000)
				{
					StartCreate = EndCreate;
					return 1;
				}
			}
			return 0;
		};
		//Get Mouse Coords screen to world  //idee venita dupa reutilizarea multipla a calculelor de offset uri si marimea pixelilor //venita un pic prea tarziu
		auto ScreenToWorld = [&](Panel& panel)
		{
			COORD Center;
			Center.X = (Mouse.X - panel.getOffsetX() * PixelWidth) / PixelWidth;
			Center.Y = (Mouse.Y - panel.getOffsetY() * PixelHeight) / PixelHeight;
			return Center;
		}; 
		//Get World to Screen Coords    //la fel
		/*auto WorldToScreen = [&](COORD Mouse, Panel& panel)
		{
			Mouse.X = (panel.getPanelWidth() + panel.getOffsetX()) * PixelWidth;
			Mouse.Y = (panel.getPanelHeight() + panel.getOffsetY()) * PixelHeight;
		};*/

		//Draw BattelField
		for (int x = 0; x < (*pMapUsed).getPanelWidth(); x++)
		{
			for (int y = 0; y < (*pMapUsed).getPanelHeight(); y++)
			{
				wchar_t sTileID = (*pMapUsed).getChar(x, y);
				switch (sTileID)
				{
					//PLANTS
				case PEASHOOTER:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_GREEN);
					break;
				case SUNFLOWER:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_YELLOW);
					break;
				case CHERRYBOMB:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_RED);
					break;
				case WALLNUT:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_THREEQUARTERS, FG_DARK_YELLOW);
					break;
				case SNOWPEASHOOTER:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_CYAN);
					break;
					//ZOMBIES
				case REGULARZOMBIE:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_GREY);
					break;
				case BUCKETHEAD:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_DARK_RED);
					break;
				case POLEVAULTING:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_BLUE);
					break;
				case SUPERZOMBIE:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_SOLID, FG_DARK_MAGENTA);
					break;
					//SHOTS
				case PEASHOT:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_THREEQUARTERS, FG_GREEN);
					break;
				case FROZENPEASHOT:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_THREEQUARTERS, FG_CYAN);
					break;
					//OTHERS
				case SPACE:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_QUARTER, FG_GREEN);
					break;
				case WALL:
					Fill((x + OffsetX) * PixelWidth, (y + OffsetY) * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_QUARTER, FG_WHITE);
					break;
				}
			}
		}

		//Draw Top Panel
		for (int x = 0; x < sTopPanel.getPanelWidth(); x++)
		{
			for (int y = 0; y < sTopPanel.getPanelHeight(); y++)
			{
				wchar_t sTileID = sTopPanel.getChar(x, y);
				switch (sTileID)
				{
				case SPACE:
					Fill((x + OffsetX) * PixelWidth, y * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + 1) * PixelHeight, PIXEL_QUARTER, FG_CYAN);
					break;
				case WALL:
					Fill((x + OffsetX) * PixelWidth, y * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + 1) * PixelHeight, PIXEL_QUARTER, FG_WHITE);
					break;
				case SUNRESOURCE:
					Fill((x + OffsetX) * PixelWidth, y * PixelHeight, (x + OffsetX + 1) * PixelWidth, (y + 1) * PixelHeight, PIXEL_SOLID, FG_YELLOW);
				}
			}
		}

		//Draw Side Panel
		for (int x = 0; x < sSidePanel.getPanelWidth(); x++)
		{
			for (int y = 0; y < sSidePanel.getPanelHeight(); y++)
			{
				wchar_t sTileID = sSidePanel.getChar(x, y);
				switch (sTileID)
				{
				case SPACE:
					Fill(x * PixelWidth, (y + OffsetY) * PixelHeight, (x + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_QUARTER, FG_BLUE);
					break;
				case WALL:
					Fill(x * PixelWidth, (y + OffsetY) * PixelHeight, (x + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_QUARTER, FG_WHITE);
					break;
				}
			}
		}

		//Click in Side Panel
		  //Choose Plant

		//Bounderies for Side Panel World Coords
		/*
		x :1-13
		y1:1-5
		y2:6-10
		y3:11-15
		y4:16-20
		y5:21-25
		*/
		//Select In Side Panel
		if (GetMouse(0).bPressed && bSelected == 0)
		{
			if (Mouse.X < (sSidePanel.getPanelWidth() + sSidePanel.getOffsetX()) * PixelWidth && Mouse.Y < (sSidePanel.getPanelHeight() + sSidePanel.getOffsetY()) * PixelHeight && Mouse.Y >(sSidePanel.getOffsetY() * PixelHeight))
			{
				MouseOld.Y = ScreenToWorld(sSidePanel).Y;
				bSelected = 1;
			}
		}
		else if (GetMouse(0).bPressed && bSelected == 1)
		{
			bSelected = 0;

			int p = MouseOld.Y / 5;
			if (p < 5)
			{
				switch (p)
				{
				case 0:
				{
					Plant* sunflower = new SunFlower(GetCenterLevelPanel((*pMapUsed)));
					if (sun.getResources() >= (*sunflower).getCost())
					{
						//pune SunFlower unde dau click
						if ((*sunflower).Draw((*pMapUsed)))
						{
							nNumberOfSunFlowers++;
							PlantList.push_back(sunflower);
							sun.setResources(sun.getResources() - (*sunflower).getCost());
							nPlantsPlanted++;
							break;
						}
					}
					delete sunflower; //nu s-a reusit, curata memoria
					break;
				}
				case 1:
				{
					Plant* wallnut = new WallNut(GetCenterLevelPanel((*pMapUsed)));
					if (sun.getResources() >= (*wallnut).getCost())
					{
						//pune wallnut unde dau click
						if ((*wallnut).Draw((*pMapUsed)))
						{
							PlantList.push_back(wallnut);
							sun.setResources(sun.getResources() - (*wallnut).getCost());
							nPlantsPlanted++;
							break;
						}
					}
					delete wallnut; //nu s-a reusit, curata memoria
					break;
				}
				case 2:
				{
					Plant* peashooter = new PeaShooter(GetCenterLevelPanel((*pMapUsed)));
					if (sun.getResources() >= (*peashooter).getCost())
					{
						//pune peashooter unde dau click
						if ((*peashooter).Draw((*pMapUsed)))
						{
							PlantList.push_back(peashooter);
							sun.setResources(sun.getResources() - (*peashooter).getCost());
							nPlantsPlanted++;
							break;
						}
					}
					delete peashooter; //nu s-a reusit, curata memoria
					break;
				}
				case 3:
				{
					Plant* snowpeashooter = new SnowPeaShooter(GetCenterLevelPanel((*pMapUsed)));
					if (sun.getResources() >= (*snowpeashooter).getCost())
					{
						//pune snowpeashooter unde dau click
						if ((*snowpeashooter).Draw((*pMapUsed)))
						{
							PlantList.push_back(snowpeashooter);
							sun.setResources(sun.getResources() - (*snowpeashooter).getCost());
							nPlantsPlanted++;
							break;
						}
					}
					delete snowpeashooter; //nu s-a reusit, curata memoria
					break;
				}
				case 4:
				{
					Plant* cherrybomb = new CherryBomb(GetCenterLevelPanel((*pMapUsed)));
					if (sun.getResources() >= (*cherrybomb).getCost())
					{
						//pune cherrybomb unde dau click
						if ((*cherrybomb).Draw((*pMapUsed)))
						{
							PlantList.push_back(cherrybomb);
							sun.setResources(sun.getResources() - (*cherrybomb).getCost());
							nPlantsPlanted++;
							break;
						}
					}
					delete cherrybomb; //nu s-a reusit, curata memoria
					break;
				}
				}
			}
		}
		if (bSelected)
		{
			for (int x = 1; x < 13; x++)
			{
				int p = MouseOld.Y / 5;
				if (p < 5)
				{
					for (int y = 1 + 5 * p; y < 5 + 5 * p; y++)
					{
						Fill(x * PixelWidth, (y + OffsetY) * PixelHeight, (x + 1) * PixelWidth, (y + OffsetY + 1) * PixelHeight, PIXEL_THREEQUARTERS, FG_WHITE);
					}
				}
			}
		}

		//Se putea face mai bine, dar e mai rapid asa
		//Plante in Side Panel
		DrawString(PixelWidth, (3 + OffsetY) * PixelHeight, L"SunFlower");
		DrawString(PixelWidth, (8 + OffsetY) * PixelHeight, L"Wall-Nut");
		DrawString(PixelWidth, (13 + OffsetY) * PixelHeight, L"PeaShooter");
		DrawString(PixelWidth, (18 + OffsetY) * PixelHeight, L"SnowPeaShooter");
		DrawString(PixelWidth, (23 + OffsetY) * PixelHeight, L"CherryBomb");
		//Costuri in Side Panel
		DrawString((OffsetX - 2) * PixelWidth, (3 + OffsetY) * PixelHeight, L"50");
		DrawString((OffsetX - 2) * PixelWidth, (8 + OffsetY) * PixelHeight, L"50");
		DrawString((OffsetX - 2) * PixelWidth, (13 + OffsetY) * PixelHeight, L"100");
		DrawString((OffsetX - 2) * PixelWidth, (18 + OffsetY) * PixelHeight, L"150");
		DrawString((OffsetX - 2) * PixelWidth, (23 + OffsetY) * PixelHeight, L"150");

		//Draw Score Panel
		for (int x = 0; x < sScorePanel.getPanelWidth(); x++)
		{
			for (int y = 0; y < sScorePanel.getPanelHeight(); y++)
			{
				wchar_t sTileID = sScorePanel.getChar(x, y);
				switch (sTileID)
				{
				case L'.':
					Fill(x * PixelWidth, y * PixelHeight, (x + 1) * PixelWidth, (y + 1) * PixelHeight, PIXEL_QUARTER, FG_RED);
					break;
				case L'#':
					Fill(x * PixelWidth, y * PixelHeight, (x + 1) * PixelWidth, (y + 1) * PixelHeight, PIXEL_QUARTER, FG_WHITE);
					break;
				}
			}
		}
		//Afisare Player Name
		DrawString(2, 2, *PlayerName);
		//Afisare Level
		DrawString(2, 3, L"Level:");
		DrawString(2, 4, std::to_wstring(login.getLevel()));
		//Afisare Resursele
		DrawString(2, 5, L"Sun:");
		DrawString(2, 6, std::to_wstring(sun.getResources()));
		DrawString(2, 7, L"Plants planted:");
		DrawString(2, 8, std::to_wstring(PlantList.size()));
		//Afisare Scor
		DrawString(2, 9, L"Zombies Killed:");
		DrawString(2, 10, std::to_wstring(login.getScore() + nZombiesKilled)); //score ul anterior plus cel curent pronind de la 0

		//Draw Sun //Asta e in ability in mod normal dar pt a indeplini cerinta din tema nu va fi necesar
		if (AbMakeSun::getSunTime(4000 - (100 * (nNumberOfSunFlowers)))) 
		{
			sun.setCenterOfDrawing(RandomTopPanelSquare());
			sun.Draw(sTopPanel);
		}

		//Collect Sun
		if (GetMouse(0).bPressed && GetMouseY() < 14)
		{
			sun.setCenterOfDrawing(GetCenterTopPanel());
			sun.Erase(sTopPanel);
		}

		//Who Let the Zombies Out !?
		if (ItsTimeForZombies())
		{
			if (nNumberOfZombiesInLevel)
			{
				if (nZombiesKilled < 15 && nNumberOfZombiesInLevel > 1) //daca inca n ai omorat 15 zombii nu se vor spawna buckethead si pole vaulting
				{
					RegularZombie* regularzombie = new RegularZombie(RandomCenterLane());
					if (regularzombie->Draw((*pMapUsed)))
					{
						ZombieList.push_back(regularzombie);
						nNumberOfZombiesInLevel--;
						nNumberOfZombiesInMap++;
					}
					else
					{
						delete regularzombie;
					}
				}
				else if ((nNumberOfZombiesInLevel - nZombiesKilled) == 1) //daca a mai ramas un singur zombie se va spawna ca fiind superzombie (the boss of every round)
				{
					SuperZombie* superzombie = new SuperZombie(RandomCenterLane());
					if (superzombie->Draw((*pMapUsed)))
					{
						ZombieList.push_back(superzombie);
						nNumberOfZombiesInLevel--;
						nNumberOfZombiesInMap++;
					}
					else
					{
						delete superzombie;
					}
				}
				else
				{ //daca ai ucis peste 15 zombii esti pregatit sa infrunti polevaulting zombie si buckethead zombie
					bool n = rand() % 2;
					if (n)
					{
						PoleVaultingZombie* polevaultingzombie = new PoleVaultingZombie(RandomCenterLane());
						if (polevaultingzombie->Draw((*pMapUsed)))
						{
							ZombieList.push_back(polevaultingzombie);
							nNumberOfZombiesInLevel--;
							nNumberOfZombiesInMap++;
						}
						else
						{
							delete polevaultingzombie;
						}
					}
					else
					{
						BucketHead* buckethead = new BucketHead(RandomCenterLane());
						if (buckethead->Draw((*pMapUsed)))
						{
							ZombieList.push_back(buckethead);
							nNumberOfZombiesInLevel--;
							nNumberOfZombiesInMap++;
						}
						else
						{
							delete buckethead;
						}
					}
				}
			}
		}

		//itereaza zombii
		for (auto zombie = ZombieList.begin(); zombie != ZombieList.end(); zombie++)
		{
			(*zombie)->Move((*pMapUsed));
			if ((*zombie)->getCenterOfDrawing().X == 0)
			{
				DrawString(70, 40, L"Game Over!");
				DrawString(55, 42, L"Left-Click your mouse to Restart the Game");
				bGameLost = 1;
			}
		}

		//Plantele Impusca
		for (auto plant = PlantList.begin(); plant != PlantList.end(); plant++)
		{
			for (auto zombie = ZombieList.begin(); zombie != ZombieList.end(); zombie++)
			{
				if ((*plant)->getCenterOfDrawing().Y == (*zombie)->getCenterOfDrawing().Y)
					(*plant)->Shoot((*pMapUsed), *(*zombie));
				if ((*zombie)->getHP() <= 0)
				{
					nNumberOfZombiesInMap--;
					nZombiesKilled++;
				}
				if ((*zombie)->getCenterOfDrawing().X - 1 == (*plant)->getCenterOfDrawing().X && (*zombie)->getCenterOfDrawing().Y == (*plant)->getCenterOfDrawing().Y)
					(*zombie)->Attack((*pMapUsed), *(*plant));
			}
			ZombieList.remove_if([&](Zombie* zombie) {return (zombie->getHP() <= 0); });
		}
		PlantList.remove_if([](Plant* plant) {return plant->getHP() <= 0; });

		if ((nNumberOfZombiesInLevel == 0) && (nNumberOfZombiesInMap == 0))
		{
			DrawString(70, 40, L"Game Won!");
			DrawString(55, 42, L"Left-Click your mouse to Get to the Next Level");
			bGameWon = 1;
		}
	}
		return true;
}