#include "Hwapi.h"

//path: D:\Magnum\Siena\hcwE5bda\HapiHost\MCHIPFiles\

//file: DXT-C_Micron_425_optimal.cfg
DRAM_BKV_CONFIG BKV_DXT_C_Micron_425_optimal = {
#if 1 //FGR - Magnum says we should be at 400MHz not 425
  /*.mem_pll=*/0x23d70a3c, //pll=400
#else
  /*.mem_pll=*/0x239d36cf, //pll=425
#endif
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10a62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x5eab676,
  /*.mem_intf_add_config=*/0xa0,
  /*.mem_intf_rfsh_ctrl=*/0x2e,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
#if 1 //FGR - Magnum says we should be at 285MHz not 320; changed in 31035
  /*.sys_pll=*/0x25631fe3, //pll=285
#else
  /*.sys_pll=*/0x24cccccc, //pll=319 //FGR - BUGBUG - changed back in 31109 due to 1080P60 encode issues @285MHz
#endif
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
#if 1 //FGR - Magnum says we should be at 285MHz not 320; changed in 31035
  /*.sys_pll2=*/0x25631fe3, //pll=285
#else
  /*.sys_pll2=*/0x24cccccc, //pll=319 //FGR - BUGBUG - changed back in 31109 due to 1080P60 encode issues @285MHz
#endif
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x4000,
  /*.mem_intf_left_ls_dll2=*/0x4000,
  /*.mem_intf_left_ms_dll2=*/0x4000,
  /*.mem_intf_right_ls_dll2=*/0x4000,
  /*.mem_intf_right_ms_dll2=*/0x4000,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: DXT-C_Micron_425.cfg
DRAM_BKV_CONFIG BKV_DXT_C_Micron_425 = {
#if 1 //FGR - Magnum says we should be at 400MHz not 425
  /*.mem_pll=*/0x23d70a3c, //pll=400
#else
  /*.mem_pll=*/0x239d36cf, //pll=425
#endif
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10a62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x5eab676,
  /*.mem_intf_add_config=*/0xa0,
  /*.mem_intf_rfsh_ctrl=*/0x2e,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x24cccccc, //pll=319
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x24cccccc, //pll=319
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x0,
  /*.mem_intf_left_ls_dll2=*/0x0,
  /*.mem_intf_left_ms_dll2=*/0x0,
  /*.mem_intf_right_ls_dll2=*/0x0,
  /*.mem_intf_right_ms_dll2=*/0x0,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: DXT-C_Hynix_425.cfg
//fixed up LEFT_DATA_CTRL, prev 0x0856e56e calculated 0x0866e46e
//fixed up RIGHT_DATA_CTRL, prev 0x0856e56e calculated 0x0846e66e
DRAM_BKV_CONFIG BKV_DXT_C_Hynix_425 = {
#if 1 //FGR - Magnum says we should be at 400MHz not 425
  /*.mem_pll=*/0x23d70a3c, //pll=400
#else
  /*.mem_pll=*/0x239d36cf, //pll=425
#endif
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10a62,
  /*.dram_emr=*/0x70040,
  /*.mem_intf_timing_ctrl=*/0x64ab67e,
  /*.mem_intf_add_config=*/0xa2,
  /*.mem_intf_rfsh_ctrl=*/0x1d86,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x24cccccc, //pll=319
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x866e46e,
  /*.mem_intf_right_data_ctrl=*/0x846e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x24cccccc, //pll=319
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x4000,
  /*.mem_intf_left_ls_dll2=*/0x4000,
  /*.mem_intf_left_ms_dll2=*/0x4000,
  /*.mem_intf_right_ls_dll2=*/0x4000,
  /*.mem_intf_right_ms_dll2=*/0x4000,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x4,
  /*.right_itm_read_delay=*/0x4,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: 24_320SYS_400DDR_CL6_DXTA3_LV_NOODT_v1.0.cfg
DRAM_BKV_CONFIG BKV_24_320SYS_400DDR_CL6_DXTA3_LV_NOODT_v1 = {
  /*.mem_pll=*/0x23d70a3c, //pll=400
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10c62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x2673d606,
  /*.mem_intf_add_config=*/0x184,
  /*.mem_intf_rfsh_ctrl=*/0x29,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x24cccccc, //pll=319
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x25631fe3, //pll=285
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x4000,
  /*.mem_intf_left_ls_dll2=*/0x4000,
  /*.mem_intf_left_ms_dll2=*/0x4000,
  /*.mem_intf_right_ls_dll2=*/0x4000,
  /*.mem_intf_right_ms_dll2=*/0x4000,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: 24_375CL6_335T_285_12SYS_1P_DXTA3_LV_NOODT_v5.0.cfg
DRAM_BKV_CONFIG BKV_24_375CL6_335T_285_12SYS_1P_DXTA3_LV_NOODT_v5 = {
  /*.mem_pll=*/0x2495c772, //pll=335
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10c62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x2673d606,
  /*.mem_intf_add_config=*/0x184,
  /*.mem_intf_rfsh_ctrl=*/0x29,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x25631fe3, //pll=285
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x25631fe3, //pll=285
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x4000,
  /*.mem_intf_left_ls_dll2=*/0x4000,
  /*.mem_intf_left_ms_dll2=*/0x4000,
  /*.mem_intf_right_ls_dll2=*/0x4000,
  /*.mem_intf_right_ms_dll2=*/0x4000,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: 375CL6_335T_285SYS_1P_MCHIPA3_LV_NOODT.cfg
DRAM_BKV_CONFIG BKV_375CL6_335T_285SYS_1P_MCHIPA3_LV_NOODT = {
  /*.mem_pll=*/0x292b8ee5, //pll=167
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10a62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x5eab676,
  /*.mem_intf_add_config=*/0xa0,
  /*.mem_intf_rfsh_ctrl=*/0x2e,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x2ac76917, //pll=142
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x2b97aafc, //pll=132
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x0,
  /*.mem_intf_left_ls_dll2=*/0x0,
  /*.mem_intf_left_ms_dll2=*/0x0,
  /*.mem_intf_right_ls_dll2=*/0x0,
  /*.mem_intf_right_ms_dll2=*/0x0,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};


//file: 24_285-12CL6_400T_SYS_1P_DXTA3_LV_NOODT_v1.0.cfg
DRAM_BKV_CONFIG BKV_24_285_12CL6_400T_SYS_1P_DXTA3_LV_NOODT_v1 = {
  /*.mem_pll=*/0x23d70a3c, //pll=400
  /*.left_ls_read_gate_guess=*/0x1a,
  /*.left_ms_read_gate_guess=*/0x1a,
  /*.right_ls_read_gate_guess=*/0x1a,
  /*.right_ms_read_gate_guess=*/0x1a,
  /*.dram_mr=*/0x10c62,
  /*.dram_emr=*/0x70000,
  /*.mem_intf_timing_ctrl=*/0x2673d606,
  /*.mem_intf_add_config=*/0x184,
  /*.mem_intf_rfsh_ctrl=*/0x29,
  /*.mem_intf_left_cmd_ctrl1=*/0x37000,
  /*.sys_pll=*/0x25631fe3, //pll=285
  /*.mem_intf_left_cmd_ctrl2=*/0x800000,
  /*.mem_intf_right_cmd_ctrl1=*/0x37000,
  /*.mem_intf_right_cmd_ctrl2=*/0x800000,
  /*.mem_intf_left_data_ctrl=*/0x66e56e,
  /*.mem_intf_right_data_ctrl=*/0x56e66e,
  /*.left_ls_read_eye_guess=*/0x3,
  /*.left_ms_read_eye_guess=*/0x3,
  /*.right_ls_read_eye_guess=*/0x3,
  /*.sys_pll_2=*/0x25631fe3, //pll=285
  /*.right_ms_read_eye_guess=*/0x3,
  /*.mem_intf_dll1=*/0x3737000,
  /*.mem_intf_dll2=*/0x4000,
  /*.mem_intf_left_ls_dll2=*/0x4000,
  /*.mem_intf_left_ms_dll2=*/0x4000,
  /*.mem_intf_right_ls_dll2=*/0x4000,
  /*.mem_intf_right_ms_dll2=*/0x4000,
  /*.mem_intf_left_ls_ditrm=*/0x0,
  /*.mem_intf_left_ms_ditrm=*/0x0,
  /*.mem_intf_right_ls_ditrm=*/0x0,
  /*.mem_intf_right_ms_ditrm=*/0x0,
  /*.mempll_workaround_attempt=*/0xffffffff,
  /*.mempll_workaround_wait=*/0xffffffff,
  /*.left_itm_read_delay=*/0x5,
  /*.right_itm_read_delay=*/0x5,
  /*.vp_boot_mode=*/0x0,
  /*.MCHIP_a2_gate_sweep=*/0x0,
  /*.MCHIP_a2_itm_sweep=*/0x0,
  /*.MCHIP_a2_dq_sweep=*/0x0,
  /*.MCHIP_a2_dqs_sweep=*/0x0,
  /*.memtest_mask=*/0x3,
  /*.reserved1=*/0x0,
  /*.reserved2=*/0x0,
  /*.reserved3=*/0x0,
  /*.reserved4=*/0x0,
  /*.otp_config_flash=*/0x0,
};

DRAM_BKV_CONFIG *BkvArray[] = {
  &BKV_DXT_C_Micron_425_optimal,
  &BKV_DXT_C_Micron_425,
  &BKV_DXT_C_Hynix_425,
  &BKV_24_320SYS_400DDR_CL6_DXTA3_LV_NOODT_v1,
  &BKV_24_375CL6_335T_285_12SYS_1P_DXTA3_LV_NOODT_v5,
  &BKV_375CL6_335T_285SYS_1P_MCHIPA3_LV_NOODT,
  &BKV_24_285_12CL6_400T_SYS_1P_DXTA3_LV_NOODT_v1,
};

DWORD BkvCount = sizeof(BkvArray)/sizeof(BkvArray[0]);
