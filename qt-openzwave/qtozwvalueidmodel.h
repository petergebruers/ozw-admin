#ifndef QTOZWVALUEIDMODEL_H
#define QTOZWVALUEIDMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QBitArray>


struct QTOZW_ValueIDList {
    QList< uint32_t > values;
    QStringList labels;
    QString selectedItem;
};
QDataStream & operator<<( QDataStream & dataStream, const QTOZW_ValueIDList & list );
QDataStream & operator>>(QDataStream & dataStream, QTOZW_ValueIDList & list);

Q_DECLARE_METATYPE(QTOZW_ValueIDList);

struct QTOZW_ValueIDBitSet {
    QBitArray values;
    QBitArray mask;
    QMap<uint32_t, QString> label;
    QMap<uint32_t, QString> help;
};
QDataStream & operator<<( QDataStream & dataStream, const QTOZW_ValueIDBitSet & list );
QDataStream & operator>>(QDataStream & dataStream, QTOZW_ValueIDBitSet & list);

Q_DECLARE_METATYPE(QTOZW_ValueIDBitSet);


class QTOZW_ValueIds : public QAbstractTableModel {
    Q_OBJECT
public:
    enum ValueIdColumns {
        Label,
        Value,
        Units,
        Min,
        Max,
        Type,
        Instance,
        CommandClass,
        Index,
        Node,
        Genre,
        Help,
        ValueIDKey,
        ValueFlags,
        ValueIdCount
    };
    Q_ENUM(ValueIdColumns)
    enum ValueIdGenres {
        Basic,
        User,
        Config,
        System,
        GenreCount
    };
    Q_ENUM(ValueIdGenres)
    enum ValueIdTypes {
        Bool,
        Byte,
        Decimal,
        Int,
        List,
        Schedule,
        Short,
        String,
        Button,
        Raw,
        BitSet,
        TypeCount
    };
    Q_ENUM(ValueIdTypes)
    enum ValueIDFlags {
        ReadOnly,
        WriteOnly,
        ValueSet,
        ValuePolled,
        ChangeVerified,
        FlagCount
    };
    Q_ENUM(ValueIDFlags)
    QTOZW_ValueIds(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
protected:
    QVariant getValueData(uint64_t, ValueIdColumns);
    int32_t getValueRow(uint64_t _node);

    QMap<int32_t, QMap<ValueIdColumns, QVariant> > m_valueData;
};

class QTOZW_ValueIds_internal : public QTOZW_ValueIds {
    Q_OBJECT
public:
    QTOZW_ValueIds_internal(QObject *parent=nullptr);
public Q_SLOTS:
    void addValue(uint64_t _vidKey);
    void setValueData(uint64_t _vidKey, QTOZW_ValueIds::ValueIdColumns column, QVariant data);
    void setValueFlags(uint64_t _vidKey, QTOZW_ValueIds::ValueIDFlags _flags, bool _value);
    void delValue(uint64_t _vidKey);
    void delNodeValues(uint8_t _node);
    void resetModel();
};



#endif // QTOZWVALUEIDMODEL_H
