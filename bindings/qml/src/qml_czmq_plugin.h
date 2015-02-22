/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_CZMQ_PLUGIN_H
#define QML_CZMQ_PLUGIN_H

#include <QQmlExtensionPlugin>
#include <qqml.h>

class QmlZframe;
class QmlZframeAttached;
class QmlZloop;
class QmlZloopAttached;
class QmlZmsg;
class QmlZmsgAttached;
class QmlZhash;
class QmlZhashAttached;
class QmlZlist;
class QmlZlistAttached;

#include "QmlZframe.h"
#include "QmlZloop.h"
#include "QmlZmsg.h"
#include "QmlZhash.h"
#include "QmlZlist.h"

class QmlCZMQPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA (IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes (const char *uri)
    {
        qmlRegisterType<QmlZframe> (uri, 1, 0, "QmlZframe");
        qmlRegisterType<QmlZframeAttached>();
        qmlRegisterType<QmlZloop> (uri, 1, 0, "QmlZloop");
        qmlRegisterType<QmlZloopAttached>();
        qmlRegisterType<QmlZmsg> (uri, 1, 0, "QmlZmsg");
        qmlRegisterType<QmlZmsgAttached>();
        qmlRegisterType<QmlZhash> (uri, 1, 0, "QmlZhash");
        qmlRegisterType<QmlZhashAttached>();
        qmlRegisterType<QmlZlist> (uri, 1, 0, "QmlZlist");
        qmlRegisterType<QmlZlistAttached>();
    };
};

#endif

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/