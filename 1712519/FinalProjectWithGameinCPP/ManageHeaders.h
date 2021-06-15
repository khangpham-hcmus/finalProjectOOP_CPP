#pragma once
#include"MetalHero.h"
#include"WoodHero.h"
#include"WaterHero.h"
#include"EarthHero.h"
#include"FireHero.h"
#include"Timing.h"
#include"Menu.h"
#include"User.h"
class DeclareHeros
{
private:
	MetalHero *metalhero;
	WoodHero *woodhero;
	WaterHero *waterhero;
	EarthHero *earthhero;
	FireHero *firehero;
public:
	DeclareHeros() 
	{
		metalhero = new MetalHero();
		woodhero = new WoodHero();
		waterhero = new WaterHero();
		earthhero = new EarthHero();
		firehero = new FireHero();
	}
public:
	~DeclareHeros()
	{
		if (metalhero != nullptr)
			delete metalhero;
		if (woodhero != nullptr)
			delete woodhero;
		if (waterhero != nullptr)
			delete waterhero;
		if (earthhero != nullptr)
			delete earthhero;
		if (firehero != nullptr)
			delete firehero;
	}
};