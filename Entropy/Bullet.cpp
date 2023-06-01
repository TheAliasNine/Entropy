#include "Bullet.h"
#include "CollisionInfo.h"
#include "SceneObject.h"

Bullet::Bullet(SceneObject* obj)
{
	this->obj = obj;
}

void Bullet::OnUpdate(float deltaTime)
{
	timer += deltaTime;
	if (timer > liveTime)
	{
		delete obj;
		return;
	}
	obj->transform.Translate(Math::Vector2(obj->transform.GetLocalRotationMatrix().m01 * speed * deltaTime, obj->transform.GetLocalRotationMatrix().m00 * speed * deltaTime));
}

void Bullet::OnCollision(CollisionInfo info)
{
	if (info.collisionLayer == Collider::InBounds)
	{

	}
	else if (info.collisionLayer == Collider::Player) return;
	else
	{
		delete obj;
		return;
	}
}