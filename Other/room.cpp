#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    string type; // 房間類型
public:
    // 帶參數的構造函數，用於初始化房間類型
    Room(const std::string& type) : type(type) {
        cout << "Room of type " << type << " created." << endl;
    }

    // 顯示房間類型
    void display() const {
        cout << "This is a " << type << "." << endl;
    }
};

class House {
private:
    Room room; // House 包含一個 Room 成員變數
public:
    // House 的構造函數，初始化 Room
    House(const string& roomType) : room(roomType) {
        cout << "House with a " << roomType << " created." << endl;
    }

    // 顯示房子內房間的資訊
    void showRoom() const {
        room.display();
    }
};

int main() {
    // 創建一個 House，並指定房間類型為 "Living Room"
    House myHouse("Living Room");

    // 顯示房子內的房間資訊
    myHouse.showRoom();

    return 0;
}
