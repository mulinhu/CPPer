MODULE = 

default:
ifndef MODULE
	@echo "Set MODULE name"
else
	@echo "Select the execution mode: sim, build, wave, module_verilate, testbench_verilate"
endif

.PHONY: sim
sim: waveform.vcd

.PHONY: build
build: ./obj_dir/V${MODULE}

.PHONY: module_verilate
module_verilate: .module.verilate

.PHONY: testbench_verilate
testbench_verilate: .testbench.verilate

.PHONY: wave
wave: waveform.vcd
	@echo "### WAVE ###"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V${MODULE}
	@echo "### SIMULATING ###"
	./obj_dir/V${MODULE}

./obj_dir/V${MODULE}: .testbench.verilate
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V${MODULE}

.testbench.verilate: $(MODULE).v tb_${MODULE}.cpp
	@echo "### TESTBENCH VERILATING ###"
	verilator -Wall --trace -cc $(MODULE).v --exe tb_${MODULE}.cpp

.module.verilate: $(MODULE).v
	@echo "### MODULE VERILATING ###"
	verilator -cc $(MODULE).v
.PHONY: clean
clean:
	rm -rf ./obj_dir
	rm -rf waveform.vcd
