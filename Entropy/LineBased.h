#pragma once

#include "Collider.h"
#include "Line.h"

#include "raylib.h"

#include <vector>

class SceneObject;
class LineBased : public Collider
{
public:
	LineBased() {};
	LineBased(Layer layer, Color color, SceneObject* obj);

	void OnDraw();
	void OnUpdate();
	
	Color color = Color();


	void AddLine(Line line);

	std::vector<Line> globalLines;

private:
	std::vector<Line> lines;


	void UpdateGlobal();
};