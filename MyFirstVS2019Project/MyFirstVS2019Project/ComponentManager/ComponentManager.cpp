#include "ComponentManager.h"
#include "../Component/Component.h"

std::vector<std::shared_ptr<Component>> ComponentManager::m_components;

void ComponentManager::Update()
{
    for (auto component : m_components)
    {
        component->Update();
    }
}

void ComponentManager::Draw()
{
    for (auto component : m_components)
    {
        component->Draw();
    }
}

std::weak_ptr<Component> ComponentManager::CreateComponent()
{
    auto component = std::make_shared<Component>();
    m_components.push_back(component);

    return component;
}
