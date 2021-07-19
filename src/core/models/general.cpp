
#include "general.h"

namespace core::model {

    Position::Position() : Position(0, 0) {}

    Position::Position(float x, float y) : x(x), y(y) {}

    Health::Health(double total) : total(total) {}
}