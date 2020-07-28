#ifndef TITLE_SCENE_OUTPUTER_H_
#define TITLE_SCENE_OUTPUTER_H_

#include "../Component/Component.h"

// �^�C�g���V�[���ł��邱�Ƃ��o�͂���R���|�[�l���g
class TitleSceneOutputer : public Component
{
public:

	virtual std::weak_ptr<Component> CloneComponent() const override;
	virtual void Update() override;

	virtual void HandleMessage(const std::string& message) override;
};

#endif // !TITLE_SCENE_OUTPUTER_H_

