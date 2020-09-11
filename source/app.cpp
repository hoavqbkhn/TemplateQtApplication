#include "app.h"
App App::self;
App::App()
{
}

App::~App()
{
}
void App::initAllSystem()
{
    initNewObject();
    initSignalSlotConnection();
    initStoreAndMiddlewareRegistration();
    initQmlAccession();
    initSystemBusiness();
}

void App::initNewObject()
{
    mAppMiddleware = QSharedPointer<MiddileWare>(new MiddileWare());
    mMainBusinessProcessor = QSharedPointer<MainBusinessProcessor>(new MainBusinessProcessor(MAIN_BUSINESS_PROCESSOR_NAME));
    mMainBusinessProcessor->setMiddlewareInterface(mAppMiddleware);
}

void App::initQmlAccession()
{
    qmlRegisterSingletonType<ActionProvider>("Flux", 1, 0, "ActionProvider",
                                             [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        QQmlEngine::setObjectOwnership(&ActionProvider::instance(), QQmlEngine::CppOwnership);
        return &ActionProvider::instance();
    });
    qmlRegisterSingletonType<AppStore>("Flux", 1, 0, "AppStore",
                                         [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        QQmlEngine::setObjectOwnership(AppStore::getInstance(), QQmlEngine::CppOwnership);
        return AppStore::getInstance();
    });
}

void App::initStoreAndMiddlewareRegistration()
{
    vtx::flux::Dispatcher::instance().registerMiddleware(mAppMiddleware);
    vtx::flux::Dispatcher::instance().registerStore(QSharedPointer<vtx::flux::Store>(AppStore::getInstance(), [](vtx::flux::Store*) {}));
}

void App::initSignalSlotConnection()
{
    QObject::connect(mAppMiddleware.get(), &MiddileWare::signalDispatchActionToBusiness, mMainBusinessProcessor.get(), &MainBusinessProcessor::slotReceiveActionFromMiddleware);
}



void App::initSystemBusiness()
{
}


