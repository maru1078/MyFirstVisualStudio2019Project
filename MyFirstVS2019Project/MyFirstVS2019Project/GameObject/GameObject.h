#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>
#include <vector>
#include <memory>

class Component;

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:

	GameObject(const std::string& name);

public:

	const std::string& GetName() const;

	void AddComponent();

private:

	std::string m_name;
	std::vector<std::weak_ptr<Component>> m_components;
};

#endif // !GAME_OBJECT_H_

