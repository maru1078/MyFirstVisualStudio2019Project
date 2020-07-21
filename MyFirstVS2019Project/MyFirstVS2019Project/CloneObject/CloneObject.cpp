#include "CloneObject.h"

#include "../GameObject/GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../ComponentManager/ComponentManager.h"

CloneObject::CloneObject(int cloneNum)
	: m_cloneNum{ cloneNum }
{
}

CloneObject::CloneObject(const std::weak_ptr<const CloneObject>& other)
	: m_cloneNum{ other.lock()->m_cloneNum }
	, m_curCloneCount{ other.lock()->m_curCloneCount }
{
}

std::weak_ptr<Component> CloneObject::CloneComponent() const
{
	return ComponentManager::CreateComponent<CloneObject>(std::dynamic_pointer_cast<const CloneObject>(shared_from_this()));
}

void CloneObject::Update()
{
	// コピー回数が残っていなければ即リターン
	if (m_cloneNum - m_curCloneCount <= 0) return;

	// 先に回数をカウントする
	// 後にカウントすると、正常に残り回数がクローンに伝わらない。
	m_curCloneCount++;

	auto clone = GameObjectManager::CloneGameObject(GetGameObject());

	for (const auto& component : GetGameObject().lock()->GetComponentAll())
	{
		clone.lock()->AddComponent(component.lock()->CloneComponent());
	}
}
