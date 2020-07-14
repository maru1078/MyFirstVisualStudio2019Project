#include "GameObject.h"

GameObject::GameObject(const std::string& name)
	: m_name{ name }
{
}

const std::string& GameObject::GetName()
{
	return m_name;
}
