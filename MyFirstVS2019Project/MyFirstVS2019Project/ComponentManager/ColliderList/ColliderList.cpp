#include "ColliderList.h"
#include "../../Collider/Collider.h"
#include "../../Component/Component.h"
#include "../../GameObject/GameObject.h"

void ColliderList::CheckAndAdd(const std::weak_ptr<Component>& component)
{
	// コライダーであるかどうかの判定
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
			// 同一のゲームオブジェクトにコンポーネントがついてる場合スキップ
			if ((*i).lock()->GetGameObject().lock() == (*j).lock()->GetGameObject().lock()) continue;

			// コンポーネントまたはゲームオブジェクトの死亡フラグが立ってたらスキップ
			if ((*i).lock()->IsDead() ||
				(*j).lock()->IsDead() ||
				(*i).lock()->GetGameObject().lock()->IsDead() ||
				(*j).lock()->GetGameObject().lock()->IsDead()) continue;

			// 衝突グループが一致していなかったらスキップ
			if ((*i).lock()->GetCollisionGroup() != (*j).lock()->GetCollisionGroup())
			{
				continue;
			}

			// 衝突していたら
			if ((*i).lock()->IsCollide(*j))
			{
				// OnCollideを呼ぶ
				(*i).lock()->GetGameObject().lock()->OnCollideAll((*j).lock()->GetGameObject());
				(*j).lock()->GetGameObject().lock()->OnCollideAll((*i).lock()->GetGameObject());
			}
		}
	}
}
