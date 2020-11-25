#include "restaurantgraphics.hh"
#include <QImage>
#include <memory>
#include <QDebug>


const QString RESTAURANT_FILE = ":/images/mcdonalds.png";
const int WIDTH = 20;
const int HEIGHT = 20;

namespace Game {

RestaurantGraphics::RestaurantGraphics(int x, int y, std::string type): x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_,y_));
    assert(picture_.load(RESTAURANT_FILE));
    picture_ = picture_.scaled(WIDTH, HEIGHT);
    setPixmap(picture_);

}

RestaurantGraphics::~RestaurantGraphics()
{

}

void RestaurantGraphics::setCoord(int x, int y)
{

}


}
