#include "actionprovider.h"
#include "flux/action.h"
#include "flux/dispatcher.h"
#include "actionprovider.h"
#include "actiontype.h"
#include "logger/logger.h"



void ActionProvider::exitApplication(QVariantMap data)
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::ExitApplication, QVariant(data)));
}

