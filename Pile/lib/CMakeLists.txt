function(add_pile_library NAME SRC)

add_library(${NAME} STATIC "${SRC}")
set_target_properties(${NAME} PROPERTIES FOLDER "Pile Libraries")
endfunction()

add_subdirectory("Parse")