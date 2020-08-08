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
	// メリット：衝突判定の組み合わせを簡単に変更できる
	// デメリット：ペア全体を見るから巡回にかかるコストが高い。
	for (auto colliderItrA = m_colliderList.begin(); colliderItrA != m_colliderList.end(); ++colliderItrA)
	{
		for (auto colliderItrB = std::next(colliderItrA); colliderItrB != m_colliderList.end(); ++colliderItrB)
		{
			// 同一のゲームオブジェクトにコンポーネントがついてる場合スキップ
			if ((*colliderItrA).lock()->GetGameObject().lock() == (*colliderItrB).lock()->GetGameObject().lock()) continue;

			// コンポーネントまたはゲームオブジェクトの死亡フラグが立ってたらスキップ
			// 「コンポーネントが死んでいるか」ではなく、「コンポーネントがアクティブ状態か」のほうがいいかも
			if ((*colliderItrA).lock()->IsDead() ||
				(*colliderItrB).lock()->IsDead() ||
				(*colliderItrA).lock()->GetGameObject().lock()->IsDead() ||
				(*colliderItrB).lock()->GetGameObject().lock()->IsDead()) continue;

			if (!CheckCollisionPair((*colliderItrA).lock()->GetCollisionGroup(), (*colliderItrB).lock()->GetCollisionGroup()))
			{
				continue;
			}

			// 衝突していたら
			if ((*colliderItrA).lock()->IsCollide(*colliderItrB))
			{
				// OnCollideを呼ぶ
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

bool ColliderList::CheckCollisionPair(int group1, int group2) const
{
	for (const auto& pair : m_groupArray)
	{
		// 衝突判定ペアに一致していたら抜ける
		if (pair.first == group1 &&
			pair.second == group2)
		{
			return true;
		}
		else if (pair.first == group2 &&
			     pair.second == group1)
		{
			return true;
		}
	}

	return false;
}
