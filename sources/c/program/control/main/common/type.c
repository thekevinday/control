#include "../control.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _di_control_delete_
  void control_delete(control_t * const control) {

    if (!control) return;

    fll_program_data_delete(&control->program);
    control_setting_delete(&control->setting);

    f_memory_array_resize(0, sizeof(f_char_t), (void **) &control->cache.large.string, &control->cache.large.used, &control->cache.large.size);
    f_memory_array_resize(0, sizeof(f_char_t), (void **) &control->cache.small.string, &control->cache.small.used, &control->cache.small.size);
    f_memory_array_resize(0, sizeof(f_char_t), (void **) &control->cache.packet.string, &control->cache.packet.used, &control->cache.packet.size);

    f_memory_array_resize(0, sizeof(f_range_t), (void **) &control->cache.objects.array, &control->cache.objects.used, &control->cache.objects.size);
    f_memory_arrays_resize(0, sizeof(f_ranges_t), (void **) &control->cache.contents.array, &control->cache.contents.used, &control->cache.contents.size, &f_rangess_delete_callback);

    f_memory_array_resize(0, sizeof(f_range_t), (void **) &control->cache.packet_objects.array, &control->cache.packet_objects.used, &control->cache.packet_objects.size);
    f_memory_arrays_resize(0, sizeof(f_ranges_t), (void **) &control->cache.packet_contents.array, &control->cache.packet_contents.used, &control->cache.packet_contents.size, &f_rangess_delete_callback);

    f_memory_array_resize(0, sizeof(f_range_t), (void **) &control->cache.header_objects.array, &control->cache.header_objects.used, &control->cache.header_objects.size);
    f_memory_arrays_resize(0, sizeof(f_ranges_t), (void **) &control->cache.header_contents.array, &control->cache.header_contents.used, &control->cache.header_contents.size, &f_rangess_delete_callback);

    f_memory_array_resize(0, sizeof(f_number_unsigned_t), (void **) &control->cache.delimits.array, &control->cache.delimits.used, &control->cache.delimits.size);
  }
#endif // _di_control_delete_

#ifndef _di_control_setting_delete_
  void control_setting_delete(control_setting_t * const setting) {

    if (!setting) return;

    f_memory_array_resize(0, sizeof(f_char_t), (void **) &setting->name_socket.string, &setting->name_socket.used, &setting->name_socket.size);
    f_memory_array_resize(0, sizeof(f_char_t), (void **) &setting->path_settings.string, &setting->path_settings.used, &setting->path_settings.size);
    f_memory_array_resize(0, sizeof(f_char_t), (void **) &setting->path_socket.string, &setting->path_socket.used, &setting->path_socket.size);

    f_memory_arrays_resize(0, sizeof(f_string_dynamic_t), (void **) &setting->actions.array, &setting->actions.used, &setting->actions.size, &f_string_dynamics_delete_callback);
  }
#endif // _di_control_setting_delete_

#ifdef __cplusplus
} // extern "C"
#endif
