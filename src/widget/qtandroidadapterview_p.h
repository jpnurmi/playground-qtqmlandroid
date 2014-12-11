#ifndef QTANDROIDADAPTERVIEW_P_H
#define QTANDROIDADAPTERVIEW_P_H

#include "qtandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidBaseAdapter;

class QtAndroidAdapterView : public QtAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidBaseAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QtAndroidAdapterView(QtAndroidView *parent = 0);

    QtAndroidBaseAdapter *adapter() const;
    void setAdapter(QtAndroidBaseAdapter *adapter);

public Q_SLOTS:
    void setSelection(int position);

Q_SIGNALS:
    void adapterChanged();
    void click(int position);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onItemClick(JNIEnv *env, jobject object, jlong instance, jint position);

private:
    QAndroidJniObject m_listener;
    QtAndroidBaseAdapter *m_adapter;
};

QT_END_NAMESPACE

#endif // QTANDROIDADAPTERVIEW_P_H