#include "Collider.h"
#include "SceneObject.h"

Collider::Collider(SceneObject* obj, Layer layer)
{
	this->obj = obj;
	this->layer = layer;
	obj->app->GetCollisionHandler()->AddCollider(this);
}

Collider::~Collider()
{
	obj->app->GetCollisionHandler()->RemoveCollider(this);
}