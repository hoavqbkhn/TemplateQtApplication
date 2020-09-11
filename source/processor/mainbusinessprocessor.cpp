#include "mainbusinessprocessor.h"


MainBusinessProcessor::MainBusinessProcessor(const QString& processorName)
    : ProcessorAbstract(processorName)
{
}

MainBusinessProcessor::~MainBusinessProcessor()
{
}




void MainBusinessProcessor::processAction(QSharedPointer<Action> action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::ExitApplication:
            {
                emit signalQuit();
                break;
            }

        default:
            break;
    }
}
void MainBusinessProcessor::slotReceiveActionFromMiddleware(QSharedPointer<Action> actionFromMiddleware)
{
    processAction(actionFromMiddleware);
}
void MainBusinessProcessor::setMiddlewareInterface(QSharedPointer<MiddileWare> middlewareInterface)
{
    mMiddlewareInterface = middlewareInterface;
}
