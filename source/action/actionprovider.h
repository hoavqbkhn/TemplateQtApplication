#ifndef ACTIONPROVIDER1_H
#define ACTIONPROVIDER1_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QUrl>
#include <QStringList>
#include <QVariantMap>

class ActionProvider final : public QObject
{

        Q_OBJECT
    public:
        static ActionProvider& instance()
        {
            static ActionProvider self;
            return self;
        }
        Q_INVOKABLE void exitApplication(QVariantMap data);





    private:
        ActionProvider() = default;
        ActionProvider(const ActionProvider&) = delete;
        ActionProvider(ActionProvider&&) = delete;
        ActionProvider& operator=(const ActionProvider&) = delete;
        ActionProvider& operator=(ActionProvider &&) = delete;
        ~ActionProvider() = default;
};

#endif // ACTIONPROVIDER_H
