#include "Component.h"
#include "CollisionInfo.h"
#include "SceneObject.h"
#include "SoTransform.h"


SceneObject::SceneObject(Application* app)
{
	this->app = app;
	transform = SoTransform(this);
}

SceneObject::~SceneObject()
{
	if (parent != nullptr) Unparent();
	for (int i = children.size() - 1; i > -1 ; i--)
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
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw();
	}
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->OnDraw();
	}
}

void SceneObject::Update(float deltaTime)
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Update(deltaTime);
	}
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
	if (so == nullptr)
	{
		UpdateTransform();
		return;
	}
	so->children.push_back(this);
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
	app->RemoveSceneObject(this);
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
	app->RemoveSceneObject(this);
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

int SceneObject::ChildrenCount()
{
	return children.size();
}