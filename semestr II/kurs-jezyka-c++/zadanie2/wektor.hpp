#ifndef WEKTOR
#define WEKTOR

class wektor{
public:
    const double dx;
    const double dy;

    wektor()=default;
    wektor(double, double);
    wektor (wektor&);
    wektor operator=(const wektor&) = delete;
};

wektor skladanie(wektor, wektor);

#endif
