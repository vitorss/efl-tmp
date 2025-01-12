#define EFL_ANIMATION_PROTECTED

#include "evas_common_private.h"
#include <Ecore.h>

typedef struct _Efl_Canvas_Animation_Data
{
   double                    duration;

   double                    start_delay_time;

   Efl_Canvas_Animation_Repeat_Mode repeat_mode;
   int                       repeat_count;

   Efl_Interpolator         *interpolator;

   Eina_Bool                 keep_final_state : 1;
} Efl_Canvas_Animation_Data;

#define EFL_ANIMATION_DATA_GET(o, pd) \
   Efl_Canvas_Animation_Data *pd = efl_data_scope_get(o, EFL_CANVAS_ANIMATION_CLASS)

#define GET_STATUS(from, to, progress) \
   ((from * (1.0 - progress)) + (to * progress))

#define FINAL_STATE_IS_REVERSE(anim) \
   ((efl_animation_repeat_mode_get(anim) == EFL_CANVAS_ANIMATION_REPEAT_MODE_REVERSE) && \
    (efl_animation_repeat_count_get(anim) & 1))
