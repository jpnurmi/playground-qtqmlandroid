/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qnativeandroidscrollview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidScrollView::QNativeAndroidScrollView(QNativeAndroidContext *context) :
    QNativeAndroidFrameLayout(context)
{
}

int QNativeAndroidScrollView::scrollX() const
{
    if (m_scrollX.isNull())
        return 0;
    return m_scrollX;
}

void QNativeAndroidScrollView::setScrollX(int x)
{
    if (updateScrollX(x))
        QtQmlAndroid::callIntMethod(instance(), "setScrollX", x);
}

bool QNativeAndroidScrollView::updateScrollX(int x)
{
    if (m_scrollX.isNull() || m_scrollX != x) {
        m_scrollX = x;
        emit scrollXChanged();
    }
    return false;
}

int QNativeAndroidScrollView::scrollY() const
{
    if (m_scrollY.isNull())
        return 0;
    return m_scrollY;
}

void QNativeAndroidScrollView::setScrollY(int y)
{
    if (updateScrollY(y))
        QtQmlAndroid::callIntMethod(instance(), "setScrollY", y);
}

bool QNativeAndroidScrollView::updateScrollY(int y)
{
    if (m_scrollY.isNull() || m_scrollY != y) {
        m_scrollY = y;
        emit scrollYChanged();
    }
    return false;
}

QAndroidJniObject QNativeAndroidScrollView::onCreate()
{
    return QAndroidJniObject("qt/android/widget/QtNativeScrollView",
                             "(Landroid/content/Context;J)V",
                             ctx().object(),
                             reinterpret_cast<jlong>(this));
}

void QNativeAndroidScrollView::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidFrameLayout::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidScrollView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onScrollChanged", "(JII)V", reinterpret_cast<void *>(onScrollChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidScrollView::onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidScrollView *view = reinterpret_cast<QNativeAndroidScrollView *>(instance);
    if (view) {
        QMetaObject::invokeMethod(view, "updateScrollX", Qt::QueuedConnection, Q_ARG(int, left));
        QMetaObject::invokeMethod(view, "updateScrollY", Qt::QueuedConnection, Q_ARG(int, top));
    }
}

QT_END_NAMESPACE
