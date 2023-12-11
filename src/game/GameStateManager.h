#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <stack>
#include "GameState.h"

class GameStateManager {
private:
    std::stack<GameState*> states;

public:
    GameStateManager();
    ~GameStateManager();

    void addState(GameState* state);
    void removeState();
    void changeState(GameState* state);
    GameState* getCurrentState() const;
};

#endif // GAMESTATEMANAGER_H
