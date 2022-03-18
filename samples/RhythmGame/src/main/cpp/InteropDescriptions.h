//
// Created by lask3 on 2022/3/18.
//

#ifndef SAMPLES_INTEROPDESCRIPTIONS_H
#define SAMPLES_INTEROPDESCRIPTIONS_H
#include <cstdint>
#include "GameConstants.h"
#include "audio/Player.h"

struct DataSourceDescription{
    uint32_t index;
    AudioProperties audioProperties;
};

struct PlayerDescription{
    uint32_t index;
    DataSource* dataSource;
    uint32_t* framePositionPtr;
    float* volumePtr;
};

#endif //SAMPLES_INTEROPDESCRIPTIONS_H
