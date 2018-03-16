﻿#ifndef UPLUSLOGIN_H
#define UPLUSLOGIN_H

#include <qglobal.h>
#include <QObject>
#include <QLineEdit>
#include "BaseDialog.h"
#include "MyTitleBar.h"
#include "UPlusRestApi.h"
#include "HttpDownloadPicture.h"

class UPlusLogin : public QDialog
{
    Q_OBJECT

public:
    explicit UPlusLogin(QWidget *parent = 0);
    ~UPlusLogin();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void customEvent(QEvent *event) override;

private:
    void initLayout();
    void initConnections();
    void readSettings();

    void onLoginSuccess();

    // test begin
    void uploadHeaderImg();
    void downloadHeadImg();
    // test end

private slots:
    void onBtnClosed();
    void onBtnMin();
    void onBtnLogin();

    void onLoginReply(QByteArray replyData, int code);
    void onReLoginReply(QByteArray replyData, int code);

    // test
    void onUploadHeaderImgReply(QByteArray replyData, int code);
    void onDownloadHeadImg(QString filename);

private:
    MyTitleBar  *m_titleBar;
    QPushButton *m_pBtnLoginOn;
    QLineEdit *m_pLineUserName;
    QLineEdit *m_pLinePassword;
    QLabel *m_pLoginTip;
    UPlusRestApi *m_pRestApi;
    bool m_doReLogin;

    HttpDownloadPicture *m_pDownloadPic;
};

#endif // UPLUSLOGIN_H