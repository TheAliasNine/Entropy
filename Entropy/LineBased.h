#pragma once

#include "Collider.h"
#include "Line.h"
#include "CollisionInfo.h"

#include "raylib.h"

#include <vector>

class SceneObject;
class Plane;
class LineBased : public Collider
{
public:
	LineBased(SceneObject* so, Layer layer, Color color);

	void OnDraw();
	void OnCollision(CollisionInfo info) override {}

	Color color;
	std::vector<Line> globalLines;

	void AddLine(Line line);
	void UpdateGlobal();
	

	bool CheckCollision(Collider* collider) override;
	bool CheckCollision(LineBased* lineBased) override;
	bool CheckCollision(Plane* lineBased) override;
	bool CheckCollision(AABB* aabb) override;

private:
	std::vector<Line> lines;
};