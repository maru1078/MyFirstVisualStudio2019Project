#include "ComponentDrawMap.h"
#include "../Component/Component.h"

void ComponentDrawMap::ExecuteDraw() const
{
    for (const auto& pair : m_drawMap)
    {
        // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
        //if (pair.second->IsDead()) continue;

        pair.second->Draw();
    }
}

void ComponentDrawMap::Add(const std::shared_ptr<Component>& component)
{
	m_drawMap.emplace(component->GetDrawPriority(), component);
}

void ComponentDrawMap::RemoveDeadComponent()
{
    for (auto it = m_drawMap.begin(); it != m_drawMap.end();)
    {
        if ((*it).second->IsDead())
        {
            it = m_drawMap.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
