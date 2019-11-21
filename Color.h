#ifndef COLOR_H
#define COLOR_H
#include <math.h>
#include <QColor>

class Color:public QColor
{
public:
    Color():QColor(){}
    Color(int r, int g, int b, int a=255){
        QColor(r,g,b,a);
    }
    int changeBrightness( int value, int brightness) {
        return qBound<int>(0, value + brightness * 255 / 100, 255);
    }
    int changeContrast( int value, int contrast ) {
        return qBound<int>(0, int(( value - 127 ) * contrast / 100 ) + 127, 255 );
    }
    int changeGamma( int value, int gamma ) {
        return qBound<int>(0, int( pow( value / 255.0, 100.0 / gamma ) * 255 ), 255 );
    }
};

#endif // COLOR_H
