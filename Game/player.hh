#ifndef PLAYER_HH
#define PLAYER_HH

#include <QObject>
#include "interfaces/iactor.hh"

#include "core/location.hh"

namespace Game {
    class player : public Interface::IActor
    {
    public:
        player();

        //Actor interface
        std::string getName() const;

        Interface::Location giveLocation() const;
        void move(Interface::Location loc);
        void remove();
        bool isRemoved() const;

    private:
        Interface::Location location_;
        bool removed_;
    };
}


#endif // PLAYER_HH
