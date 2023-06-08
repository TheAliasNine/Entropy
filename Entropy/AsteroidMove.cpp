#include "AsteroidMove.h"
#include "SceneObject.h"
#include "PremadeSceneObjects.h"

#include "Vector2.h"

#include <math.h>
#include <random>

AsteroidMove::AsteroidMove(SceneObject* obj, float directionRadians, Size size)
{
	this->obj = obj;
	direction.x = (float)cos(directionRadians);
	direction.y = (float)sin(directionRadians);

	this->size = size;
	if (this->size == Size::Large)
	{
		obj->transform.SetLocalScale(2);
	}
	else if (this->size == Size::Small)
	{
		obj->transform.SetLocalScale(0.5f);
	}
}

void AsteroidMove::OnUpdate(float deltaTime)
{
	obj->transform.Translate(direction * speed * deltaTime);
}


void AsteroidMove::OnCollision(CollisionInfo info)
{
	if (info.collisionLayer == Collider::Enemy || info.collisionLayer == Collider::Player || info.collisionLayer == Collider::PlayerBullet || info.collisionLayer == Collider::Solid)
	{
		Break();
	}
}

void AsteroidMove::Break()
{
	if (size == Size::Large)
	{
		float newRotation = obj->transform.GetLocalRotation();
		float a = GetRandomValue(-60, 60);
		newRotation += a / 180 * PI;
		float newRotation2 = obj->transform.GetLocalRotation();
		newRotation2 += GetRandomValue(-60, 60) / 180 * PI;

		SceneObject* new1 = PremadeSceneObjects::ScreenBoundAsteroid(obj->app, obj->app->screen, newRotation, Size::Medium);
		new1->transform.SetLocalTranslation(obj->transform.GetLocalTranslation());
		new1->transform.SetLocalRotation(newRotation);
		new1->SetParent(obj->GetParent());

		SceneObject* new2 = PremadeSceneObjects::ScreenBoundAsteroid(obj->app, obj->app->screen, newRotation, Size::Medium);
		new2->transform.SetLocalTranslation(obj->transform.GetLocalTranslation());
		new2->transform.SetLocalRotation(newRotation2);
		new2->SetParent(obj->GetParent());

		obj->app->AddSceneObject(new1);
		obj->app->AddSceneObject(new2);

		delete obj;
		return;
	}
	else if (size == Size::Medium)
	{
		float newRotation = obj->transform.GetLocalRotation();
		float a = GetRandomValue(-60, 60);
		newRotation += a / 180 * PI;
		float newRotation2 = obj->transform.GetLocalRotation();
		newRotation2 += GetRandomValue(-60, 60) / 180 * PI;

		SceneObject* new1 = PremadeSceneObjects::ScreenBoundAsteroid(obj->app, obj->app->screen, newRotation, Size::Small);
		new1->transform.SetLocalTranslation(obj->transform.GetLocalTranslation());
		new1->transform.SetLocalRotation(newRotation);
		new1->SetParent(obj->GetParent());

		SceneObject* new2 = PremadeSceneObjects::ScreenBoundAsteroid(obj->app, obj->app->screen, newRotation, Size::Small);
		new2->transform.SetLocalTranslation(obj->transform.GetLocalTranslation());
		new2->transform.SetLocalRotation(newRotation2);
		new2->SetParent(obj->GetParent());

		obj->app->AddSceneObject(new1);
		obj->app->AddSceneObject(new2);

		delete obj;
		return;
	}

	delete obj;
	return;
}