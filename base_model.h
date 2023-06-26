#ifndef MODELS_BASEMODEL_H
#define MODELS_BASEMODEL_H

#include <set>
#include <concepts>

#include <QObject>
#include <QVariant>

namespace models {

enum class UNDECLARED_POLICY {
    CREATE_NEW, ERROR
};

enum class FieldType
{
    INVALID = -1, INT = 0, REAL, STRING
};

template <typename T>
concept is_field_convertible = requires(T t) {
{
    t.value() } -> std::same_as<typename T::value_type>;
};

//template <typename ValueType>
//class ModelField
//{
//public:
////    using value_type = ValueType;
//    ModelField() {}
//    ModelField(ModelField &other): name{other.name}, type{other.type} {}
//    ModelField(QString name, FieldType type) : name{name}, type{type} {}
//    QString name{""};
//    FieldType type{FieldType::INVALID};
//    void *value = nullptr;
//    virtual void init() = 0;
//};

/*template <typename ValueType>
class OptionalField : public ModelField<std::optional<ValueType>>
{
public:
    ValueType &value()
    {
        return this->value;
    }
    ValueType &operator *()
    {
        return value();
    }
    bool has_value()
    {
        return static_cast<bool>(this->value);
    }
    operator bool()
    {
        return has_value();
    }
};*/

//class RealField: ModelField<double> {};

//class StringField : ModelField<QString> {};

//class IntField : ModelField
//{
//    IntField(QString name) : ModelField(name, FieldType::INT) {
//        init();
//    }
//    void init()
//    {
//        value = new int;
//    }
//    void set(int x)
//    {
//        *reinterpret_cast<int*>(value) = x;
//    }
//    int get()
//    {
//        return *reinterpret_cast<int*>(value);
//    }
//    static int empty_init_value()
//    {
//        return 0;
//    }
//};

//class RealField: ModelField
//{
//    void init()
//    {
//        value = new double;
//    }
//    void set(double x)
//    {
//        *reinterpret_cast<double*>(value) = x;
//    }
//    double get()
//    {
//        return *reinterpret_cast<double*>(value);
//    }
//    static double empty_init_value()
//    {
//        return 0.0;
//    }
//};

//template <class T>
//T empty_init_value();

//template <>
//int empty_init_value()
//{
//    return 0;
//}
//template <>
//double empty_init_value()
//{
//    return 0.0;
//}

//template <>
//QString empty_init_value()
//{
//    return QString{""};
//}

//template <typename T>
//concept has_get_set = requires (T t)
//{
//    { t.get() } -> std::same_as<T>;
//    { t.set(std::declval<T>()) };
//    { T::empty_init_value() } -> std::same_as<decltype(T::value_type)>;
//};


//class StringField: ModelField
//{
//    void init()
//    {
//        value = new QString;
//    }
//    void set(QString x)
//    {
//        *reinterpret_cast<QString*>(value) = x;
//    }
//    QString get()
//    {
//        return *reinterpret_cast<QString*>(value);
//    }
//    static QString empty_init_value()
//    {
//        return "";
//    }
//};

class BaseModel : public QObject
{
    Q_OBJECT
public:
    explicit BaseModel(QObject *parent = nullptr);
    QString primary_key_field = "id";
    UNDECLARED_POLICY undeclared_policy = UNDECLARED_POLICY::CREATE_NEW;
    const static std::map<QString, FieldType> fields;
    std::map<QString, QVariant> values;
    bool field_exists(QString name);
    void set(QString name, QVariant value);

    void init_values()
    {
        for (auto &[field_name, field] : fields)
        {
            values[field_name] = QVariant{};
        }
    }
    auto & get(QString name)
    {
        if (field_exists(name))
        {
            return values.find(std::move(name))->second;
        }
        throw std::runtime_error("does not have such field '"+ name.toStdString() + "'");
    }
signals:
    void field_changed(BaseModel* model, QString name, QString new_value);
    void request_update(BaseModel*);
};

} // namespace models

#endif // MODELS_BASEMODEL_H
