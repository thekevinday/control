/**
 * FLL - Level 3
 *
 * Project: Control
 * API Version: 0.7
 * Licenses: lgpl-2.1-or-later
 *
 * Provides the common define types.
 *
 * This is auto-included and should not need to be explicitly included.
 */
#ifndef _control_main_common_define_h
#define _control_main_common_define_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The program allocation defines.
 *
 * control_allocation_*_d:
 *   - console: An allocation step used for small buffers specifically for console parameter.
 *   - large:   An allocation step used for buffers that are anticipated to have large buffers.
 *   - pipe:    A buffer size used for processing piped data.
 *   - small:   An allocation step used for buffers that are anticipated to have small buffers.
 */
#ifndef _di_control_allocation_d_
  #define control_allocation_console_d 4
  #define control_allocation_large_d   256
  #define control_allocation_pipe_d    16384
  #define control_allocation_small_d   4
#endif // _di_control_allocation_d_

/**
 * General defines used throughout the program.
 *
 * control_default_*_d:
 *   - buffer_limit_soft_large: The preferred maximum size of buffers intended for large data sets such that sizes exceeding this will be shrunk when operations are complete (aka: a soft limit).
 *   - buffer_limit_soft_small: The preferred maximum size of buffers intended for small data sets such that sizes exceeding this will be shrunk when operations are complete (aka: a soft limit).
 */
#ifndef _di_control_default_d_
  #define control_default_buffer_limit_soft_large_d 2048
  #define control_default_buffer_limit_soft_small_d 64
#endif // _di_control_default_d_

/**
 * Flags passed to the main function or program.
 *
 * control_main_flag_*_d:
 *   - none:                   No flags set.
 *   - copyright:              Print copyright.
 *   - header:                 Enable printing of headers.
 *   - help:                   Print help.
 *   - pipe:                   Use the input pipe.
 *   - return:                 Print a message about the response packet.
 *   - version:                Print version.
 *   - version_copyright_help: A helper flag representing version, copyright, and help flag bits being set.
 */
#ifndef _di_control_main_flag_d_
  #define control_main_flag_none_d                   0x0
  #define control_main_flag_copyright_d              0x1
  #define control_main_flag_help_d                   0x2
  #define control_main_flag_pipe_d                   0x4
  #define control_main_flag_return_d                 0x8
  #define control_main_flag_version_e                0x10
  #define control_main_flag_version_copyright_help_d 0x13
#endif // _di_control_main_flag_d_

/**
 * A codes repesent different flags associated with a packet.
 *
 * control_packet_flag_*_d:
 *   - binary:     Designate that the packet is in binary mode (when not set then packet is in string mode).
 *   - endian_big: Designate that the packet is in big endian order (when not set then packet is in little endian order).
 */
#ifndef _di_control_packet_flag_d_
  #define control_packet_flag_binary_d     0x80
  #define control_packet_flag_endian_big_d 0x40
#endif // _di_control_packet_flag_d_

/**
 * Flags for fine-tuned print control.
 *
 * control_print_flag_*_d:
 *   - none:    No flags set.
 *   - debug:   Stream is for debug printing.
 *   - error:   Stream is for error printing.
 *   - in:      Stream is a source file.
 *   - message: Stream is for message printing.
 *   - out:     Stream is a destination file.
 *   - warning: Stream is for warning printing.
 */
#ifndef _di_control_print_flag_d_
  #define control_print_flag_none_d    0x0
  #define control_print_flag_debug_d   0x1
  #define control_print_flag_error_d   0x2
  #define control_print_flag_file_d    0x4
  #define control_print_flag_in_d      0x8
  #define control_print_flag_out_d     0x10
  #define control_print_flag_message_d 0x20
  #define control_print_flag_warning_d 0x40
#endif // _di_control_print_flag_d_

/**
 * The program signal defines.
 *
 * control_signal_*_d:
 *   - check:          Number of iterations before performing signal check in non-threaded signal handling.
 *   - check_failsafe: When using threads, how many consecutive failures to check signal before aborting (as a recursion failsafe).
 *   - check_tiny:     The tiny check.
 *   - check_short:    The short signal check.
 */
#ifndef _di_control_signal_d_
  #define control_signal_check_d          500000
  #define control_signal_check_failsafe_d 20000
  #define control_signal_check_tiny_d     4
  #define control_signal_check_short_d    16
#endif // _di_control_signal_d_

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _control_main_common_define_h
