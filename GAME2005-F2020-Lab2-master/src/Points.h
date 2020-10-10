#pragma once
#ifndef __POINTS__
#define __POINTS__

#include "Sprite.h"

class Points : public Sprite
{
public:
	Points();
	~Points();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
};

#endif

