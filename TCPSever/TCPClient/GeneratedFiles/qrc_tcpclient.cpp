/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.5.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // E:/Documents/Visual Studio 2013/Projects/QT/QTTest/TCPSever/TCPClient/tcpclient.qrc
  0x0,0x0,0x0,0x65,
  0x3c,
  0x52,0x43,0x43,0x3e,0xa,0x20,0x20,0x20,0x20,0x3c,0x71,0x72,0x65,0x73,0x6f,0x75,
  0x72,0x63,0x65,0x20,0x70,0x72,0x65,0x66,0x69,0x78,0x3d,0x22,0x2f,0x54,0x43,0x50,
  0x43,0x6c,0x69,0x65,0x6e,0x74,0x22,0x3e,0xa,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
  0x20,0x3c,0x66,0x69,0x6c,0x65,0x3e,0x74,0x63,0x70,0x63,0x6c,0x69,0x65,0x6e,0x74,
  0x2e,0x71,0x72,0x63,0x3c,0x2f,0x66,0x69,0x6c,0x65,0x3e,0xa,0x20,0x20,0x20,0x20,
  0x3c,0x2f,0x71,0x72,0x65,0x73,0x6f,0x75,0x72,0x63,0x65,0x3e,0xa,0x3c,0x2f,0x52,
  0x43,0x43,0x3e,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // TCPClient
  0x0,0x9,
  0x4,0xa2,0x4d,0x54,
  0x0,0x54,
  0x0,0x43,0x0,0x50,0x0,0x43,0x0,0x6c,0x0,0x69,0x0,0x65,0x0,0x6e,0x0,0x74,
    // tcpclient.qrc
  0x0,0xd,
  0x1,0x1a,0x1c,0xa3,
  0x0,0x74,
  0x0,0x63,0x0,0x70,0x0,0x63,0x0,0x6c,0x0,0x69,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x71,0x0,0x72,0x0,0x63,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/TCPClient
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/TCPClient/tcpclient.qrc
  0x0,0x0,0x0,0x18,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_tcpclient)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_tcpclient)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_tcpclient)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_tcpclient)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_tcpclient)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_tcpclient)(); }
   } dummy;
}