#include "ColliderList.h"
#include "../../Collider/Collider.h"
#include "../../Component/Component.h"
#include "../../GameObject/GameObject.h"

void ColliderList::CheckAndAdd(const std::weak_ptr<Component>& component)
{
	// �R���C�_�[�ł��邩�ǂ����̔���
	auto collider = std::dynamic_pointer_cast<Collider>(component.lock());

	if (collider == nullptr)
	{
		return;
	}

	m_colliderList.push_front(collider);
}

void ColliderList::RemoveDeadComponent()
{
	m_colliderList.remove_if([](const auto& component)
		{
			return component.lock()->IsDead();
		});
}

void ColliderList::ExecuteIsCollide() const
{
	for (auto colliderItrA = m_colliderList.begin(); colliderItrA != m_colliderList.end(); ++colliderItrA)
	{
		for (auto colliderItrB = std::next(colliderItrA); colliderItrB != m_colliderList.end(); ++colliderItrB)
		{
			// ����̃Q�[���I�u�W�F�N�g�ɃR���|�[�l���g�����Ă�ꍇ�X�L�b�v
			if ((*colliderItrA).lock()->GetGameObject().lock() == (*colliderItrB).lock()->GetGameObject().lock()) continue;

			// �R���|�[�l���g�܂��̓Q�[���I�u�W�F�N�g�̎��S�t���O�������Ă���X�L�b�v
			if ((*colliderItrA).lock()->IsDead() ||
				(*colliderItrB).lock()->IsDead() ||
				(*colliderItrA).lock()->GetGameObject().lock()->IsDead() ||
				(*colliderItrB).lock()->GetGameObject().lock()->IsDead()) continue;

			bool isSkip{ true };

			for (const auto& pair : m_groupArray)
			{
				// �Փ˔���y�A�Ɉ�v���Ă����甲����
				if (pair.first == (*colliderItrA).lock()->GetCollisionGroup() &&
					pair.second == (*colliderItrB).lock()->GetCollisionGroup())
				{
					isSkip = false;
					break;
				}
				else if (pair.first == (*colliderItrB).lock()->GetCollisionGroup() &&
					     pair.second == (*colliderItrA).lock()->GetCollisionGroup())
				{
					isSkip = false;
					break;
				}
			}

			if (isSkip) continue;

			// �Փ˂��Ă�����
			if ((*colliderItrA).lock()->IsCollide(*colliderItrB))
			{
				// OnCollide���Ă�
				(*colliderItrA).lock()->GetGameObject().lock()->OnCollideAll((*colliderItrB).lock()->GetGameObject());
				(*colliderItrB).lock()->GetGameObject().lock()->OnCollideAll((*colliderItrA).lock()->GetGameObject());
			}
		}
	}
}

void ColliderList::AddCollisionGroupPair(int first, int second)
{
	m_groupArray.emplace_back(std::make_pair(first, second));
}
