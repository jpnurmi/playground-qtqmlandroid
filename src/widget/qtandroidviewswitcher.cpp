#include "qtandroidviewswitcher_p.h"

QtAndroidViewSwitcher::QtAndroidViewSwitcher(QtAndroidView *parent) : QtAndroidViewAnimator(parent)
{
}

QAndroidJniObject QtAndroidViewSwitcher::onCreate()
{
    return QAndroidJniObject("android/widget/ViewSwitcher",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidViewSwitcher::onInflate()
{
    QtAndroidViewAnimator::onInflate();
}
