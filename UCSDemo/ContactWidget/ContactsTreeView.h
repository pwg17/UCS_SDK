﻿#ifndef CONTRACTS_TREE_VIEW_H
#define CONTRACTS_TREE_VIEW_H

#include <QFutureWatcher>
#include <QtConcurrent>
#include "common/qtheaders.h"
#include "ContactTreeItemModel.h"
#include "UPlusRestApi.h"

class ContactsTreeView : public QTreeView
{
    Q_OBJECT

public:
    explicit ContactsTreeView(QWidget *parent = 0);
    virtual ~ContactsTreeView();

    void doUpdateContacts();

    static ContactItem downloadHeader(const ContactItem &contact);

    ContactList contactList() const;

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    void init();
    void initConnection();
    void initMenu();
    void loadStyleSheet();

    void parseContactData();
    void startDownloadHeader();

signals:
    void sigItemClicked(ContactItem);

public slots:
    ///< item slot >
    void onItemClicked(QModelIndex index);
    void onItemDoubleClicked(QModelIndex index);
    void onItemPressed(QModelIndex index);

    ///< menu action >
    void onAddGroupAction(bool checked);
    void onDeleteGroupAction(bool checked);
    void onAddContactAction(bool checked);
    void onRemoveContactAction(bool checked);
    void onSendMessageAction(bool checked);
    void onAudioCallAction(bool checked);
    void onVideoCallAction(bool checked);

    ///< contact update action >
    void onUpdateContactsReply(QByteArray data, int code);

    ///< contact header download finish >
    void onHeaderReady(int index);

private:
    ContactTreeItemModel *m_pContactModel;
    QMenu *m_pGroupMenu;
    QMenu *m_pPersonMenu;

    UPlusRestApi *m_pRestApi;
    QByteArray m_contactData;

    ContactList m_contactList;
    QString m_contactVer;

    QFutureWatcher<ContactItem> *m_pDownloadWatcher;
};

#endif // MIDLEFTCONTRACTSTREEVIEW_H
