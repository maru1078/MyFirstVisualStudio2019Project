#ifndef SCENE_H_
#define SCENE_H_

// �V�[������邽�߂̊��N���X
class Scene
{
public:

	virtual ~Scene() {}

	virtual void Start() = 0;
	virtual void End() = 0;
};

#endif // !SCENE_H_

