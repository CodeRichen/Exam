#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Garden namespace
namespace Garden {

    // Class to represent a magical plant
    class Plant {
    private:
        string name;   // Plant's name
        float height;  // Plant's height
        string color;  // Plant's color
        string shape;  // Plant's shape

    public:
        // Constructor to initialize a Plant object
        Plant(const string& name, float height, const string& color, const string& shape)
            : name(name), height(height), color(color), shape(shape) {}

        // Grow function to increase plant height
        void grow(float amount) {
            height += amount;
        }

        // Bloom function to change the plant's color
        void bloom(const string& newColor) {
            color = newColor;
        }

        // Transform function to change the plant's shape
        void transform(const string& newShape) {
            shape = newShape;
        }

        // Getter for the plant's name
        string getName() const {
            return name;
        }

        // Function to print the current state of the plant
        void printState() const {
            cout << name << " " << height << " " << color << " " << shape << endl;
        }
    };

    // Class to represent a gardener managing plants
    class Gardener {
    private:
        int maxPlants;                // Maximum plant capacity
        vector<Plant> plants;         // List of plants in the garden

    public:
        // Constructor to initialize Gardener with maximum capacity
        Gardener(int maxPlants) : maxPlants(maxPlants) {}

        // Add a plant to the garden
        void addPlant(const Plant& p) {
            if (plants.size() >= maxPlants) {
                cout << "The garden is full" << endl;
            }
            else {
                plants.push_back(p);
            }
        }

        // Find a plant by its name
        Plant* findPlant(const string& name) {
            for (auto& plant : plants) {
                if (plant.getName() == name) {
                    return &plant;
                }
            }
            return nullptr;
        }

        // Nurture the plant by increasing its height (pass-by-reference)
        void nurture(Plant& plant, float amount) {
            plant.grow(amount);
        }

        // Nurture the plant by changing its shape (pass-by-pointer)
        void nurture(Plant* plant, const string& newShape) {
            if (plant) {
                plant->transform(newShape);
            }
        }

        // Analyze a plant's current state (pass-by-value, const)
        void analyze(const Plant& plant) const {
            plant.printState();
        }
    };

}  // namespace Garden

int main() {
    using namespace Garden;

    int maxPlants;
    cin >> maxPlants; // Maximum number of plants
    Gardener gardener(maxPlants);

    string command;
    while (cin >> command && command != "end") {
        if (command == "add") {
            string name, color, shape;
            float height;
            cin >> name >> height >> color >> shape;
            Plant p(name, height, color, shape);
            gardener.addPlant(p);

        }
        else if (command == "grow") {
            string name;
            float amount;
            cin >> name >> amount;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                plant->grow(amount);
            }

        }
        else if (command == "bloom") {
            string name, newColor;
            cin >> name >> newColor;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                plant->bloom(newColor);
            }

        }
        else if (command == "transform") {
            string name, newShape;
            cin >> name >> newShape;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                plant->transform(newShape);
            }

        }
        else if (command == "analyze") {
            string name;
            cin >> name;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                gardener.analyze(*plant);
            }

        }
        else if (command == "nurtureH") {
            string name;
            float amount;
            cin >> name >> amount;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                gardener.nurture(*plant, amount);
            }

        }
        else if (command == "nurtureS") {
            string name, newShape;
            cin >> name >> newShape;
            Plant* plant = gardener.findPlant(name);
            if (plant) {
                gardener.nurture(plant, newShape);
            }
        }
    }

    return 0;
}
