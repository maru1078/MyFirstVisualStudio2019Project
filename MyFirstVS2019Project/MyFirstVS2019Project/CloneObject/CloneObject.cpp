#include "CloneObject.h"

#include "../GameObject/GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../ComponentManager/ComponentManager.h"

CloneObject::CloneObject(int cloneNum)
	: m_cloneNum{ cloneNum }
{
}

std::weak_ptr<Component> CloneObject::CloneComponent()
{
	// コピーの残り回数を渡す
	return ComponentManager::CreateComponent<CloneObject>(m_cloneNum - m_curCloneCount);
}

void CloneObject::Update()
{
	// コピー回数が残っていればクローン
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
