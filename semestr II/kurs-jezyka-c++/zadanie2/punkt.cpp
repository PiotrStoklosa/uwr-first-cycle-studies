#include "punkt.hpp"
#include "wektor.hpp"

punkt::punkt(punkt &p): x(p.x), y(p.y){};

punkt::punkt(punkt p, wektor w): x(p.x+w.dx), y(p.y+w.dy){};

punkt::punkt(const double ws1, const double ws2): x(ws1), y(ws2){};
