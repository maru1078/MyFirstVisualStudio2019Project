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
	// �R�s�[�̎c��񐔂�n��
	return ComponentManager::CreateComponent<CloneObject>(m_cloneNum - m_curCloneCount);
}

void CloneObject::Update()
{
	// �R�s�[�񐔂��c���Ă���΃N���[��
	if (m_cloneNum - m_curCloneCount <= 0) return;

	// ��ɉ񐔂��J�E���g����
	// ��ɃJ�E���g����ƁA����Ɏc��񐔂��N���[���ɓ`���Ȃ��B
	m_curCloneCount++;

	auto clone = GameObjectManager::CloneGameObject(GetGameObject());

	for (const auto& component : GetGameObject().lock()->GetComponentAll())
	{
		clone.lock()->AddComponent(component.lock()->CloneComponent());
	}
}
