#include "PlayerShooting.h"
#include "PremadeSceneObjects.h"

#include "raylib.h"

void PlayerShooting::OnUpdate(float deltaTime)
{
	if (IsKeyPressed(KeyboardKey::KEY_SPACE))
	{
		//create bullet
		SceneObject* bullet = PremadeSceneObjects::PlayerBullet(obj->app);

		bullet->transform.SetLocalRotation(obj->transform.GetGlobalRotation());
		bullet->transform.SetLocalTranslation(obj->transform.GetGlobalTranslation());

		obj->app->AddSceneObject(bullet);
	}
}