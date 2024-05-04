#include "../../inc/defines.h"
#include "../../inc/objects.h"

void init_list_shape(shapes_s* list_shapes) {
  // O
  list_shapes[0] = (shapes_s){0,
                              0,
                              2,
                              2,  // 00
                              2,  // 00
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(1)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[1] = (shapes_s){0,
                              0,
                              2,
                              2,  // 00
                              2,  // 00
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(1)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[2] = (shapes_s){0,
                              0,
                              2,
                              2,  // 00
                              2,  // 00
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(1)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[3] = (shapes_s){0,
                              0,
                              2,
                              2,  // 00
                              2,  // 00
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(1)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  // I
  list_shapes[4] = (shapes_s){4,
                              -1,
                              4,
                              1,
                              1,  // 0000
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(0), SHIFT_R(2)},
                               {SHIFT_D(0), SHIFT_R(3)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[5] = (shapes_s){4,
                              2,
                              1,  // 0
                              4,  // 0
                              3,  // 0
                              2,  // 0
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(2), SHIFT_R(0)},
                               {SHIFT_D(3), SHIFT_R(0)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[6] = (shapes_s){4,
                              -1,
                              4,
                              1,
                              1,  // 0000
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(0), SHIFT_R(2)},
                               {SHIFT_D(0), SHIFT_R(3)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[7] = (shapes_s){4,
                              2,
                              1,  // 0
                              4,  // 0
                              3,  // 0
                              2,  // 0
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(2), SHIFT_R(0)},
                               {SHIFT_D(3), SHIFT_R(0)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  // Z
  list_shapes[8] = (shapes_s){8,
                              0,
                              3,
                              1,  // 00
                              2,  //  00
                              1,
                              1,
                              {{SHIFT_D(0), SHIFT_R(0)},
                               {SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(2)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  list_shapes[9] = (shapes_s){8,
                              1,
                              2,
                              2,  //  0
                              2,  // 00
                              1,  // 0
                              1,
                              {{SHIFT_D(0), SHIFT_R(1)},
                               {SHIFT_D(1), SHIFT_R(0)},
                               {SHIFT_D(1), SHIFT_R(1)},
                               {SHIFT_D(2), SHIFT_R(0)}},
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0,
                              0};
  // // S
  list_shapes[10] = (shapes_s){10,
                               0,
                               3,
                               2,  //  00
                               1,  // 00
                               1,
                               1,
                               {{SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(0), SHIFT_R(2)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[11] = (shapes_s){10,
                               1,
                               2,
                               2,  // 0
                               2,  // 00
                               1,  //  0
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(2), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  // J
  list_shapes[12] = (shapes_s){12,
                               0,
                               3,
                               2,
                               1,  //  0
                               1,  //  000
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(2)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[13] = (shapes_s){12,
                               1,
                               2,
                               3,  //  00
                               1,  //  0
                               2,  //  0
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(2), SHIFT_R(0)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[14] = (shapes_s){12,
                               0,
                               3,
                               1,  // 000
                               1,  //   0
                               2,
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(0), SHIFT_R(2)},
                                {SHIFT_D(1), SHIFT_R(2)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[15] = (shapes_s){12,
                               1,
                               2,
                               3,  //  0
                               2,  //  0
                               1,  // 00
                               1,
                               {{SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(2), SHIFT_R(0)},
                                {SHIFT_D(2), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  // L
  list_shapes[16] = (shapes_s){16,
                               0,
                               3,
                               2,  // 000
                               1,  // 0
                               1,
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(0), SHIFT_R(2)},
                                {SHIFT_D(1), SHIFT_R(0)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[17] = (shapes_s){16,
                               1,
                               2,
                               1,  // 00
                               3,  //  0
                               2,  //  0
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(2), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[18] = (shapes_s){16,
                               0,
                               3,
                               2,  //   0
                               1,  // 000
                               1,
                               1,
                               {{SHIFT_D(0), SHIFT_R(2)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(2)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[19] = (shapes_s){16,
                               1,
                               2,
                               3,  //  0
                               2,  //  0
                               1,  //  00
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(2), SHIFT_R(0)},
                                {SHIFT_D(2), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  // // T
  list_shapes[20] = (shapes_s){20,
                               0,
                               3,
                               1,  // 000
                               2,  //  0
                               1,
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(0), SHIFT_R(2)},
                                {SHIFT_D(1), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[21] = (shapes_s){20,
                               1,
                               2,
                               3,  //   0
                               1,  //  00
                               2,  //   0
                               1,
                               {{SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(2), SHIFT_R(1)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[22] = (shapes_s){20,
                               0,
                               3,
                               2,  //  0
                               1,  // 000
                               1,
                               1,
                               {{SHIFT_D(0), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(1), SHIFT_R(2)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
  list_shapes[23] = (shapes_s){20,
                               1,
                               2,
                               3,  //  0
                               2,  //  00
                               1,  //  0
                               1,
                               {{SHIFT_D(0), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(0)},
                                {SHIFT_D(1), SHIFT_R(1)},
                                {SHIFT_D(2), SHIFT_R(0)}},
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0,
                               0};
}
