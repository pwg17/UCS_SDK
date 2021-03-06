﻿#ifndef MIDLEFTCONTACTTREEMODEL_H
#define MIDLEFTCONTACTTREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "common/util.h"

class TreeItem;

enum CustomRole
{
    MyRole = Qt::UserRole,
    GroupRole = MyRole + 1,
    SexRole = MyRole + 2,
};

class MidLeftContactTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MidLeftContactTreeModel(QObject *parent = 0);
    ~MidLeftContactTreeModel();

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // for a editable model
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // custom functionality:
    void importJSON(QString jsonFile);

private:
    void setupModelData(TreeItem *parent);
    TreeItem *item(TreeItem *item, ContactUtil contract);

public:

private:
    QList<ContactUtil> m_organizationList;
    QList<ContactUtil> m_privateList;
//    QMap<QString, QList> m_listMap;
    TreeItem *m_pRootItem;
};

#endif // MIDLEFTCONTACTTREEMODEL_H
