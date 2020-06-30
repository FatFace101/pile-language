function(add_pile_executable name sources)
add_executable(${name} ${sources})
set_target_properties(${name} PROPERTIES FOLDER "Pile Tools")

endfunction(add_pile_executable)


add_subdirectory(pbc)