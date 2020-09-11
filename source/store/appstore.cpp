#include "appstore.h"
AppStore* AppStore::instance = NULL;
AppStore::AppStore()
{

}

AppStore::~AppStore()
{
}

AppStore* AppStore::getInstance()
{
    if (instance == NULL)
    {
        instance = new AppStore();
    }

    return instance;
}

void AppStore::process(const QSharedPointer<vtx::flux::Action>& action)
{
    switch (action->getType<ActionType>())
    {

        default:
            break;
    }
}
