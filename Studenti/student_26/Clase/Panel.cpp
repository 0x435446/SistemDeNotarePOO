#include "Panel.h"
#include<iostream>

Panel::Panel(int nWidth, int nHeight, int nOffsetX, int nOffsetY)
{
	this->nPanelWidth = nWidth;
	this->nPanelHeight = nHeight;
	this->nOffsetX = nOffsetX;
	this->nOffsetY = nOffsetY;
}

Panel::Panel(const Panel& other)
{
	this->sPanel = other.sPanel;
	this->nPanelWidth = other.nPanelWidth;
	this->nPanelHeight = other.nPanelHeight;
	this->nOffsetX = other.nOffsetX;
	this->nOffsetY = other.nOffsetY;
}					 

void Panel::resetPanel()
{
	for (int i = 0; i < sPanel.size(); i++)
	{
		if (sPanel[i] != '#')
		{
			sPanel[i] = '.';
		}
	}
}

std::wstring& Panel::operator+=(const std::wstring& s)
{
	// TODO: insert return statement here
	if ((sPanel.length() + s.length()) <= this->nPanelHeight * this->nPanelWidth)
		this->sPanel += s;
	return sPanel;
}

std::wstring& Panel::operator+=(const char* s)
{
	// TODO: insert return statement here
	if ((sPanel.length() + strlen(s)) <= this->nPanelHeight * this->nPanelWidth)
	{
		for (int i = 0; i < strlen(s); i++)
			this->sPanel += s[i];
	}
	return this->sPanel;
}

Panel& Panel::operator=(const Panel& other) noexcept
{
	if (this == &other)
		return *this;
	this->sPanel = other.sPanel;
	this->nPanelWidth = other.nPanelWidth;
	this->nPanelHeight = other.nPanelHeight;
	this->nOffsetX = other.nOffsetX;
	this->nOffsetY = other.nOffsetY;	
	return *this;
}

void Panel::setChar(int x, int y, const wchar_t& c)
{
	if (x >= 0 && x < this->nPanelWidth && y >= 0 && y < this->nPanelHeight)
	{
		this->sPanel[y * nPanelWidth + x] = c;
	}
}

wchar_t Panel::getChar(int x, int y)
{
	if (x >= 0 && x < this->nPanelWidth && y >= 0 && y < this->nPanelHeight)
	{
		return this->sPanel[y * nPanelWidth + x];
	}
	else
	{
		return L' ';
	}
}

