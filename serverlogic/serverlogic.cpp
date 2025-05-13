#include "serverlogic.h"

// Accessors from main.cpp
extern "C" int get_input1_value();
extern "C" int get_input2_value();
extern "C" void set_result_value(int value);

static int last_input1 = 0;
static int last_input2 = 0;

void process_inputs_if_new() {
    int input1 = get_input1_value();
    int input2 = get_input2_value();
    // Only process if values have changed
    if (input1 != last_input1 || input2 != last_input2) {
        set_result_value(input1 + input2);
        last_input1 = input1;
        last_input2 = input2;
    }
}
