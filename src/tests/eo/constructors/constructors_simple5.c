#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "Eo.h"
#include "constructors_mixin.h"
#include "constructors_simple5.h"

#define MY_CLASS SIMPLE5_CLASS

static void
_destructor(Eo *obj, void *class_data EINA_UNUSED, va_list *list EINA_UNUSED)
{
   (void) obj;
}

static Efl_Op_Description op_descs[] = {
     EFL_OBJECT_OP_FUNC_OVERRIDE(efl_destructor, _destructor),
};

static const Efl_Class_Description class_desc = {
     EO_VERSION,
     "Simple5",
     EFL_CLASS_TYPE_REGULAR,
     EFL_CLASS_DESCRIPTION_OPS(op_descs),
     0,
     NULL,
     NULL
};

EFL_DEFINE_CLASS(simple5_class_get, &class_desc, EO_CLASS, NULL);

