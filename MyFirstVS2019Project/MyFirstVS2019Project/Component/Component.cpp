#include "Component.h"
#include "../GameObject/GameObject.h"

void Component::Destroy()
{
	m_isDead = true;
}

bool Component::IsDead() const
{
	return m_isDead;
}

const std::weak_ptr<GameObject>& Component::GetGameObject() const
{
	return m_gameObject;
}

void Component::SetGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	m_gameObject = gameObject;
}
