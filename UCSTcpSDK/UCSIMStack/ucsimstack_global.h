#ifndef UCSPROTOCALSTACK_GLOBAL_H
#define UCSPROTOCALSTACK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UCSPROTOCALSTACK_LIBRARY)
#  define UCSPROTOCALSTACKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define UCSPROTOCALSTACKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UCSPROTOCALSTACK_GLOBAL_H
