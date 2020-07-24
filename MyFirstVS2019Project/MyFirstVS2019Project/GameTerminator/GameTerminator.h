#ifndef GAME_TERMINATOR_H_
#define GAME_TERMINATOR_H_

#include "../Component/Component.h"

class GameTerminator : public Component
{
public:

	explicit GameTerminator(const std::string& inputStr);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Input(const std::string& inputStr) override;

private:

	std::string m_gameEndStr;
};

#endif // !GAME_TERMINATOR_H_

