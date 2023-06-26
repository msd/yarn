#ifndef VIEWS_EDIT_MATERIAL_H
#define VIEWS_EDIT_MATERIAL_H

#include "base_model.h"

namespace models {

class material : public BaseModel
{
public:
    explicit material(QObject *parent = nullptr);
};

} // namespace models

#endif // VIEWS_EDIT_MATERIAL_H
