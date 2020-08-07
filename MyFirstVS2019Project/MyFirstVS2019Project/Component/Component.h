#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>
#include <string>

class GameObject;

class Component : public std::enable_shared_from_this<Component>
{
public:

	explicit Component(float drawPriority = 0.0f);
	virtual ~Component() {}

	virtual std::weak_ptr<Component> CloneComponent() const = 0;
	virtual void Input(const std::string& inputStr) {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void HandleMessage(const std::string& message) {}
	virtual void OnCollide(const std::weak_ptr<GameObject>& other) {}

public:

	void Destroy();
	bool IsDead() const;

	const std::weak_ptr<GameObject>& GetGameObject() const;
	void SetGameObject(const std::weak_ptr<GameObject>& gameObject);

	float GetDrawPriority() const;

private:

	std::weak_ptr<GameObject> m_gameObject;
	float m_drawPriority{ 0.0f };
	bool m_isDead{ false };
};

#endif // !COMPONENT_H_
