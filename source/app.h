#ifndef KIAPP_H
#define KIAPP_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSharedPointer>
#include "common.h"
#include "action/actionprovider.h"
#include "flux/dispatcher.h"
#include "middleware/middleware.h"
#include "processor/mainbusinessprocessor.h"
#include "store/appstore.h"
class App: public QObject
{

        Q_OBJECT
    public:
        static App& instance()
        {
            return App::self;
        }

        virtual ~App();
        /**
         * @brief initAllSystem
         * init all component of system
         * this function call all init function below
         */
        void initAllSystem();
        /**
         * @brief initNewObject
         * create all middleware, processor, business thread ...
         */
        void initNewObject();
        /**
         * @brief initQmlAccession
         */
        void initQmlAccession();
        /**
         * @brief initStoreAndMiddlewareRegistration
         * register store and middleware in to dispatcher
         */
        void initStoreAndMiddlewareRegistration();
        /**
         * @brief initSignalSlotConnection
         * connect signal from middleware to others
         */
        void initSignalSlotConnection();

        /**
         * @brief initSystemBusiness
         * start business
         */
        void initSystemBusiness();
    private:
        App();
        static App self;
        QSharedPointer<MiddileWare> mAppMiddleware {nullptr};
        QSharedPointer<MainBusinessProcessor> mMainBusinessProcessor {nullptr};
};

#endif // KIAPP_H
