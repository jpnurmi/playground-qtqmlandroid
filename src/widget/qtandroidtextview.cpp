#include "qtandroidtextview_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidcolor_p.h"

QtAndroidTextView::QtAndroidTextView(QtAndroidView *parent) : QtAndroidView(parent)
{
}

QString QtAndroidTextView::text() const
{
    return m_text;
}

void QtAndroidTextView::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        QtAndroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QtAndroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QtAndroidColor::BLACK; // TODO
    return m_textColor.value();
}

void QtAndroidTextView::setTextColor(int color)
{
    if (color != textColor()) {
        m_textColor = color;
        QtAndroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QtAndroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize.value();
}

void QtAndroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        QtAndroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QtAndroidTextView::hint() const
{
    return m_hint;
}

void QtAndroidTextView::setHint(const QString &hint)
{
    if (m_hint != hint) {
        m_hint = hint;
        QtAndroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

QAndroidJniObject QtAndroidTextView::onCreate()
{
    return QAndroidJniObject("android/widget/TextView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidTextView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidView::onInflate(instance);

    if (!m_text.isNull())
        instance.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_text).object());
    if (!m_textColor.isNull())
        instance.callMethod<void>("setTextColor", "(I)V", m_textColor.value());
    if (!m_textSize.isNull())
        instance.callMethod<void>("setTextSize", "(F)V", m_textSize.value());
    if (!m_hint.isNull())
        instance.callMethod<void>("setHint", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_hint).object());
}
