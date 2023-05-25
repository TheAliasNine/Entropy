#include "SceneObject.h"

#include "Transform.h"

SceneObject::SceneObject()
{
	transform = Transform(this);

}

SceneObject::~SceneObject()
{
	if (parent == nullptr) Unparent();
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void SceneObject::Draw()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Draw();
	}
}

void SceneObject::Update()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update();
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