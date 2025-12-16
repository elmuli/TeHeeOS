#include <linux/export-internal.h>

#include <linux/module.h>
#undef __MODULE_INFO_PREFIX
#define __MODULE_INFO_PREFIX
MODULE_INFO(keyboard.alias, "input:b*v*p*e*-e*1,*k*r*a*m*l*s*f*w*");
MODULE_INFO(keyboard.alias, "input:b*v*p*e*-e*12,*k*r*a*m*l*s*f*w*");
MODULE_INFO(atkbd.alias, "serio:ty01pr*id*ex*");
MODULE_INFO(atkbd.alias, "serio:ty06pr*id*ex*");
MODULE_INFO(atkbd.alias, "serio:ty02pr22id*ex*");
MODULE_INFO(psmouse.alias, "serio:ty05pr*id*ex*");
MODULE_INFO(hid_generic.alias, "hid:b*g*v*p*");
