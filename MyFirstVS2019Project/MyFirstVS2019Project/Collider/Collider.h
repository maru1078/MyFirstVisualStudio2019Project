#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "../Component/Component.h"

class Collider : public Component
{
public:

	Collider(int collisionGroup);

	virtual std::weak_ptr<Component> CloneComponent() const override;

	bool IsCollide(const std::weak_ptr<Collider>& other) const;

	int GetCollisionGroup() const;

private:

	int m_collisionGroup;
};

#endif // !COLLIDER_H_

