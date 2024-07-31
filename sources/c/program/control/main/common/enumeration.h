/**
 * FLL - Level 3
 *
 * Project: Control
 * API Version: 0.7
 * Licenses: lgpl-2.1-or-later
 *
 * Provides the common enumeration types.
 *
 * This is auto-included and should not need to be explicitly included.
 */
#ifndef _control_main_common_enumeration_h
#define _control_main_common_enumeration_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Codes representing supported actions.
 *
 * control_action_type_*_e:
 *   - none:     No type set.
 *   - freeze:   Perform the freeze controller operation.
 *   - kexec:    Perform the kexec controller operation (only for init mode).
 *   - kill:     Perform the kill controller operation.
 *   - pause:    Perform the pause controller operation.
 *   - reboot:   Perform the reboot controller operation (only for init mode).
 *   - reload:   Perform the reload controller operation.
 *   - rerun:    Perform the rerun controller operation.
 *   - restart:  Perform the restart controller operation.
 *   - resume:   Perform the resume controller operation.
 *   - shutdown: Perform the shutdown controller operation (only for init mode).
 *   - start:    Perform the start controller operation.
 *   - stop:     Perform the stop controller operation.
 *   - thaw:     Perform the thaw controller operation.
 */
#ifndef _di_control_action_type_e_
  enum {
    control_action_type_none_e = 0,
    control_action_type_freeze_e,
    control_action_type_kexec_e,
    control_action_type_kill_e,
    control_action_type_pause_e,
    control_action_type_reboot_e,
    control_action_type_reload_e,
    control_action_type_rerun_e,
    control_action_type_restart_e,
    control_action_type_resume_e,
    control_action_type_shutdown_e,
    control_action_type_start_e,
    control_action_type_stop_e,
    control_action_type_thaw_e,
  }; // enum
#endif // _di_control_action_type_e_

/**
 * Supported payload types.
 *
 * control_payload_type_*_e:
 *   - controller: The payload is a controller payload.
 *   - error:      The payload is an error payload.
 *   - init:       The payload is an init payload (only available when operating in "init" mode).
 */
#ifndef _di_control_payload_type_e_
  enum {
    control_payload_type_controller_e = 1,
    control_payload_type_error_e,
    control_payload_type_init_e,
  }; // enum
#endif // _di_control_payload_type_e_

/**
 * The main program parameters.
 */
#ifndef _di_control_parameter_e_
  enum {
    control_parameter_name_e = f_console_standard_parameter_last_e,
    control_parameter_return_e,
    control_parameter_settings_e,
    control_parameter_socket_e,
  }; // enum

  #define control_console_parameter_t_initialize \
    { \
      macro_fll_program_console_parameter_standard_initialize, \
      \
      macro_f_console_parameter_t_initialize_3(control_short_name_s,     control_long_name_s,     1, f_console_flag_normal_e), \
      macro_f_console_parameter_t_initialize_3(control_short_return_s,   control_long_return_s,   1, f_console_flag_normal_e), \
      macro_f_console_parameter_t_initialize_3(control_short_settings_s, control_long_settings_s, 1, f_console_flag_normal_e), \
      macro_f_console_parameter_t_initialize_3(control_short_socket_s,   control_long_socket_s,   1, f_console_flag_normal_e), \
    }

  #define control_parameter_total_d (f_console_parameter_state_type_total_d + 4)
#endif // _di_control_parameter_e_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_common_enumeration_h
