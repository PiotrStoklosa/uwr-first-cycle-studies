#include "wektor.hpp"

wektor::wektor(wektor &w): dx(w.dx), dy(w.dy){};

wektor::wektor(const double ws1, const double ws2): dx(ws1), dy(ws2){};

wektor skladanie(wektor w1, wektor w2){

    wektor nowy(w1.dx + w2.dx, w2.dy + w2.dy);
    return nowy;
}
