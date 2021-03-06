﻿#include "treeItem.h"


TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)
{
    m_pParentItem = parent;
    m_itemData = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem *child)
{
    m_childItems.append(child);
}

TreeItem *TreeItem::child(int row)
{
    return m_childItems.value(row);
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

int TreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant TreeItem::data(int column) const
{
    return m_itemData.value(column);
}

int TreeItem::row() const
{
    if (m_pParentItem)
    {
        return m_pParentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
    }

    return 0;
}

TreeItem *TreeItem::parent()
{
    return m_pParentItem;
}
