#ifndef CLONE_OBJECT_H_
#define CLONE_OBJECT_H_

#include "../Component/Component.h"

class CloneObject : public Component
{
public:

	CloneObject(int cloneNum);
	CloneObject(const std::weak_ptr<const CloneObject>& other);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Update() override;

private:

	int m_cloneNum;
	int m_curCloneCount{ 0 };
};

#endif // !CLONE_OBJECT_H_

