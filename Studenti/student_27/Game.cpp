#include "Game.h"


static int enter = 0;

bool finish_game = false;

Game* iGame::get_instance()
{
	return (new Game());
}

void CreateZombie(int &nivel,PieceOnTable*& piece_table)
{

	int check_nivel_1 = 0;

	int check_nivel_2 = 0;

	int check_nivel_3 = 0;

	int number_of_zombie_nivel_1 = 3;

	int number_of_zombie_nivel_2 = 5;

	int number_of_zombie_nivel_3 = 5;

	while (true && finish_game == false)
	{

		if (number_of_zombie_nivel_1 == 0 && check_nivel_1==0)
		{
			nivel = 2;

			check_nivel_1 = 1;

			piece_table->Get_Game()->ShowNivel();

		}

		if (number_of_zombie_nivel_2 == 0 && check_nivel_2 == 0)
		{
			nivel = 3;

			check_nivel_2 = 1;

			piece_table->Get_Game()->ShowNivel();
		}

		if (number_of_zombie_nivel_3 == 0 && check_nivel_3 == 0)
		{
			nivel = 4;

			check_nivel_3 = 1;

			//piece_table->Get_Game()->ShowNivel();
		}


		if (check_nivel_1 == 1)
		{
			Sleep(15000);
			check_nivel_1++;
			piece_table->Get_Game()->NextLevel();
		}
		if (check_nivel_2 == 1)
		{
			Sleep(15000);
			check_nivel_2++;
			piece_table->Get_Game()->NextLevel();
		}
		if (check_nivel_3 == 1)
		{
			Sleep(15000);
			check_nivel_3++;
			piece_table->Get_Game()->Win();
			piece_table->Get_Game()->Put_Player_in_File();
		}

		list<iZombie*> listZombie = piece_table->GetListZombie();

	     list<iZombie*>::iterator it;

		 int empty = 1;



		if (nivel==1)
		Sleep(30000);

		if (nivel == 2)
			Sleep(25000);

		if (nivel == 3)
			Sleep(23000);

		if (nivel == 1 || nivel == 2 || nivel == 3)

		{
			UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

			iZombie* zombie = new BanalZombie(100, 100, '?');

			iZombie* zombie1 = new BucketHead_Zombie(100, 300, '@');

			srand(time(NULL));

			int iSecret;
			/* generate secret number between 1 and 10: */

			if (nivel == 1)
				iSecret = rand() % 1;

			if (nivel == 2)
				iSecret = rand() % 3;

			if (nivel == 3)
				iSecret = rand() % 5;

			int xPos = 10;

			for (int i = 1; i <= iSecret; i++)
			{
				xPos = xPos + 6;
			}

			zombie->SetxPos(xPos);
			zombie->SetyPos(146);

			{
				conOut(zombie->GetxPos(), zombie->GetyPos()) <<zombie->GetSymbol();

			}

			piece_table->Push_Back(zombie);

			if (iSecret == 0)
				xPos = xPos + 6;
			else
				xPos = xPos - 6;

			if (nivel == 2 || nivel == 3)
			{
				zombie1->SetxPos(xPos);
				zombie1->SetyPos(146);

				{
					conOut(zombie1->GetxPos(), zombie1->GetyPos()) << zombie1->GetSymbol();
				}
				piece_table->Push_Back(zombie1);
			}


			if (nivel == 1)
				number_of_zombie_nivel_1--;

			if (nivel == 2)
				number_of_zombie_nivel_2--;

			if (nivel == 3)
				number_of_zombie_nivel_3--;

		}

	}
}

void EachZombie(iZombie*& zombie)
{

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	Sleep(zombie->GetSpeed());


	conOut(zombie->GetxPos(),zombie->GetyPos()) << " ";
	zombie->SetyPos(zombie->GetyPos() - 1);

	conOut(zombie->GetxPos(), zombie->GetyPos()) << "?";


}


void MoveZombie(int &nivel,PieceOnTable*& piece_table)
{
	//while (true && finish_game == false)
	{
		//Sleep(100);

		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

		list<iZombie*> listZombie = piece_table->GetListZombie();

		list<iZombie*>::iterator it;

		list<iPlant*>::iterator it1;

		list<iPlant*> listPlant1 = piece_table->GetListPlant();

		int i = 0;

		int empty = 1;

		for (it = listZombie.begin(); it != listZombie.end(); ++it)
		{
		
			empty = 0;

				int col = 0;

				int plant_on_table = 0;

				for (it1 = listPlant1.begin(); it1 != listPlant1.end(); ++it1)
				{
					if ((*it)->GetyPos() - (*it1)->GetyPos() <= 2)
					{
						if ((*it)->GetxPos() == (*it1)->GetxPos())
						{
							piece_table->Remove_Plant(*it1);
							conOut((*it1)->GetxPos(), (*it1)->GetyPos()) << " ";
							plant_on_table == 1;
						}
					}
				}

				for (int i = 13; i <= 133; i = i + 15)
				{
					if ((*it)->GetyPos()== i)
					{
						col = 1;
					}
				}

				for (int i = 21; i <= 141; i = i + 15)
				{
					if ((*it)->GetyPos() == i)
					{
						col = 1;
					}
				}

				if (col == 1)
				{
					char x = 179;
					conOut((*it)->GetxPos(), (*it)->GetyPos()) << x;
				}
				else
					conOut((*it)->GetxPos(), (*it)->GetyPos()) << " ";

				(*it)->SetyPos((*it)->GetyPos() - 1);

				if ((*it)->GetyPos() != 10)
				{
					conOut((*it)->GetxPos(), (*it)->GetyPos()) <<(*it)->GetSymbol();
				}

				else
				{
					finish_game = true;
					piece_table->Get_Game()->Put_Player_in_File();
				}
			}

	}
}

void TryToShoot(int &nivel,PieceOnTable*& piece_table)
{
	while (true && finish_game == false)
	{
		Sleep(100);

		list<iPlant*>::iterator it;

		list<iPlant*>::iterator it1;

		list<iZombie*>::iterator it2;

		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

		list<iPlant*> listPlant = piece_table->GetListPlant();

		list<iPlant*> listPlant1 = piece_table->GetListPlant();

		list<iZombie*> listZombie = piece_table->GetListZombie();



		for (it = listPlant.begin(); it != listPlant.end(); ++it)
		{
			if ((*it)->GetSymbol() == 'P')
			{
				Peashooter* peaShooter = (Peashooter*)(*it);
				Projectile* project = peaShooter->GetProjectile();

				int lastX;
				int lastY;

				if (project->GetyPos() == 147)
				{
					project->SetyPos(peaShooter->GetyPos() + 1);
					conOut(project->GetxPos(), 146) << " ";
				}

				int zombie_on_table = 0;

				for (it2 = listZombie.begin(); it2 != listZombie.end(); ++it2)
				{
					if ((*it2)->GetyPos() - project->GetyPos() <=2 )
					{
						if ((*it2)->GetxPos() == project->GetxPos())
						{
							(*it2)->ReduceHealth(project->GetDamage());
							conOut(project->GetxPos(), project->GetyPos()-1) << " ";
							project->SetyPos(peaShooter->GetyPos() + 1);

							if ((*it2)->GetHealth() == 0)
							{
								//conOut((*it2)->GetLastX(),(*it2)->GetLastY()+1 )<< " ";
								piece_table->Remove_Zombie(*it2);
								
								if ((*it2)->GetSymbol()=='?')
								piece_table->Get_Game()->AddScore(25);

								if ((*it2)->GetSymbol() == '@')
									piece_table->Get_Game()->AddScore(100);

								piece_table->Get_Game()->ShowScore();
							}
							zombie_on_table == 1;
						}
					}
				}

				if (zombie_on_table == 0)

				{
					conOut(project->GetxPos(), project->GetyPos()) << project->GetSymbol();



					if (peaShooter->GetyPos() != project->GetyPos() - 1)
					{
						int another_piece = 0;

						for (it1 = listPlant1.begin(); it1 != listPlant1.end(); ++it1)
						{
							if ((*it1)->GetyPos() == project->GetyPos() - 1 && (*it1)->GetxPos()== project->GetxPos())
							{
								conOut(project->GetxPos(), project->GetyPos() - 1) << (*it1)->GetSymbol();
								another_piece = 1;
							}
						}

						if (another_piece == 0)

						{
							int col = 0;

							for (int i = 13; i <= 133; i = i + 15)
							{
								if (project->GetyPos() - 1 == i)
								{
									col = 1;
								}
							}

							for (int i = 21; i <= 141; i = i + 15)
							{
								if (project->GetyPos() - 1 == i)
								{
									col = 1;
								}
							}

							if (col == 1)
							{
								char x = 179;
								conOut(project->GetxPos(), project->GetyPos() - 1) << x;
							}
							else
								conOut(project->GetxPos(), project->GetyPos() - 1) << " ";
						}
					}

					project->SetyPos();
				}
			}
		}
		MoveZombie(nivel, piece_table);
	}
}

void GenerateSun_(Sun*& s)
{

	while (true && finish_game==false)
	{
		Sleep(3000);
		srand(time(NULL));

		int iSecret;
		/* generate secret number between 1 and 10: */
		iSecret = rand() % 9;

		int x = 17;

		for (int i = 1; i <= iSecret; i++)
		{
			x = x + 15;
		}
		if (s->GetSunRow() != 0 && s->GetSunRow() != 0)
		{
			COORD coord;
			coord.X = s->GetSunCol();
			coord.Y = s->GetSunRow();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << " ";
			s->SetSunRow(0);
			s->SetSunCol(0);
		}

		{   
			int wait = s->GetSunWait();
			Sleep(wait);
			COORD coord;
			coord.X = x;
			coord.Y = 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << "*";
			s->SetSunRow(3);
			s->SetSunCol(x);
		}
	}
}
Game::Game()
{
	this->Create_User_Password();

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	piece_table = new PieceOnTable();


	piece_table->Connection_With_Game(this);

	conOut.Game_Loading();

	conOut.Create_Start();

	this->Create_First_Sun_Flower();

	this->Create_First_PeaShooter();

	this->ShowNivel();

	this->ShowScore();


	//std::thread t([&](viewWindow* view) { view->refreshWindow(render, playerRect, backTexture, playerTexture); }, &window);

	//Game* game;

	//game = this;

//	std::thread second(TryToShoot,std::ref(*this));

}

Game::~Game()
{
}

void Game::Create_First_Sun_Flower()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	firstSunFlower = new SunFlower('$', 100,9,4);

	conOut(FIRST_ROW + 4, FIRST_COL-1) << "$";

}

void Game::Put_Sun_Flower_On_The_Table(int xPos, int yPos ,int &push)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	int count = 9;
	int x = -15;

	int y = -6;

	int contor = 5;

	if (nivel == 1)
		contor = 1;
	if (nivel == 2)
		contor = 3;
	if (nivel == 3)
		contor = 5;

	while (contor > 0)
	{
		y = y + 6;

		count = 9;

		x = -15;

		while (count > 0)
		{
			x = x + 15;

			for (int j = 9 + y; j <= 11 + y; j++)
			{

				for (int i = 14 + x; i <= 20 + x; i++)
				{
					if (push==1 && xPos == j && yPos == i)
					{
						if (sun->GetNumberSun() >= 100)
						{
							int check_exist = 0;

							list<iPlant*>::iterator it;

							list<iPlant*> listPlant = piece_table->GetListPlant();

							for (it = listPlant.begin(); it != listPlant.end(); ++it)
							{
								if ((*it)->GetxPos() == 9+y+1 && (*it)->GetyPos() == 14+x+3)
								{
									check_exist = 1;
								}
							}

							if (check_exist == 0)

							{
								iPlant* plant = new SunFlower('$', 100, 9 + y + 1, 14 + x + 3);
								piece_table->Push_Back(plant);
								//listPlant.push_back(plant);
								conOut(9 + y + 1, 14 + x + 3) << "$";
								sun->ReduceNumberSun(100);
								sun->SetSun();
								if (sun->GetSunWait()>2000)
								sun->ReduceTimeToWait();
								push = 0;
							}
						}
					}
				}
			}
			count--;
		}
		contor--;
	}
}

void Game::Put_Sun_PeaShooter_On_The_Table(int xPos, int yPos, int& push)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	int count = 9;
	int x = -15;

	int y = -6;

	int contor = 5;

	if (nivel == 1)
		contor = 1;
	if (nivel == 2)
		contor = 3;
	if (nivel == 3)
		contor = 5;

	while (contor > 0)
	{
		y = y + 6;

		count = 9;

		x = -15;

		while (count > 0)
		{
			x = x + 15;

			for (int j = 9 + y; j <= 11 + y; j++)
			{

				for (int i = 14 + x; i <= 20 + x; i++)
				{
					if (push == 1 && xPos == j && yPos == i)
					{
						if (sun->GetNumberSun() >= 100)
						{
							int check_exist = 0;

							list<iPlant*>::iterator it;

							list<iPlant*> listPlant = piece_table->GetListPlant();

							for (it = listPlant.begin(); it != listPlant.end(); ++it)
							{
								if ((*it)->GetxPos() == 9 + y + 1 && (*it)->GetyPos() == 14 + x + 3)
								{
									check_exist = 1;
								}
							}

							if (check_exist == 0)

							{
								Projectile* project = new Projectile('-',9+y+1,14+x+4,25);
								iPlant* plant = new Peashooter('P', 100, 9 + y + 1, 14 + x + 3,project);
								piece_table->Push_Back(plant);
								//listPlant.push_back(plant);
								conOut(9 + y + 1, 14 + x + 3) << "P";
								sun->ReduceNumberSun(100);
								sun->SetSun();
								push = 0;
							}
						}
					}
				}
			}
			count--;
		}
		contor--;
	}
}


void Game::Create_First_PeaShooter()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	firstPeaShooter = new Peashooter('P', 100, 16, 4);

	conOut(FIRST_ROW + 11, FIRST_COL - 1) << "P";
}

void Game::Listen()
{
	std::thread first(GenerateSun_, std::ref(sun));

	std::thread second(TryToShoot, std::ref(nivel), std::ref(piece_table));

	std::thread third(CreateZombie,std::ref(nivel), std::ref(piece_table));

	//std::thread fourth(MoveZombie, std::ref(nivel), std::ref(piece_table));

	//std::thread fifth(Update_Map, std::ref(piece_table));

	int nSun = 0;

int push = 0;

int Push = 0;

while (true && finish_game==false)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	std::string action = conIn.getUserActions();
	if (action != "")
	{

	//	conOut(41, 2) << action;

		char* sentence = new char[512];

		strcpy(sentence, action.c_str());

		char* token = strtok(sentence, " ");

		int x = 1;

		int ok = 0;

		while (token)
		{
			if (x == 4 && strcmp(token, "double") == 0)
			{
				ok = 1;
			}
			x++;
			token = strtok(NULL, " ");
		}

		if (ok == 1)
		{
			int xPos;
			int yPos;

			char posX[10];
			char posY[10];

			int OK = 0;

			int i = 0;

			while (OK == 0)
			{
				if (action[i] == '(')
				{
					int j = i + 1;

					int k = 0;

					while (action[j] != ',')
					{
						posX[k] = action[j];
						j++;
						k++;
					}
					posX[k] = '\0';
					yPos = atoi(posX);
					k = 0;

					while (action[j] != ')')
					{
						int ok = 0;

						if (action[j] != ' ' && action[j] != ',')
						{
							posY[k] = action[j];
							k++;
							j++;
							ok = 1;
						}
						posY[k] = '\0';
						if (ok == 0)
							j++;
					}
					xPos = atoi(posY);
					OK = 1;
				}
				i++;
			}
			sun->CheckForSun(xPos, yPos);
			if (push==0)
			push=firstSunFlower->CheckForSunFlower(xPos, yPos);

			if (Push == 0)
				Push = firstPeaShooter->CheckForPeaShooter(xPos, yPos);

			if (push == 1)
			{
				this->Put_Sun_Flower_On_The_Table(xPos, yPos, push);
			}

			if (Push==1)
			{
				this->Put_Sun_PeaShooter_On_The_Table(xPos, yPos, Push);
			}
		}

	}
   }

   first.detach();
   second.detach();
   third.detach();
  // fourth.detach();
  // fifth.detach();
}

void Game::ShowNivel()
{

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();


	conOut(0, 35) << "Nivel=";

	char level[10];

	_itoa(nivel, level, 10);



	conOut(0,41) <<level;

}

void Game::NextLevel()
{

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();


	conOut(0, 50) << "S-a terminat nivelul=";

	char level[10];

	_itoa(nivel-1, level, 10);

	conOut(0, 72) << level;


	conOut(0, 76) << "Urmeaza nivelul=";

	char level1[10];

	_itoa(nivel, level1, 10);


	conOut(0, 93) << level1;

	conOut(0, 96) <<"Urmatorul nivel in 15sec";

	Sleep(15000);

	for(int i=50;i<=140;i++)
		conOut(0, i) << " ";
}

void Game::Win()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(0, 50) << "Zombii au fost infranti.Felicitari!";

	finish_game = true;
}

void Game::ShowScore()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(0, 150) << "Score";

	for(int i=150;i<=152;i++)
		conOut(1,i) << "";

	char score[10];

	_itoa(Score, score, 10);

	conOut(1, 150) <<score;

}

void Game::AddScore(int score)
{
	Score = Score + score;
}

void Game::Create_User_Password()
{
	std::cout << "My Name=";

	std::string name;

	std::string password;

	std::cin >> name;

	std::cout << "My Password=";

	std::cin >> password;
   
	ply = new Player(name,password);

	FILE* file = fopen("user.txt", "rt");

	int same_user = 0;

	int same_password = 0;


	while (!feof(file))
	{
		char buffer[512];

		fgets(buffer, 512, file);

		char *token = strtok(buffer, " ");

		int position = 0;

		int Score = 0;

		same_user = 0;

		same_password = 0;

		while (token)
		{
			switch (position)
			{
			case 0:if (strcmp(token, name.c_str()) == 0)
				same_user = 1;
				break;
			case 1:if (strcmp(token, password.c_str()) == 0)
				same_password = 1;
				break;
			case 2:Score = atoi(token);
				break;
			default:
				break;
			}

			position++;
			token = strtok(NULL, " ");
		}

		if (same_user == 1 && same_password == 1 && another_player==1)
		{
			ply->SetScore(Score);
			another_player = 0;
		}
	}
	Score = ply->GetScore();
}

void Game::Put_Player_in_File()
{
	FILE* file = fopen("user.txt", "wt");

	ply->SetScore(Score);

	string Put_User = ply->Return_User();

	char buffer[512];

	strcpy(buffer, Put_User.c_str());

	fputs(buffer, file);
}
