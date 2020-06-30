
add_library(PileParse STATIC 
ASTNode.cpp 
Tokenizer.cpp 
ASTBuilder.cpp
ObjectType.cpp
TokenGrouper.cpp
TokenWord.cpp
)
set_target_properties(PileParse PROPERTIES FOLDER "Pile Libraries")
llvm_map_components_to_libnames(LLVM_LIBS
	Core
	Support
)
target_link_libraries(PileParse ${LLVM_LIBS})