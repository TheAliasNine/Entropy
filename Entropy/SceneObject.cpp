#include "SceneObject.h"
#include "Component.h"
#include "CollisionInfo.h"

#include "SoTransform.h"

SceneObject::SceneObject(Application* app)
{
	this->app = app;
	transform = SoTransform(this);
}

SceneObject::~SceneObject()
{
	if (parent != nullptr) Unparent();
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}

	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}

	app->RemoveSceneObject(this);
}

void SceneObject::Draw()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->OnDraw();
	}
}

void SceneObject::Update(float deltaTime)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->OnUpdate(deltaTime);
	}
}

void SceneObject::UpdateTransform()
{
	transform.UpdateGlobal();
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->UpdateTransform();
	}
}

SceneObject* SceneObject::GetParent()
{
	return parent;
}

void SceneObject::SetParent(SceneObject* so)
{
	if (parent != nullptr)
	{
		Unparent();
	}
	so->children.push_back(so);
	parent = so;
	UpdateTransform();
}

void SceneObject::Unparent()
{
	for (int i = 0; i < parent->children.size(); i++)
	{
		if (parent->children[i] == this)
		{
			std::vector<SceneObject*>::iterator it = parent->children.begin();
			it += i;
			parent->children.erase(it);
			break;
		}
	}
	parent = nullptr;
	UpdateTransform();
}
void SceneObject::Unparent(bool updateObj)
{
	for (int i = 0; i < parent->children.size(); i++)
	{
		if (parent->children[i] == this)
		{
			std::vector<SceneObject*>::iterator it = parent->children.begin();
			it += i;
			parent->children.erase(it);
			break;
		}
	}
	parent = nullptr;
	if (!updateObj) return;
	UpdateTransform();
}

void SceneObject::AddComponent(Component* component)
{
	components.push_back(component);
}

void SceneObject::OnCollision(CollisionInfo info)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->OnCollision(info);
	}
}