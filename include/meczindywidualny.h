#ifndef MECZINDYWIDUALNY_H
#define MECZINDYWIDUALNY_H

#include "mecz.h"
#include "zawodnik.h"

class MeczIndywidualny : public Mecz {
protected:
    QString m_Gospodarz;
    QString m_Gosc;
public:
    MeczIndywidualny(QString Gospodarz, QString Gosc, QString Sedzia);
    QString Gospodarz() const;
    QString Gosc() const;
};

#endif // MECZINDYWIDUALNY_H
