/**
 * FLL - Level 3
 *
 * Project: Control
 * API Version: 0.7
 * Licenses: lgpl-2.1-or-later
 *
 * Provides the process functionality.
 *
 * This is auto-included and should not need to be explicitly included.
 */
#ifndef _control_main_process_h
#define _control_main_process_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Execute main program.
 *
 * If main.signal is non-zero, then this blocks and handles the following signals:
 *   - F_signal_abort
 *   - F_signal_broken_pipe
 *   - F_signal_hangup
 *   - F_signal_interrupt
 *   - F_signal_quit
 *   - F_signal_termination
 *
 * @param main
 *   The main program data and settings.
 *
 *   This alters main.setting.state.status:
 *     F_okay on success.
 *     F_true on success when performing verification and verify passed.
 *     F_false on success when performing verification and verify failed.
 *
 *     F_interrupt (with error bit) on (exit) signal received.
 *     F_parameter (with error bit) if main is NULL or setting is NULL.
 */
#ifndef _di_control_process_
  extern void control_process(control_t * const main);
#endif // _di_control_process_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_process_h
