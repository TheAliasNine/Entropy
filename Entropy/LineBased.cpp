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
	UpdateGlobal();

	for (int i = 0; i < lines.size(); i++)
	{
		DrawLine(globalLines[i].start.x, globalLines[i].start.y, globalLines[i].end.x, globalLines[i].end.y, color);
	}
}

void LineBased::OnUpdate()
{

}

void LineBased::AddLine(Line line)
{
	lines.push_back(line);
	Math::Vector3 startPos = obj->transform.GetGlobalMatrix() * Math::Vector3(line.start.x, line.start.y, 1);
	Math::Vector3 endPos = obj->transform.GetGlobalMatrix() * Math::Vector3(line.end.x, line.end.y, 1);
	globalLines.push_back(Line(Math::Vector2(startPos.x, startPos.y), Math::Vector2(endPos.x, endPos.y)));
}

void::LineBased::UpdateGlobal()
{
	for (int i = 0; i < globalLines.size(); i++)
	{
		Math::Vector3 startPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].start.x, lines[i].start.y, 1);
		Math::Vector3 endPos = obj->transform.GetGlobalMatrix() * Math::Vector3(lines[i].end.x, lines[i].end.y, 1);

		globalLines[i] = Line(Line(Math::Vector2(startPos.x, startPos.y), Math::Vector2(endPos.x, endPos.y)));
	}
}