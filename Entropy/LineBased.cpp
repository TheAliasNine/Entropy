#include "LineBased.h"
#include "SceneObject.h"
#include "SoTransform.h"

#include "Vector2.h"

#include "raylib.h"


LineBased::LineBased()
{
	obj = nullptr;
}

LineBased::LineBased(SceneObject* so)
{
	obj = so;
}

void LineBased::OnDraw()
{

}

void LineBased::OnUpdate()
{

}