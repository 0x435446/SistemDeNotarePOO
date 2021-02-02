#pragma once
enum class ActionType {
	ADD, SUBSTRACT
};
class UserData
{
	static int _instanceCount;
	static UserData* _instance;

	static int inGameCurrency;
	static int currency;
public:
	static UserData& getInstance();
	static void releaseInstance();

	void Init();
	UserData(const UserData&) = delete;
	UserData(UserData&&) = delete;
	UserData& operator=(const UserData&) = delete;
	UserData& operator=(UserData&&) = delete;

	int getCurrency()
	{
		return currency;
	}
	int getInGameCurrency()
	{
		return inGameCurrency;
	}
	void setCurrency(int sum, ActionType type)
	{
		if (type == ActionType::ADD)
		{
			currency += sum;
		}
		else
		{
			currency -= sum;
		}
	}
	int& _getCurrency()
	{
		return currency;
	}
	int& _getInGameCurrency()
	{
		return inGameCurrency;
	}

	void setInGameCurrency(int sum, ActionType type)
	{
		if (type == ActionType::ADD)
		{
			inGameCurrency += sum;
		}
		else
		{
			inGameCurrency -= sum;
		}
		if (inGameCurrency > 900)
			inGameCurrency = 900;
	}

	static int& _getCurrencyAccess()
	{
		return currency;
	}
	static int& _getInGameCurrencyAccess()
	{
		return inGameCurrency;
	}

private:
	UserData();
	~UserData();
};

