#ifndef MAINBUSINESSPROCESSOR_H
#define MAINBUSINESSPROCESSOR_H

#include <QObject>
#include <QSharedPointer>
#include <QTimer>
#include "common.h"
#include "flux/action.h"
#include "action/actiontype.h"
#include <QDateTime>
#include <QMap>
#include "middleware/middleware.h"
#include <QDateTime>
#include <QMap>
#include "processorabstract.h"
using vtx::flux::Action;
class MainBusinessProcessor: public ProcessorAbstract
{
        Q_OBJECT
    public:
        MainBusinessProcessor(const QString& processorName);

        virtual ~MainBusinessProcessor();

        /**
         * @brief processAction
         * @param action
         * process action from user in worker thread
         */
        void processAction(QSharedPointer<Action> action);

        void setMiddlewareInterface(QSharedPointer<MiddileWare> middlewareInterface);

    public slots:
        void slotReceiveActionFromMiddleware(QSharedPointer<Action> actionFromMiddleware);

    signals:
        void signalQuit();

    private:
        QSharedPointer<MiddileWare> mMiddlewareInterface{nullptr};

};

#endif // MAINBUSINESSPROCESSOR_H
