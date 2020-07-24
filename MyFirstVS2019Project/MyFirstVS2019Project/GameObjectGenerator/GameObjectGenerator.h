#ifndef GAME_OBJECT_GENERATOR_H_
#define GAME_OBJECT_GENERATOR_H_

#include <string>
#include "../Component/Component.h"

class GameObjectGenerator : public Component
{
public:

	GameObjectGenerator(const std::string& inputStr, char splitter);
	GameObjectGenerator(const std::weak_ptr<const GameObjectGenerator>& other);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Input(const std::string& inputStr) override;

private:

	std::string m_generateStr;
	char m_splitter;
};

#endif // !GAME_OBJECT_GENERATOR_H_

