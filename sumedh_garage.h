#include <stdint.h>
#define NUM_SAMPLES 757
const PROGMEM int32_t signal[NUM_SAMPLES] = {103, -334, 9691, -6478, 4254, -66, 361, -66, 163, -262, 195, -98, 161, -98, 197, -98, 261, -428, 131, -100, 261, -66, 849, -100, 1287, -100, 1019, -66, 633, -100, 81079, -66, 229, -168, 233, -98, 261, -66, 197, -102, 201, -66, 231, -102, 233, -132, 335, -98, 165, -66, 233, -198, 1097, -66, 1015, -66, 589, -66, 229, -98, 689, -100, 191, -98, 263, -168, 201, -66, 167, -100, 169, -102, 269, -134, 199, -234, 265, -100, 263, -66, 199, -300, 1427, -66, 331, -66, 2023, -98, 333, -100, 265, -130, 63, -100, 133, -100, 131, -100, 167, -134, 199, -100, 199, -200, 131, -100, 167, -68, 201, -102, 167, -100, 299, -98, 3907, -98, 1275, -66, 107393, -7832, 15115, -134, 127, -242, 183, -122, 781, -164, 15125, -196, 157, -62, 181, -152, 541, -132, 163, -66, 127, -96, 13777, -170, 213, -632, 175, -1268, 479, -104, 14073, -2198, 319, -250, 217, -182, 13345, -2812, 13423, -3318, 223, -122, 185, -320, 12107, -132, 273, -3834, 173, -272, 11377, -66, 173, -436, 67, -4806, 11119, -490, 97, -226, 10889, -174, 71, -5792, 10349, -6062, 133, -316, 10155, -6346, 99, -288, 9795, -6606, 10209, -6432, 9727, -7028, 103, -336, 9247, -7322, 157, -96, 8861, -176, 209, -7048, 403, -220, 8915, -7334, 101, -366, 159, -142, 7795, -350, 333, -7828, 297, -182, 7623, -140, 105, -8960, 7283, -8568, 277, -616, 6787, -210, 143, -8838, 133, -130, 97, -498, 6585, -9860, 175, -180, 6047, -9854, 241, -218, 181, -182, 5809, -556, 103, -10556, 5263, -10520, 139, -214, 143, -180, 181, -218, 4743, -132, 323, -182, 217, -208, 259, -9624, 97, -378, 191, -98, 167, -144, 5111, -142, 105, -212, 103, -10290, 101, -434, 171, -108, 4289, -176, 105, -456, 257, -158, 125, -10202, 133, -424, 99, -318, 3759, -554, 417, -130, 213, -10602, 135, -272, 151, -120, 91, -664, 3259, -876, 177, -70, 135, -12234, 3057, -13952, 2419, -552, 199, -292, 105, -340, 129, -444, 2211, -558, 67, -12432, 201, -732, 173, -72, 227, -250, 69, -98, 97, -12936, 4931, -11892, 131, -94, 151, -272, 249, -92, 151, -276, 217, -272, 959, -654, 99, -172, 473, -12354, 99, -64, 243, -122, 123, -156, 305, -156, 433, -100, 1313, -198, 227, -150, 121, -152, 119, -248, 281, -12152, 97, -156, 315, -100, 137, -194, 1195, -178, 351, -214, 209, -72, 143, -214, 219, -180, 143, -12598, 239, -254, 217, -220, 139, -228, 145, -646, 285, -290, 361, -104, 173, -310, 141, -12506, 245, -108, 247, -218, 143, -308, 91, -208, 145, -108, 179, -360, 203, -694, 131, -108, 403, -13330, 101, -450, 207, -216, 107, -536, 103, -212, 71, -14346, 167, -108, 145, -762, 67, -174, 179, -1822, 131, -156, 89, -13342, 135, -1152, 177, -106, 65, -324, 191, -968, 153, -12862, 97, -770, 97, -672, 197, -1706, 67, -13452, 343, -564, 375, -284, 73, -252, 105, -658, 349, -220, 121, -13932, 133, -738, 167, -580, 163, -124, 91, -190, 95, -94, 159, -13420, 359, -182, 145, -218, 145, -476, 65, -128, 135, -370, 209, -72, 131, -352, 97, -14488, 443, -152, 153, -60, 185, -92, 121, -336, 187, -94, 595, -13632, 141, -1062, 227, -632, 139, -560, 131, -14018, 193, -274, 153, -234, 105, -186, 161, -208, 61, -370, 97, -174, 143, -108, 181, -13810, 467, -648, 173, -496, 235, -110, 145, -298, 283, -13668, 99, -1664, 133, -140, 109, -144, 173, -144, 143, -13936, 99, -392, 143, -306, 197, -290, 153, -766, 95, -14414, 105, -142, 107, -146, 217, -146, 107, -312, 95, -250, 217, -14410, 2947, -13732, 2523, -14184, 971, -1022, 809, -13936, 2397, -14294, 2589, -14018, 2355, -14362, 2615, -14102, 2261, -14612, 2155, -14310, 2073, -14706, 2299, -14270, 2327, -14506, 323, -962, 805, -14644, 1735, -14978, 127, -968, 873, -14834, 1839, -14670, 169, -924, 917, -14698, 1571, -15288, 1601, -14910, 1367, -16020, 1061, -14952, 1827, -15504, 1103, -14892, 1733, -15056, 1595, -15110, 1493, -15166, 1519, -15508, 1025, -15462, 1291, -15270, 1415, -16104, 449, -15474, 1279, -15250, 1443, -15152, 685, -16052, 1489, -14984, 1767, -14866, 1771, -14946, 1731, -14956, 1733, -14838, 539, -1012, 201, -15038, 1681, -14948, 1681, -15012, 1661, -15082, 1533, -15178, 1495, -15298, 1313, -15356, 1345, -15274, 1375, -15350, 1297, -16136, 525, -15314, 1343, -16044, 603, -15282, 1501, -15964, 643, -15238, 1305, -15376, 1411, -15340, 1309, -15358, 1323, -15392, 1271, -15384, 1267, -15472, 1175, -15538, 1123, -15746, 919, -15766, 843, -15972, 709, -167990, 361, -132, 163, -134, 197, -100, 165, -168, 361, -100, 261, -66, 3221, -300, 163, -132, 265, -100, 201, -66, 165, -164, 131, -334, 265, -132, 367, -66, 1263, -98, 667, -68, 2493};
