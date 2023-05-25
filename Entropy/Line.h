#pragma once

#include "Vector2.h"

struct Line
{
public:

	Line(Math::Vector2 start, Math::Vector2 end)
	{
		this->start = start;
		this->end = end;
	}

	Math::Vector2 start;
	Math::Vector2 end;
};