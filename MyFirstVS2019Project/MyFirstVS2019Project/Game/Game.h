#ifndef GAME_H_
#define GAME_H_

class Game
{
public:

	static void Run();

	static void ExitGame();

private:

	static bool m_isExit;
};

#endif // !GAME_H_

