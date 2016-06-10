#ifndef MECZDRUZYNOWY_H
#define MECZDRUZYNOWY_H



#include "mecz.h"
#include "druzyna.h"

class MeczDruzynowy : public Mecz {
protected:
    QString m_Gospodarz;
    QString m_Gosc;
public:
    MeczDruzynowy();
    MeczDruzynowy(QString Gospodarz, QString Gosc, QString Sedzia);
    QString Gospodarz() const;
    QString Gosc() const;
};

#endif // MECZDRUZYNOWY_H
