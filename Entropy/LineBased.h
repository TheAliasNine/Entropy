#pragma once

#include "Collider.h"
#include "Line.h"
#include "CollisionInfo.h"

#include "raylib.h"

#include <vector>

class SceneObject;
class LineBased : public Collider
{
public:
	LineBased(Layer layer, Color color, SceneObject* so);

	void OnDraw();
	
	Color color = Color();


	void AddLine(Line line);

	std::vector<Line> globalLines;

	void AddColliderToHandler() override;

	void CheckCollision(const Collider* collider) const override;
	void CheckCollision(const LineBased* lineBased) const override;

	void OnCollision(CollisionInfo info) override {}

private:
	std::vector<Line> lines;


	void UpdateGlobal();
};