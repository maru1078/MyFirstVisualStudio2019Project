#include "GameObject.h"
#include "../Component/Component.h"

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
}

void GameObject::Destroy()
{
	// 自分が持っているコンポーネントの死亡フラグを立てる
	for (const auto& component : m_components)
	{
		if (component.expired()) continue;

		component.lock()->Destroy();
	}

	// 自分の死亡フラグを立てる
	m_isDead = true;
}

bool GameObject::IsDead() const
{
	return m_isDead;
}

const std::string& GameObject::GetName() const
{
	return m_name;
}
