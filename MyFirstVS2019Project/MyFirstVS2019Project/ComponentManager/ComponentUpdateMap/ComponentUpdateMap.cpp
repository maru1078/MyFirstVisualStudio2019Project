#include "ComponentUpdateMap.h"
#include "../../Component/Component.h"

void ComponentUpdateMap::ExecuteUpdate() const
{
	for (const auto& pair : m_updateMap)
	{
		// �ǉ����ꂽ�����ō폜����Ă邩�ǂ����̊m�F�̂��߁A���̓R�����g���B
		if (pair.second.expired()) continue;

		pair.second.lock()->Update();
	}
}

void ComponentUpdateMap::Add(float priority, const std::weak_ptr<Component>& component)
{
	m_updateMap.emplace(priority, component);
}

void ComponentUpdateMap::RemoveDeadComponent()
{
	for (auto it = m_updateMap.begin(); it != m_updateMap.end();)
	{
		if ((*it).second.expired())
		{
			it = m_updateMap.erase(it);
		}
		else
		{
			++it;
		}
	}
}
