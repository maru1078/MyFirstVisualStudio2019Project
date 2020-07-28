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
		// シーン終了処理
		m_curScene->End();
	}

	// 新しいシーンをセット
	m_curScene.reset(new T(args...));

	// シーン開始処理
	m_curScene->Start();
}

#endif // !SCENE_MANAGER_H_
