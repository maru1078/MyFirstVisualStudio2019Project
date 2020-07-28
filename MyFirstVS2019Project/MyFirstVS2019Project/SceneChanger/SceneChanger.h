#ifndef SCENE_CHANGER_H_
#define SCENE_CHANGER_H_

#include "../Component/Component.h"

class SceneChanger : public Component
{
public:

	explicit SceneChanger(const std::string& changeStr);

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Input(const std::string& inputStr) override;

	virtual void HandleMessage(const std::string& message) override;

private:

	std::string m_changeStr;
};

#endif // !SCENE_CHANGER_H_

