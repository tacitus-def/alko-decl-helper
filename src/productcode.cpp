#include "productcode.h"

ProductCode::ProductCode(ushort code, ushort declaration, bool licensed, QString title)
{
    this->code = code;
    this->declaration = declaration;
    this->licensed = licensed;
    this->title = title;
}

QString ProductCode::getTitle() const
{
    return title;
}

void ProductCode::setTitle(const QString &value)
{
    title = value;
}

bool ProductCode::getLicensed() const
{
    return licensed;
}

void ProductCode::setLicensed(bool value)
{
    licensed = value;
}

ushort ProductCode::getDeclaration() const
{
    return declaration;
}

void ProductCode::setDeclaration(const ushort &value)
{
    declaration = value;
}

ushort ProductCode::getCode() const
{
    return code;
}

void ProductCode::setCode(const ushort &value)
{
    code = value;
}
