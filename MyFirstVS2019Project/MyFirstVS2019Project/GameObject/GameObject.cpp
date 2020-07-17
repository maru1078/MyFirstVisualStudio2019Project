#include "GameObject.h"
#include "../Component/Component.h"

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
}

void GameObject::Destroy()
{
	// �����������Ă���R���|�[�l���g�̎��S�t���O�𗧂Ă�
	for (const auto& component : m_components)
	{
		if (component.expired()) continue;

		component.lock()->Destroy();
	}

	// �����̎��S�t���O�𗧂Ă�
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
