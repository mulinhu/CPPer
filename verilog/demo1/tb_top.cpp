#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#define MAX_SIM_TIME 200
vluint64_t sim_time = 0;

int main(int argc, char** argv) {
    Vtop *dut = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");
    while (sim_time < MAX_SIM_TIME) {
	    int a = rand() & 1;
	    int b = rand() & 1;
	    dut->a = a;
        dut->b = b;
        dut->eval(); 
        printf("a = %d, b = %d, f = %d\n", a, b, dut->f);
        m_trace->dump(sim_time);
        sim_time++;
        assert(dut->f == (a ^ b));
    }
    m_trace->close();
    delete dut;
    return 0;
}
