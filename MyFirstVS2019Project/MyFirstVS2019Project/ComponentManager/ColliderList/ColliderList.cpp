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
	for (auto i = m_colliderList.begin(); i != m_colliderList.end(); ++i)
	{
		for (auto j = std::next(i); j != m_colliderList.end(); ++j)
		{
			// ����̃Q�[���I�u�W�F�N�g�ɃR���|�[�l���g�����Ă�ꍇ�X�L�b�v
			if ((*i).lock()->GetGameObject().lock() == (*j).lock()->GetGameObject().lock()) continue;

			// �R���|�[�l���g�܂��̓Q�[���I�u�W�F�N�g�̎��S�t���O�������Ă���X�L�b�v
			if ((*i).lock()->IsDead() ||
				(*j).lock()->IsDead() ||
				(*i).lock()->GetGameObject().lock()->IsDead() ||
				(*j).lock()->GetGameObject().lock()->IsDead()) continue;

			// �Փ˃O���[�v����v���Ă��Ȃ�������X�L�b�v
			if ((*i).lock()->GetCollisionGroup() != (*j).lock()->GetCollisionGroup())
			{
				continue;
			}

			// �Փ˂��Ă�����
			if ((*i).lock()->IsCollide(*j))
			{
				// OnCollide���Ă�
				(*i).lock()->GetGameObject().lock()->OnCollideAll((*j).lock()->GetGameObject());
				(*j).lock()->GetGameObject().lock()->OnCollideAll((*i).lock()->GetGameObject());
			}
		}
	}
}
