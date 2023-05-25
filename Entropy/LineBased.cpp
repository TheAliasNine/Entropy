#include "LineBased.h"
#include "SceneObject.h"
#include "SoTransform.h"

#include "Vector2.h"

#include "raylib.h"


LineBased::LineBased(Layer layer, Color color, SceneObject* so)
{
	obj = so;
	this->layer = layer;
	this->color = color;
}

void LineBased::OnDraw()
{
	for (int i = 0; i < lines.size(); i++)
	{
		Math::Vector2 localPos = obj->transform.GetLocalTranslation();
		float scale = obj->transform.GetLocalScale();
		DrawLine(lines[i].start.x + localPos.x, lines[i].start.y + localPos.y, lines[i].end.x + localPos.x, lines[i].end.y + localPos.y, color);
	}
}

void LineBased::OnUpdate()
{

}