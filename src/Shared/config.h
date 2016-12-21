#ifndef CONFIG_H
#define CONFIG_H

#include <qglobal.h>

#define VERSION QString("2.6.3")

static const quint16 PROTOCOL_VERSION = 3;
static const quint16 PROTOCOL_SUBVERSION = 3;
static const quint16 CLIENT_VERSION_NUMBER = 2630;
static const int UPDATE_ID = 4;

#ifdef Q_OS_LINUX
#define OS "linux"
#elif defined(Q_OS_WIN)
#define OS "windows"
#elif defined(Q_OS_MAC)
#define OS "mac"
#elif defined(Q_OS_FREEBSD)
#define OS "freebsd"
#elif defined(Q_OS_SOLARIS)
#define OS "solaris"
#endif

#endif // CONFIG_H
