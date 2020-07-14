#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>

void Component::Update()
{
	std::cout << m_gameObject.lock()->GetName() << " Update" << std::endl;
}

void Component::Draw()
{
	std::cout << m_gameObject.lock()->GetName() << " Draw" << std::endl;
}

void Component::SetGameObject(std::weak_ptr<GameObject> gameObject)
{
	m_gameObject = gameObject;
}
