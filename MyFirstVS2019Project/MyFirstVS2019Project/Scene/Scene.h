#ifndef SCENE_H_
#define SCENE_H_

// シーンを作るための基底クラス
class Scene
{
public:

	virtual ~Scene() {}

	virtual void Start() = 0;
	virtual void End() = 0;
};

#endif // !SCENE_H_

