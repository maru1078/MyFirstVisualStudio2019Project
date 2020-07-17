#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>

//void Component::Update()
//{
//	std::cout << m_gameObject.lock()->GetName() << " Update" << std::endl;
//}
//
//void Component::Draw()
//{
//	std::cout << m_gameObject.lock()->GetName() << " Draw" << std::endl;
//}

const std::weak_ptr<GameObject>& Component::GetGameObject() const
{
	return m_gameObject;
}

void Component::SetGameObject(std::weak_ptr<GameObject> gameObject)
{
	m_gameObject = gameObject;
}
