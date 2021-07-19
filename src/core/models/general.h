//
// Created by yacopsae on 06/10/2020.
//

#ifndef PLATFORMER_GENERAL_H
#define PLATFORMER_GENERAL_H

namespace core::model {

    class Position {
    private:
        float x, y;
    public:
        Position();
        Position(float x, float y);

        float getX() const {
            return x;
        }

        float getY() const {
            return y;
        }

        void addX(float _x) {
            x += _x;
        }

        void addY(float _y) {
            y += _y;
        }
    };

    class Health {
    private:
        double total;
    public:
        Health(double d);
    };
}
#endif //PLATFORMER_GENERAL_H
