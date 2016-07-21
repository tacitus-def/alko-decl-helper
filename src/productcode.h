#ifndef PRODUCTCODE_H
#define PRODUCTCODE_H

#include <QString>

class ProductCode
{
public:
    ProductCode(ushort code, ushort declaration, bool licensed, QString title);

    ushort getCode() const;
    void setCode(const ushort &value);

    ushort getDeclaration() const;
    void setDeclaration(const ushort &value);

    bool getLicensed() const;
    void setLicensed(bool value);

    QString getTitle() const;
    void setTitle(const QString &value);

private:
    ushort code;
    ushort declaration;
    bool licensed;
    QString title;
};

#endif // PRODUCTCODE_H
