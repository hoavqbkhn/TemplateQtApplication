#ifndef DTC1MIDDLEWARE_H
#define DTC1MIDDLEWARE_H

#include <QObject>
#include <QString>
#include "logger/logger.h"
#include "flux/action.h"
#include "flux/middleware.h"
#include "flux/dispatcher.h"
#include "action/actiontype.h"
#include "flux/action.h"

using vtx::flux::Action;

class  MiddileWare : public QObject, public vtx::flux::Middleware
{
        Q_OBJECT
    public:
        MiddileWare();
        virtual ~ MiddileWare();
        QSharedPointer<vtx::flux::Action> process(const QSharedPointer<vtx::flux::Action>& action) override;
        void dispatchActionTemplate() ;
    signals:
        void signalDispatchActionToBusiness(QSharedPointer<Action> actionFromMiddleware);

    private:

};

#endif // DTC1MIDDLEWARE_H
