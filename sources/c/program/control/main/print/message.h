/**
 * FLL - Level 3
 *
 * Project: Control
 * API Version: 0.7
 * Licenses: lgpl-2.1-or-later
 *
 * Provides the print functionality.
 *
 * This is auto-included and should not need to be explicitly included.
 */
#ifndef _control_main_print_message_h
#define _control_main_print_message_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Print help.
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 */
#ifndef _di_control_print_message_help_
  extern f_status_t control_print_message_help(fl_print_t * const print);
#endif // _di_control_print_message_help_

/**
 * Print a message about a packet response.
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 * @param header
 *   The control payload packet header data.
 *
 *   Must not be NULL.
 * @param status
 *   A string representing the name of the status code from header.status.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 */
#ifndef _di_control_print_message_packet_response_
  extern f_status_t control_print_message_packet_response(fl_print_t * const print, control_payload_header_t * const header, const f_string_static_t string_status);
#endif // _di_control_print_message_packet_response_

/**
 * Print a message about a packet response when the return flag is set.
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 * @param header
 *   The control payload packet header data.
 *
 *   Must not be NULL.
 * @param status
 *   A string representing the name of the status code from header.status.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 */
#ifndef _di_control_print_message_packet_response_return_
  extern f_status_t control_print_message_packet_response_return(fl_print_t * const print, control_payload_header_t * const header, const f_string_static_t string_status);
#endif // _di_control_print_message_packet_response_return_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_print_message_h
