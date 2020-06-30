

add_executable("pile-pbc" "pbc.cpp")
set_target_properties("pile-pbc" PROPERTIES FOLDER "Pile Tools")
llvm_map_components_to_libnames(LLVM_LIBS
	Support
	Core
	Target
	Passes




	AArch64CodeGen
	AMDGPUCodeGen
	ARMCodeGen
	BPFCodeGen
	HexagonCodeGen
	LanaiCodeGen
	MipsCodeGen
	MSP430CodeGen
	PowerPCCodeGen
	RISCVCodeGen
	SparcCodeGen
	SystemZCodeGen
	WebAssemblyCodeGen
	X86CodeGen
	XCoreCodeGen
	NVPTXCodeGen
	AArch64ASMParser
	AMDGPUASMParser
	ARMASMParser
	BPFASMParser
	HexagonASMParser
	LanaiASMParser
	MipsASMParser
	MSP430ASMParser
	PowerPCASMParser
	RISCVASMParser
	SparcASMParser
	SystemZASMParser
	WebAssemblyASMParser
	X86ASMParser
	

)
target_link_libraries("pile-pbc" ${LLVM_LIBS} "PileParse")