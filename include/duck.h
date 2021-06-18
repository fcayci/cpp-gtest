#ifndef DUCK_H_
#define DUCK_H_

#include <iostream>
#include <vector>
#include <memory>

struct Speed
{
    int x;
    int y;
    Speed(int _x, int _y) : x(_x), y(_y) {std::cout << "Speed in\n";};
    ~Speed() {std::cout << "Speed out\n";};
};


class Move
{
    protected:
        double pos {0};
        double height {0};

    public:
        virtual ~Move() = default;
        virtual void step() = 0;
        virtual std::pair<int, int> getSpeed() = 0;
        virtual void setSpeed(int, int) = 0;
        virtual double getHeight() = 0;
        virtual void setHeight(double) = 0;

        double getLocation();
};


class Fly : public Move
{
    private:
        static int initialized;
        static std::shared_ptr<Speed> speed;

    public:

        Fly();
        ~Fly();

        void step() override;
        std::pair<int, int> getSpeed() override;
        void setSpeed(int, int) override;
        double getHeight() override;
        void setHeight(double) override;
};


class Walk : public Move
{
   private:
        static int initialized;
        static std::shared_ptr<Speed> speed;

    public:
        Walk();
        ~Walk();

        void step() override;
        std::pair<int, int> getSpeed() override;
        void setSpeed(int, int) override;
        double getHeight() override;
        void setHeight(double) override;
};


class Duck
{
    public:
        const int wings {2};
        const int legs {2};

        Duck();
        Duck(int);
        ~Duck();

        Move* setupMove();

        void setID(int);
        int getID();
        void quack();
        void move();
        double getLocation();
        std::pair<int, int> getSpeed();
        void setSpeed(int, int);

    private:
        Move* m;
        static int _c;
        int id {0};

};


class Raft
{
    public:
        Raft();
        ~Raft();

        void sing();
        void move();
        void move(int);
        std::vector<double> getLocations();
        std::vector<std::pair<int, int>> getSpeeds();
        void deleteDuck(int);

    private:
        // std::vector<Duck*> ducks;
        std::vector<std::unique_ptr<Duck>> ducks;
};

#endif /* DUCK_H_ */
