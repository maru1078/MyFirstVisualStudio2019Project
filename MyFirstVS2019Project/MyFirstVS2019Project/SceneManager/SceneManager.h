#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include <memory>
#include "../Scene/Scene.h"

class SceneManager
{
public:

	template<class T, class... Args>
	static void ChangeScene(const Args&... args);

private:

	static std::shared_ptr<Scene> m_curScene;
};

template<class T, class ...Args>
inline void SceneManager::ChangeScene(const Args& ...args)
{
	if (m_curScene)
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
