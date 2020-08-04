#include "ComponentDrawMap.h"
#include "../Component/Component.h"

void ComponentDrawMap::ExecuteDraw() const
{
    for (const auto& pair : m_drawMap)
    {
        // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
        //if (pair.second.expired()) continue;

        pair.second.lock()->Draw();
    }
}

void ComponentDrawMap::Add(const std::weak_ptr<Component>& component)
{
	m_drawMap.emplace(component.lock()->GetDrawPriority(), component);
}

void ComponentDrawMap::RemoveDeadComponent()
{
    for (auto it = m_drawMap.begin(); it != m_drawMap.end();)
    {
        if ((*it).second.expired())
        {
            it = m_drawMap.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
