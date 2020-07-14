#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>

class GameObject;

class Component
{
public:

	void Update();
	void Draw();

public:

	void SetGameObject(std::weak_ptr<GameObject> gameObject);

private:

	std::weak_ptr<GameObject> m_gameObject;
};

#endif // !COMPONENT_H_

