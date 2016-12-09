#ifndef QQMLANDROIDBOUNCEINTERPOLATOR_P_H
#define QQMLANDROIDBOUNCEINTERPOLATOR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQmlAndroid/private/qtqmlandroidglobal_p.h>
#include <QtQmlAndroid/private/qqmlandroidoptional_p.h>
#include <QtQmlAndroid/private/qqmlandroidinterpolator_p.h>
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidBounceInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidBounceInterpolator(QObject *parent = 0);

Q_SIGNALS:

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
};

QT_END_NAMESPACE

#endif // QQMLANDROIDBOUNCEINTERPOLATOR_P_H
