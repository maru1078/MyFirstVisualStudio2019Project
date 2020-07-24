#include "GameTerminator.h"

#include "../ComponentManager/ComponentManager.h"
#include "../Game/Game.h"

GameTerminator::GameTerminator(const std::string& inputStr)
	: m_gameEndStr{ inputStr }
{
}

std::weak_ptr<Component> GameTerminator::CloneComponent() const
{
	return ComponentManager::CreateComponent<GameTerminator>(m_gameEndStr);
}

void GameTerminator::Input(const std::string& inputStr)
{
	if (inputStr == m_gameEndStr)
	{
		// �Q�[���I������
		Game::ExitGame();
	}
}
