#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    string type; // �ж�����
public:
    // �a�Ѽƪ��c�y��ơA�Ω��l�Ʃж�����
    Room(const std::string& type) : type(type) {
        cout << "Room of type " << type << " created." << endl;
    }

    // ��ܩж�����
    void display() const {
        cout << "This is a " << type << "." << endl;
    }
};

class House {
private:
    Room room; // House �]�t�@�� Room �����ܼ�
public:
    // House ���c�y��ơA��l�� Room
    House(const string& roomType) : room(roomType) {
        cout << "House with a " << roomType << " created." << endl;
    }

    // ��ܩФl���ж�����T
    void showRoom() const {
        room.display();
    }
};

int main() {
    // �Ыؤ@�� House�A�ë��w�ж������� "Living Room"
    House myHouse("Living Room");

    // ��ܩФl�����ж���T
    myHouse.showRoom();

    return 0;
}
