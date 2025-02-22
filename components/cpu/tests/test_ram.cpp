#include "../ram.h"

int main(){
    Random_Access_Memory ram;

    ram.print(40);

    bool arr[32];
    bool address[32];
    Reg_32 reg;
    Reg_32 reg2;
    
    int_to_bin(24143, arr, 32);
    int_to_bin(512, address, 32);
    reg.fill_arr_lower(arr, 32);
    reg.print();
    ram.data_clk_step(address, arr, true, false);

    int_to_bin(255, arr, 32);
    int_to_bin(516, address, 32);
    reg.fill_arr_lower(arr, 32);
    reg.print();
    ram.data_clk_step(address, arr, true, false);

    int_to_bin(43453533, arr, 32);
    int_to_bin(520, address, 32);
    reg.fill_arr_lower(arr, 32);
    reg.print();
    ram.data_clk_step(address, arr, true, false);

    ram.get_data_out(arr);
    reg2.fill_arr_lower(arr, 32);

    int_to_bin(10000000, arr, 32);
    int_to_bin(524, address, 32);
    reg.fill_arr_lower(arr, 32);
    reg.print();
    ram.data_clk_step(address, arr, true, false);

    bool arr2[32] = {};

    ram.data_clk_step(address, arr2, false, true);
    ram.get_data_out(arr);
    reg.fill_arr_lower(arr, 32);

    ram.print_data();
    ram.print_stack();
    reg.print();
    reg2.set_name("empt $r2");
    reg2.print();

    r_type_inst inst = create_r_type_inst(5,6,7,8,9,10);
    bool arr3[1][32];
    
    for(int i = 0; i < 32; i++){
        arr3[0][i] = inst.full[i];
    }

    ram.load_instructions(arr3, 1);
    std::cout<<"pointer:"<<ram.get_top_inst_pointer();

}
