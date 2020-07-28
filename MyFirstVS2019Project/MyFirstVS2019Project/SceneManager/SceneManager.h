#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include "../Scene/Scene.h"

class SceneManager
{
public:

	template<class T, class... Args>
	static void CreateCurrentScene(const Args&... args);

private:

	static std::shared_ptr<Scene> m_curScene;
};

template<class T, class ...Args>
inline void SceneManager::CreateCurrentScene(const Args& ...args)
{
	if (m_curScene != nullptr)
	{
		// �V�[���I������
		m_curScene->End();
	}

	// �V�����V�[�����Z�b�g
	m_curScene.reset(new T(args...));

	// �V�[���J�n����
	m_curScene->Start();
}

#endif // !SCENE_MANAGER_H_
