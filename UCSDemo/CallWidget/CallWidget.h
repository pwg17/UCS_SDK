﻿#ifndef CALLWIDGET_H
#define CALLWIDGET_H

#include <QWidget>
#include <qglobal.h>
#include "BaseWidget.h"
#include "searchLineEdit.h"
#include "TopBarWidget.h"
#include "CallListView.h"
#include "DialWidget.h"

class CallWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit CallWidget(QWidget *parent = 0);
    void updateLogin();

signals:

public slots:

private:
    void initLayout();
    void initConnections();

private:
    TopBarWidget *m_pTitleBar;
    SearchLineEdit *m_pSearchEdit;
    DialWidget *m_pDialWidget;
    CallListView *m_pCallListView;
};

#endif // CALLWIDGET_H
