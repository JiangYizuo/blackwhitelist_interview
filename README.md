# blackwhitelist_interview
单元测试运行结果
<br>
Try to add segment [14, 16] WHITE
before:
[empty]
after:
BLANK[17,18446744073709551615]
WHITE[14,16]
BLANK[1,13]


Try to add segment [15, 15] BLACK
before:
BLANK[17,18446744073709551615]
WHITE[14,16]
BLANK[1,13]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[1,13]


Try to add segment [2, 2] BLACK
before:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[1,13]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]


Try to add segment [2, 2] BLACK
before:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]


Try to add segment [0, 2] WHITE
before:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]


Try to add segment [2, 0] WHITE
before:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]


Try to add segment [2, 1] WHITE
before:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]
after:
BLANK[17,18446744073709551615]
WHITE[16,16]
BLACK[15,15]
WHITE[14,14]
BLANK[3,13]
BLACK[2,2]
BLANK[1,1]


Try to remove segment [1, ?]
before:
[empty]
after:
[empty]


Try to add segment [1, 10] WHITE
before:
[empty]
after:
BLANK[11,18446744073709551615]
WHITE[1,10]


Try to remove segment [1, ?]
before:
BLANK[11,18446744073709551615]
WHITE[1,10]
after:
BLANK[11,18446744073709551615]
BLANK[1,10]


Try to remove segment [1, ?]
before:
BLANK[11,18446744073709551615]
BLANK[1,10]
after:
BLANK[11,18446744073709551615]
BLANK[1,10]


Try to add segment [10, 10] WHITE
before:
BLANK[11,18446744073709551615]
BLANK[1,10]
after:
BLANK[11,18446744073709551615]
WHITE[10,10]
BLANK[1,9]


Try to remove segment [10, ?]
before:
BLANK[11,18446744073709551615]
WHITE[10,10]
BLANK[1,9]
after:
BLANK[11,18446744073709551615]
BLANK[10,10]
BLANK[1,9]


Try to remove segment [10, ?]
before:
BLANK[11,18446744073709551615]
BLANK[10,10]
BLANK[1,9]
after:
BLANK[11,18446744073709551615]
BLANK[10,10]
BLANK[1,9]


Try to add segment [1, 2] WHITE
before:
[empty]
after:
BLANK[3,18446744073709551615]
WHITE[1,2]


Try to add segment [10, 30] BLACK
before:
BLANK[3,18446744073709551615]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[10,30]
BLANK[3,9]
WHITE[1,2]


Try to add segment [15, 15] BLACK
before:
BLANK[31,18446744073709551615]
BLACK[10,30]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[10,15]
BLANK[3,9]
WHITE[1,2]


Try to remove segment [15, ?]
before:
BLANK[31,18446744073709551615]
BLACK[10,15]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[10,15]
BLANK[3,9]
WHITE[1,2]


Try to remove segment [10, ?]
before:
BLANK[31,18446744073709551615]
BLACK[10,15]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLANK[10,15]
BLANK[3,9]
WHITE[1,2]


Try to add segment [10, 30] BLACK
before:
BLANK[31,18446744073709551615]
BLANK[10,15]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[10,30]
BLANK[10,15]
BLANK[3,9]
WHITE[1,2]


Try to add segment [15, 15] WHITE
before:
BLANK[31,18446744073709551615]
BLACK[10,30]
BLANK[10,15]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[16,30]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [22, 23] WHITE
before:
BLANK[31,18446744073709551615]
BLACK[16,30]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[24,30]
WHITE[22,23]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [23, 26] WHITE
before:
BLANK[31,18446744073709551615]
BLACK[24,30]
WHITE[22,23]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[31,18446744073709551615]
BLACK[27,30]
WHITE[22,26]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [25, 39] BLACK
before:
BLANK[31,18446744073709551615]
BLACK[27,30]
WHITE[22,26]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[40,18446744073709551615]
BLACK[25,39]
WHITE[22,24]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [20, 40] WHITE
before:
BLANK[40,18446744073709551615]
BLACK[25,39]
WHITE[22,24]
BLACK[16,21]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[41,18446744073709551615]
WHITE[20,40]
BLACK[16,19]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [45, 45] WHITE
before:
BLANK[41,18446744073709551615]
WHITE[20,40]
BLACK[16,19]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[46,18446744073709551615]
WHITE[45,45]
BLANK[41,44]
WHITE[20,40]
BLACK[16,19]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]


Try to add segment [1, 50] BLACK
before:
BLANK[46,18446744073709551615]
WHITE[45,45]
BLANK[41,44]
WHITE[20,40]
BLACK[16,19]
WHITE[15,15]
BLACK[10,14]
BLANK[3,9]
WHITE[1,2]
after:
BLANK[51,18446744073709551615]
BLACK[1,50]

Success: 3 tests passed.
Test time: 0.00 seconds.
/<br>
