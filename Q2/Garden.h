# ifndef GARDEN_H
# define GARDEN_H
# include <iostream>
# include <string>

using namespace std;

namespace Garden{
    class Plant {
        private:
            float height;
            string name;
            string color;
            string shape;
        public:
            Plant();
            Plant(string,float, string, string);
            void grow(float);
            void bloom(string);
            void transform(string);
            string getName(){
                return name;
            }
            string getColor(){
                return color;
            }
            string getShape(){
                return shape;
            }
            float getHeight(){
                return height;
            }
    };

    class Gardener{
        private:
            int MaxPlant;
            Plant plants[10];
            int numPlants = 0;
        public:
            Gardener();
            Gardener(int);
            void nurture(Plant&, float);
            void nurture(Plant*, string);
            void analyze(Plant);
            void addPlant(Plant);
            Plant* findPlant(string);
    };
}

# endif