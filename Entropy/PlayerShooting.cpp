#include "PlayerShooting.h"
#include "PremadeSceneObjects.h"

#include "raylib.h"

void PlayerShooting::OnUpdate(float deltaTime)
{
	if (IsKeyPressed(KeyboardKey::KEY_SPACE))
	{
		//create bullet
		SceneObject* bullet = PremadeSceneObjects::ScreenBoundPlayerBullet(obj->app, obj->app->screen);

		bullet->transform.SetLocalRotation(obj->transform.GetGlobalRotation());
		bullet->transform.SetLocalTranslation(obj->transform.GetGlobalTranslation());

		obj->app->AddSceneObject(bullet);
	}
}