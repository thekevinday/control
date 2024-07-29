/**
 * FLL - Level 3
 *
 * Project: Control
 * API Version: 0.7
 * Licenses: lgpl-2.1-or-later
 */
#ifndef _control_main_control_h
#define _control_main_control_h

// Libc includes.
#include <unistd.h>

// FLL-0 includes.
#include <fll/level_0/type.h>
#include <fll/level_0/status.h>
#include <fll/level_0/memory.h>
#include <fll/level_0/string.h>
#include <fll/level_0/utf.h>
#include <fll/level_0/color.h>
#include <fll/level_0/compare.h>
#include <fll/level_0/console.h>
#include <fll/level_0/conversion.h>
#include <fll/level_0/directory.h>
#include <fll/level_0/file.h>
#include <fll/level_0/fss.h>
#include <fll/level_0/path.h>
#include <fll/level_0/pipe.h>
#include <fll/level_0/print.h>
#include <fll/level_0/rip.h>
#include <fll/level_0/signal.h>
#include <fll/level_0/socket.h>
#include <fll/level_0/thread.h>
#include <fll/level_0/status_string.h>

// FLL-1 includes.
#include <fll/level_1/conversion.h>
#include <fll/level_1/fss.h>
#include <fll/level_1/print.h>
#include <fll/level_1/status_string.h>

// FLL-2 includes.
#include <fll/level_2/error.h>
#include <fll/level_2/fss/basic_list.h>
#include <fll/level_2/fss/extended.h>
#include <fll/level_2/fss/payload.h>
#include <fll/level_2/print.h>
#include <fll/level_2/program.h>

// Control includes.
#include <program/control/main/common/define.h>
#include <program/control/main/common/enumeration.h>
#include <program/control/main/common/print.h>
#include <program/control/main/common/string.h>
#include <program/control/main/common/type.h>
#include <program/control/main/common.h>
#include <program/control/main/print/data.h>
#include <program/control/main/print/debug.h>
#include <program/control/main/print/error.h>
#include <program/control/main/print/message.h>
#include <program/control/main/print/warning.h>
#include <program/control/main/action.h>
#include <program/control/main/packet.h>
#include <program/control/main/payload.h>
#include <program/control/main/process.h>
#include <program/control/main/signal.h>
#include <program/control/main/thread.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_control_h
