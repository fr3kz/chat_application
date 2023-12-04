#include "authpage.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/chat_app/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    authpage *apage = new authpage(&app);
   // chatpage *cpage = new chatpage(&app);
    QQmlContext *context = engine.rootContext();

    context->setContextProperty("authpage", apage);
  //  context->setContextProperty("chatpage", cpage);

    return app.exec();
}
