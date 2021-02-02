#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

class Consola
{
private:
	Consola() {};
	static Consola* INstanta;

public:
	static Consola* SetINstanta();
	static void colorMov(const string Cuvant);
	static void colorGalben(const string Cuvant);
	static void colorVerde(const string Cuvant);
	static void colorRosu(const string Cuvant);
	static void gotoYXMov(int x, int y, const string Cuv);
	static void gotoYXVerde(int x, int y, const string Cuv);
	static void gotoYXRosu(int x, int y, const string Cuv);
	static void gotoYXGalben(int x, int y, const string Cuv);
};
