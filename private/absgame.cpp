#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 抽象基类：游戏对象
class GameObject {
protected:
    string name;

public:
    GameObject(const string& objName) : name(objName) {cout<<2;}

    // 抽象方法：更新逻辑
    virtual void update() const = 0;

    // 抽象方法：渲染逻辑
    virtual void render() const = 0;

    virtual ~GameObject() {cout<<1;}
};

// 开发者自定义的敌人类
class Enemy : public GameObject {
    int health;

public:
    Enemy(const string& enemyName, int initialHealth) 
        : GameObject(enemyName), health(initialHealth) {cout<<3;}

    void update() const override {
        cout << name << " is moving towards the player." << endl;
    }

    void render() const override {
        cout << name << " with health " << health << " is being rendered on screen." << endl;
    }
};

// 开发者自定义的道具类
class Item : public GameObject {
    string effect;

public:
    Item(const string& itemName, const string& itemEffect) 
        : GameObject(itemName), effect(itemEffect) {}

    void update() const override {
        cout << name << " is waiting to be picked up." << endl;
    }

    void render() const override {
        cout << name << " with effect: " << effect << " is shining brightly." << endl;
    }
};

// 游戏引擎核心：管理和更新所有游戏对象
class GameEngine {
    vector<unique_ptr<GameObject>> gameObjects;

public:
    void addGameObject(unique_ptr<GameObject> obj) {
        gameObjects.push_back(move(obj));
    }

    void gameLoop() const {
        for (const auto& obj : gameObjects) {
            obj->update();
            obj->render();
        }
    }
};

int main() {
    GameEngine engine;

    // 插件开发者添加自定义对象
    engine.addGameObject(make_unique<Enemy>("Goblin", 100));
    engine.addGameObject(make_unique<Item>("Healing Potion", "Restore 50 HP"));

    cout << "Running game loop:" << endl;
    engine.gameLoop();

    return 0;
}
