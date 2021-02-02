#include "CGame.h"
using namespace std::chrono;

CGame *CGame::instance = nullptr;

CGame::CGame()
{
	for (int i = 0; i <= 41; i++)
	{
		for (int j = 0; j <= 154; j++)
		{
			mat[i][j] = nullptr;
		}
	}
	for (int i = 18; i <= 154; i += 16)
	{
		listOfPositionsResurse.push_back(i);
	}
}

void CGame::updateLvl(int lvl, int code, std::ofstream& filename)
{
	system("cls");
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	if (lvl < 0)
	{
		throw new CException(LVL_ERR, "Weird level!");
	}
	if ((lvl == 0)&&(code==1))
	{
		clearMatrix();
		conOut(23, 80) << "Game over! Zombies win!";
		filename << "The zombies won!" << std::endl;
		std::chrono::milliseconds timespan(2000); 
		std::this_thread::sleep_for(timespan);
		exit(0);
	}
	else if ((lvl >= 1)&&(code==1))
	{
		conOut(23, 80) << "Back to level " << lvl << "!";
		filename << "Level "<<lvl<<" lost." << std::endl;
		CBoard& Board = CBoard::GetInstance(lvl);
		addBoardToMatrix(lvl);
	}
	else if ((lvl >= 1) && (code == 2))
	{
		static auto begin = steady_clock::now();
		lvl++;
		clearMatrix();
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > 4000)
		{
			begin = end;
			conOut(23, 70) << "LEVEL UP! WELCOME TO LEVEL " << lvl << "!";
		}
		system("cls");
		filename << "Level up. Now level " << lvl << "." << std::endl;
		Score = 0;
		CBoard::DestroyInstance();
		CBoard& Board = CBoard::GetInstance(lvl);
		addBoardToMatrix(lvl);
	}
}

CGame& CGame::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CGame();
	}
	return *instance;
}

void CGame::clearScore()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 2; i <= 8; i++)
	{
		conOut(3, i) << ' ';
	}
}

void CGame::changeScore(int key,int value)
{
	switch (key)
	{
	case 1:
		Score += value;
		break;
	case 2:
		Score -= value;
		clearScore();
		getScore();
		break;
	default: 
		std::cout << 0;
		break;  //error handling
	}
}

int CGame::nrofdigits(int nr)
{
	int k = 0;
	if (nr == 0) return 1;
	while (nr)
	{
		nr = nr / 10;
		k++;
	}
	return k;
}

void CGame::arrangeScore(int nr)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	int aux = Score;
	switch (nr)
	{
	case 1:
		conOut(3, 5) << aux;
		break;
	case 2:
		conOut(3, 6) << aux % 10;
		aux = aux / 10;
		conOut(3, 5) << aux;
		break;
	case 3:
		conOut(3, 6) << aux % 10;
		aux = aux / 10;
		conOut(3, 5) << aux % 10;
		aux = aux / 10;
		conOut(3, 4) << aux % 10;
		break;
	case 4:
		conOut(3, 7) << aux % 10;
		aux = aux / 10;
		conOut(3, 6) << aux % 10;
		aux = aux / 10;
		conOut(3, 5) << aux % 10;
		aux = aux / 10;
		conOut(3, 4) << aux % 10;
		break;
	default: 
		std::cout << 0; 
		break;         //error handling
	}
}

void CGame::getScore()
{
	int nr = nrofdigits(Score);
	arrangeScore(nr);
}

int CGame::getRandPosResurse()
{
	int ok = 1;
	int index = rand() % listOfPositionsResurse.size();
	int value = listOfPositionsResurse[index];
	return value;
}

bool CGame::checkmatResurse()
{
	for (int i = 18; i <= 154; i += 16)
	{
		if (mat[3][i] == 0)
		{
			return true;
		}
	}
	return false;
}

bool CGame::checkPosPlant(const int& lvl,const int& row,const int& col)
{
	if (lvl == 1)
	{
		if (row == 23)
		{
			for (int i = 18; i <= 154; i += 16)
			{
				if (col == i)
				{
					return true;
				}
			}
		}
	}
	if (lvl == 2)
	{
		if (row == 16 || row == 23 || row == 30)
		{
			for (int i = 18; i <= 154; i += 16)
			{
				if (col == i)
				{
					return true;
				}
			}
		}
	}
	if (lvl >= 3)
	{
		for (int j = 9; j <= 37; j += 7)
		{
			if (row == j)
			{
				for (int i = 18; i <= 154; i += 16)
				{
					if (col == i)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void CGame::drawProiectil(CEntity* peashooter,CEntity* pea,const int& lvl, std::ofstream& filename)
{
	static auto begin5 = std::chrono::steady_clock::now();

	auto end5 = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(end5 - begin5).count() > pea->getMovingSpeed())
	{
		begin5 = end5;
		if (lvl == 1)
		{
			for (int i = 18; i <= 154; i += 16)
			{
				if (mat[23][i] != nullptr)
				{
					if (mat[23][i]->getAscii() == peashooter->getAscii())
					{
						CEntity *pea = new CPea(2000, 5, 4000, 249);
						filename << "A new pea has been created." << std::endl;
						if (mat[23][i + 2] == nullptr)
						{
							pea->drawEntity(23, i + 2);
							filename << "The pea appeared on the screen." << std::endl;
							mat[23][i + 2] = pea;
						}
					}
				}
			}
		}
		else if (lvl == 2)
		{
			for (int j = 16; j <= 30; j += 7)
			{
				for (int i = 18; i <= 154; i += 16)
				{
					if (mat[j][i] != nullptr)
					{
						if (mat[j][i]->getAscii() == peashooter->getAscii())
						{
							CEntity *pea = new CPea(2000, 5, 4000, 249);
							filename << "A new pea has been created." << std::endl;
							if (mat[j][i + 2] == nullptr)
							{
								pea->drawEntity(j, i + 2);
								filename << "The pea appeared on the screen." << std::endl;
								mat[j][i + 2] = pea;
							}
						}
					}
				}
			}
		}
		else if (lvl == 3)
		{
			for (int j = 9; j <= 37; j += 7)
			{
				for (int i = 18; i <= 154; i += 16)
				{
					if (mat[j][i] != nullptr)
					{
						if (mat[j][i]->getAscii() == peashooter->getAscii())
						{
							CEntity *pea = new CPea(2000, 5, 4000, 249);
							filename << "A new pea has been created." << std::endl;
							if (mat[j][i + 2] == nullptr)
							{
								pea->drawEntity(j, i + 2);
								filename << "The pea appeared on the screen." << std::endl;
								mat[j][i + 2] = pea;
							}
						}
					}
				}
			}
		}
	}
}

void CGame::moveProiectil(CEntity* sunflower, CEntity* peashooter,CEntity* ordzomb, CEntity* buckethead, CEntity* pea,const int&lvl,std::ofstream& filename)
{
	CEntity* boardline1 = new CBoardEntity(0, 221);
	CEntity* boardline2 = new CBoardEntity(0, 222);
	static auto begin5 = std::chrono::steady_clock::now();

	auto end5 = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(end5 - begin5).count() > pea->getMovingSpeed())
	{
		begin5 = end5;
		UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
		if (lvl == 1)
		{
			for (int j = 19; j <= 154; j ++)
			{
				if (mat[23][j] != nullptr)
				{
					if (mat[23][j]->getAscii() == pea->getAscii())
					{
						if (mat[23][j + 1] == nullptr)
						{
							mat[23][j + 1] = mat[23][j];
							mat[23][j] = nullptr;
							conOut(23, j) << ' ';
							conOut(23, j + 1) << static_cast<char>(mat[23][j + 1]->getAscii());
							j++;
						}
						else if ((mat[23][j + 1]->getAscii() == boardline1->getAscii())||(mat[23][j + 1]->getAscii() == boardline2->getAscii()))
						{
							if (mat[23][j + 2] != nullptr)
							{
								if ((mat[23][j + 2]->getAscii() == ordzomb->getAscii()) || (mat[23][j + 2]->getAscii() == buckethead->getAscii()))
								{
									mat[23][j + 2]->reduceHealth(mat[23][j]->getValue());
									mat[23][j] = nullptr;
									conOut(23, j) << ' ';
									if (mat[23][j + 2]->getValue() == 0)
									{
										mat[23][j + 2] = nullptr;
										conOut(23, j + 2) << ' ';
									}
								}
								else if ((mat[23][j + 2]->getAscii() == peashooter->getAscii()) || (mat[23][j + 2]->getAscii() == sunflower->getAscii()))
								{
									if (mat[23][j + 4] != nullptr)
									{
										if ((mat[23][j + 4]->getAscii() == ordzomb->getAscii()) || (mat[23][j + 4]->getAscii() == buckethead->getAscii()))
										{
											mat[23][j + 4]->reduceHealth(mat[23][j]->getValue());
											mat[23][j] = nullptr;
											conOut(23, j) << ' ';
											if (mat[23][j + 4]->getValue() == 0)
											{
												mat[23][j + 4] = nullptr;
												conOut(23, j + 4) << ' ';
											}
										}
										else if (mat[23][j + 4]->getAscii() == pea->getAscii())
										{
											mat[23][j + 4]->reduceHealth(mat[23][j]->getValue());
											mat[23][j] = nullptr;
											conOut(23, j) << ' ';
										}
										else
										{
											mat[23][j + 4] = mat[23][j];
											mat[23][j] = nullptr;
											conOut(23, j) << ' ';
											conOut(23, j + 4) << static_cast<char>(mat[23][j + 4]->getAscii());
											j += 4;
										}
									}
								}
							}
							else
							{
								mat[23][j + 2] = mat[23][j];
								mat[23][j] = nullptr;
								conOut(23, j) << ' ';
								conOut(23, j + 2) << static_cast<char>(mat[23][j + 2]->getAscii());
								j += 2;
							}
						}
						else if ((mat[23][j + 1]->getAscii() == ordzomb->getAscii()) || (mat[23][j + 1]->getAscii() == buckethead->getAscii()))
						{
							mat[23][j + 1]->reduceHealth(mat[23][j]->getValue());
							if (mat[23][j + 1]->getValue() == 0)
							{
								mat[23][j + 1] = nullptr;
								conOut(23, j + 1) << ' ';
							}
							mat[23][j] = nullptr;
							conOut(23, j) << ' ';
						}
					}
				}
			}
			filename << "The peas have moved one position." << std::endl;
		}
		else if (lvl == 2)
		{
			for (int i = 16; i <= 30; i += 7)
			{
				for (int j = 19; j <= 154; j++)
				{
					if (mat[i][j] != nullptr)
					{
						if (mat[i][j]->getAscii() == pea->getAscii())
						{
							if (mat[i][j + 1] == nullptr)
							{
								mat[i][j + 1] = mat[i][j];
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
								conOut(i, j + 1) << static_cast<char>(mat[i][j + 1]->getAscii());
								j++;
							}
							else if ((mat[i][j + 1]->getAscii() == boardline1->getAscii()) || (mat[i][j + 1]->getAscii() == boardline2->getAscii()))
							{
								if (mat[i][j + 2] != nullptr)
								{
									if ((mat[i][j + 2]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 2]->getAscii() == buckethead->getAscii()))
									{
										mat[i][j + 2]->reduceHealth(mat[i][j]->getValue());
										mat[i][j] = nullptr;
										conOut(i, j) << ' ';
										if (mat[i][j + 2]->getValue() == 0)
										{
											mat[i][j + 2] = nullptr;
											conOut(i, j + 2) << ' ';
										}
									}
									else if ((mat[i][j + 2]->getAscii() == peashooter->getAscii()) || (mat[i][j + 2]->getAscii() == sunflower->getAscii()))
									{
										if (mat[i][j + 4] != nullptr)
										{
											if ((mat[i][j + 4]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 4]->getAscii() == buckethead->getAscii()))
											{
												mat[i][j + 4]->reduceHealth(mat[i][j]->getValue());
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
												if (mat[i][j + 4]->getValue() == 0)
												{
													mat[i][j + 4] = nullptr;
													conOut(i, j + 4) << ' ';
												}
											}
											else if (mat[i][j + 4]->getAscii() == pea->getAscii())
											{
												mat[i][j + 4]->reduceHealth(mat[i][j]->getValue());
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
											}
											else
											{
												mat[i][j + 4] = mat[i][j];
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
												conOut(i, j + 4) << static_cast<char>(mat[i][j + 4]->getAscii());
												j += 4;
											}
										}
									}
								}
								else
								{
									mat[i][j + 2] = mat[i][j];
									mat[i][j] = nullptr;
									conOut(i, j) << ' ';
									conOut(i, j + 2) << static_cast<char>(mat[i][j + 2]->getAscii());
									j += 2;
								}
							}
							else if ((mat[i][j + 1]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 1]->getAscii() == buckethead->getAscii()))
							{
								mat[i][j + 1]->reduceHealth(mat[i][j]->getValue());
								if (mat[i][j + 1]->getValue() == 0)
								{
									mat[i][j + 1] = nullptr;
									conOut(i, j + 1) << ' ';
								}
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
							}
						}
					}
				}
			}
			filename << "The peas have moved one position." << std::endl;
		}
		else if (lvl == 3)
		{
			for (int i = 9; i <= 37; i += 7)
			{
				for (int j = 19; j <= 154; j++)
				{
					if (mat[i][j] != nullptr)
					{
						if (mat[i][j]->getAscii() == pea->getAscii())
						{
							if (mat[i][j + 1] == nullptr)
							{
								mat[i][j + 1] = mat[i][j];
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
								conOut(i, j + 1) << static_cast<char>(mat[i][j + 1]->getAscii());
								j++;
							}
							else if ((mat[i][j + 1]->getAscii() == boardline1->getAscii()) || (mat[i][j + 1]->getAscii() == boardline2->getAscii()))
							{
								if (mat[i][j + 2] != nullptr)
								{
									if ((mat[i][j + 2]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 2]->getAscii() == buckethead->getAscii()))
									{
										mat[i][j + 2]->reduceHealth(mat[i][j]->getValue());
										mat[i][j] = nullptr;
										conOut(i, j) << ' ';
										if (mat[i][j + 2]->getValue() == 0)
										{
											mat[i][j + 2] = nullptr;
											conOut(i, j + 2) << ' ';
										}
									}
									else if ((mat[i][j + 2]->getAscii() == peashooter->getAscii()) || (mat[i][j + 2]->getAscii() == sunflower->getAscii()))
									{
										if (mat[i][j + 4] != nullptr)
										{
											if ((mat[i][j + 4]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 4]->getAscii() == buckethead->getAscii()))
											{
												mat[i][j + 4]->reduceHealth(mat[i][j]->getValue());
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
												if (mat[i][j + 4]->getValue() == 0)
												{
													mat[i][j + 4] = nullptr;
													conOut(i, j + 4) << ' ';
												}
											}
											else if (mat[i][j + 4]->getAscii() == pea->getAscii())
											{
												mat[i][j + 4]->reduceHealth(mat[i][j]->getValue());
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
											}
											else
											{
												mat[i][j + 4] = mat[i][j];
												mat[i][j] = nullptr;
												conOut(i, j) << ' ';
												conOut(i, j + 4) << static_cast<char>(mat[i][j + 4]->getAscii());
												j += 4;
											}
										}
									}
								}
								else
								{
									mat[i][j + 2] = mat[i][j];
									mat[i][j] = nullptr;
									conOut(i, j) << ' ';
									conOut(i, j + 2) << static_cast<char>(mat[i][j + 2]->getAscii());
									j += 2;
								}
							}
							else if ((mat[i][j + 1]->getAscii() == ordzomb->getAscii()) || (mat[i][j + 1]->getAscii() == buckethead->getAscii()))
							{
								mat[i][j + 1]->reduceHealth(mat[i][j]->getValue());
								if (mat[i][j + 1]->getValue() == 0)
								{
									mat[i][j + 1] = nullptr;
									conOut(i, j + 1) << ' ';
								}
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
							}
						}
					}
				}
			}
			filename << "The peas have moved one position." << std::endl;
		}
	}
}

int CGame::getRowZombie(const int& lvl)
{
	srand(time(NULL));
	if (lvl == 1)
	{
		return 23;
	}
	else if (lvl == 2)
	{
		std::vector<int>s = { 16,23,30 };
		int index = rand() % s.size();
		return s[index];
	}
	else if (lvl == 3)
	{
		std::vector<int>s = { 9,16,23,30,37 };
		int index = rand() % s.size();
		return s[index];
	}
}

int CGame::moveZombie(CEntity* sunflower, CEntity* peashooter, CEntity* pea, CEntity* ordzombie, int lvl, std::ofstream& filename)
{
	CEntity* boardline1 = new CBoardEntity(0, 221);
	CEntity* boardline2 = new CBoardEntity(0, 222);
	static auto begin5 = std::chrono::steady_clock::now();
	int ok = 5;
	auto end5 = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::milliseconds>(end5 - begin5).count() > ordzombie->getMovingSpeed())
	{
		begin5 = end5;
		ok = 0;
		UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
		if (lvl == 1)
		{
			for (int j = 154; j >= 11; j--)
			{
				if (mat[23][j] != nullptr)
				{
					if (mat[23][j]->getAscii() == ordzombie->getAscii())
					{
						ok = 1;
						if (mat[23][j - 1] == nullptr)
						{
							mat[23][j - 1] = mat[23][j];
							mat[23][j] = nullptr;
							conOut(23, j) << ' ';
							conOut(23, j - 1) << static_cast<char>(mat[23][j - 1]->getAscii());
							j--;
						}
						else if ((mat[23][j - 1]->getAscii() == boardline1->getAscii()) || (mat[23][j - 1]->getAscii() == boardline2->getAscii()))
						{
							if (mat[23][j - 2] == nullptr)
							{
								mat[23][j - 2] = mat[23][j];
								mat[23][j] = nullptr;
								conOut(23, j) << ' ';
								conOut(23, j - 2) << static_cast<char>(mat[23][j - 2]->getAscii());
								j -= 2;
							}
							else if (mat[23][j - 2]->getAscii() == peashooter->getAscii())
							{
								peashooter->reduceHealth(1);
								if (peashooter->getMaxBites() == 0)
								{
									mat[23][j - 2] = nullptr;
									conOut(23, j - 2) << ' ';
								}
							}
							else if (mat[23][j - 2]->getAscii() == sunflower->getAscii())
							{
								sunflower->reduceHealth(1);
								if (sunflower->getMaxBites() == 0)
								{
									mat[23][j - 2] = nullptr;
									conOut(23, j - 2) << ' ';
								}
							}
						}
					}
				}
			}
			if (ok == 1) filename << "The zombies have moved one position." << std::endl;
		}
		else if (lvl == 2)
		{
			for (int i = 16; i <= 30; i += 7)
			{
				for (int j = 154; j >= 11; j--)
				{
					if (mat[i][j] != nullptr)
					{
						if (mat[i][j]->getAscii() == ordzombie->getAscii())
						{
							ok = 1;
							if (mat[i][j - 1] == nullptr)
							{
								mat[i][j - 1] = mat[i][j];
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
								conOut(i, j - 1) << static_cast<char>(mat[i][j - 1]->getAscii());
								j--;
							}
							else if ((mat[i][j - 1]->getAscii() == boardline1->getAscii()) || (mat[i][j - 1]->getAscii() == boardline2->getAscii()))
							{
								if (mat[i][j - 2] == nullptr)
								{
									mat[i][j - 2] = mat[23][j];
									mat[i][j] = nullptr;
									conOut(i, j) << ' ';
									conOut(i, j - 2) << static_cast<char>(mat[i][j - 2]->getAscii());
									j -= 2;
								}
								else if (mat[i][j - 2]->getAscii() == peashooter->getAscii())
								{
									peashooter->reduceHealth(1);
									if (peashooter->getMaxBites() == 0)
									{
										mat[i][j - 2] = nullptr;
										conOut(i, j - 2) << ' ';
									}
								}
								else if (mat[i][j - 2]->getAscii() == sunflower->getAscii())
								{
									sunflower->reduceHealth(1);
									if (sunflower->getMaxBites() == 0)
									{
										mat[i][j - 2] = nullptr;
										conOut(i, j - 2) << ' ';
									}
								}
							}
						}
					}
				}
			}
			if (ok == 1) filename << "The zombies have moved one position." << std::endl;
		}
		else if (lvl == 3)
		{
			for (int i = 9; i <= 37; i += 7)
			{
				for (int j = 154; j >= 11; j--)
				{
					if (mat[i][j] != nullptr)
					{
						if (mat[i][j]->getAscii() == ordzombie->getAscii())
						{
							ok = 1;
							if (mat[i][j - 1] == nullptr)
							{
								mat[i][j - 1] = mat[i][j];
								mat[i][j] = nullptr;
								conOut(i, j) << ' ';
								conOut(i, j - 1) << static_cast<char>(mat[i][j - 1]->getAscii());
								j--;
							}
							else if ((mat[i][j - 1]->getAscii() == boardline1->getAscii()) || (mat[i][j - 1]->getAscii() == boardline2->getAscii()))
							{
								if (mat[i][j - 2] == nullptr)
								{
									mat[i][j - 2] = mat[23][j];
									mat[i][j] = nullptr;
									conOut(i, j) << ' ';
									conOut(i, j - 2) << static_cast<char>(mat[i][j - 2]->getAscii());
									j -= 2;
								}
								else if (mat[i][j - 2]->getAscii() == peashooter->getAscii())
								{
									peashooter->reduceHealth(1);
									if (peashooter->getMaxBites() == 0)
									{
										mat[i][j - 2] = nullptr;
										conOut(i, j - 2) << ' ';
									}
								}
								else if (mat[i][j - 2]->getAscii() == sunflower->getAscii())
								{
									sunflower->reduceHealth(1);
									if (sunflower->getMaxBites() == 0)
									{
										mat[i][j - 2] = nullptr;
										conOut(i, j - 2) << ' ';
									}
								}
							}
						}
					}
				}
			}
			if (ok == 1) filename << "The zombies have moved one position." << std::endl;
		}
	}
	return ok;
}

void CGame::addBoardToMatrix(const int& lvl)
{
	CEntity* line1 = new CBoardEntity(0, 221);
	CEntity* line2 = new CBoardEntity(0, 222);
	if (lvl == 1)
	{
		for (int i = 17; i <= 154; i += 16)
		{
			mat[23][i] = line1;
		}
		for (int i = 19; i <= 154; i += 16)
		{
			mat[23][i] = line2;
		}
	}
	else if (lvl == 2)
	{
		for (int i = 17; i <= 154; i += 16)
		{
			mat[16][i] = line1;
			mat[23][i] = line1;
			mat[30][i] = line1;
		}
		for (int i = 19; i <= 154; i += 16)
		{
			mat[16][i] = line2;
			mat[23][i] = line2;
			mat[30][i] = line2;
		}
	}
	else if (lvl == 3)
	{
		for (int j = 9; j <= 37; j += 7)
		{
			for (int i = 17; i <= 154; i += 16)
			{
				mat[j][i] = line1;
			}
		}
		for (int j = 9; j <= 37; j += 7)
		{
			for (int i = 19; i <= 154; i += 16)
			{
				mat[j][i] = line2;
			}
		}
	}
}

bool CGame::check_ordinary_zombies(int lvl, int nr)
{
	if (lvl == 1)
	{
		if (nr < 8) return true;
	}
	else if (lvl == 2)
	{
			if (nr < 15) return true;
	}
	else if (lvl == 3)
	{
		if (nr < 30) return true;
	}
	return false;

}

bool CGame::check_buckethead_zombies(int lvl, int nr)
{
	if (lvl == 1)
	{
		if (nr < 2) return true;
	}
	else if (lvl == 2)
	{
		if (nr < 6) return true;
	}
	else if (lvl == 3)
	{
		if (nr < 15) return true;
	}
	return false;
}

void CGame::clearMatrix()
{
	CEntity* pea = new CPea(2000, 5, 4000, 249);
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i <= 41; i++)
	{
		for (int j = 0; j <= 154; j++)
		{
			if (mat[i][j]->getAscii() == pea->getAscii())
			{
				mat[i][j] = nullptr;
				conOut(i, j) << ' ';
			}
		}
	}
	delete pea;
}

void CGame::Start(int lvl)
{
	std::ofstream f("log.txt");
	f << "Welcome to the log file of the game!" << std::endl;
	getScore();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	CBoard& Board = CBoard::GetInstance(lvl);           //lvl parametru la fctia start
	f << "The board has been created." << std::endl;
	addBoardToMatrix(lvl);
	bool plantPeaShooter = false;
	bool plantSunflower = false;
	bool isplantedpeashooter = true;
	bool isplantedsunflower = true;
	CEntity*aux = nullptr;
	int ordzombnr = 0;
	int bucketheadnr = 0;

	CEntity* sun = new CResurse(25, 5000, 167);
	CEntity* peashooter = new CPeaShooter(20000, 147, 100, 5);
	CEntity *pea = new CPea(2000, 5, 4000, 249);
	CEntity* ordzombie = new COrdinaryZombie(1000, 25, 10000, 35);
	CEntity* buckethead = new CBucketheadZombie(1000, 45, 35000, 157);
	CEntity* sunflower = new CSunflower(10000, 64, 50, 5);
	int speed = sun->getSpeed();

	while (true)
	{
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
		}

		int val = getRandPosResurse();
		do
		{
			val = getRandPosResurse();
			if (checkmatResurse() == false)
			{
				break;
			}
		} while (mat[3][val] != nullptr);

		static auto begin = std::chrono::steady_clock::now();

		auto end = std::chrono::steady_clock::now();

		if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() > sun->getSpeed())       //apar sorii la pozitii random neocupate din speed in speed milisec
		{
			begin = end;
			CEntity* sun = new CResurse(25, speed, 167);
			sun->drawEntity(3, val);
			mat[3][val] = sun;
			f << "A new sun has appeared on the screen." << std::endl;
		}

	

		std::string s = " double clicked";
		if (action.find(s) != std::string::npos)
		{
			DoubleClick clk(action);
			int row = clk.returnX();
			int col = clk.returnY();
			if ((plantPeaShooter == true) && (checkPosPlant(lvl, row, col) == true))
			{
				mat[row][col] = peashooter;
				conOut(row, col) << static_cast<char>(peashooter->getAscii());
				f << "A peashooter has been placed at a position and is ready to attack." << std::endl;
				plantPeaShooter = false;
				isplantedpeashooter = true;
			}
			else if ((plantSunflower == true) && (checkPosPlant(lvl, row, col) == true))
			{
				mat[row][col] = sunflower;
				conOut(row, col) << static_cast<char>(sunflower->getAscii());
				f << "A sunflower has been placed at a position and is ready to attack." << std::endl;
				plantSunflower = false;
				sun->reduceHealth(1);
				f << "The speed of sun appearance has increased.";
				speed = sun->getSpeed();
				isplantedsunflower = true;
			}
			else
			{
				if (mat[row][col] != nullptr)
					if (mat[row][col]->getAscii() == sun->getAscii())
					{
						changeScore(1, sun->getValue());
						f << "You took a sun and the score increased." << std::endl;
						mat[row][col] = nullptr;
						conOut(row, col) << ' ';
					}
					else if ((mat[row][col]->getAscii() == peashooter->getAscii()) && (Score >= peashooter->getValue()))
					{
						mat[row][col] = nullptr;
						conOut(row, col) << ' ';
						plantPeaShooter = true;
						changeScore(2, peashooter->getValue());
						f << "You have bought a peashooter." << std::endl;
					}
					else if ((mat[row][col]->getAscii() == sunflower->getAscii()) && (Score >= sunflower->getValue()))
					{
						mat[row][col] = nullptr;
						conOut(row, col) << ' ';
						plantSunflower = true;
						changeScore(2, sunflower->getValue());
						f << "You have bought a sunflower." << std::endl;
					}
			}
		}


		if (isplantedpeashooter==true)
		{
			static auto begin2 = std::chrono::steady_clock::now();

			auto end2 = std::chrono::steady_clock::now();

			if (std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() > peashooter->getSpeed())
			{
				begin2 = end2;
				CEntity* peashooter = new CPeaShooter(20000, 147, 100, 5);
				f << "A new peashooter has been created." << std::endl;
				peashooter->drawEntity(23, 6);
				f << "The peashooter appeared on the screen." << std::endl;
				mat[23][6] = peashooter;
				isplantedpeashooter = false;
			}
		}

		if (isplantedsunflower==true)
		{
			static auto begin2 = std::chrono::steady_clock::now();

			auto end2 = std::chrono::steady_clock::now();

			if (std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() > sunflower->getSpeed())
			{
				begin2 = end2;
				CEntity* sunflower = new CSunflower(10000, 64, 50, 5);
				f << "A new sunflower has been created." << std::endl;
				sunflower->drawEntity(16, 6);
				f << "The sunflower appeared on the screen." << std::endl;
				mat[16][6] = sunflower;
				isplantedsunflower = false;
			}
		}


		static auto begin3 = std::chrono::steady_clock::now();

		auto end3 = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3).count() > pea->getSpeed())
		{
			begin3 = end3;
			drawProiectil(peashooter, pea, lvl, f);
		}


		static auto begin4 = std::chrono::steady_clock::now();

		auto end4 = std::chrono::steady_clock::now();
	
		if (check_ordinary_zombies(lvl, ordzombnr) == true)
		{
			if (std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4).count() > ordzombie->getSpeed())
			{
				begin4 = end4;
				int row = getRowZombie(lvl);
				int col = 154;
				CEntity* ordzombie = new COrdinaryZombie(1000, 25, 10000, 35);
				f << "A new ordinary zombie has been created." << std::endl;
				ordzombie->drawEntity(row, col);
				f << "The ordinary zombie appeared on the screen." << std::endl;
				mat[row][col] = ordzombie;
				ordzombnr++;
			}
		}
		if (check_buckethead_zombies(lvl, bucketheadnr) == true)
		{
			static auto begin6 = std::chrono::steady_clock::now();

			auto end6 = std::chrono::steady_clock::now();

			if (std::chrono::duration_cast<std::chrono::milliseconds>(end6 - begin6).count() > buckethead->getSpeed())
			{
				begin6 = end6;
				int row = getRowZombie(lvl);
				int col = 154;
				CEntity* buckethead = new CBucketheadZombie(1000, 45, 35000, 157);
				f << "A new buckethead zombie has been created." << std::endl;
				buckethead->drawEntity(row, col);
				f << "The buckethead zombie appeared on the screen." << std::endl;
				mat[row][col] = buckethead;
				bucketheadnr++;
			}
		}


		int nr1 = moveZombie(sunflower, peashooter, pea, ordzombie, lvl, f);

		int nr2 = moveZombie(sunflower, peashooter, pea, buckethead, lvl, f);
		if ((nr1 == 0)&&(ordzombnr!=0))              // && (nr2 == 0))
		{
			updateLvl(lvl, 2, f);
			ordzombnr = 0;
			bucketheadnr = 0;
		}
		else getScore();

		moveProiectil(sunflower, peashooter, ordzombie, buckethead, pea, lvl, f);

		if (mat[23][11] != nullptr)
		{
			lvl--;
			updateLvl(lvl, 1, f);
		}
	}
	f.close();
}

CGame::~CGame()
{
}