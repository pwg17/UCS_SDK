﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QStackedLayout>
#include "baseWindow.h"
#include "trayiconmenu/trayIconMenu.h"
#include "LeftNavigatorBarWidget.h"
#include "CallWidget.h"
#include "ContactWidget.h"
#include "IMWidget.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    static MainWindow* InitInstance();
    static MainWindow *GetInstance() { return s_pMainWnd; }

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool doLogin();

protected:
    static MainWindow* s_pMainWnd;

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void customEvent(QEvent *event) override;

private:
    void initLayout();
    void initTrayMenu();
    void initConnections();
    void initMisc();
    void initNetwork();
    void initDatabase();

    void readSetting();
    void saveSetting();

private slots:
    void onTrayIconActived(QSystemTrayIcon::ActivationReason);
    void onQuitClient();
    void onSwitchPage();
    void onSwitchIMPage(ContactItem contact);

private:
    QSystemTrayIcon m_system_tray;
    TrayIconMenu m_traymenu;
    LeftNavigatorBarWidget *m_pLeftNavBar;
    CallWidget *m_pCallWidget;
    ContactWidget *m_pContactWidget;
    IMWidget *m_pImWidget;
    QStackedLayout *m_pStackedLayout;
};

#endif // MAINWINDOW_H
