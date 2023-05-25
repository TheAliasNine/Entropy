#pragma once

class Component
{
public:
	virtual void OnUpdate() = 0;
	virtual void OnDraw() = 0;
};