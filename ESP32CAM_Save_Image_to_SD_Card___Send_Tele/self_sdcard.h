#ifndef SDCARD_H
#define SDCARD_H

#include <FS.h>
#include <SD_MMC.h>
#include "fb_gfx.h"
#include "fd_forward.h"
#include "fr_forward.h"
#include "img_converters.h"
//#include "fr_flash.h"

void sdmmc_init_system()
{
    if (!SD_MMC.begin())
    {
        Serial.println("Card mount failed!");
        return;
    }

    uint8_t card_type = SD_MMC.cardType();
    if (card_type == CARD_NONE)
    {
        Serial.println("SD Card Not attached!");
        return;
    }

    String str;
    switch (card_type)
    {
    case CARD_MMC:
        str = "MMC";
        break;
    case CARD_SD:
        str = "SDSC";
        break;
    case CARD_SDHC:
        str = "SDHC";
        break;
    default:
        str = "UNKNOWN";
        break;
    }

    Serial.println("SD Card type : " + str);
}

void sdmmc_write_face_data(face_id_list *face_list)
{
    File fl = SD_MMC.open((const char *)"/FILE.dat", FILE_WRITE);

    fl.write(face_list->head);
    fl.write(face_list->tail);
    fl.write(face_list->count);
    fl.write(face_list->size);
    fl.write(face_list->confirm_times);

    const int b_len = FACE_ID_SIZE * sizeof(float);
    for (uint8_t x = 0; x < face_list->count; x++)
    {
        fl.write((uint8_t *)face_list->id_list[x], b_len);
    }

    fl.close();
}

void sdmmc_read_face_data(face_id_list *face_list)
{
    File fl = SD_MMC.open((const char *)"/FACE.dat", FILE_READ);

    face_list->head = fl.read();
    face_list->tail = fl.read();
    face_list->count = fl.read();
    face_list->size = fl.read();
    face_list->confirm_times = fl.read();

    dl_matrix3d_t **fc_list = face_list->id_list;
    const int b_len = FACE_ID_SIZE * sizeof(float);

    for (uint8_t x = 0; x < face_list->count; x++)
    {
        fc_list[x] = dl_matrix3d_alloc(1, 1, 1, FACE_ID_SIZE);
        fl.read((uint8_t *)fc_list[x]->item, b_len);
    }

    fl.close();
}

#endif
