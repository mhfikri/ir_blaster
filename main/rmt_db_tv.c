#include "rmt_db_tv.h"

TV_DB_FORM TV_DbForm[] = {
    {2000,
     SAMSUNGTV,
     LC8C8D8DB8E,
     0,
     0x07,
     0xff,
     {0x02, 0x07, 0x0b, 0x01, 0x60, 0x61, 0x65, 0x62, 0x68, 0x12, 0x10, 0x1a, 0x0f, 0x58, 0xff},
     {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
     0xff,
     0xff,
     0xff,
     0xff,
     0xff,
     0xff},

    {2010,
     LGTV,
     LC8CB8D8DB8E,
     0,
     0x04,
     0xff,
     {0x08, 0x02, 0x03, 0x0b, 0x40, 0x41, 0x07, 0x06, 0x44, 0x00, 0x01, 0x43, 0x09, 0x28, 0x7c},
     {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
     0xff,
     0xff,
     0xff,
     0xff,
     0xff,
     0xff},
};

WAVE_FORM TV_WaveForm[] = {
    // SAMSUNGTV
    {{70, 140},
     {{{HIGH, 550}, {LOW, 570}},
      {{HIGH, 550}, {LOW, 1690}},
      {{HIGH, 4510}, {LOW, 4510}},
      {{0, 0}, {0, 0}},
      {{0, 0}, {0, 0}}}},

    // LGTV
    {{70, 140},
     {{{HIGH, 570}, {LOW, 570}},
      {{HIGH, 570}, {LOW, 1710}},
      {{HIGH, 9150}, {LOW, 4610}},
      {{0, 0}, {0, 0}},
      {{0, 0}, {0, 0}}}},
};

DATA_FORM TV_DataForm[] = {
    // LC8C8D8DB8E
    {{{LEADER, 2, 0, 0},
      {CUSTOM1, 0, 0, 8},
      {CUSTOM2, 0, 0, 8},
      {DEFAULT0, 0, 2, 8},
      {BAR, 0, 2, 8},
      {END, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0}}},

    // LC8CB8D8DB8E
    {{{LEADER, 2, 0, 0},
      {CUSTOM1, 0, 0, 8},
      {BAR, 0, 0, 8},
      {DEFAULT0, 0, 2, 8},
      {BAR, 0, 2, 8},
      {END, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0},
      {NONE, 0, 0, 0}}},
};

unsigned int tv_db_size = sizeof(TV_DbForm) / sizeof(TV_DbForm[0]);