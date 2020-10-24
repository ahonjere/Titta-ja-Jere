#include "engine.hh"

namespace Game {

    const QString BUS_DATA = ":/offlinedata/offlinedata/final_bus_liteN.json";
    const QString STOP_DATA = ":/offlinedata/offlinedata/full_stations_kkj3.json";

    Engine::Engine() :
        logic_(new CourseSide::Logic),
        mainwindow_(new CourseSide::SimpleMainWindow)
    {
        initGame();

        QObject::connect(&mainwindow_, &CourseSide::SimpleMainWindow::gameStarted,
                         this, &Engine::startGame);
    }

    void Engine::initGame()
    {
        std::shared_ptr<Interface::ICity> icityptr = Interface::createGame();
        logic_.takeCity(icityptr);
        logic_.fileConfig();

        std::shared_ptr<Game::City> cityptr = std::dynamic_pointer_cast<Game::City>(icityptr);
        city_ = cityptr;

        mainwindow_.show();
        QImage img = city_->getBasicBackground();
        mainwindow_.setPicture(img);

    }

    void Engine::startGame()
    {
        logic_.setTime(QTime::currentTime().hour(), QTime::currentTime().minute());
        logic_.finalizeGameStart();

    }
}

