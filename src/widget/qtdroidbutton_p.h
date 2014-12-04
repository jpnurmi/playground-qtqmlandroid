#ifndef QTDROIDBUTTON_P_H
#define QTDROIDBUTTON_P_H

#include "qtdroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidButton : public QtDroidTextView
{
    Q_OBJECT

public:
    explicit QtDroidButton(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDBUTTON_P_H
