#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "Eo.h"
#include "function_overrides_simple.h"
#include "function_overrides_inherit2.h"
#include "function_overrides_inherit3.h"

#define MY_CLASS INHERIT3_CLASS

static void
_a_set(Eo *obj, void *class_data EINA_UNUSED, int a)
{
   printf("%s %d\n", efl_class_name_get(MY_CLASS), a);
   simple_a_set(efl_super(obj, MY_CLASS), a + 1);
}

static Efl_Op_Description op_descs[] = {
     EFL_OBJECT_OP_FUNC_OVERRIDE(simple_a_set, _a_set),
};

static const Efl_Class_Description class_desc = {
     EO_VERSION,
     "Inherit3",
     EFL_CLASS_TYPE_REGULAR,
     EFL_CLASS_DESCRIPTION_OPS(op_descs),
     0,
     NULL,
     NULL
};

EFL_DEFINE_CLASS(inherit3_class_get, &class_desc, INHERIT2_CLASS, NULL);

