#include "control.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _di_control_process_
  void control_process(control_t * const main) {

    if (!main || F_status_is_error(main->setting.state.status)) return;

    main->setting.state.status = F_okay;

    if (main->setting.flag & control_main_flag_version_copyright_help_d) {
      if (main->setting.flag & control_main_flag_help_d) {
        control_print_message_help(&main->program.message);
      }
      else if (main->setting.flag & control_main_flag_version_e) {
        fll_program_print_version(&main->program.message, control_program_version_s);
      }
      else if (main->setting.flag & control_main_flag_copyright_d) {
        fll_program_print_copyright(&main->program.message, fll_program_copyright_year_author_s);
      }

      return;
    }

    if (main->setting.flag & control_main_flag_pipe_d) {
      control_print_error_pipe_supported_not(&main->program.error);

      main->setting.state.status = F_status_set_error(F_support_not);
    }
    else if (main->setting.actions.used) {
      main->setting.action = control_action_type_identify(main->setting.actions.array[0]);

      if (main->setting.action) {
        control_action_verify(main);
      }
      else {
        control_print_error_parameter_action_not(&main->program.error, main->setting.actions.array[0]);

        main->setting.state.status = F_status_set_error(F_parameter);
      }

      if (F_status_is_error_not(main->setting.state.status)) {
        control_packet_build(main);

        if (F_status_is_error(main->setting.state.status)) {
          if (F_status_set_fine(main->setting.state.status) == F_too_large) {
            control_print_error_request_packet_too_large(&main->program.error);
          }
          else {
            control_print_error(&main->program.error, macro_control_f(control_packet_build));
          }
        }

        if (F_status_is_error_not(main->setting.state.status)) {
          control_packet_send(main);

          if (F_status_is_error(main->setting.state.status)) {
            control_print_error(&main->program.error, macro_control_f(control_packet_send));
          }
        }

        if (F_status_is_error_not(main->setting.state.status)) {
          control_payload_header_t header = control_payload_header_t_initialize;

          control_packet_receive(main, &header);

          if (F_status_is_error(main->setting.state.status)) {
            if (F_status_set_fine(main->setting.state.status) == F_too_large) {
              control_print_error_response_packet_valid_not(&main->program.error);
            }
            else {
              control_print_error(&main->program.error, macro_control_f(control_packet_receive));
            }
          }
          else {
            control_packet_process(main, &header);

            // Print the error message only if the error message is not already printed.
            if (F_status_is_error(main->setting.state.status)) {
              if (header.type != control_payload_type_error_e && (header.type != control_payload_type_controller_e || F_status_set_fine(main->setting.state.status) != header.status || (header.status != F_failure && header.status != F_busy))) {
                control_print_error(&main->program.error, macro_control_f(control_packet_process));
              }
            }
          }
        }
      }

      if (main->setting.socket.id != -1) {
        f_socket_disconnect(&main->setting.socket, f_socket_close_fast_e);
      }
    }
    else {
      control_print_error_parameter_actions_none(&main->program.error);

      main->setting.state.status = F_status_set_error(F_data_not);
    }

    if (F_status_is_error(main->setting.state.status)) return;

    main->setting.state.status = F_okay;
  }
#endif // _di_control_process_

#ifdef __cplusplus
} // extern "C"
#endif
