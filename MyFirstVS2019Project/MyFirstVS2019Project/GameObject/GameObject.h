#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>

class GameObject
{
public:

	GameObject(const std::string& name);

	const std::string& GetName();

private:

	std::string m_name;
};

#endif // !GAME_OBJECT_H_

