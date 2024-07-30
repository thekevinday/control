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
#ifndef _control_main_print_debug_h
#define _control_main_print_debug_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Print a message displaying the object and content for some packet header.
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 * @param object
 *   The object string.
 * @param content
 *   The content string.
 * @param content_range
 *   The range representing the content where the content is found within the content string.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 */
#ifndef _di_control_print_debug_packet_header_object_and_content_
  extern f_status_t control_print_debug_packet_header_object_and_content(fl_print_t * const print, const f_string_static_t object, const f_string_static_t content, const f_range_t content_range);
#endif // _di_control_print_debug_packet_header_object_and_content_

/**
 * Print a debug message regarding some packet.
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 * @param message
 *   The message to print.
 *
 *   A single "%[" followed by a single "%]" is supported in the message and is replaced with "notable" context.
 * @param buffer
 *   (optional) An additonal message to print (this is syntax highlighted).
 *
 *   Set to NULL to not use.
 * @param range
 *   (optional) The range within the buffer to print rather than printing the entire buffer.
 *   This is ignored when buffer is NULL.
 *
 *   Set to NULL to not use.
 * @param status
 *   (optional) A status code that triggered the failure (this is syntax highlighted).
 *
 *   Set to NULL to not use.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 */
#ifndef _di_control_print_debug_packet_message_
  extern f_status_t control_print_debug_packet_message(fl_print_t * const print, const f_string_t message, f_string_static_t * const buffer, f_range_t * const range);
#endif // _di_control_print_debug_packet_message_

/**
 * Helper function for printing a debug message regarding some packet.
 *
 * This is essentially a wrapper to control_print_debug_packet_message()
 *
 * @param print
 *   The output structure to print to.
 *
 *   This does not alter print.custom.setting.state.status.
 *
 *   Must not be NULL.
 * @param type
 *   An enumeration code used to derive the specific message to print.
 * @param buffer
 *   (optional) An additonal message to print (this is syntax highlighted).
 *
 *   Set to NULL to not use.
 * @param range
 *   (optional) The range within the buffer to print rather than printing the entire buffer.
 *   This is ignored when buffer is NULL.
 *
 *   Set to NULL to not use.
 * @param status
 *   (optional) A status code that triggered the failure (this is syntax highlighted).
 *
 *   Set to NULL to not use.
 *
 * @return
 *   F_okay on success.
 *   F_output_not on success, but no printing is performed.
 *
 *   F_output_not (with error bit) if setting is NULL.
 *
 * @see control_print_debug_packet_message()
 */
#ifndef _di_control_print_debug_packet_message_of_
  extern f_status_t control_print_debug_packet_message_of(fl_print_t * const print, const uint8_t type, f_string_static_t * const buffer, f_range_t * const range);
#endif // _di_control_print_debug_packet_message_of_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_print_debug_h
