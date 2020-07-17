#include "GameObject.h"
#include "../Component/Component.h"
#include "../ComponentManager/ComponentManager.h"

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
}

const std::string& GameObject::GetName() const
{
	return m_name;
}

void GameObject::AddComponent()
{
	auto component = ComponentManager::CreateComponent();
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_back(component);
}
