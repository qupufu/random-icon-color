#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <random>

inline static std::vector<std::vector<int>> unlocked = {};

int randomNumber(int start, int end) {
    std::random_device os_seed;
    const unsigned int seed = os_seed();

    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribute(start, end);

    return distribute(generator);
}

void setupUnlocked() {
    auto gameManager = GameManager::sharedState();
    unlocked.clear();
    unlocked.push_back({});
    for (int i = 0; i <= 106; i++) {
        if (gameManager->isColorUnlocked(i, UnlockType::Col1)) unlocked.back().push_back(i);
    }
    }
}

void randomize() {
    auto gameManager = GameManager::sharedState();
    auto num = 0;
        num = unlocked[1][randomNumber(0, unlocked[1].size() - 1)];
        gameManager->setPlayerColor(num);
        break;
}

class $modify(PlayerObject) {

    void resetObject() {
        PlayerObject::resetObject();
        if (!PlayLayer::get()) return;

        auto gameManager = GameManager::sharedState();

        if (m_gameLayer->m_player1 == this)
        {
            setupUnlocked();
            PlayerObject::setColor(gameManager->colorForIdx(gameManager->getPlayerColor()));
        }

        if (m_gameLayer->m_player2 == this)
        {
            PlayerObject::setSecondColor(gameManager->colorForIdx(gameManager->getPlayerColor()));
        }
    }
};
