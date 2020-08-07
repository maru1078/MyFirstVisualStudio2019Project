#include "GameObject.h"
#include "../Component/Component.h"

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
}

GameObject::GameObject(const std::weak_ptr<GameObject>& other)
	: m_name{ other.lock()->m_name }
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

void GameObject::AddComponent(const std::weak_ptr<Component>& component)
{
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_front(component);
}

const std::forward_list<std::weak_ptr<Component>>& GameObject::GetComponentAll() const
{
	return m_components;
}

void GameObject::SendMessage(const std::string& message)
{
	for (const auto& component : m_components)
	{
		component.lock()->HandleMessage(message);
	}
}

void GameObject::OnCollideAll(const std::weak_ptr<GameObject>& other)
{
	for (const auto& component : m_components)
	{
		component.lock()->OnCollide(other);
	}
}
