#pragma once
#include <string>

class Panel
{
private:
	std::wstring sPanel;
	int nPanelWidth;
	int nPanelHeight;
	int nOffsetX;
	int nOffsetY;
public:
	Panel(int nWidth, int nHeight, int nOffsetX = 0, int nOffsetY = 0);
	Panel(const Panel&);
	//Get
	wchar_t getChar(int x, int y);
	int& getPanelWidth() { return this->nPanelWidth; }
	int& getPanelHeight() { return this->nPanelHeight; }
	int& getOffsetX() { return this->nOffsetX; }
	int& getOffsetY() { return this->nOffsetY; }
	//Set
	void setChar(int x, int y, const wchar_t&);
	void setOffsetX(int nOffsetX) { this->nOffsetX = nOffsetX; }
	void setOffsetY(int nOffsetY) { this->nOffsetY = nOffsetY; }
	//Reset Panel
	void resetPanel();
	//Operators Overloaded
	std::wstring& operator+=(const std::wstring&);
	std::wstring& operator+=(const char*);
	Panel& operator=(const Panel&) noexcept;
	
	//de facut o lambda pt centru doar pt BattleField
};

