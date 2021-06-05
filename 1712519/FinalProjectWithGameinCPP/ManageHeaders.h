#pragma once
#include"MetalHero.h"
#include"WoodHero.h"
#include"WaterHero.h"
#include"EarthHero.h"
#include"FireHero.h"
class DeclareHeros
{
private:
	MetalHero metalhero;
	WoodHero woodhero;
	WaterHero waterhero;
	EarthHero earthhero;
	FireHero firehero;
public:
	DeclareHeros() 
	{
		metalhero;
		woodhero;
		waterhero;
		earthhero;
		firehero;
	}
public:
	~DeclareHeros()
	{

	}
};