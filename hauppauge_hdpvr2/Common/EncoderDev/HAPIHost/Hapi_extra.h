//Sorry, TMDL_HDMITX_VFMT_NULL is already used in the very different way
#define TMDL_HDMITX_VFMT_CUSTOM 0xFFFF

typedef enum
{
    TMDL_HDMITX_VFMT_NULL               = 0,    /**< Not a valid format...        */
    TMDL_HDMITX_VFMT_NO_CHANGE          = 0,    /**< ...or no change required     */
    TMDL_HDMITX_VFMT_MIN                = 1,    /**< Lowest valid format          */
    TMDL_HDMITX_VFMT_TV_MIN             = 1,    /**< Lowest valid TV format       */
    TMDL_HDMITX_VFMT_01_640x480p_60Hz   = 1,    /**< Format 01 640  x 480p  60Hz  */
    TMDL_HDMITX_VFMT_02_720x480p_60Hz   = 2,    /**< Format 02 720  x 480p  60Hz  */
    TMDL_HDMITX_VFMT_03_720x480p_60Hz   = 3,    /**< Format 03 720  x 480p  60Hz  */
    TMDL_HDMITX_VFMT_04_1280x720p_60Hz  = 4,    /**< Format 04 1280 x 720p  60Hz  */
    TMDL_HDMITX_VFMT_05_1920x1080i_60Hz = 5,    /**< Format 05 1920 x 1080i 60Hz  */
    TMDL_HDMITX_VFMT_06_720x480i_60Hz   = 6,    /**< Format 06 720  x 480i  60Hz  */
    TMDL_HDMITX_VFMT_07_720x480i_60Hz   = 7,    /**< Format 07 720  x 480i  60Hz  */
    TMDL_HDMITX_VFMT_08_720x240p_60Hz   = 8,    /**< Format 08 720  x 240p  60Hz  */
    TMDL_HDMITX_VFMT_09_720x240p_60Hz   = 9,    /**< Format 09 720  x 240p  60Hz  */
    TMDL_HDMITX_VFMT_10_720x480i_60Hz   = 10,   /**< Format 10 720  x 480i  60Hz  */
    TMDL_HDMITX_VFMT_11_720x480i_60Hz   = 11,   /**< Format 11 720  x 480i  60Hz  */
    TMDL_HDMITX_VFMT_12_720x240p_60Hz   = 12,   /**< Format 12 720  x 240p  60Hz  */
    TMDL_HDMITX_VFMT_13_720x240p_60Hz   = 13,   /**< Format 13 720  x 240p  60Hz  */
    TMDL_HDMITX_VFMT_14_1440x480p_60Hz  = 14,   /**< Format 14 1440 x 480p  60Hz  */
    TMDL_HDMITX_VFMT_15_1440x480p_60Hz  = 15,   /**< Format 15 1440 x 480p  60Hz  */
    TMDL_HDMITX_VFMT_16_1920x1080p_60Hz = 16,   /**< Format 16 1920 x 1080p 60Hz  */
    TMDL_HDMITX_VFMT_17_720x576p_50Hz   = 17,   /**< Format 17 720  x 576p  50Hz  */
    TMDL_HDMITX_VFMT_18_720x576p_50Hz   = 18,   /**< Format 18 720  x 576p  50Hz  */
    TMDL_HDMITX_VFMT_19_1280x720p_50Hz  = 19,   /**< Format 19 1280 x 720p  50Hz  */
    TMDL_HDMITX_VFMT_20_1920x1080i_50Hz = 20,   /**< Format 20 1920 x 1080i 50Hz  */
    TMDL_HDMITX_VFMT_21_720x576i_50Hz   = 21,   /**< Format 21 720  x 576i  50Hz  */
    TMDL_HDMITX_VFMT_22_720x576i_50Hz   = 22,   /**< Format 22 720  x 576i  50Hz  */
    TMDL_HDMITX_VFMT_23_720x288p_50Hz   = 23,   /**< Format 23 720  x 288p  50Hz  */
    TMDL_HDMITX_VFMT_24_720x288p_50Hz   = 24,   /**< Format 24 720  x 288p  50Hz  */
    TMDL_HDMITX_VFMT_25_720x576i_50Hz   = 25,   /**< Format 25 720  x 576i  50Hz  */
    TMDL_HDMITX_VFMT_26_720x576i_50Hz   = 26,   /**< Format 26 720  x 576i  50Hz  */
    TMDL_HDMITX_VFMT_27_720x288p_50Hz   = 27,   /**< Format 27 720  x 288p  50Hz  */
    TMDL_HDMITX_VFMT_28_720x288p_50Hz   = 28,   /**< Format 28 720  x 288p  50Hz  */
    TMDL_HDMITX_VFMT_29_1440x576p_50Hz  = 29,   /**< Format 29 1440 x 576p  50Hz  */
    TMDL_HDMITX_VFMT_30_1440x576p_50Hz  = 30,   /**< Format 30 1440 x 576p  50Hz  */
    TMDL_HDMITX_VFMT_31_1920x1080p_50Hz = 31,   /**< Format 31 1920 x 1080p 50Hz  */
    TMDL_HDMITX_VFMT_32_1920x1080p_24Hz = 32,   /**< Format 32 1920 x 1080p 24Hz  */
    TMDL_HDMITX_VFMT_33_1920x1080p_25Hz = 33,   /**< Format 33 1920 x 1080p 25Hz  */
    TMDL_HDMITX_VFMT_34_1920x1080p_30Hz = 34,   /**< Format 34 1920 x 1080p 30Hz  */
    TMDL_HDMITX_VFMT_35_2880x480p_60Hz  = 35,   /**< Format 35 2880 x 480p  60Hz 4:3  */
    TMDL_HDMITX_VFMT_36_2880x480p_60Hz  = 36,   /**< Format 36 2880 x 480p  60Hz 16:9 */
    TMDL_HDMITX_VFMT_37_2880x576p_50Hz  = 37,   /**< Format 37 2880 x 576p  50Hz 4:3  */
    TMDL_HDMITX_VFMT_38_2880x576p_50Hz  = 38,   /**< Format 38 2880 x 576p  50Hz 16:9 */

#if 0//FGR - these are missing (from http://en.wikipedia.org/wiki/CEA-861#CEA-861-E )
    TMDL_HDMITX_VFMT_39_1920x1080i_1250_50Hz = 39,   /**< Format 39 1920 x 1080i 50Hz(1250 lines)  */
    TMDL_HDMITX_VFMT_40_1920x1080i_100Hz = 40,   /**< Format 40 1920 x 1080i 100Hz  */
    TMDL_HDMITX_VFMT_41_1280x720p_100Hz  = 41,   /**< Format 41 1280 x 720p  100Hz  */
    TMDL_HDMITX_VFMT_42_720x576p_100Hz   = 42,   /**< Format 42 720  x 576p  100Hz 4x3 */
    TMDL_HDMITX_VFMT_43_720x576p_100Hz   = 43,   /**< Format 43 720  x 576p  100Hz  */
    TMDL_HDMITX_VFMT_44_1440x576i_100Hz  = 44,   /**< Format 44 1440 x 576i  100Hz 4x3 */
    TMDL_HDMITX_VFMT_45_1440x576i_100Hz  = 45,   /**< Format 45 1440 x 576i  100Hz  */
39 1080i25  16:9  1920x1080i(1250 Total) @ 50Hz*

40 1080i50  16:9              1920x1080i @ 100Hz
41 720p100  16:9               1280x720p @ 100Hz
42 576p100   4:3                720x576p @ 100Hz
43 576p100H 16:9                720x576p @ 100Hz
44 576i50    4:3          720(1440)x576i @ 100Hz
45 576i50H  16:9          720(1440)x576i @ 100Hz

    TMDL_HDMITX_VFMT_46_1920x1080i_120Hz = 46,   /**< Format 46 1920 x 1080i 120Hz  */
    TMDL_HDMITX_VFMT_47_1280x720p_120Hz  = 47,   /**< Format 47 1280 x 720p  120Hz  */
    TMDL_HDMITX_VFMT_48_720x480p_120Hz   = 48,   /**< Format 48 720  x 480p  120Hz 4x3 */
    TMDL_HDMITX_VFMT_49_720x480p_120Hz   = 49,   /**< Format 49 720  x 480p  120Hz  */
    TMDL_HDMITX_VFMT_50_1440x480i_120Hz  = 50,   /**< Format 50 1440 x 480i  120Hz 4x3 */
    TMDL_HDMITX_VFMT_51_1440x480i_120Hz  = 51,   /**< Format 51 1440 x 480i  120Hz  */
46 1080i60  16:9              1920x1080i @ 119.88/120Hz
47 720p120  16:9               1280x720p @ 119.88/120Hz
48 480p119   4:3                720x480p @ 119.88/120Hz
49 480p119H 16:9                720x480p @ 119.88/120Hz
50 480i59    4:3          720(1440)x480i @ 119.88/120Hz
51 480i59H  16:9          720(1440)x480i @ 119.88/120Hz

    TMDL_HDMITX_VFMT_52_720x576p_200Hz   = 52,   /**< Format 52 720  x 576p  200Hz 4x3 */
    TMDL_HDMITX_VFMT_53_720x576p_200Hz   = 53,   /**< Format 53 720  x 576p  200Hz  */
    TMDL_HDMITX_VFMT_54_1440x576i_200Hz  = 54,   /**< Format 54 1440 x 576i  200Hz 4x3 */
    TMDL_HDMITX_VFMT_55_1440x576i_200Hz  = 55,   /**< Format 55 1440 x 576i  200Hz  */
52 576p200   4:3                720x576p @ 200Hz
53 576p200H 16:9                720x576p @ 200Hz
54 576i100   4:3          720(1440)x576i @ 200Hz
55 576i100H 16:9          720(1440)x576i @ 200Hz

    TMDL_HDMITX_VFMT_56_720x480p_240Hz   = 56,   /**< Format 56 720  x 480p  240Hz 4x3 */
    TMDL_HDMITX_VFMT_57_720x480p_240Hz   = 57,   /**< Format 57 720  x 480p  240Hz  */
    TMDL_HDMITX_VFMT_58_1440x480i_240Hz  = 58,   /**< Format 58 1440 x 480i  240Hz 4x3 */
    TMDL_HDMITX_VFMT_59_1440x480i_240Hz  = 59,   /**< Format 59 1440 x 480i  240Hz  */
56 480p239   4:3                720x480p @ 239.76/240Hz
57 480p239H 16:9                720x480p @ 239.76/240Hz
58 480i119   4:3          720(1440)x480i @ 239.76/240Hz
59 480i119H 16:9          720(1440)x480i @ 239.76/240Hz


   TMDL_HDMITX_VFMT_63_1920x1080p_120Hz = 63,   /**< Format 63 1920 x 1080p 120Hz  */
   TMDL_HDMITX_VFMT_64_1920x1080p_100Hz = 64,   /**< Format 64 1920 x 1080p 100Hz  */
63 1080p120 16:9        1920x1080p @ 119.88/120Hz,
64 1080p100 16:9        1920x1080p @ 100Hz,

    TMDL_HDMITX_VFMT_INDEX_60_1280x720p_24Hz = 60,/**< Index of HDMITX_VFMT_60_1280x720p_24Hz */
	//FGR - see dlHdmiTxCalcVidFmtIndex() callers to decide what tables need to be patched
	//   kVfmtToShortFmt_TV(missing PC_FORMATS?), kVfmtToAspect_TV, kRefpixRefline
    TMDL_HDMITX_VFMT_TV_MAX             = 64,   /**< Highest valid TV format      */
    TMDL_HDMITX_VFMT_TV_NUM             = 65,   /**< Number of TV formats & null  */
#endif

    TMDL_HDMITX_VFMT_INDEX_60_1280x720p_24Hz = 39,/**< Index of HDMITX_VFMT_60_1280x720p_24Hz */
	TMDL_HDMITX_VFMT_60_1280x720p_24Hz  = 60,   /**< Format 60 1280 x 720p  23.97/24Hz 16:9 */
    TMDL_HDMITX_VFMT_61_1280x720p_25Hz  = 61,   /**< Format 61 1280 x 720p  25Hz 16:9 */
    TMDL_HDMITX_VFMT_62_1280x720p_30Hz  = 62,   /**< Format 60 1280 x 720p  29.97/30Hz 16:9 */

    TMDL_HDMITX_VFMT_TV_MAX             = 62,   /**< Highest valid TV format      */
    TMDL_HDMITX_VFMT_TV_NO_REG_MIN      = 32,   /**< Lowest TV format without prefetched table */
    TMDL_HDMITX_VFMT_TV_NUM             = 42,   /**< Number of TV formats & null  */

    TMDL_HDMITX_VFMT_PC_MIN             = 128,  /**< Lowest valid PC format       */
    TMDL_HDMITX_VFMT_PC_640x480p_60Hz   = 128,  /**< PC format 128                */
    TMDL_HDMITX_VFMT_PC_800x600p_60Hz   = 129,  /**< PC format 129                */
    TMDL_HDMITX_VFMT_PC_1152x960p_60Hz  = 130,  /**< PC format 130                */
    TMDL_HDMITX_VFMT_PC_1024x768p_60Hz  = 131,  /**< PC format 131                */
    TMDL_HDMITX_VFMT_PC_1280x768p_60Hz  = 132,  /**< PC format 132                */
    TMDL_HDMITX_VFMT_PC_1280x1024p_60Hz = 133,  /**< PC format 133                */
    TMDL_HDMITX_VFMT_PC_1360x768p_60Hz  = 134,  /**< PC format 134                */
    TMDL_HDMITX_VFMT_PC_1400x1050p_60Hz = 135,  /**< PC format 135                */
    TMDL_HDMITX_VFMT_PC_1600x1200p_60Hz = 136,  /**< PC format 136                */
    TMDL_HDMITX_VFMT_PC_1024x768p_70Hz  = 137,  /**< PC format 137                */
    TMDL_HDMITX_VFMT_PC_640x480p_72Hz   = 138,  /**< PC format 138                */
    TMDL_HDMITX_VFMT_PC_800x600p_72Hz   = 139,  /**< PC format 139                */
    TMDL_HDMITX_VFMT_PC_640x480p_75Hz   = 140,  /**< PC format 140                */
    TMDL_HDMITX_VFMT_PC_1024x768p_75Hz  = 141,  /**< PC format 141                */
    TMDL_HDMITX_VFMT_PC_800x600p_75Hz   = 142,  /**< PC format 142                */
    TMDL_HDMITX_VFMT_PC_1024x864p_75Hz  = 143,  /**< PC format 143                */
    TMDL_HDMITX_VFMT_PC_1280x1024p_75Hz = 144,  /**< PC format 144                */
    TMDL_HDMITX_VFMT_PC_640x350p_85Hz   = 145,  /**< PC format 145                */
    TMDL_HDMITX_VFMT_PC_640x400p_85Hz   = 146,  /**< PC format 146                */
    TMDL_HDMITX_VFMT_PC_720x400p_85Hz   = 147,  /**< PC format 147                */
    TMDL_HDMITX_VFMT_PC_640x480p_85Hz   = 148,  /**< PC format 148                */
    TMDL_HDMITX_VFMT_PC_800x600p_85Hz   = 149,  /**< PC format 149                */
    TMDL_HDMITX_VFMT_PC_1024x768p_85Hz  = 150,  /**< PC format 150                */
    TMDL_HDMITX_VFMT_PC_1152x864p_85Hz  = 151,  /**< PC format 151                */
    TMDL_HDMITX_VFMT_PC_1280x960p_85Hz  = 152,  /**< PC format 152                */
    TMDL_HDMITX_VFMT_PC_1280x1024p_85Hz = 153,  /**< PC format 153                */
    TMDL_HDMITX_VFMT_PC_1024x768i_87Hz  = 154,  /**< PC format 154                */
    TMDL_HDMITX_VFMT_PC_MAX             = 154,  /**< Highest valid PC format      */
    TMDL_HDMITX_VFMT_PC_NUM             = (TMDL_HDMITX_VFMT_PC_MAX-TMDL_HDMITX_VFMT_PC_MIN+1),   /**< Number of PC formats         */
#ifdef HCW_E5BDA
    TMDL_HDMITX_VFMT_PC_848x480p_60Hz   = 155,  /**< PC format 155 HCW only       */
    TMDL_HDMITX_VFMT_PC_1440x900p_60Hz  = 156,  /**< PC format 156 HCW only       */
//  TMDL_HDMITX_VFMT_PC_1680x1050p_60Hz = 157,  /**< PC format 157 HCW only       */
//  TMDL_HDMITX_VFMT_PC_MAX             = 157,  /**< Highest valid PC format      */
#endif
} tmdlHdmiTxVidFmt_t;
