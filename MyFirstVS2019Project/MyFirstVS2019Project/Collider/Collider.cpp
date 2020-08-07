#include "Collider.h"
#include "../ComponentManager/ComponentManager.h"

Collider::Collider(int collisionGroup)
	: m_collisionGroup{ collisionGroup }
{
}

std::weak_ptr<Component> Collider::CloneComponent() const
{
	return ComponentManager::CreateComponent<Collider>(m_collisionGroup);
}

bool Collider::IsCollide(const std::weak_ptr<Collider>& other) const
{
	return true;
}

int Collider::GetCollisionGroup() const
{
	return m_collisionGroup;
}
