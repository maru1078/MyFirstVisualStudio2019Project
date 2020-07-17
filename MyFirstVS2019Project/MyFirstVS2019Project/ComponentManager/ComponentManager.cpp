#include "ComponentManager.h"
#include "../Component/Component.h"

std::list<std::shared_ptr<Component>> ComponentManager::m_components;

void ComponentManager::RemoveDeadComponent()
{
    m_components.remove_if([](const auto& component)
        {
            return component->IsDead();
        });
}

void ComponentManager::Update()
{
    for (const auto& component : m_components)
    {
        // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
        //if (component->IsDead()) continue;

        component->Update();
    }
}

void ComponentManager::Draw()
{
    for (const auto& component : m_components)
    {
        // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
        //if (component->IsDead()) continue;

        component->Draw();
    }
}
