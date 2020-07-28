#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>
#include <string>

class GameObject;

class Component : public std::enable_shared_from_this<Component>
{
public:

	virtual ~Component() {}

	virtual std::weak_ptr<Component> CloneComponent() const = 0;
	virtual void Input(const std::string& inputStr) {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void HandleMessage(const std::string& message) {}

public:

	void Destroy();
	bool IsDead() const;

	const std::weak_ptr<GameObject>& GetGameObject() const;
	void SetGameObject(const std::weak_ptr<GameObject>& gameObject);

private:

	std::weak_ptr<GameObject> m_gameObject;
	bool m_isDead{ false };
};

#endif // !COMPONENT_H_
