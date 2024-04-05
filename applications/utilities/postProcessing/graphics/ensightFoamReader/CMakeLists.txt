add_library( userd-foam )
target_link_libraries( userd-foam
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
)
target_include_directories( userd-foam
  PUBLIC
  .
)
target_sources( userd-foam
  PRIVATE
  libuserd.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  USERD_API.H
  USERD_bkup.H
  USERD_exit_routine.H
  USERD_get_border_availability.H
  USERD_get_border_elements_by_type.H
  USERD_get_changing_geometry_status.H
  USERD_get_constant_val.H
  USERD_get_dataset_query_file_info.H
  USERD_get_descrip_lines.H
  USERD_get_element_label_status.H
  USERD_get_geom_timeset_number.H
  USERD_get_gold_part_build_info.H
  USERD_get_gold_variable_info.H
  USERD_get_matf_set_info.H
  USERD_get_matf_var_info.H
  USERD_get_maxsize_info.H
  USERD_get_model_extents.H
  USERD_get_name_of_reader.H
  USERD_get_nfaced_conn.H
  USERD_get_nfaced_nodes_per_face.H
  USERD_get_node_label_status.H
  USERD_get_nsided_conn.H
  USERD_get_num_of_time_steps.H
  USERD_get_number_of_files_in_dataset.H
  USERD_get_number_of_material_sets.H
  USERD_get_number_of_materials.H
  USERD_get_number_of_model_parts.H
  USERD_get_number_of_variables.H
  USERD_get_number_timesets.H
  USERD_get_part_coords.H
  USERD_get_part_element_ids_by_type.H
  USERD_get_part_elements_by_type.H
  USERD_get_part_node_ids.H
  USERD_get_reader_release.H
  USERD_get_reader_version.H
  USERD_get_sol_times.H
  USERD_get_timeset_description.H
  USERD_get_var_by_component.H
  USERD_get_var_value_at_specific.H
  USERD_load_matf_data.H
  USERD_set_filenames.H
  USERD_set_server_number.H
  USERD_set_time_set_and_step.H
  USERD_size_matf_data.H
  USERD_stop_part_building.H
  USERD_structured_data.H
  getFieldScalar.H
  getFieldTensor.H
  getFieldVector.H
  getLagrangianScalar.H
  getLagrangianVector.H
  getPatchFieldScalar.H
  getPatchFieldTensor.H
  getPatchFieldVector.H
  globalFoam.H
  tensorConversion.H
)
install( TARGETS userd-foam )