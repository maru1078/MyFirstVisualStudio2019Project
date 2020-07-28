#ifndef GAME_OBJECT_GENERATOR_H_
#define GAME_OBJECT_GENERATOR_H_

#include <string>
#include "../Component/Component.h"

class GameObjectCreator : public Component
{
public:

	GameObjectCreator(const std::string& inputStr, char splitter);
	explicit GameObjectCreator(const std::weak_ptr<const GameObjectCreator>& other);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Input(const std::string& inputStr) override;

private:

	std::string m_createStr;
	char m_splitter;
};

#endif // !GAME_OBJECT_GENERATOR_H_

