#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;

// ============================== ACTOR BASE CLASS ============================== // 

class Actor : public GraphObject 
{

    public:
        // Constructor
        Actor(StudentWorld* world, int imageID, int startX, int startY, Direction dir, float size = 1.0, int depth = 0) 
             : GraphObject(imageID, startX, startY, dir, size, depth),
               m_world(world), m_active(true) { setVisible(true); }

        // Destructor
        virtual ~Actor() {}

        // Function for all objects to override to do something
        virtual void doSomething() = 0;

        // Getters and setters
        bool isActive() const { return m_active; }
        void setInactive() { m_active = false; };
        StudentWorld* getWorld() { return m_world; }

    private:
        StudentWorld* m_world;
        bool m_active;
};

// ============================== TUNNELMAN CLASS ============================== // 

class Tunnelman : public Actor 
{

    public: 
        // Constructor
        Tunnelman(StudentWorld* world)
            : Actor(world, TID_PLAYER, 30, 60, right, 1.0, 0) {}

        // Destructor
        virtual ~Tunnelman() {};
        
        void doSomething() override;

    private:
        int m_health;
        int m_gold;
        int m_squirts;

        void movement();

};

// ============================== EARTH CLASS ============================== //

class Earth : public Actor {
    public:
        // Constructor
        Earth(StudentWorld* world, int startX, int startY) 
            : Actor(world, TID_EARTH, startX, startY, right, 0.25, 3) {}

        // Destructor 
        virtual ~Earth() {}

        virtual void doSomething() override {}
};

// ============================== PROTESTORS CLASS ============================== //

class Protestor : public Actor {
    public:
        // Constructor

        // Destructor

};

class RegularProtestor : public Protestor {
    public:
        // Constructor

        // Destructor

};

class HardcoreProtestor : public Protestor {
    public:
        // Constructor

        // Destructor
};

// ============================== GOODIES CLASS ============================== //

class Goodie : public Actor {
    public:
        // Constructor

        // Destructor
        
};

class SonarKit : public Goodie {
    public:
        // Constructor

        // Destructor
};

class WaterPool : public Goodie {
    public:
        // Constructor

        // Destructor
};

// ============================== PICKUP-ABLE ITEMS ============================== //

class Barrel : public Goodie {
    public:
        // Constructor

        // Destructor
};

class GoldNugget : public Goodie {
    public:
        // Constructor

        // Destructor
};


// ============================== OTHER CLASSES ============================== //

class Boulder : public Actor {

};

class Squirt : public Actor {

};

#endif // ACTOR_H_
