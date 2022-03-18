//
// Created by lask3 on 2022/3/8.
//

#include "RawAudioSource.h"

int64_t RawAudioSource::getSize() const {
    return mLength;
}

AudioProperties RawAudioSource::getProperties() const {
    return mProperties;
}

const float *RawAudioSource::getData() const {
    return mRawAudioData;
}

RawAudioSource::RawAudioSource(float* rawAudioData,int64_t length, const AudioProperties& properties):
        mRawAudioData(rawAudioData),
        mLength(length),
        mProperties(properties)
{}
