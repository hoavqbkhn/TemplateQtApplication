#include "middleware.h"

MiddileWare:: MiddileWare()
{
}

MiddileWare::~ MiddileWare()
{
}

QSharedPointer<vtx::flux::Action>  MiddileWare::process(const QSharedPointer<vtx::flux::Action>& action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::ExitApplication:
            emit signalDispatchActionToBusiness(action);
            return QSharedPointer<vtx::flux::Action>(new vtx::flux::Action(ActionType::None_Action, QVariant()));

        default:
            return action;
    }
}

void MiddileWare::dispatchActionTemplate()
{
    vtx::flux::Dispatcher::instance().dispatch(new vtx::flux::Action(ActionType::DispatchActionTemplate, QVariant()));
}





