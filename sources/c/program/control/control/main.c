#include "control.h"

int main(const int argc, const f_string_t *argv, const f_string_t *envp) {

  control_t data = control_t_initialize;

  data.program.debug.flag |= control_print_flag_debug_e | control_print_flag_out_e;
  data.program.error.flag |= control_print_flag_error_e | control_print_flag_out_e;
  data.program.output.flag |= control_print_flag_out_e;
  data.program.message.flag |= control_print_flag_message_e | control_print_flag_out_e;
  data.program.warning.flag |= control_print_flag_warning_e | control_print_flag_out_e;
  data.program.error.custom = (void *) &data;
  data.program.debug.custom = (void *) &data;
  data.program.message.custom = (void *) &data;
  data.program.output.custom = (void *) &data;
  data.program.warning.custom = (void *) &data;

  f_console_parameter_t parameters[] = control_console_parameter_t_initialize;

  data.program.parameters.array = parameters;
  data.program.parameters.used = control_parameter_total_d;
  data.program.environment = envp;

  if (f_pipe_input_exists()) {
    data.program.pipe = fll_program_data_pipe_input_e;
  }

  data.setting.flag |= control_main_flag_interruptible_e;

  fll_program_standard_set_up(&data.program);

  f_file_umask_get(&data.program.umask);

  {
    const f_console_arguments_t arguments = macro_f_console_arguments_t_initialize_1(argc, argv, envp);

    control_setting_load(arguments, &data);
  }

  control_process(&data);

  control_delete(&data);

  fll_program_standard_set_down(&data.program);

  if (data.setting.state.status == F_child) {
    exit(data.program.child);
  }

  return (F_status_is_error(data.setting.state.status) || data.setting.state.status == F_false) ? 1 : 0;
}
