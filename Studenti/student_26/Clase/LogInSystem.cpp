#include "LogInSystem.h"
LogInSystem* LogInSystem::Instance = nullptr;
namespace fs = std::experimental::filesystem;


void LogInSystem::verifyPath()
{
	this->PathSalvari = "C:\\PvZ_Users";
	if (!fs::exists(this->PathSalvari))
		fs::create_directory(this->PathSalvari);
}

void LogInSystem::readUsers()
{
	for (auto& folder : fs::directory_iterator(this->PathSalvari))
	{
		this->UsersList.push_back(folder.path().filename().string());
	}
}

bool LogInSystem::verifyUser()
{
	for (auto it : UsersList)
	{
		if ((it) == User.getName())
		{
			return 1;
		}
	}
	return 0;
}

void LogInSystem::createUserFolder()
{
	fs::path userpath = this->PathSalvari;
	userpath.append(User.getName());
	fs::create_directory(userpath);
}

void LogInSystem::createPasswordFile()
{
	std::ofstream File;
	fs::path PasswordPath = this->PathSalvari;
	PasswordPath.append(User.getName());
	PasswordPath.append("Parola.password");
	File.open(PasswordPath);
	if(File.is_open())
	{
		File << User.getPassword();
	}
	File.close();
}

bool LogInSystem::verifyPassword()
{
	std::ifstream File;
	std::string buffer;
	fs::path PasswordPath = this->PathSalvari;
	PasswordPath.append(User.getName());
	PasswordPath.append("Parola.password");
	File.open(PasswordPath);
	if (File.is_open())
	{
		if (std::getline(File, buffer))
		{
			if (buffer == this->User.getPassword())
			{
				File.close();
				return 1;
			}
			else
			{
				File.close();
				return 0;
			}
		}
	}
	return 0;
}

LogInSystem::LogInSystem(const Credentials& user):User(user)
{
	this->verifyPath();
	this->readUsers();
	if (!this->verifyUser())
	{
		//nu exista userul => se inscrie un nou cont
		this->createUserFolder();
		this->createPasswordFile();
		//setez Log ul pentru new player
		fs::path userpath = this->PathSalvari;
		userpath.append(User.getName());
		History.setPathFiles(userpath);
	}
	else
	{
		//exista user ul se verifica parola
		if (verifyPassword())
		{
			//daca parola e corecta setez Log ul pt acel folder in cautarea salvarilor
			fs::path userpath = this->PathSalvari;
			userpath.append(User.getName());
			History.setPathFiles(userpath);
			History.readLog(&this->Level, &this->Score); //citeste salvarea si afla la ce level si scor se afla player ul
		}
		else
		{
			//parola incorecta =>level = 0, un flag pentru game ca parola nu e buna
			this->Level = 0;
		}
	}
}

LogInSystem::LogInSystem(const LogInSystem&) :Level(0), Score(0)
{
}

LogInSystem::~LogInSystem()
{
}


LogInSystem& LogInSystem::GetInstance(const Credentials&User)
{
	if (Instance == nullptr)
		Instance = new LogInSystem(User);
	return *Instance;
}

void LogInSystem::destroyInstance()
{
	if (Instance == nullptr)
		return;
	delete Instance;
	Instance = nullptr;
}

Credentials LogInSystem::getUser() const
{
	return this->User;
}

int LogInSystem::getLevel() const
{
	return this->Level;
}

int LogInSystem::getScore() const
{
	return this->Score;
}

void LogInSystem::setUser(const Credentials& User)
{
	this->User = User;
}

void LogInSystem::setLevel(const int& Level)
{
	this->Level = Level;
}

void LogInSystem::setScore(const int& Score)
{
	this->Score = Score;
}

void LogInSystem::updateGame()
{
	this->History.addInLog(this->Level, this->Score);
}
