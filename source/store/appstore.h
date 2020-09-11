#ifndef KIAPPSTORE_H
#define KIAPPSTORE_H
#include <QSharedPointer>
#include <QTimer>
#include <QDateTime>
#include "logger/logger.h"
#include <QObject>
#include "flux/action.h"
#include "flux/store.h"
#include "action/actiontype.h"
#include "flux/dispatcher.h"
#include "common.h"
class AppStore : public QObject, public vtx::flux::Store
{
        Q_OBJECT

    public:
        ~AppStore();
        static AppStore* getInstance();


        void process(const QSharedPointer<vtx::flux::Action>& action) Q_DECL_OVERRIDE;

    signals:

    private:
        AppStore();
        static AppStore* instance;

};

#endif // KIAPPSTORE_H
