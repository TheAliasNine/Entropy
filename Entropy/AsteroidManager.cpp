#include "AsteroidManager.h"
#include "AsteroidMove.h"
#include "PremadeSceneObjects.h"

#include "Vector2.h"

#include <random>
#include <math.h>
void AsteroidManager::OnUpdate(float deltaTime)
{
	if (obj->ChildrenCount() == 0)
	{
		wave++;
		for (int i = 0; i < wave + 3; i++)
		{
			SceneObject* asteroid = PremadeSceneObjects::ScreenBoundAsteroid(obj->app, obj->app->screen, GetRandomValue(0, 360), AsteroidMove::Large);
			asteroid->transform.SetLocalRotation(GetRandomValue(0, 360));
			
			float direction = GetRandomValue(0, 360);
			Math::Vector2 offset = player->transform.GetGlobalTranslation() + (Math::Vector2((float)cos(direction), (float)sin(direction)) * GetRandomValue(minDist, maxDist));
			asteroid->transform.Translate(offset);
			asteroid->SetParent(this->obj);
		}
	}
}