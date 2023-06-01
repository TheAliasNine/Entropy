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
	

	void CheckCollision(Collider* collider) override;
	void CheckCollision(LineBased* lineBased) override;
	void CheckCollision(Plane* lineBased) override;
	void CheckCollision(AABB* aabb) override;

private:
	std::vector<Line> lines;
};