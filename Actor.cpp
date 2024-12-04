#include "Actor.h"
#include "StudentWorld.h"

// ============================== TUNNEL MAN CLASS ============================== //

void Tunnelman:: doSomething() {
    if (!isActive()) return;
    movement();
}

void Tunnelman:: movement() {
    // Account for other keys like WASD?
    int key;

    if (getWorld()->getKey(key)) {
        int x = getX(); int y = getY();

        switch (key) {
            case KEY_PRESS_LEFT:
                if (x > 0) {
                    setDirection(left);
                    x -= 1;
                }
                break;
            
            case KEY_PRESS_RIGHT:
                if (x < VIEW_WIDTH - 4) {
                    setDirection(right);
                    x += 1;
                }
                break;

            case KEY_PRESS_UP:
                if (y < VIEW_HEIGHT) {
                    setDirection(up);
                    y += 1;
                }
                break;

            case KEY_PRESS_DOWN:
                if (y > 0) {
                    setDirection(down);
                    y -= 1;
                }
                break;

            default: break;
        }

        getWorld()->removeEarth(x, y);
        moveTo(x, y);
    }
}


