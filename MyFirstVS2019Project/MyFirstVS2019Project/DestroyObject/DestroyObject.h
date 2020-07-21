#ifndef DESTROY_OBJECT_H_
#define DESTROY_OBJECT_H_

#include <string>
#include "../Component/Component.h"

class DestroyObject : public Component
{
public:

	DestroyObject(const std::string& objectName);

public:

	virtual std::weak_ptr<Component> CloneComponent() override;
	virtual void Update() override;

private:

	std::string m_objectName;
};

#endif // !DESTROY_OBJECT_H_

