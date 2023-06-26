#include "base_model.h"

namespace models {

BaseModel::BaseModel(QObject *parent)
    : QObject{parent}
{
}
bool BaseModel::field_exists(QString name) {
    return fields.count(name) != 0;
}
const std::map<QString, FieldType> BaseModel::fields{};
void BaseModel::set(QString name, QVariant value) {
    if (!field_exists(name) && undeclared_policy == UNDECLARED_POLICY::ERROR)
    {
        throw std::runtime_error("undesclared field '" + name.toStdString() + "'");
    }
    values[name] = value;
}
} // namespace models
