#ifndef DLL001_GLOBAL_H
#define DLL001_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLL001_LIBRARY)
#  define DLL001SHARED_EXPORT Q_DECL_EXPORT
#else
#  define DLL001SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DLL001_GLOBAL_H
