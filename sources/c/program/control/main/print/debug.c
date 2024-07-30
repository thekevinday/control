#include "../control.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _di_control_print_debug_packet_header_object_and_content_
  f_status_t control_print_debug_packet_header_object_and_content(fl_print_t * const print, const f_string_static_t object, const f_string_static_t content, const f_range_t content_range) {

    if (!print) return F_status_set_error(F_output_not);
    if (print->verbosity < f_console_verbosity_debug_e) return F_output_not;

    f_file_stream_lock(print->to);

    fl_print_format("Packet header Object '%[%Q%]", print->to, print->set->notable, object, print->set->notable);
    fl_print_format("' has value '%[%/Q%]'.%r", print->to, print->set->notable, content, content_range, print->set->notable, f_string_eol_s);

    f_file_stream_unlock(print->to);

    return F_okay;
  }
#endif // _di_control_print_debug_packet_header_object_and_content_

#ifndef _di_control_print_debug_packet_message_
  f_status_t control_print_debug_packet_message(fl_print_t * const print, const f_string_t message, f_string_static_t * const buffer, f_range_t * const range) {

    if (!print || !print->custom) return F_status_set_error(F_output_not);
    if (print->verbosity < f_console_verbosity_debug_e) return F_output_not;

    control_t * const main = (control_t *) print->custom;

    f_file_stream_lock(print->to);

    fl_print_format(f_string_format_s_single_s.string, print->to, message);

    if (buffer) {
      if (range) {
        fl_print_format("'%[%/Q%]'", print->to, print->set->notable, *buffer, *range, print->set->notable);
      }
      else {
        fl_print_format("'%[%Q%]'", print->to, print->set->notable, *buffer, print->set->notable);
      }
    }

    if (main->setting.state.status) {
      fl_print_format(", with status code %[%ui%]'", print->to, print->set->notable, main->setting.state.status, print->set->notable);
    }

    fl_print_format(f_string_format_sentence_end_s.string, print->to, f_string_eol_s);

    f_file_stream_unlock(print->to);

    return F_okay;
  }
#endif // _di_control_print_debug_packet_message_

#ifndef _di_control_print_debug_packet_message_of_
  f_status_t control_print_debug_packet_message_of(fl_print_t * const print, const uint8_t type, f_string_static_t * const buffer, f_range_t * const range) {

    f_string_t message;

    if (type == control_print_debug_message_failure_identify_action_e) {
      message = "Failed to identify %[" CONTROL_action_s "%] from: ";
    }
    else if (type == control_print_debug_message_failure_reading_fss_extended_response_e) {
      message = "Failure while reading FSS Extended in the response packet";
    }
    else if (type == control_print_debug_message_failure_reading_fss_basic_list_response_e) {
      message = "Failure while reading FSS Basic List in the response packet";
    }
    else if (type == control_print_debug_message_failure_process_delimits_fss_basic_list_response_e) {
      message = "Failure while processing delimits for the FSS Basic List in the response packet";
    }
    else if (type == control_print_debug_message_failure_process_number_exceeds_response_e) {
      message = "Processed number for %[" CONTROL_length_s "%] exceeds allowed size in the response packet, number is:";
    }
    else if (type == control_print_debug_message_failure_process_number_response_e) {
      message = "Failed to process number for %[" CONTROL_length_s "%] in the response packet, number is:";
    }
    else if (type == control_print_debug_message_failure_process_status_response_e) {
      message = "Failed to process %[" CONTROL_status_s "%] in the response packet, Content is:";
    }
    else if (type == control_print_debug_message_invalid_payload_last_not_e) {
      message = "Invalid FSS Payload format, the %[" F_fss_payload_s "%] is required to be the last FSS Basic List Object";
    }
    else if (type == control_print_debug_message_multiple_fss_header_response_e) {
      message = "Multiple %[" F_fss_header_s "%] found in response packet";
    }
    else if (type == control_print_debug_message_multiple_fss_payload_response_e) {
      message = "Multiple %[" F_fss_payload_s "%] found in response packet";
    }
    else if (type == control_print_debug_message_missing_fss_header_response_e) {
      message = "Did not find a %[" F_fss_header_s "%] in the response packet";
    }
    else if (type == control_print_debug_message_missing_fss_payload_response_e) {
      message = "Did not find a %[" F_fss_payload_s "%] in the response packet";
    }
    else if (type == control_print_debug_message_missing_header_content_e) {
      message = "Did not find any Content within the %[" F_fss_header_s "%]";
    }
    else if (type == control_print_debug_message_unknown_type_response_e) {
      message = "Unknown %[" CONTROL_type_s "%] in response packet, Content is:";
    }
  }
#endif // _di_control_print_debug_packet_message_of_

#ifdef __cplusplus
} // extern "C"
#endif
