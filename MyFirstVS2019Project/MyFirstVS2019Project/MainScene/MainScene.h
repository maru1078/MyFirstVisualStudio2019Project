#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "../Scene/Scene.h"

// ���C���V�[���i���͌`�����B���g�̎����Ȃ��j
class MainScene : public Scene
{
public:

	virtual void Start() override;
	virtual void End() override;
};

#endif // !MAIN_SCENE_H_

