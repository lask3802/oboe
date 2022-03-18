//
// Created by lask3 on 2022/3/8.
//

#ifndef SAMPLES_RAWAUDIOSOURCE_H
#define SAMPLES_RAWAUDIOSOURCE_H

#include <cstdint>
#include "DataSource.h"
#include "../GameConstants.h"

class RawAudioSource: public DataSource {
public:
    RawAudioSource(float* rawAudioData, int64_t length, const AudioProperties& properties);

    virtual int64_t getSize() const;

    virtual AudioProperties getProperties() const;

    virtual const float *getData() const;

private:
    float* mRawAudioData;
    int64_t mLength;
    AudioProperties mProperties;

};


#endif //SAMPLES_RAWAUDIOSOURCE_H
