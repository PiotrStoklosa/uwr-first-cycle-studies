#include "wektor.hpp"
#ifndef PUNKT
#define PUNKT

class punkt{
public:
    const double x;
    const double y;

    punkt()=default;
    punkt(double, double);
    punkt(punkt,wektor);
    punkt(punkt&);

private:
    punkt operator=(const punkt&) = delete;
};

#endif
