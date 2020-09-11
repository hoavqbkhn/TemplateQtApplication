#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "app.h"
#include "common.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qRegisterMetaType<QSharedPointer<Action>>("QSharedPointer<Action>");
    App::instance().initAllSystem();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    qRegisterMetaType<QSharedPointer<InnerMessage>>("QSharedPointer<InnerMessage>");

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
