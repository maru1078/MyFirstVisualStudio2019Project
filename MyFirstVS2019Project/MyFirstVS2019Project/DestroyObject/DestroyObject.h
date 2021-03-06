#ifndef DESTROY_OBJECT_H_
#define DESTROY_OBJECT_H_

#include "../Component/Component.h"

class DestroyObject : public Component
{
public:

	explicit DestroyObject(const std::string& objectName);

public:

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Update() override;

private:

	std::string m_objectName;
};

#endif // !DESTROY_OBJECT_H_

