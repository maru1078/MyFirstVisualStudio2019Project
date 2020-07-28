#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "../Scene/Scene.h"

// メインシーン（今は形だけ。中身の実装なし）
class MainScene : public Scene
{
public:

	virtual void Start() override;
	virtual void End() override;
};

#endif // !MAIN_SCENE_H_

